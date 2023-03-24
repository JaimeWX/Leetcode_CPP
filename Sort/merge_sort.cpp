class Solution {
public:

    void print_nums(vector<int> nums)
    {
        int i;
        for(i=0;i<=nums.size()-1;i++)
        {
            printf("%d ",nums[i]);
            printf("\n");
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {   
        int y=0;
        for(int x=0;x<nums1.size();x++)
        {   
            if(x>(m-1))
            {   
                nums1[x] = nums2[y++];
            }
        }

        int left = 0;
        int right = nums1.size()-1;
        MergeSort(nums1,left,right);
    }

    void MergeSort(vector<int> &nums,int left,int right)
    {
        if(left>=right)
            return;
        int mid=(left+right)/2;
        MergeSort(nums,left,mid);
        MergeSort(nums,mid+1,right);
        Merge(nums,left,mid,right);
        
    }

    void Merge(vector<int>& nums, int left, int mid, int right) 
    {
        vector<int> tmp(nums.begin()+left,nums.begin()+right+1);   
    
        int leftStart=left-left,leftEnd=mid-left;
        int rightStart=mid+1-left,rightEnd=right-left;

        int i=leftStart, j=rightStart;                
        for (int k=left; k<=right;k++)
        {
            if (i > leftEnd)
                nums[k] = tmp[j++];
            else if (j > rightEnd || tmp[i] <= tmp[j])
                nums[k] = tmp[i++];
            else
                nums[k] = tmp[j++];
        }
    }


};