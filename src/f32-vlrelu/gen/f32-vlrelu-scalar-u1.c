// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-vlrelu/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/vunary.h"


void xnn_f32_vlrelu_ukernel__scalar_u1(
    size_t batch,
    const float* input,
    float* output,
    const struct xnn_f32_lrelu_params* restrict params)
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const float vslope = params->scalar.slope;

  do {
    const float vx = *input++;
    float vacc = vx * vslope;
    vacc = XNN_UNPREDICTABLE(vx < 0.0f) ? vacc : vx;
    *output++ = vacc;
    batch -= sizeof(float);
  } while (batch != 0);
}
