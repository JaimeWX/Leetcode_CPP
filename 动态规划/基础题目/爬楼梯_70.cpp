#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void traversalDP(vector<int> dp)
    {
        for(int i=0; i<dp.size(); i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
public:
    int climbStairs(int n) 
    {
        if(n <= 1)  return n;

        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i<dp.size(); i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
            // traversalDP(dp);
        }

        return dp[n];
    }
};