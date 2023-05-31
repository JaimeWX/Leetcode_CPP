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
    int integerBreak(int n) 
    {
        vector<int> dp(n+1);

        dp[2] = 1;

        for(int i=3; i<=n; i++)
        {
            for(int j=1; j<=i/2; j++)
            {
                dp[i] = max(dp[i], max((i-j)*j, dp[i-j]*j));
            }
        }
        // traversalDP(dp);
        return dp[n];
    }
};