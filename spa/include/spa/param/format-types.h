/* Simple Plugin API
 *
 * Copyright © 2018 Wim Taymans
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

#ifndef SPA_PARAM_FORMAT_TYPES_H
#define SPA_PARAM_FORMAT_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup spa_param
 * \{
 */

#include <spa/param/format.h>
#include <spa/param/param-types.h>

#include <spa/param/audio/type-info.h>
#include <spa/param/video/type-info.h>

#define SPA_TYPE_INFO_Format			SPA_TYPE_INFO_PARAM_BASE "Format"
#define SPA_TYPE_INFO_FORMAT_BASE		SPA_TYPE_INFO_Format ":"

#define SPA_TYPE_INFO_MediaType		SPA_TYPE_INFO_ENUM_BASE "MediaType"
#define SPA_TYPE_INFO_MEDIA_TYPE_BASE	SPA_TYPE_INFO_MediaType ":"

static const struct spa_type_info spa_type_media_type[] = {
	{ SPA_MEDIA_TYPE_unknown, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_TYPE_BASE "unknown", NULL },
	{ SPA_MEDIA_TYPE_audio,   SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_TYPE_BASE "audio", NULL },
	{ SPA_MEDIA_TYPE_video,   SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_TYPE_BASE "video", NULL },
	{ SPA_MEDIA_TYPE_image,   SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_TYPE_BASE "image", NULL },
	{ SPA_MEDIA_TYPE_binary,  SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_TYPE_BASE "binary", NULL },
	{ SPA_MEDIA_TYPE_stream,  SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_TYPE_BASE "stream", NULL },
	{ SPA_MEDIA_TYPE_application,  SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_TYPE_BASE "application", NULL },
	{ 0, 0, NULL, NULL },
};

#define SPA_TYPE_INFO_MediaSubtype		SPA_TYPE_INFO_ENUM_BASE "MediaSubtype"
#define SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE	SPA_TYPE_INFO_MediaSubtype ":"

static const struct spa_type_info spa_type_media_subtype[] = {
	{ SPA_MEDIA_SUBTYPE_unknown, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "unknown", NULL },
	/* generic subtypes */
	{ SPA_MEDIA_SUBTYPE_raw, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "raw", NULL },
	{ SPA_MEDIA_SUBTYPE_dsp, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "dsp", NULL },
	{ SPA_MEDIA_SUBTYPE_iec958, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "iec958", NULL },
	{ SPA_MEDIA_SUBTYPE_dsd, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "dsd", NULL },
	/* audio subtypes */
	{ SPA_MEDIA_SUBTYPE_mp3, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "mp3", NULL },
	{ SPA_MEDIA_SUBTYPE_aac, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "aac", NULL },
	{ SPA_MEDIA_SUBTYPE_vorbis, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "vorbis", NULL },
	{ SPA_MEDIA_SUBTYPE_wma, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "wma", NULL },
	{ SPA_MEDIA_SUBTYPE_ra, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "ra", NULL },
	{ SPA_MEDIA_SUBTYPE_sbc, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "sbc", NULL },
	{ SPA_MEDIA_SUBTYPE_adpcm, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "adpcm", NULL },
	{ SPA_MEDIA_SUBTYPE_g723, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "g723", NULL },
	{ SPA_MEDIA_SUBTYPE_g726, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "g726", NULL },
	{ SPA_MEDIA_SUBTYPE_g729, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "g729", NULL },
	{ SPA_MEDIA_SUBTYPE_amr, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "amr", NULL },
	{ SPA_MEDIA_SUBTYPE_gsm, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "gsm", NULL },
	/* video subtypes */
	{ SPA_MEDIA_SUBTYPE_h264, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "h264", NULL },
	{ SPA_MEDIA_SUBTYPE_mjpg, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "mjpg", NULL },
	{ SPA_MEDIA_SUBTYPE_dv, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "dv", NULL },
	{ SPA_MEDIA_SUBTYPE_mpegts, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "mpegts", NULL },
	{ SPA_MEDIA_SUBTYPE_h263, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "h263", NULL },
	{ SPA_MEDIA_SUBTYPE_mpeg1, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "mpeg1", NULL },
	{ SPA_MEDIA_SUBTYPE_mpeg2, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "mpeg2", NULL },
	{ SPA_MEDIA_SUBTYPE_mpeg4, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "mpeg4", NULL },
	{ SPA_MEDIA_SUBTYPE_xvid, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "xvid", NULL },
	{ SPA_MEDIA_SUBTYPE_vc1, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "vc1", NULL },
	{ SPA_MEDIA_SUBTYPE_vp8, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "vp8", NULL },
	{ SPA_MEDIA_SUBTYPE_vp9, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "vp9", NULL },
	{ SPA_MEDIA_SUBTYPE_bayer, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "bayer", NULL },
	/* image subtypes */
	{ SPA_MEDIA_SUBTYPE_jpeg, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "jpeg", NULL },
	/* stream subtypes */
	{ SPA_MEDIA_SUBTYPE_midi, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "midi", NULL },
	/* application subtypes */
	{ SPA_MEDIA_SUBTYPE_control, SPA_TYPE_Int, SPA_TYPE_INFO_MEDIA_SUBTYPE_BASE "control", NULL },
	{ 0, 0, NULL, NULL },
};

