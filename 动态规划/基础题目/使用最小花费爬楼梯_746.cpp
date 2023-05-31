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
    int minCostClimbingStairs(vector<int>& cost) 
    {
        if(cost.size() == 0)    return 0;
        if(cost.size() == 1)    return cost[0];
            
        vector<int> dp(cost.size()+1);

        dp[0] = 0;
        dp[1] = 0;

        for(int i=2; i<dp.size(); i++)
        {
            dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
            // traversalDP(dp);
        }

        return dp[dp.size()-1];


    }
 };