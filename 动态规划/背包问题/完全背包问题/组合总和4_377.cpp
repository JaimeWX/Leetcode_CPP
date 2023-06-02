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
    int combinationSum4(vector<int>& nums, int target) 
    {
        // dp[j]: 填满容量为j的背包，总共有dp[j]种方法
        vector<int> dp(target+1, 0);

        dp[0] = 1;

        for(int i=0; i<=target; i++)
        {
            for(int j=0; j<nums.size(); j++)
            {
                if(i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
                    dp[i] += dp[i-nums[j]];
            }
            // traversalDP(dp);
        }

        return dp[target];
    }
};