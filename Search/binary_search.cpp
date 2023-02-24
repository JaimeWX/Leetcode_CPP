#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {   
        int len_nums = nums.size();
        if (len_nums == 1 && nums[0] == target)
        {
            return 0;
        }

        int low,high,mid;
        low = 0;
        high = len_nums - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (target < nums[mid])
            {
                high = mid - 1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};