/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef VPX_VP9_DECODER_VP9_DECODEFRAME_H_
#define VPX_VP9_DECODER_VP9_DECODEFRAME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vpx/vpx_decoder.h"
#include "vp9/common/vp9_enums.h"

struct VP9Decoder;
struct vpx_read_bit_buffer;

int vp9_read_sync_code(struct vpx_read_bit_buffer *const rb);
void vp9_read_frame_size(struct vpx_read_bit_buffer *rb, int *width,
                         int *height);
BITSTREAM_PROFILE vp9_read_profile(struct vpx_read_bit_buffer *rb);

void vp9_decode_frame(struct VP9Decoder *pbi, const uint8_t *data,
                      const uint8_t *data_end, const uint8_t **p_data_end,
                      // tile 0 offset, tile 0 size, tile 1 offset, tile 1 size, ...
                      size_t *tile_offset_size);

void vp9_decode_tiles_in_frame(struct VP9Decoder *pbi, const uint8_t *data,
                      const uint8_t *data_end,
                      const vpx_compressed_tile_info_t* tinfo,
                      int num_tinfo);

void vp9_get_tiles_info(struct VP9Decoder *pbi, const uint8_t *data,
                      const uint8_t *data_end,
                      size_t *tile_offset_size);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // VPX_VP9_DECODER_VP9_DECODEFRAME_H_
