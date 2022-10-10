//Longest Binary Subsequence Less Than or Equal to K
/*
You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that 
makes up a binary number less than or equal to k.

Note:

The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by 
deleting some or no characters without changing the order of the remaining characters.
*/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long n = s.size(),sum = 0;
        int len = 0;
        for(int i = n-1;i>=0;i--){
            if(s[i] == '0') len++;
            else if(sum + pow(2,n-1-i) <= k){
                len++;
                sum += pow(2,min(31LL,n-1-i));
            }
        }
        return len;
    }
};