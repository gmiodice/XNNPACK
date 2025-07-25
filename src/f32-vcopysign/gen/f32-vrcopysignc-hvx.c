// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-vcopysign/rcopysignc.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/simd/f32-hvx.h"
#include "src/xnnpack/vunary.h"


void xnn_f32_vrcopysignc_ukernel__hvx_u32(
    size_t batch,
    const float* sign,
    const float* mag,
    float* output,
    const struct xnn_f32_default_params* unused_params)
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(sign != NULL);
  assert(mag != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 32);

  XNN_SIMD_CONST_F32(vsign_mask, -0.f);
  xnn_simd_f32_t vmag = xnn_abs_f32(xnn_set1_f32(*mag));

  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vsign = xnn_loadu_f32(sign);
    sign += xnn_simd_size_f32;

    vsign = xnn_and_f32(vsign, vsign_mask);

    xnn_simd_f32_t vy = xnn_or_f32(vsign, vmag);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_f32_t vsign = xnn_load_tail_f32(sign, batch >> XNN_LOG2_SIZEOF_FLOAT);
    vsign = xnn_and_f32(vsign, vsign_mask);

    xnn_simd_f32_t vy = xnn_or_f32(vsign, vmag);

    xnn_store_tail_f32(output, vy, batch >> XNN_LOG2_SIZEOF_FLOAT);
  }
}

void xnn_f32_vrcopysignc_ukernel__hvx_u64(
    size_t batch,
    const float* sign,
    const float* mag,
    float* output,
    const struct xnn_f32_default_params* unused_params)
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(sign != NULL);
  assert(mag != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 32);

  XNN_SIMD_CONST_F32(vsign_mask, -0.f);
  xnn_simd_f32_t vmag = xnn_abs_f32(xnn_set1_f32(*mag));

  for (; batch >= 64 * sizeof(float); batch -= 64 * sizeof(float)) {
    xnn_simd_f32_t vsign_0 = xnn_loadu_f32(sign + 0 * xnn_simd_size_f32);
    xnn_simd_f32_t vsign_1 = xnn_loadu_f32(sign + 1 * xnn_simd_size_f32);
    sign += 64;

    vsign_0 = xnn_and_f32(vsign_0, vsign_mask);
    vsign_1 = xnn_and_f32(vsign_1, vsign_mask);

    xnn_simd_f32_t vy_0 = xnn_or_f32(vsign_0, vmag);
    xnn_simd_f32_t vy_1 = xnn_or_f32(vsign_1, vmag);

    xnn_storeu_f32(output + 0 * xnn_simd_size_f32, vy_0);
    xnn_storeu_f32(output + 1 * xnn_simd_size_f32, vy_1);
    output += 64;
  }
  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vsign = xnn_loadu_f32(sign);
    sign += xnn_simd_size_f32;

    vsign = xnn_and_f32(vsign, vsign_mask);

    xnn_simd_f32_t vy = xnn_or_f32(vsign, vmag);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_f32_t vsign = xnn_load_tail_f32(sign, batch >> XNN_LOG2_SIZEOF_FLOAT);
    vsign = xnn_and_f32(vsign, vsign_mask);

    xnn_simd_f32_t vy = xnn_or_f32(vsign, vmag);

    xnn_store_tail_f32(output, vy, batch >> XNN_LOG2_SIZEOF_FLOAT);
  }
}

