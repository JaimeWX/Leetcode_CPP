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
    int change(int amount, vector<int>& coins) 
    {
        // dp[j]: 填满容量为j的背包，总共有dp[j]种方法
        vector<int> dp(amount+1);

        dp[0] = 1;

        for(int i=0; i<coins.size(); i++)
        {
            for(int j=coins[i]; j<=amount; j++)
            {
                dp[j] += dp[j-coins[i]];
            }
            // traversalDP(dp);
        }
        
        return dp[amount];
    }
};