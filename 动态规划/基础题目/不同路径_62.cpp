#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void traversalDP(vector<vector<int>> dp)
    {
        for(int i=0; i<dp.size(); i++)
        {
            for(int j=0; j<dp[0].size(); j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i=0; i<m; i++)
        {
            dp[i][0] = 1;
        }
        for(int i=0; i<n; i++)
        {
            dp[0][i] = 1;
        }
        // traversalDP(dp);

        for(int i=1; i<dp.size(); i++)
        {
            for(int j=1; j<dp[0].size(); j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        // traversalDP(dp);

        return dp[m-1][n-1];

    }
};