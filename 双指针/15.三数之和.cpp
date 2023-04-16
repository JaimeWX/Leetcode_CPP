/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        //对nums进行排序
        sort(nums.begin(),nums.end());
        /*
        a + b + c = 0
        a is nums[i]
        b is left
        c is right
        */
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0) return result; // left, right一定比nums[i]大

            // 对a进行去重
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int left = i+1;
            int right = nums.size()-1;

            while(right>left)
            {
                if(nums[i] + nums[left] + nums[right] > 0)  right--;
                else if(nums[i] + nums[left] + nums[right] < 0) left++;
                else
                {
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(right > left && nums[right] == nums[right-1]) 
                        right--;
                    while(right > left && nums[left] == nums[left+1]) 
                        left++;

                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};
// @lc code=end

