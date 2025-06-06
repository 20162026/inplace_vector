#include <array>
#include <cassert>
#include <iostream>

#include <beman/inplace_vector/inplace_vector.hpp>

using namespace beman;

/**
 * Generates fibonacci sequence using inplace_vector.
 * See: https://en.wikipedia.org/wiki/Fibonacci_sequence
 */
template <int Capacity>
constexpr inplace_vector<int, Capacity> fibonacci_to(int num) {
  assert(num < Capacity);

  inplace_vector<int, Capacity> vec;

  constexpr std::array<int, 2> first_two{0, 1};
  for (auto i = 0; i <= num; ++i) {
    auto new_val = i < 2 ? first_two[i] : vec[i - 1] + vec[i - 2];
    vec.push_back(new_val);
  }

  return vec;
}

/*
 * Check the result of the computation at compile time.
 */
constexpr bool check_5() {
  auto got = fibonacci_to<10>(5);
  constexpr inplace_vector<int, 10> correct{0, 1, 1, 2, 3, 5};
  return got == correct;
}

static_assert(check_5());

/**
 * Expected program output:
 *
 * 0: 0
 * 1: 1
 * 2: 1
 * 3: 2
 * 4: 3
 * 5: 5
 * 6: 8
 * 7: 13
 * 8: 21
 * 9: 34
 * 10: 55
 *
 */
int main() {
  auto fib_seq = fibonacci_to<50>(10);
  for (auto i = 0U; i < fib_seq.size(); ++i) {
    std::cout << i << ": " << fib_seq[i] << "\n";
  }
  std::cout << std::endl;
}
