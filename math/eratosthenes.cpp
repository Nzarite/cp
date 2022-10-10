#include <iostream>
#include <vector>

const int N_LIMIT = 10000000;

void sieveOfEratosthenes(int n, std::vector<int>& primes)
{
	std::vector<bool> isPrime(n + 1, true);
	for(int i = 2; i <= n; ++i)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
			for(int j = i + i; j <= n; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	int n;
	std::cin >> n;

	if(n > N_LIMIT)
	{
		std::cout << "WARNING: n is too large - sieve algorithm may work visibly slower." << std::endl;
	}

	std::vector<int> primes;
	sieveOfEratosthenes(n, primes);

	// Print primes
	std::cout << "Printing the prime numbers found:" << std::endl;
	int numPrimes = primes.size();
	for(int i=0; i < numPrimes; ++i)
	{
		std::cout << primes[i] << std::endl;
	}
 
    return 0;
}
