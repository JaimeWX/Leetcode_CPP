class Solution {
public:

    class mycomparison
    {
        public:
            bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs)
            {
                return lhs.second > rhs.second;
            }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {   
        vector<int> res;
        unordered_map<int,int> umap;
        for(int i=0; i<nums.size(); i++)
        {
            umap[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomparison> pri_que_greater;
        for(unordered_map<int,int>::iterator it = umap.begin(); it != umap.end(); it++)
        {
            pri_que_greater.push(*it);
            if(pri_que_greater.size() > k)
            {
                pri_que_greater.pop();
            }
        }
        // while(!pri_que_greater.empty())
        // {
        //     cout << pri_que_greater.top().first << "--" << pri_que_greater.top().second << endl;
        //     pri_que_greater.pop();
        // }
        
        while(k--)
        {
            res.push_back(pri_que_greater.top().first);
            pri_que_greater.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

};