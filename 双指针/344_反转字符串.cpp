/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int head = 0;
        int tail = s.size()-1;
        while(head < tail)
        {
            char tmp = s[head];
            s[head] = s[tail];
            s[tail] = tmp;
            head++;
            tail--;
        }
    }
};
// @lc code=end

