/* PipeWire
 *
 * Copyright © 2022 Wim Taymans <wim.taymans@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <pipewire/pipewire.h>

#include "../module.h"

#define NAME "always-sink"

PW_LOG_TOPIC_STATIC(mod_topic, "mod." NAME);
#define PW_LOG_TOPIC_DEFAULT mod_topic

struct module_always_sink_data {
	struct module *module;

	struct pw_impl_module *mod;
	struct spa_hook mod_listener;
};

static void module_destroy(void *data)
{
	struct module_always_sink_data *d = data;
	spa_hook_remove(&d->mod_listener);
	d->mod = NULL;
	module_schedule_unload(d->module);
}

static const struct pw_impl_module_events module_events = {
	PW_VERSION_IMPL_MODULE_EVENTS,
	.destroy = module_destroy
};

static int module_always_sink_load(struct client *client, struct module *module)
{
	struct module_always_sink_data *data = module->user_data;
	FILE *f;
	char *args;
	const char *str;
	size_t size;

	if ((f = open_memstream(&args, &size)) == NULL)
		return -errno;

	fprintf(f, "{");
	if ((str = pw_properties_get(module->props, "sink_name")) != NULL)
		fprintf(f, " sink.name = \"%s\"", str);
	fprintf(f, " }");
	fclose(f);

	data->mod = pw_context_load_module(module->impl->context,
			"libpipewire-module-fallback-sink",
			args, NULL);
	free(args);

	if (data->mod == NULL)
		return -errno;

	pw_impl_module_add_listener(data->mod,
			&data->mod_listener,
			&module_events, data);
	return 0;
}

static int module_always_sink_unload(struct module *module)
{
	struct module_always_sink_data *d = module->user_data;

	if (d->mod) {
		spa_hook_remove(&d->mod_listener);
		pw_impl_module_destroy(d->mod);
		d->mod = NULL;
	}
	return 0;
}

static const struct spa_dict_item module_always_sink_info[] = {
	{ PW_KEY_MODULE_AUTHOR, "Pauli Virtanen <pav@iki.fi>" },
	{ PW_KEY_MODULE_DESCRIPTION, "Always keeps at least one sink loaded even if it's a null one" },
	{ PW_KEY_MODULE_USAGE,  "sink_name=<name of sink>" },
	{ PW_KEY_MODULE_VERSION, PACKAGE_VERSION },
};

int module_always_sink_prepare(struct module * const module)
{
	PW_LOG_TOPIC_INIT(mod_topic);

	struct module_always_sink_data * const data = module->user_data;
	data->module = module;

	return 0;
}

DEFINE_MODULE_INFO(module_always_sink) = {
	.name = "module-always-sink",
	.load_once = true,
	.prepare = module_always_sink_prepare,
	.load = module_always_sink_load,
	.unload = module_always_sink_unload,
	.properties = &SPA_DICT_INIT_ARRAY(module_always_sink_info),
	.data_size = sizeof(struct module_always_sink_data),
};
