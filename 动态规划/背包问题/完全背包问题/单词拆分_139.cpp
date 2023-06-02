#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void traversalDP(vector<bool> dp)
    {
        for(int i=0; i<dp.size(); i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {   
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        // 完全背包 + 排列 + 能否装满背包
        //dp[i]: 字符串长度为i的话，dp[i]为true则表示：可以拆分为一个或多个在字典中出现的单词
        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) 
        {   
            for (int j = 0; j < i; j++) 
            {       
                string word = s.substr(j, i - j); // 截取物品 
                
                // 判断所截去的物品是否在字典里
                if (wordSet.find(word) != wordSet.end() && dp[j] == true) 
                {
                    dp[i] = true;
                    // cout << word << endl;
                    // traversalDP(dp);
                }
            }
        }
        return dp[s.size()];
    }   
};