#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    void traversalDP(vector<int> dp)
    {
        for(int i=0; i<dp.size(); i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
public:
    int bag01_problem_one_array()
    {
        vector<int> dp(bagWeight+1, 0);

        for(int i=0; i<weight.size(); i++)
        {
            for(int j=bagWeight; j>=weight[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
                // cout << j << " " << dp[j] << endl;
            }
            traversalDP(dp);
        }

        return dp[bagWeight];
    }
};

int main()
{
    Solution so;
    int ans = so.bag01_problem_one_array();
    cout << ans << endl;
}