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
    int coinChange(vector<int>& coins, int amount) 
    {
        //dp[j]: 装满容量为j的背包，所需的硬币个数最小为dp[j]个
        vector<int> dp(amount+1, INT_MAX);

        dp[0] = 0;

        for(int i=0; i<coins.size(); i++)
        {
            for(int j=coins[i]; j<=amount; j++)
            {
                if(dp[j-coins[i]] != INT_MAX)
                    dp[j] = min(dp[j], dp[j-coins[i]] + 1);
            }
            // traversalDP(dp);
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];

    }
};