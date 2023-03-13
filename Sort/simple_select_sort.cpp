class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {   
        vector<int> results;
        int length = nums.size();
        simpleSelectSort(nums,length);
        int i;
        for (i=0; i<length; i++)
        {
            if (nums[i] == target)
            {
                results.push_back(i);
            }
        }
        return results;
    }
    void simpleSelectSort(vector<int>& nums, int length)
    {
        int i,j,min;
        
        for (i=0; i<length; i++)
        {
            min = i;
            for (j=i+1; j<length; j++)
            {
                if (nums[min] > nums[j])
                {
                    min = j;
                }
            }
            if (i != min)
            {
                int tmp = nums[i];
                nums[i] = nums[min];
                nums[min] = tmp;
            }
        }
    }
};