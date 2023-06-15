#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> res;
        unordered_set<int> set_nums1(nums1.begin(), nums1.end());
        for(int num : nums2)
        {
            if(set_nums1.find(num) != set_nums1.end())
                res.insert(num);
        }
        return vector<int>(res.begin(), res.end());
    }
};