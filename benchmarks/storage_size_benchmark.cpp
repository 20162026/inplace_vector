#include <array>
#include <beman/inplace_vector/inplace_vector.hpp>
#include <benchmark/benchmark.h>
#include <cstdint>
#include <vector>

using namespace beman::inplace_vector;

// Performance comparison across size types
template <typename T, size_t N>
static void BM_PushBack_BySize(benchmark::State &state) {
  inplace_vector<T, N> vec;

  for (auto _ : state) {
    vec.clear();
    for (int i = 0; i < state.range(0); ++i) {
      vec.push_back(T{1});
    }
    benchmark::DoNotOptimize(vec);

    for (int i = 0; i < state.range(0); ++i) {
      vec.pop_back();
    }
    benchmark::DoNotOptimize(vec);
  }
  state.counters["N"] = N;
  state.counters["storage_ssize"] = sizeof(details::smallest_size_t<N>);
  state.counters["typesize"] = sizeof(T);
  state.counters["sizeof"] = sizeof(vec);
}

BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint8_t, 128)
    ->Name("PushBack_uint8_t_128")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint8_t, 512)
    ->Name("PushBack_uint8_t_512")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint8_t, 65536)
    ->Name("PushBack_uint8_t_65536")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint16_t, 128)
    ->Name("PushBack_uint16_t_128")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint16_t, 512)
    ->Name("PushBack_uint16_t_512")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint16_t, 65536)
    ->Name("PushBack_uint16_t_65536")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint32_t, 128)
    ->Name("PushBack_uint32_t_128")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint32_t, 512)
    ->Name("PushBack_uint32_t_512")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint32_t, 65536)
    ->Name("PushBack_uint32_t_65536")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, int, 128)
    ->Name("PushBack_int_128")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, int, 512)
    ->Name("PushBack_int_512")
    ->Arg(10);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, int, 65536)
    ->Name("PushBack_int_65536")
    ->Arg(10);

BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint8_t, 128)
    ->Name("PushBack_uint8_t_128")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint8_t, 512)
    ->Name("PushBack_uint8_t_512")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint8_t, 65536)
    ->Name("PushBack_uint8_t_65536")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint16_t, 128)
    ->Name("PushBack_uint16_t_128")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint16_t, 512)
    ->Name("PushBack_uint16_t_512")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint16_t, 65536)
    ->Name("PushBack_uint16_t_65536")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint32_t, 128)
    ->Name("PushBack_uint32_t_128")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint32_t, 512)
    ->Name("PushBack_uint32_t_512")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint32_t, 65536)
    ->Name("PushBack_uint32_t_65536")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, int, 128)
    ->Name("PushBack_int_128")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, int, 512)
    ->Name("PushBack_int_512")
    ->Arg(64);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, int, 65536)
    ->Name("PushBack_int_65536")
    ->Arg(64);

BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint8_t, 128)
    ->Name("PushBack_uint8_t_128")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint8_t, 512)
    ->Name("PushBack_uint8_t_512")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint8_t, 65536)
    ->Name("PushBack_uint8_t_65536")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint16_t, 128)
    ->Name("PushBack_uint16_t_128")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint16_t, 512)
    ->Name("PushBack_uint16_t_512")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint16_t, 65536)
    ->Name("PushBack_uint16_t_65536")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint32_t, 128)
    ->Name("PushBack_uint32_t_128")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint32_t, 512)
    ->Name("PushBack_uint32_t_512")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, uint32_t, 65536)
    ->Name("PushBack_uint32_t_65536")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, int, 128)
    ->Name("PushBack_int_128")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, int, 512)
    ->Name("PushBack_int_512")
    ->Arg(100);
BENCHMARK_TEMPLATE(BM_PushBack_BySize, int, 65536)
    ->Name("PushBack_int_65536")
    ->Arg(100);

BENCHMARK_MAIN();
