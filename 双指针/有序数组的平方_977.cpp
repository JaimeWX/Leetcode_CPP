#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> res(nums.size());
        int resIndex = res.size()-1;
        for(int i=0,j=nums.size()-1; i<=j;)
        {
            if(nums[i]*nums[i] > nums[j]*nums[j])
            {
                res[resIndex--] = nums[i]*nums[i];
                i++;
            }
            else
            {
                res[resIndex--] = nums[j]*nums[j];
                j--;
            }
        }
        return res;
    }
};