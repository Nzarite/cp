#include <iostream>
#include <vector>

const int N_LIMIT = 10000000;

long long logNExponentiation(long long n, long long exp, long long mod)
{
	long long val[64] = {n};
	for(int i = 1; i < 64; ++i)
	{
		val[i] = val[i-1] * val[i-1] % mod;
	}

	long long result = 1LL;
	for(int i = 0; i < 64; ++i)
	{
		if((exp >> i) & 1LL)
		{
			result = result * val[i] % mod;
		}
	}

	return result;
}

int main()
{
	long long n, exp, mod;
	std::cin >> n >> exp >> mod;

	long long result = logNExponentiation(n, exp, mod);

	std::cout << "Printing (n ^ exp) % mod : " << result << std::endl;
 
    return 0;
}