#define SPA_TYPE_INFO_FormatAudio		SPA_TYPE_INFO_FORMAT_BASE "Audio"
#define SPA_TYPE_INFO_FORMAT_AUDIO_BASE		SPA_TYPE_INFO_FormatAudio ":"

#define SPA_TYPE_INFO_FormatVideo		SPA_TYPE_INFO_FORMAT_BASE "Video"
#define SPA_TYPE_INFO_FORMAT_VIDEO_BASE		SPA_TYPE_INFO_FormatVideo ":"

#define SPA_TYPE_INFO_FORMAT_VIDEO_H264		SPA_TYPE_INFO_FORMAT_VIDEO_BASE "H264"
#define SPA_TYPE_INFO_FORMAT_VIDEO_H264_BASE	SPA_TYPE_INFO_FORMAT_VIDEO_H264 ":"

static const struct spa_type_info spa_type_format[] = {
	{ SPA_FORMAT_START, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_BASE, spa_type_param, },

	{ SPA_FORMAT_mediaType, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_BASE "mediaType",
		spa_type_media_type, },
	{ SPA_FORMAT_mediaSubtype, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_BASE "mediaSubtype",
		spa_type_media_subtype, },

	{ SPA_FORMAT_AUDIO_format, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "format",
		spa_type_audio_format },
	{ SPA_FORMAT_AUDIO_flags, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "flags",
		spa_type_audio_flags },
	{ SPA_FORMAT_AUDIO_rate, SPA_TYPE_Int, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "rate", NULL },
	{ SPA_FORMAT_AUDIO_channels, SPA_TYPE_Int, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "channels", NULL },
	{ SPA_FORMAT_AUDIO_position, SPA_TYPE_Array, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "position",
		spa_type_prop_channel_map },

	{ SPA_FORMAT_AUDIO_iec958Codec, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "iec958Codec",
		spa_type_audio_iec958_codec },

	{ SPA_FORMAT_AUDIO_bitorder, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "bitorder",
		spa_type_param_bitorder },
	{ SPA_FORMAT_AUDIO_interleave, SPA_TYPE_Int, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "interleave", NULL },
	{ SPA_FORMAT_AUDIO_bitrate, SPA_TYPE_Int, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "bitrate", NULL },
	{ SPA_FORMAT_AUDIO_blockAlign, SPA_TYPE_Int, SPA_TYPE_INFO_FORMAT_AUDIO_BASE "blockAlign", NULL },

	{ SPA_FORMAT_VIDEO_format, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "format",
		spa_type_video_format, },
	{ SPA_FORMAT_VIDEO_modifier, SPA_TYPE_Long, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "modifier", NULL },
	{ SPA_FORMAT_VIDEO_size,  SPA_TYPE_Rectangle, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "size", NULL },
	{ SPA_FORMAT_VIDEO_framerate, SPA_TYPE_Fraction, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "framerate", NULL },
	{ SPA_FORMAT_VIDEO_maxFramerate, SPA_TYPE_Fraction, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "maxFramerate", NULL },
	{ SPA_FORMAT_VIDEO_views, SPA_TYPE_Int, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "views", NULL },
	{ SPA_FORMAT_VIDEO_interlaceMode, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "interlaceMode",
		spa_type_video_interlace_mode, },
	{ SPA_FORMAT_VIDEO_pixelAspectRatio, SPA_TYPE_Fraction, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "pixelAspectRatio", NULL },
	{ SPA_FORMAT_VIDEO_multiviewMode, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "multiviewMode", NULL },
	{ SPA_FORMAT_VIDEO_multiviewFlags, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "multiviewFlags", NULL },
	{ SPA_FORMAT_VIDEO_chromaSite, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "chromaSite", NULL },
	{ SPA_FORMAT_VIDEO_colorRange, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "colorRange", NULL },
	{ SPA_FORMAT_VIDEO_colorMatrix, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "colorMatrix", NULL },
	{ SPA_FORMAT_VIDEO_transferFunction, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "transferFunction", NULL },
	{ SPA_FORMAT_VIDEO_colorPrimaries, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "colorPrimaries", NULL },
	{ SPA_FORMAT_VIDEO_profile, SPA_TYPE_Int, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "profile", NULL },
	{ SPA_FORMAT_VIDEO_level, SPA_TYPE_Int, SPA_TYPE_INFO_FORMAT_VIDEO_BASE "level", NULL },

	{ SPA_FORMAT_VIDEO_H264_streamFormat, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_H264_BASE "streamFormat", NULL },
	{ SPA_FORMAT_VIDEO_H264_alignment, SPA_TYPE_Id, SPA_TYPE_INFO_FORMAT_VIDEO_H264_BASE "alignment", NULL },
	{ 0, 0, NULL, NULL },
};

/**
 * \}
 */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* SPA_PARAM_FORMAT_TYPES_H */
