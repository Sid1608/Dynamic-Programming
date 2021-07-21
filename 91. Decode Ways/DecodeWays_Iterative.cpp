//Author:Siddharth Akar
//Problem Link:https://leetcode.com/problems/decode-ways/
//Given a string s containing only digits, return the number of ways to decode it.A message containing letters from A-Z can be encoded into numbers.



class Solution {
public:
    int numDecodings(string s) {
        int n=s.size(),res=0;
        vector<int>dp(n+2,0);
        dp[n]=1;
        dp[n+1]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]!='0'){
                dp[i]+=dp[i+1];
                if(i!=n-1){
                    string r=s.substr(i,2);
                    int currNum2=stoi(r);
                    if(currNum2<=26)
                        dp[i]+=dp[i+2];
                }
            }
            
        }
        return dp[0];
    }
};
