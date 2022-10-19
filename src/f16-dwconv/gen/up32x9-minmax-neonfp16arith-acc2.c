// Auto-generated file. Do not edit!
//   Template: src/f16-dwconv/unipass-neonfp16arith.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include <xnnpack/dwconv.h>


void xnn_f16_dwconv_minmax_ukernel_up32x9__neonfp16arith_acc2(
    size_t channels,
    size_t output_width,
    const void** input,
    const void* weights,
    void* output_ptr,
    size_t input_stride,
    size_t output_increment,
    size_t input_offset,
    const void* zero,
    const union xnn_f16_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(channels != 0);
  assert(output_width != 0);

  __fp16* output = (__fp16*) output_ptr;
  const float16x8_t vmin = vreinterpretq_f16_u16(vld1q_dup_u16(&params->fp16arith.min));
  const float16x8_t vmax = vreinterpretq_f16_u16(vld1q_dup_u16(&params->fp16arith.max));
  do {
    const __fp16* i0 = (const __fp16*) input[0];
    assert(i0 != NULL);
    if XNN_UNPREDICTABLE(i0 != (const __fp16*) zero) {
      i0 = (const __fp16*) ((uintptr_t) i0 + input_offset);
    }
    const __fp16* i1 = (const __fp16*) input[1];
    assert(i1 != NULL);
    if XNN_UNPREDICTABLE(i1 != (const __fp16*) zero) {
      i1 = (const __fp16*) ((uintptr_t) i1 + input_offset);
    }
    const __fp16* i2 = (const __fp16*) input[2];
    assert(i2 != NULL);
    if XNN_UNPREDICTABLE(i2 != (const __fp16*) zero) {
      i2 = (const __fp16*) ((uintptr_t) i2 + input_offset);
    }
    const __fp16* i3 = (const __fp16*) input[3];
    assert(i3 != NULL);
    if XNN_UNPREDICTABLE(i3 != (const __fp16*) zero) {
      i3 = (const __fp16*) ((uintptr_t) i3 + input_offset);
    }
    const __fp16* i4 = (const __fp16*) input[4];
    assert(i4 != NULL);
    if XNN_UNPREDICTABLE(i4 != (const __fp16*) zero) {
      i4 = (const __fp16*) ((uintptr_t) i4 + input_offset);
    }
    const __fp16* i5 = (const __fp16*) input[5];
    assert(i5 != NULL);
    if XNN_UNPREDICTABLE(i5 != (const __fp16*) zero) {
      i5 = (const __fp16*) ((uintptr_t) i5 + input_offset);
    }
    const __fp16* i6 = (const __fp16*) input[6];
    assert(i6 != NULL);
    if XNN_UNPREDICTABLE(i6 != (const __fp16*) zero) {
      i6 = (const __fp16*) ((uintptr_t) i6 + input_offset);
    }
    const __fp16* i7 = (const __fp16*) input[7];
    assert(i7 != NULL);
    if XNN_UNPREDICTABLE(i7 != (const __fp16*) zero) {
      i7 = (const __fp16*) ((uintptr_t) i7 + input_offset);
    }
    const __fp16* i8 = (const __fp16*) input[8];
    assert(i8 != NULL);
    if XNN_UNPREDICTABLE(i8 != (const __fp16*) zero) {
      i8 = (const __fp16*) ((uintptr_t) i8 + input_offset);
    }

    input = (const void**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const __fp16* w = (const __fp16*) weights;
    for (; c >= 32; c -= 32) {
      float16x8_t vacc01234567p0 = vld1q_f16(w); w += 8;
      float16x8_t vacc89ABCDEFp0 = vld1q_f16(w); w += 8;
      float16x8_t vaccGHIJKLMNp0 = vld1q_f16(w); w += 8;
      float16x8_t vaccOPQRSTUVp0 = vld1q_f16(w); w += 8;


      const float16x8_t vi0x01234567 = vld1q_f16(i0); i0 += 8;
      const float16x8_t vi0x89ABCDEF = vld1q_f16(i0); i0 += 8;
      const float16x8_t vi0xGHIJKLMN = vld1q_f16(i0); i0 += 8;
      const float16x8_t vi0xOPQRSTUV = vld1q_f16(i0); i0 += 8;
      const float16x8_t vk0x01234567 = vld1q_f16(w); w += 8;
      const float16x8_t vk0x89ABCDEF = vld1q_f16(w); w += 8;
      const float16x8_t vk0xGHIJKLMN = vld1q_f16(w); w += 8;
      const float16x8_t vk0xOPQRSTUV = vld1q_f16(w); w += 8;
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi0x01234567, vk0x01234567);
      vacc89ABCDEFp0 = vfmaq_f16(vacc89ABCDEFp0, vi0x89ABCDEF, vk0x89ABCDEF);
      vaccGHIJKLMNp0 = vfmaq_f16(vaccGHIJKLMNp0, vi0xGHIJKLMN, vk0xGHIJKLMN);
      vaccOPQRSTUVp0 = vfmaq_f16(vaccOPQRSTUVp0, vi0xOPQRSTUV, vk0xOPQRSTUV);

      const float16x8_t vi1x01234567 = vld1q_f16(i1); i1 += 8;
      const float16x8_t vi1x89ABCDEF = vld1q_f16(i1); i1 += 8;
      const float16x8_t vi1xGHIJKLMN = vld1q_f16(i1); i1 += 8;
      const float16x8_t vi1xOPQRSTUV = vld1q_f16(i1); i1 += 8;
      const float16x8_t vk1x01234567 = vld1q_f16(w); w += 8;
      const float16x8_t vk1x89ABCDEF = vld1q_f16(w); w += 8;
      const float16x8_t vk1xGHIJKLMN = vld1q_f16(w); w += 8;
      const float16x8_t vk1xOPQRSTUV = vld1q_f16(w); w += 8;
      float16x8_t vacc01234567p1 = vmulq_f16(vi1x01234567, vk1x01234567);
      float16x8_t vacc89ABCDEFp1 = vmulq_f16(vi1x89ABCDEF, vk1x89ABCDEF);
      float16x8_t vaccGHIJKLMNp1 = vmulq_f16(vi1xGHIJKLMN, vk1xGHIJKLMN);
      float16x8_t vaccOPQRSTUVp1 = vmulq_f16(vi1xOPQRSTUV, vk1xOPQRSTUV);

      const float16x8_t vi2x01234567 = vld1q_f16(i2); i2 += 8;
      const float16x8_t vi2x89ABCDEF = vld1q_f16(i2); i2 += 8;
      const float16x8_t vi2xGHIJKLMN = vld1q_f16(i2); i2 += 8;
      const float16x8_t vi2xOPQRSTUV = vld1q_f16(i2); i2 += 8;
      const float16x8_t vk2x01234567 = vld1q_f16(w); w += 8;
      const float16x8_t vk2x89ABCDEF = vld1q_f16(w); w += 8;
      const float16x8_t vk2xGHIJKLMN = vld1q_f16(w); w += 8;
      const float16x8_t vk2xOPQRSTUV = vld1q_f16(w); w += 8;
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi2x01234567, vk2x01234567);
      vacc89ABCDEFp0 = vfmaq_f16(vacc89ABCDEFp0, vi2x89ABCDEF, vk2x89ABCDEF);
      vaccGHIJKLMNp0 = vfmaq_f16(vaccGHIJKLMNp0, vi2xGHIJKLMN, vk2xGHIJKLMN);
      vaccOPQRSTUVp0 = vfmaq_f16(vaccOPQRSTUVp0, vi2xOPQRSTUV, vk2xOPQRSTUV);

      const float16x8_t vi3x01234567 = vld1q_f16(i3); i3 += 8;
      const float16x8_t vi3x89ABCDEF = vld1q_f16(i3); i3 += 8;
      const float16x8_t vi3xGHIJKLMN = vld1q_f16(i3); i3 += 8;
      const float16x8_t vi3xOPQRSTUV = vld1q_f16(i3); i3 += 8;
      const float16x8_t vk3x01234567 = vld1q_f16(w); w += 8;
      const float16x8_t vk3x89ABCDEF = vld1q_f16(w); w += 8;
      const float16x8_t vk3xGHIJKLMN = vld1q_f16(w); w += 8;
      const float16x8_t vk3xOPQRSTUV = vld1q_f16(w); w += 8;
      vacc01234567p1 = vfmaq_f16(vacc01234567p1, vi3x01234567, vk3x01234567);
      vacc89ABCDEFp1 = vfmaq_f16(vacc89ABCDEFp1, vi3x89ABCDEF, vk3x89ABCDEF);
      vaccGHIJKLMNp1 = vfmaq_f16(vaccGHIJKLMNp1, vi3xGHIJKLMN, vk3xGHIJKLMN);
      vaccOPQRSTUVp1 = vfmaq_f16(vaccOPQRSTUVp1, vi3xOPQRSTUV, vk3xOPQRSTUV);

      const float16x8_t vi4x01234567 = vld1q_f16(i4); i4 += 8;
      const float16x8_t vi4x89ABCDEF = vld1q_f16(i4); i4 += 8;
      const float16x8_t vi4xGHIJKLMN = vld1q_f16(i4); i4 += 8;
      const float16x8_t vi4xOPQRSTUV = vld1q_f16(i4); i4 += 8;
      const float16x8_t vk4x01234567 = vld1q_f16(w); w += 8;
      const float16x8_t vk4x89ABCDEF = vld1q_f16(w); w += 8;
      const float16x8_t vk4xGHIJKLMN = vld1q_f16(w); w += 8;
      const float16x8_t vk4xOPQRSTUV = vld1q_f16(w); w += 8;
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi4x01234567, vk4x01234567);
      vacc89ABCDEFp0 = vfmaq_f16(vacc89ABCDEFp0, vi4x89ABCDEF, vk4x89ABCDEF);
      vaccGHIJKLMNp0 = vfmaq_f16(vaccGHIJKLMNp0, vi4xGHIJKLMN, vk4xGHIJKLMN);
      vaccOPQRSTUVp0 = vfmaq_f16(vaccOPQRSTUVp0, vi4xOPQRSTUV, vk4xOPQRSTUV);

      const float16x8_t vi5x01234567 = vld1q_f16(i5); i5 += 8;
      const float16x8_t vi5x89ABCDEF = vld1q_f16(i5); i5 += 8;
      const float16x8_t vi5xGHIJKLMN = vld1q_f16(i5); i5 += 8;
      const float16x8_t vi5xOPQRSTUV = vld1q_f16(i5); i5 += 8;
      const float16x8_t vk5x01234567 = vld1q_f16(w); w += 8;
      const float16x8_t vk5x89ABCDEF = vld1q_f16(w); w += 8;
      const float16x8_t vk5xGHIJKLMN = vld1q_f16(w); w += 8;
      const float16x8_t vk5xOPQRSTUV = vld1q_f16(w); w += 8;
      vacc01234567p1 = vfmaq_f16(vacc01234567p1, vi5x01234567, vk5x01234567);
      vacc89ABCDEFp1 = vfmaq_f16(vacc89ABCDEFp1, vi5x89ABCDEF, vk5x89ABCDEF);
      vaccGHIJKLMNp1 = vfmaq_f16(vaccGHIJKLMNp1, vi5xGHIJKLMN, vk5xGHIJKLMN);
      vaccOPQRSTUVp1 = vfmaq_f16(vaccOPQRSTUVp1, vi5xOPQRSTUV, vk5xOPQRSTUV);

      const float16x8_t vi6x01234567 = vld1q_f16(i6); i6 += 8;
      const float16x8_t vi6x89ABCDEF = vld1q_f16(i6); i6 += 8;
      const float16x8_t vi6xGHIJKLMN = vld1q_f16(i6); i6 += 8;
      const float16x8_t vi6xOPQRSTUV = vld1q_f16(i6); i6 += 8;
      const float16x8_t vk6x01234567 = vld1q_f16(w); w += 8;
      const float16x8_t vk6x89ABCDEF = vld1q_f16(w); w += 8;
      const float16x8_t vk6xGHIJKLMN = vld1q_f16(w); w += 8;
      const float16x8_t vk6xOPQRSTUV = vld1q_f16(w); w += 8;
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi6x01234567, vk6x01234567);
      vacc89ABCDEFp0 = vfmaq_f16(vacc89ABCDEFp0, vi6x89ABCDEF, vk6x89ABCDEF);
      vaccGHIJKLMNp0 = vfmaq_f16(vaccGHIJKLMNp0, vi6xGHIJKLMN, vk6xGHIJKLMN);
      vaccOPQRSTUVp0 = vfmaq_f16(vaccOPQRSTUVp0, vi6xOPQRSTUV, vk6xOPQRSTUV);

      const float16x8_t vi7x01234567 = vld1q_f16(i7); i7 += 8;
      const float16x8_t vi7x89ABCDEF = vld1q_f16(i7); i7 += 8;
      const float16x8_t vi7xGHIJKLMN = vld1q_f16(i7); i7 += 8;
      const float16x8_t vi7xOPQRSTUV = vld1q_f16(i7); i7 += 8;
      const float16x8_t vk7x01234567 = vld1q_f16(w); w += 8;
      const float16x8_t vk7x89ABCDEF = vld1q_f16(w); w += 8;
      const float16x8_t vk7xGHIJKLMN = vld1q_f16(w); w += 8;
      const float16x8_t vk7xOPQRSTUV = vld1q_f16(w); w += 8;
      vacc01234567p1 = vfmaq_f16(vacc01234567p1, vi7x01234567, vk7x01234567);
      vacc89ABCDEFp1 = vfmaq_f16(vacc89ABCDEFp1, vi7x89ABCDEF, vk7x89ABCDEF);
      vaccGHIJKLMNp1 = vfmaq_f16(vaccGHIJKLMNp1, vi7xGHIJKLMN, vk7xGHIJKLMN);
      vaccOPQRSTUVp1 = vfmaq_f16(vaccOPQRSTUVp1, vi7xOPQRSTUV, vk7xOPQRSTUV);

      const float16x8_t vi8x01234567 = vld1q_f16(i8); i8 += 8;
      const float16x8_t vi8x89ABCDEF = vld1q_f16(i8); i8 += 8;
      const float16x8_t vi8xGHIJKLMN = vld1q_f16(i8); i8 += 8;
      const float16x8_t vi8xOPQRSTUV = vld1q_f16(i8); i8 += 8;
      const float16x8_t vk8x01234567 = vld1q_f16(w); w += 8;
      const float16x8_t vk8x89ABCDEF = vld1q_f16(w); w += 8;
      const float16x8_t vk8xGHIJKLMN = vld1q_f16(w); w += 8;
      const float16x8_t vk8xOPQRSTUV = vld1q_f16(w); w += 8;
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi8x01234567, vk8x01234567);
      vacc89ABCDEFp0 = vfmaq_f16(vacc89ABCDEFp0, vi8x89ABCDEF, vk8x89ABCDEF);
      vaccGHIJKLMNp0 = vfmaq_f16(vaccGHIJKLMNp0, vi8xGHIJKLMN, vk8xGHIJKLMN);
      vaccOPQRSTUVp0 = vfmaq_f16(vaccOPQRSTUVp0, vi8xOPQRSTUV, vk8xOPQRSTUV);

      // Add up all accumulators to vacc0123456789ABCDEFGHIJKLMNOPQRSTUVp0
      vacc01234567p0 = vaddq_f16(vacc01234567p0, vacc01234567p1);
      vacc89ABCDEFp0 = vaddq_f16(vacc89ABCDEFp0, vacc89ABCDEFp1);
      vaccGHIJKLMNp0 = vaddq_f16(vaccGHIJKLMNp0, vaccGHIJKLMNp1);
      vaccOPQRSTUVp0 = vaddq_f16(vaccOPQRSTUVp0, vaccOPQRSTUVp1);

      float16x8_t vacc01234567 = vmaxq_f16(vacc01234567p0, vmin);
      float16x8_t vacc89ABCDEF = vmaxq_f16(vacc89ABCDEFp0, vmin);
      float16x8_t vaccGHIJKLMN = vmaxq_f16(vaccGHIJKLMNp0, vmin);
      float16x8_t vaccOPQRSTUV = vmaxq_f16(vaccOPQRSTUVp0, vmin);
      vacc01234567 = vminq_f16(vacc01234567, vmax);
      vacc89ABCDEF = vminq_f16(vacc89ABCDEF, vmax);
      vaccGHIJKLMN = vminq_f16(vaccGHIJKLMN, vmax);
      vaccOPQRSTUV = vminq_f16(vaccOPQRSTUV, vmax);

      vst1q_f16(output, vacc01234567); output += 8;
      vst1q_f16(output, vacc89ABCDEF); output += 8;
      vst1q_f16(output, vaccGHIJKLMN); output += 8;
      vst1q_f16(output, vaccOPQRSTUV); output += 8;
    }
    for (; c >= 8; c -= 8) {
      float16x8_t vacc01234567p0 = vld1q_f16(w); w += 8;


      const float16x8_t vi0x01234567 = vld1q_f16(i0); i0 += 8;
      const float16x8_t vk0x01234567 = vld1q_f16(w + 24);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi0x01234567, vk0x01234567);

      const float16x8_t vi1x01234567 = vld1q_f16(i1); i1 += 8;
      const float16x8_t vk1x01234567 = vld1q_f16(w + 56);
      float16x8_t vacc01234567p1 = vmulq_f16(vi1x01234567, vk1x01234567);

      const float16x8_t vi2x01234567 = vld1q_f16(i2); i2 += 8;
      const float16x8_t vk2x01234567 = vld1q_f16(w + 88);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi2x01234567, vk2x01234567);

      const float16x8_t vi3x01234567 = vld1q_f16(i3); i3 += 8;
      const float16x8_t vk3x01234567 = vld1q_f16(w + 120);
      vacc01234567p1 = vfmaq_f16(vacc01234567p1, vi3x01234567, vk3x01234567);

      const float16x8_t vi4x01234567 = vld1q_f16(i4); i4 += 8;
      const float16x8_t vk4x01234567 = vld1q_f16(w + 152);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi4x01234567, vk4x01234567);

      const float16x8_t vi5x01234567 = vld1q_f16(i5); i5 += 8;
      const float16x8_t vk5x01234567 = vld1q_f16(w + 184);
      vacc01234567p1 = vfmaq_f16(vacc01234567p1, vi5x01234567, vk5x01234567);

      const float16x8_t vi6x01234567 = vld1q_f16(i6); i6 += 8;
      const float16x8_t vk6x01234567 = vld1q_f16(w + 216);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi6x01234567, vk6x01234567);

      const float16x8_t vi7x01234567 = vld1q_f16(i7); i7 += 8;
      const float16x8_t vk7x01234567 = vld1q_f16(w + 248);
      vacc01234567p1 = vfmaq_f16(vacc01234567p1, vi7x01234567, vk7x01234567);

      const float16x8_t vi8x01234567 = vld1q_f16(i8); i8 += 8;
      const float16x8_t vk8x01234567 = vld1q_f16(w + 280);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi8x01234567, vk8x01234567);

      // Add up all accumulators to vacc01234567p0
      vacc01234567p0 = vaddq_f16(vacc01234567p0, vacc01234567p1);

      float16x8_t vacc01234567 = vmaxq_f16(vacc01234567p0, vmin);
      vacc01234567 = vminq_f16(vacc01234567, vmax);

      vst1q_f16(output, vacc01234567); output += 8;
    }
    if XNN_UNLIKELY(c != 0) {
      float16x8_t vacc01234567p0 = vld1q_f16(w);


      const float16x8_t vi0x01234567 = vld1q_f16(i0);
      const float16x8_t vk0x01234567 = vld1q_f16(w + 32);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi0x01234567, vk0x01234567);

      const float16x8_t vi1x01234567 = vld1q_f16(i1);
      const float16x8_t vk1x01234567 = vld1q_f16(w + 64);
      float16x8_t vacc01234567p1 = vmulq_f16(vi1x01234567, vk1x01234567);

      const float16x8_t vi2x01234567 = vld1q_f16(i2);
      const float16x8_t vk2x01234567 = vld1q_f16(w + 96);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi2x01234567, vk2x01234567);

      const float16x8_t vi3x01234567 = vld1q_f16(i3);
      const float16x8_t vk3x01234567 = vld1q_f16(w + 128);
      vacc01234567p1 = vfmaq_f16(vacc01234567p1, vi3x01234567, vk3x01234567);

      const float16x8_t vi4x01234567 = vld1q_f16(i4);
      const float16x8_t vk4x01234567 = vld1q_f16(w + 160);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi4x01234567, vk4x01234567);

      const float16x8_t vi5x01234567 = vld1q_f16(i5);
      const float16x8_t vk5x01234567 = vld1q_f16(w + 192);
      vacc01234567p1 = vfmaq_f16(vacc01234567p1, vi5x01234567, vk5x01234567);

      const float16x8_t vi6x01234567 = vld1q_f16(i6);
      const float16x8_t vk6x01234567 = vld1q_f16(w + 224);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi6x01234567, vk6x01234567);

      const float16x8_t vi7x01234567 = vld1q_f16(i7);
      const float16x8_t vk7x01234567 = vld1q_f16(w + 256);
      vacc01234567p1 = vfmaq_f16(vacc01234567p1, vi7x01234567, vk7x01234567);

      const float16x8_t vi8x01234567 = vld1q_f16(i8);
      const float16x8_t vk8x01234567 = vld1q_f16(w + 288);
      vacc01234567p0 = vfmaq_f16(vacc01234567p0, vi8x01234567, vk8x01234567);

      // Add up all accumulators to vacc01234567p0
      vacc01234567p0 = vaddq_f16(vacc01234567p0, vacc01234567p1);

      float16x8_t vacc01234567 = vmaxq_f16(vacc01234567p0, vmin);
      vacc01234567 = vminq_f16(vacc01234567, vmax);

      float16x4_t vacc0123 = vget_low_f16(vacc01234567);
      if (c & 4) {
        vst1_f16(output, vacc0123); output += 4;
        vacc0123 = vget_high_f16(vacc01234567);
      }
      if (c & 2) {
        vst1_lane_u32((void*) output, vreinterpret_u32_f16(vacc0123), 0); output += 2;
        vacc0123 = vext_f16(vacc0123, vacc0123, 2);
      }
      if (c & 1) {
        vst1_lane_f16(output, vacc0123, 0); output += 1;
      }
    }

    output = (__fp16*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
