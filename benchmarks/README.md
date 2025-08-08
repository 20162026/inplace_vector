# run gooogle test

```bash
# Configure with benchmarks enabled
cmake -S . -B build -DCMAKE_CXX_STANDARD=20 -DBEMAN_INPLACE_VECTOR_BUILD_BENCHMARKS=ON -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build build --target inplace_vector_benchmarks

# Run benchmarks
./build/benchmarks/inplace_vector_benchmarks
```
