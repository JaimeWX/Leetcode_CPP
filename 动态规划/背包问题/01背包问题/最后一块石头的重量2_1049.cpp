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
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = 0;
        for(int i : stones)
        {
            sum += i;
        }
        int target = sum / 2;

        vector<int> dp(target+1, 0);

        for(int i=0; i<stones.size(); i++)
        {
            for(int j=target; j>=stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
        }
        // traversalDP(dp);
        int ans = sum - 2 * dp[target];
        return ans;
    }
};