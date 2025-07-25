// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <algorithm>
#include <cmath>
#include <functional>
#include <limits>
#include <random>
#include <vector>

#include "bench/utils.h"
#include "include/xnnpack.h"
#include "src/xnnpack/buffer.h"
#include "src/xnnpack/common.h"
#include "src/xnnpack/hardware-config.h"
#include "src/xnnpack/microfnptr.h"
#include "src/xnnpack/raddexpminusmax.h"
#include "src/xnnpack/reduce.h"
#include <benchmark/benchmark.h>

static void f32_raddexpminusmax(
    benchmark::State& state, xnn_f32_rmax_ukernel_fn rmax,
    xnn_f32_raddexpminusmax_ukernel_fn raddexpminusmax,
    uint64_t arch_flags = 0) {
  if (!benchmark::utils::CheckArchFlags(state, arch_flags)) {
    return;
  }

  const size_t elements = state.range(0);
  const size_t cache_line_size_max = 128;
  const size_t packed_elements =
      benchmark::utils::RoundUp(elements, cache_line_size_max / sizeof(float));

  std::random_device random_device;
  auto rng = std::mt19937(random_device());
  auto f32rng = std::bind(
      std::uniform_real_distribution<float>(-1000.0f, 1000.0f), std::ref(rng));

  const size_t num_buffers = 1 + benchmark::utils::DivideRoundUp<size_t>(
                                     benchmark::utils::GetMaxCacheSize(),
                                     packed_elements * sizeof(float));
  xnnpack::Buffer<float, XNN_ALLOCATION_ALIGNMENT> x(elements);

  std::generate(x.begin(), x.end(), std::ref(f32rng));

  benchmark::utils::DisableDenormals();

  size_t buffer_index = 0;
  for (auto _ : state) {
    state.PauseTiming();
    float x_max = -std::numeric_limits<float>::infinity();
    rmax(elements * sizeof(float), x.data(), &x_max, /*params=*/nullptr);
    if (++buffer_index == num_buffers) {
      buffer_index = 0;
    }
    state.ResumeTiming();

    float y_sum;
    raddexpminusmax(elements * sizeof(float), x.data(), &y_sum, x_max);
  }

  const uint64_t cpu_frequency = benchmark::utils::GetCurrentCpuFrequency();
  if (cpu_frequency != 0) {
    state.counters["cpufreq"] = cpu_frequency;
  }

  const size_t elements_per_iteration = elements;
  state.counters["elements"] =
      benchmark::Counter(uint64_t(state.iterations()) * elements_per_iteration,
                         benchmark::Counter::kIsRate);

  const size_t bytes_per_iteration = 2 * elements * sizeof(float);
  state.counters["bytes"] =
      benchmark::Counter(uint64_t(state.iterations()) * bytes_per_iteration,
                         benchmark::Counter::kIsRate);
}

#if XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u64,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u64,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u64_acc2,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u64_acc2,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u64_acc4,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u64_acc4,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u128,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u128,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u128_acc2,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u128_acc2,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u128_acc4,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u128_acc4,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u144,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u144,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u144_acc3,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u144_acc3,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u160,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u160,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u160_acc2,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u160_acc2,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u160_acc5,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u160_acc5,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u192,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u192,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u192_acc2,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u192_acc2,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u192_acc3,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u192_acc3,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx512f_p5_scalef_u192_acc6,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx512f_p5_scalef_u192_acc6,
                  xnn_arch_x86_avx512f)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
#endif  // XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u32,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u32,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u32_acc2,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u32_acc2,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u32_acc4,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u32_acc4,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u64,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u64,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u64_acc2,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u64_acc2,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u64_acc4,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u64_acc4,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u72,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u72,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u72_acc3,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u72_acc3,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u80,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u80,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u80_acc2,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u80_acc2,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u80_acc5,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u80_acc5,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u96,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u96,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u96_acc2,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u96_acc2,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u96_acc3,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u96_acc3,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
BENCHMARK_CAPTURE(f32_raddexpminusmax, avx2_p5_u96_acc6,
                  xnn_f32_rmax_ukernel__avx_u32_acc4,
                  xnn_f32_raddexpminusmax_ukernel__avx2_p5_u96_acc6,
                  xnn_arch_x86_avx2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#ifndef XNNPACK_BENCHMARK_NO_MAIN
XNN_BENCHMARK_MAIN();
#endif
