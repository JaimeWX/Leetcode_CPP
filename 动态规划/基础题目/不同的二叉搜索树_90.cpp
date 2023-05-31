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
    int numTrees(int n) 
    {
        vector<int> dp(n+1);

        dp[0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                // if(i == 4)
                // {
                //     cout << i-j << " " << j-1 << endl;
                // }
                dp[i] += dp[i-j] * dp[j-1];
            }
            // traversalDP(dp);
        }

        return dp[n];

    }
};