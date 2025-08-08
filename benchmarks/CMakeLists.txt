# Benchmark executable
add_executable(inplace_vector_benchmarks storage_size_benchmark.cpp)

target_link_libraries(
    inplace_vector_benchmarks
    PRIVATE beman::inplace_vector benchmark::benchmark benchmark::benchmark_main
)

target_compile_features(inplace_vector_benchmarks PRIVATE cxx_std_20)

target_compile_options(inplace_vector_benchmarks PRIVATE -O2)
