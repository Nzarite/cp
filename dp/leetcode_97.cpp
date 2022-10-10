//Interleaving string
/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m non-empty substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(),m = s2.size();
        if(n+m != s3.size()) return false;
        vector<vector<int>> v(n+1,vector<int>(m+1));
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i == 0 && j == 0){
                    v[i][j] = 1;
                }
                else if (i == 0) {
                    v[i][j] = v[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    v[i][j] = v[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                }
                else{
                    v[i][j] = s3[i+j - 1] == s1[i-1]&&
                        v[i-1][j] || s3[i+j - 1] == s2[j-1] && v[i][j-1];
                    }  
                }
            }
        return v[n][m];
    }
};