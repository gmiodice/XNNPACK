// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/x8-packw/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/packw.h"
#include "src/xnnpack/unaligned.h"

void xnn_x8_packw_gemm_goi_ukernel_x16__scalar_u2(
  size_t g,
  size_t nc,
  size_t kc,
  size_t nr,
  size_t kr,
  size_t sr,
  const int8_t* weights,
  const uint32_t* bias,
  const void* scale,
  int8_t* packed_weights,
  size_t extra_bytes,
  const void* params)
{
  assert(g != 0);
  assert(nc != 0);
  assert(kc != 0);
  assert(nr == 16);   // This kernel is for NR=16
  assert(kr == 1);
  assert(sr == 1);
  assert(weights != NULL);
  assert(packed_weights != NULL);

  int8_t* out = (int8_t*) packed_weights;
  const uint32_t* b = (const uint32_t*) bias;

  do {
    // NC main loop multiple of 16
    const int8_t* w0 = (const int8_t*) weights;
    size_t n = nc;
    for (;n >= 16; n -= 16) {
      if XNN_LIKELY(b != NULL) {
        unaligned_store_s32(out + 0 * sizeof(int32_t), b[0]);
        unaligned_store_s32(out + 1 * sizeof(int32_t), b[1]);
        unaligned_store_s32(out + 2 * sizeof(int32_t), b[2]);
        unaligned_store_s32(out + 3 * sizeof(int32_t), b[3]);
        unaligned_store_s32(out + 4 * sizeof(int32_t), b[4]);
        unaligned_store_s32(out + 5 * sizeof(int32_t), b[5]);
        unaligned_store_s32(out + 6 * sizeof(int32_t), b[6]);
        unaligned_store_s32(out + 7 * sizeof(int32_t), b[7]);
        unaligned_store_s32(out + 8 * sizeof(int32_t), b[8]);
        unaligned_store_s32(out + 9 * sizeof(int32_t), b[9]);
        unaligned_store_s32(out + 10 * sizeof(int32_t), b[10]);
        unaligned_store_s32(out + 11 * sizeof(int32_t), b[11]);
        unaligned_store_s32(out + 12 * sizeof(int32_t), b[12]);
        unaligned_store_s32(out + 13 * sizeof(int32_t), b[13]);
        unaligned_store_s32(out + 14 * sizeof(int32_t), b[14]);
        unaligned_store_s32(out + 15 * sizeof(int32_t), b[15]);
        b += 16;
      } else {
        unaligned_store_s32(out + 0 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 1 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 2 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 3 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 4 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 5 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 6 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 7 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 8 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 9 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 10 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 11 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 12 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 13 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 14 * sizeof(int32_t), 0);
        unaligned_store_s32(out + 15 * sizeof(int32_t), 0);
      }
      out += 16 * sizeof(uint32_t);

      const int8_t* w1 = w0 + kc;
      const int8_t* w2 = w1 + kc;
      const int8_t* w3 = w2 + kc;
      const int8_t* w4 = w3 + kc;
      const int8_t* w5 = w4 + kc;
      const int8_t* w6 = w5 + kc;
      const int8_t* w7 = w6 + kc;
      const int8_t* w8 = w7 + kc;
      const int8_t* w9 = w8 + kc;
      const int8_t* w10 = w9 + kc;
      const int8_t* w11 = w10 + kc;
      const int8_t* w12 = w11 + kc;
      const int8_t* w13 = w12 + kc;
      const int8_t* w14 = w13 + kc;
      const int8_t* w15 = w14 + kc;

      // KC main loop multiple of 16x2
      size_t k = kc;
      for (; k >= 2; k -= 2) {
        const int8_t v00 = w0[0];
        const int8_t v01 = w0[1];
        w0 += 2;
        const int8_t v10 = w1[0];
        const int8_t v11 = w1[1];
        w1 += 2;
        const int8_t v20 = w2[0];
        const int8_t v21 = w2[1];
        w2 += 2;
        const int8_t v30 = w3[0];
        const int8_t v31 = w3[1];
        w3 += 2;
        const int8_t v40 = w4[0];
        const int8_t v41 = w4[1];
        w4 += 2;
        const int8_t v50 = w5[0];
        const int8_t v51 = w5[1];
        w5 += 2;
        const int8_t v60 = w6[0];
        const int8_t v61 = w6[1];
        w6 += 2;
        const int8_t v70 = w7[0];
        const int8_t v71 = w7[1];
        w7 += 2;
        const int8_t v80 = w8[0];
        const int8_t v81 = w8[1];
        w8 += 2;
        const int8_t v90 = w9[0];
        const int8_t v91 = w9[1];
        w9 += 2;
        const int8_t v100 = w10[0];
        const int8_t v101 = w10[1];
        w10 += 2;
        const int8_t v110 = w11[0];
        const int8_t v111 = w11[1];
        w11 += 2;
        const int8_t v120 = w12[0];
        const int8_t v121 = w12[1];
        w12 += 2;
        const int8_t v130 = w13[0];
        const int8_t v131 = w13[1];
        w13 += 2;
        const int8_t v140 = w14[0];
        const int8_t v141 = w14[1];
        w14 += 2;
        const int8_t v150 = w15[0];
        const int8_t v151 = w15[1];
        w15 += 2;
        out[0] = v00;
        out[1] = v10;
        out[2] = v20;
        out[3] = v30;
        out[4] = v40;
        out[5] = v50;
        out[6] = v60;
        out[7] = v70;
        out[8] = v80;
        out[9] = v90;
        out[10] = v100;
        out[11] = v110;
        out[12] = v120;
        out[13] = v130;
        out[14] = v140;
        out[15] = v150;
        out[16] = v01;
        out[17] = v11;
        out[18] = v21;
        out[19] = v31;
        out[20] = v41;
        out[21] = v51;
        out[22] = v61;
        out[23] = v71;
        out[24] = v81;
        out[25] = v91;
        out[26] = v101;
        out[27] = v111;
        out[28] = v121;
        out[29] = v131;
        out[30] = v141;
        out[31] = v151;
        out += 32;
      }

      // KC remainder
      for (; k != 0; --k) {
        const int8_t v0 = *w0++;
        out[0] = v0;
        const int8_t v1 = *w1++;
        out[1] = v1;
        const int8_t v2 = *w2++;
        out[2] = v2;
        const int8_t v3 = *w3++;
        out[3] = v3;
        const int8_t v4 = *w4++;
        out[4] = v4;
        const int8_t v5 = *w5++;
        out[5] = v5;
        const int8_t v6 = *w6++;
        out[6] = v6;
        const int8_t v7 = *w7++;
        out[7] = v7;
        const int8_t v8 = *w8++;
        out[8] = v8;
        const int8_t v9 = *w9++;
        out[9] = v9;
        const int8_t v10 = *w10++;
        out[10] = v10;
        const int8_t v11 = *w11++;
        out[11] = v11;
        const int8_t v12 = *w12++;
        out[12] = v12;
        const int8_t v13 = *w13++;
        out[13] = v13;
        const int8_t v14 = *w14++;
        out[14] = v14;
        const int8_t v15 = *w15++;
        out[15] = v15;
        out += 16;
      }
      out = (int8_t*) ((uintptr_t) out + extra_bytes);
      w0 = w15;
    }

    // NC remainder (1..15)
    if XNN_UNLIKELY(n != 0) {
      if XNN_LIKELY(b != NULL) {
        size_t nb = n;
        do {
          unaligned_store_s32(out, *b++);
          out += sizeof(uint32_t);
        } while (--nb != 0);
      } else {
        size_t nb = n;
        do {
          unaligned_store_s32(out, 0);
          out += sizeof(uint32_t);
        } while (--nb != 0);
      }
      out += (16 - n) * sizeof(uint32_t);

      // NR remainder has less than 16 rows so last row is not loaded
      const int8_t* w1 = w0 + kc;
      if XNN_UNPREDICTABLE(n < 2) {
        w1 = w0;
      }
      const int8_t* w2 = w1 + kc;
      if XNN_UNPREDICTABLE(n <= 2) {
        w2 = w1;
      }
      const int8_t* w3 = w2 + kc;
      if XNN_UNPREDICTABLE(n < 4) {
        w3 = w2;
      }
      const int8_t* w4 = w3 + kc;
      if XNN_UNPREDICTABLE(n <= 4) {
        w4 = w3;
      }
      const int8_t* w5 = w4 + kc;
      if XNN_UNPREDICTABLE(n < 6) {
        w5 = w4;
      }
      const int8_t* w6 = w5 + kc;
      if XNN_UNPREDICTABLE(n <= 6) {
        w6 = w5;
      }
      const int8_t* w7 = w6 + kc;
      if XNN_UNPREDICTABLE(n < 8) {
        w7 = w6;
      }
      const int8_t* w8 = w7 + kc;
      if XNN_UNPREDICTABLE(n <= 8) {
        w8 = w7;
      }
      const int8_t* w9 = w8 + kc;
      if XNN_UNPREDICTABLE(n < 10) {
        w9 = w8;
      }
      const int8_t* w10 = w9 + kc;
      if XNN_UNPREDICTABLE(n <= 10) {
        w10 = w9;
      }
      const int8_t* w11 = w10 + kc;
      if XNN_UNPREDICTABLE(n < 12) {
        w11 = w10;
      }
      const int8_t* w12 = w11 + kc;
      if XNN_UNPREDICTABLE(n <= 12) {
        w12 = w11;
      }
      const int8_t* w13 = w12 + kc;
      if XNN_UNPREDICTABLE(n < 14) {
        w13 = w12;
      }
      const int8_t* w14 = w13 + kc;
      if XNN_UNPREDICTABLE(n <= 14) {
        w14 = w13;
      }

      // KC main loop multiple of 16x2
      size_t k = kc;
      for (; k >= 2; k -= 2) {
        const int8_t v00 = w0[0];
        const int8_t v01 = w0[1];
        w0 += 2;
        const int8_t v10 = w1[0];
        const int8_t v11 = w1[1];
        w1 += 2;
        const int8_t v20 = w2[0];
        const int8_t v21 = w2[1];
        w2 += 2;
        const int8_t v30 = w3[0];
        const int8_t v31 = w3[1];
        w3 += 2;
        const int8_t v40 = w4[0];
        const int8_t v41 = w4[1];
        w4 += 2;
        const int8_t v50 = w5[0];
        const int8_t v51 = w5[1];
        w5 += 2;
        const int8_t v60 = w6[0];
        const int8_t v61 = w6[1];
        w6 += 2;
        const int8_t v70 = w7[0];
        const int8_t v71 = w7[1];
        w7 += 2;
        const int8_t v80 = w8[0];
        const int8_t v81 = w8[1];
        w8 += 2;
        const int8_t v90 = w9[0];
        const int8_t v91 = w9[1];
        w9 += 2;
        const int8_t v100 = w10[0];
        const int8_t v101 = w10[1];
        w10 += 2;
        const int8_t v110 = w11[0];
        const int8_t v111 = w11[1];
        w11 += 2;
        const int8_t v120 = w12[0];
        const int8_t v121 = w12[1];
        w12 += 2;
        const int8_t v130 = w13[0];
        const int8_t v131 = w13[1];
        w13 += 2;
        const int8_t v140 = w14[0];
        const int8_t v141 = w14[1];
        w14 += 2;
        out[0] = v00;
        out[1] = v10;
        out[2] = v20;
        out[3] = v30;
        out[4] = v40;
        out[5] = v50;
        out[6] = v60;
        out[7] = v70;
        out[8] = v80;
        out[9] = v90;
        out[10] = v100;
        out[11] = v110;
        out[12] = v120;
        out[13] = v130;
        out[14] = v140;
        out[16] = v01;
        out[17] = v11;
        out[18] = v21;
        out[19] = v31;
        out[20] = v41;
        out[21] = v51;
        out[22] = v61;
        out[23] = v71;
        out[24] = v81;
        out[25] = v91;
        out[26] = v101;
        out[27] = v111;
        out[28] = v121;
        out[29] = v131;
        out[30] = v141;
        out += 32;
      }

      // KC remainder of 1..1
      for (; k != 0; --k) {
        const int8_t v0 = *w0++;
        out[0] = v0;
        const int8_t v1 = *w1++;
        out[1] = v1;
        const int8_t v2 = *w2++;
        out[2] = v2;
        const int8_t v3 = *w3++;
        out[3] = v3;
        const int8_t v4 = *w4++;
        out[4] = v4;
        const int8_t v5 = *w5++;
        out[5] = v5;
        const int8_t v6 = *w6++;
        out[6] = v6;
        const int8_t v7 = *w7++;
        out[7] = v7;
        const int8_t v8 = *w8++;
        out[8] = v8;
        const int8_t v9 = *w9++;
        out[9] = v9;
        const int8_t v10 = *w10++;
        out[10] = v10;
        const int8_t v11 = *w11++;
        out[11] = v11;
        const int8_t v12 = *w12++;
        out[12] = v12;
        const int8_t v13 = *w13++;
        out[13] = v13;
        const int8_t v14 = *w14++;
        out[14] = v14;
        out += 16;
      }
      out = (int8_t*) ((uintptr_t) out + extra_bytes);
    }
    weights += nc * kc;
  } while (--g != 0);
}
