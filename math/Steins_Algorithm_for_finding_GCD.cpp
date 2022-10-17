/*
Stein’s algorithm or binary GCD algorithm is an algorithm that computes the greatest common divisor 
of two non-negative integers. Stein’s algorithm replaces division with arithmetic shifts,
comparisons, and subtraction.
*/

/*
Algorithm to find GCD using Stein’s algorithm gcd(a, b)

1. If both a and b are 0, gcd is zero gcd(0, 0) = 0.
2. gcd(a, 0) = a and gcd(0, b) = b because everything divides 0.
2. If a and b are both even, gcd(a, b) = 2*gcd(a/2, b/2) because 2 is a common divisor. Multiplication with 2 can be done with bitwise shift operator.
3. If a is even and b is odd, gcd(a, b) = gcd(a/2, b). Similarly, if a is odd and b is even, then 
4. gcd(a, b) = gcd(a, b/2). It is because 2 is not a common divisor.
5. If both a and b are odd, then gcd(a, b) = gcd(|a-b|/2, b). Note that difference of two odd numbers is even
6. Repeat steps 3–5 until a = b, or until a = 0. In either case, the GCD is power(2, k) * b, where power(2, k) is 2 raise to the power of k and k is the number of common factors of 2 found in step 3.
*/

// Iterative C++ program to
// implement Stein's Algorithm
#include <bits/stdc++.h>
using namespace std;
 

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k)
    {
        a >>= 1;
        b >>= 1;
    }
 
    while ((a & 1) == 0)
        a >>= 1;
    do
    {
        while ((b & 1) == 0)
            b >>= 1;
 
        if (a > b)
            swap(a, b); // Swap u and v.
 
        b = (b - a);
    }while (b != 0);
 
    /* restore common factors of 2 */
    return a << k;
}
 
int main()
{
    int a = 34, b = 17;
    printf("Gcd of given numbers is %d\n", gcd(a, b));
    return 0;
}
