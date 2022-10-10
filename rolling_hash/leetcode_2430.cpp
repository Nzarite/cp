/*
You are given a string s consisting of only lowercase English letters.
 In one operation, you can:

Delete the entire string s, or
Delete the first i letters of s if the first i letters of s are equal to the following i letters in s,
for any i in the range 1 <= i <= s.length / 2.
For example, if s = "ababc", then in one operation,
you could delete the first two letters of s to get "abc",
since the first two letters of s and the following two letters of s are both equal to "ab".

Return the maximum number of operations needed to delete all of s.
*/



class Solution {
    int dp[4040];
    long long mod = 1e9 + 7;
    long long rolling = 31;
public:
    int deleteString(string s) {
        memset(dp,-1,sizeof dp);
        dp[0] = 0;
        vector<long long> hash(s.length());
        for(long long i = 0, h = 1; i < s.length(); i++, h = h * rolling % mod) hash[i] = (s[i] - 'a' + 1) * h % mod;

        for(int i = 0; i < s.length(); i++) {
            if(dp[i] == -1) continue;
            dp[s.length()] = max(dp[s.length()], dp[i] + 1);
            long long front = 0, back = 0;
            for(long long j = i + 1, k = i, po = rolling; j < s.length(); j += 2, k += 1, po = po * rolling % mod) {
                front = (front + hash[k]) % mod;
                back = (back + hash[j] + hash[j - 1]) % mod;
                if((front + front * po % mod) % mod == back) dp[k + 1] = max(dp[k + 1], dp[i] + 1);
            }
        }
        return dp[s.length()];
    }
};