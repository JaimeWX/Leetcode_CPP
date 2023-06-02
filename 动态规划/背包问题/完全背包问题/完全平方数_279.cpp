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
    int numSquares(int n) 
    {
        // dp[i]: 凑满容量为i的背包，最少需要dp[i]个物品
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;

        for(int i=0; i<=n; i++) // 遍历背包容量
        {
            for(int j=1; j*j<=i; j++) // 遍历物品（完全平方数应该小于等于bagSize[i]）
            {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
            // traversalDP(dp);
        }

        return dp[n];
    }
};