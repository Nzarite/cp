/*
Number of people are aware of A secret
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day,
 starting from delay days after discovering the secret. 
You are also given an integer forget, which means that each person
 will forget the secret forget days after discovering it. 
A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.
*/
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        vector<long long>dp(n+1);
        dp[0] = 0;dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] += (dp[i-1]%mod + (dp[max(i-delay,0)] - dp[max(i-forget,0)])%mod + mod)%mod;
        }
        // for(int i = 0;i<=n;i++) cout<<dp[i]<<" ";
        return (dp[n] - dp[max(n - forget,0)] +mod)%mod;
    }
};