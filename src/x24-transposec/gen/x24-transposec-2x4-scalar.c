// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/x24-transposec/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/transpose.h"

void xnn_x24_transposec_ukernel__2x4_scalar(
    const void *input,
    void * output,
    size_t input_stride,
    size_t output_stride,
    size_t block_width,
    size_t block_height) XNN_OOB_READS
{
  assert(output_stride >= block_height * 3);
  assert(input_stride >= block_width * 3);

  const size_t input_reset = 12 - round_down_po2(block_height, 2) * input_stride;
  const size_t output_reset = 4 * output_stride - block_height * 3;
  const size_t input_offset = 2 * input_stride;

  const uint8_t* i0 = (const uint8_t*) input;
  const uint8_t* i1 = (const uint8_t*) ((uintptr_t) i0 + input_stride);

  uint8_t* o0 = (uint8_t*) output;
  uint8_t* o1 = (uint8_t*) ((uintptr_t) o0 + output_stride);
  uint8_t* o2 = (uint8_t*) ((uintptr_t) o1 + output_stride);
  uint8_t* o3 = (uint8_t*) ((uintptr_t) o2 + output_stride);

  do {
    if XNN_UNPREDICTABLE(block_width < 2) {
      o1 = o0;
    }
    if XNN_UNPREDICTABLE(block_width <= 2) {
      o2 = o0;
    }
    if XNN_UNPREDICTABLE(block_width < 4) {
      o3 = o0;
    }
    size_t bh = block_height;
    for (; bh >= 2; bh -= 2) {
      o3[0] = i0[9];
      o3[1] = i0[10];
      o3[2] = i0[11];
      o3[3] = i1[9];
      o3[4] = i1[10];
      o3[5] = i1[11];
      o3 += 6;
      o2[0] = i0[6];
      o2[1] = i0[7];
      o2[2] = i0[8];
      o2[3] = i1[6];
      o2[4] = i1[7];
      o2[5] = i1[8];
      o2 += 6;
      o1[0] = i0[3];
      o1[1] = i0[4];
      o1[2] = i0[5];
      o1[3] = i1[3];
      o1[4] = i1[4];
      o1[5] = i1[5];
      o1 += 6;
      o0[0] = i0[0];
      o0[1] = i0[1];
      o0[2] = i0[2];
      o0[3] = i1[0];
      o0[4] = i1[1];
      o0[5] = i1[2];
      o0 += 6;
      i0 = (const uint8_t*) ((uintptr_t) i0 + input_offset);
      i1 = (const uint8_t*) ((uintptr_t) i1 + input_offset);
    }
    const uint8_t* i = i0;
    if (bh & 1) {
      o3[0] = i[9];
      o3[1] = i[10];
      o3[2] = i[11];
      o3 += 3;
      o2[0] = i[6];
      o2[1] = i[7];
      o2[2] = i[8];
      o2 += 3;
      o1[0] = i[3];
      o1[1] = i[4];
      o1[2] = i[5];
      o1 += 3;
      o0[0] = i[0];
      o0[1] = i[1];
      o0[2] = i[2];
      o0 += 3;
    }

    i0 = (const uint8_t*) ((uintptr_t) i0 + input_reset);
    i1 = (const uint8_t*) ((uintptr_t) i0 + input_stride);
    o0 = (uint8_t*) ((uintptr_t) o0 + output_reset);
    o1 = (uint8_t*) ((uintptr_t) o1 + output_reset);
    o2 = (uint8_t*) ((uintptr_t) o2 + output_reset);
    o3 = (uint8_t*) ((uintptr_t) o3 + output_reset);
    block_width = doz(block_width, 4);
  } while (block_width != 0);
}
