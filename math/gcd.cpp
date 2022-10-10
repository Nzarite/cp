#include <iostream>

long long greatestCommonDivisor(long long a, long long b)
{
	return (b > 0 ? greatestCommonDivisor(b, a%b) : a);
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	long long gcd = greatestCommonDivisor(a, b);
	std::cout << "Greatest Common Divisor of " << a << " & " << b << " is: " << gcd << std::endl;
 
    return 0;
}
