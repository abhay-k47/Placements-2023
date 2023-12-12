#include <bits/stdc++.h>

/**
 * @brief Get all the primes till N
 *
 * @param N
 * @return std::vector<uint32_t>
 */
std::vector<uint32_t> getPrimes(uint32_t N)
{
  std::vector<bool> isPrime(N + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (uint32_t i = 2; i * i <= N; i++)
    if (isPrime[i])
      for (uint32_t j = i * i; j <= N; j += i)
        isPrime[j] = false;

  std::vector<uint32_t> res;
  for (uint32_t i = 0; i <= N; i++)
    if (isPrime[i])
      res.push_back(i);

  return res;
}

/**
 * @brief Get the factors of N
 *
 * @param N
 * @return std::vector<uint32_t>
 */
std::vector<uint32_t> getFactors(uint32_t N)
{
  std::vector<uint32_t> res;
  for (uint32_t i = 2; i * i <= N; i++)
  {
    if (N % i == 0)
    {
      res.push_back(i);
      if (i * i != N)
        res.push_back(N / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main(int argc, char const* argv[])
{
  auto&& res1 = getFactors(124);
  for (auto&& i : res1)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  auto&& res2 = getPrimes(1000);
  for (auto&& i : res2)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
