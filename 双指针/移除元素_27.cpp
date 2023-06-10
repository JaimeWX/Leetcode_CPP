#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int slowIndex = 0;
        for(int fastIndex=0; fastIndex<nums.size(); fastIndex++)
        {
            if(nums[fastIndex] != val)
            {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 2;
    Solution so;
    int res = so.removeElement(nums,val);
    cout << res << endl;
    return 0;
}