void xnn_f32_vrcopysignc_ukernel__hvx_u96(
    size_t batch,
    const float* sign,
    const float* mag,
    float* output,
    const struct xnn_f32_default_params* unused_params)
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(sign != NULL);
  assert(mag != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 32);

  XNN_SIMD_CONST_F32(vsign_mask, -0.f);
  xnn_simd_f32_t vmag = xnn_abs_f32(xnn_set1_f32(*mag));

  for (; batch >= 96 * sizeof(float); batch -= 96 * sizeof(float)) {
    xnn_simd_f32_t vsign_0 = xnn_loadu_f32(sign + 0 * xnn_simd_size_f32);
    xnn_simd_f32_t vsign_1 = xnn_loadu_f32(sign + 1 * xnn_simd_size_f32);
    xnn_simd_f32_t vsign_2 = xnn_loadu_f32(sign + 2 * xnn_simd_size_f32);
    sign += 96;

    vsign_0 = xnn_and_f32(vsign_0, vsign_mask);
    vsign_1 = xnn_and_f32(vsign_1, vsign_mask);
    vsign_2 = xnn_and_f32(vsign_2, vsign_mask);

    xnn_simd_f32_t vy_0 = xnn_or_f32(vsign_0, vmag);
    xnn_simd_f32_t vy_1 = xnn_or_f32(vsign_1, vmag);
    xnn_simd_f32_t vy_2 = xnn_or_f32(vsign_2, vmag);

    xnn_storeu_f32(output + 0 * xnn_simd_size_f32, vy_0);
    xnn_storeu_f32(output + 1 * xnn_simd_size_f32, vy_1);
    xnn_storeu_f32(output + 2 * xnn_simd_size_f32, vy_2);
    output += 96;
  }
  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vsign = xnn_loadu_f32(sign);
    sign += xnn_simd_size_f32;

    vsign = xnn_and_f32(vsign, vsign_mask);

    xnn_simd_f32_t vy = xnn_or_f32(vsign, vmag);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_f32_t vsign = xnn_load_tail_f32(sign, batch >> XNN_LOG2_SIZEOF_FLOAT);
    vsign = xnn_and_f32(vsign, vsign_mask);

    xnn_simd_f32_t vy = xnn_or_f32(vsign, vmag);

    xnn_store_tail_f32(output, vy, batch >> XNN_LOG2_SIZEOF_FLOAT);
  }
}

void xnn_f32_vrcopysignc_ukernel__hvx_u128(
    size_t batch,
    const float* sign,
    const float* mag,
    float* output,
    const struct xnn_f32_default_params* unused_params)
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(sign != NULL);
  assert(mag != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f32 == 32);

  XNN_SIMD_CONST_F32(vsign_mask, -0.f);
  xnn_simd_f32_t vmag = xnn_abs_f32(xnn_set1_f32(*mag));

  for (; batch >= 128 * sizeof(float); batch -= 128 * sizeof(float)) {
    xnn_simd_f32_t vsign_0 = xnn_loadu_f32(sign + 0 * xnn_simd_size_f32);
    xnn_simd_f32_t vsign_1 = xnn_loadu_f32(sign + 1 * xnn_simd_size_f32);
    xnn_simd_f32_t vsign_2 = xnn_loadu_f32(sign + 2 * xnn_simd_size_f32);
    xnn_simd_f32_t vsign_3 = xnn_loadu_f32(sign + 3 * xnn_simd_size_f32);
    sign += 128;

    vsign_0 = xnn_and_f32(vsign_0, vsign_mask);
    vsign_1 = xnn_and_f32(vsign_1, vsign_mask);
    vsign_2 = xnn_and_f32(vsign_2, vsign_mask);
    vsign_3 = xnn_and_f32(vsign_3, vsign_mask);

    xnn_simd_f32_t vy_0 = xnn_or_f32(vsign_0, vmag);
    xnn_simd_f32_t vy_1 = xnn_or_f32(vsign_1, vmag);
    xnn_simd_f32_t vy_2 = xnn_or_f32(vsign_2, vmag);
    xnn_simd_f32_t vy_3 = xnn_or_f32(vsign_3, vmag);

    xnn_storeu_f32(output + 0 * xnn_simd_size_f32, vy_0);
    xnn_storeu_f32(output + 1 * xnn_simd_size_f32, vy_1);
    xnn_storeu_f32(output + 2 * xnn_simd_size_f32, vy_2);
    xnn_storeu_f32(output + 3 * xnn_simd_size_f32, vy_3);
    output += 128;
  }
  for (; batch >= xnn_simd_bytes_f32; batch -= xnn_simd_bytes_f32) {
    xnn_simd_f32_t vsign = xnn_loadu_f32(sign);
    sign += xnn_simd_size_f32;

    vsign = xnn_and_f32(vsign, vsign_mask);

    xnn_simd_f32_t vy = xnn_or_f32(vsign, vmag);

    xnn_storeu_f32(output, vy);
    output += xnn_simd_size_f32;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_f32_t vsign = xnn_load_tail_f32(sign, batch >> XNN_LOG2_SIZEOF_FLOAT);
    vsign = xnn_and_f32(vsign, vsign_mask);

    xnn_simd_f32_t vy = xnn_or_f32(vsign, vmag);

    xnn_store_tail_f32(output, vy, batch >> XNN_LOG2_SIZEOF_FLOAT);
  }
}
