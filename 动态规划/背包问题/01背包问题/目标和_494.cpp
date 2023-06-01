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
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = 0;
        for(int i : nums)
            sum += i;
        if((sum + target) % 2 == 1) return 0;
        int bagSize = (sum+target)/2;

        vector<int> dp(bagSize+1, 0);

        dp[0] = 1;

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=bagSize; j>=nums[i]; j--)
            {
                dp[j] += dp[j-nums[i]];
            }
            // traversalDP(dp);
        }
        return dp[bagSize];
    }
};