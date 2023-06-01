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
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for(int i : nums)
            sum += i;
        if(sum % 2 == 1)    return false;

        int target = sum / 2;
        vector<int> dp(target+1, 0);

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=target; j>=nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
            }
            // traversalDP(dp);
        }

        if(target == dp[target])    return true;
        return false;

    }
};