class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char, int> map;
        for (char i = 'a'; i <= 'z'; i++)
        {
            map.insert(pair<char, int>(i,0));
        }

        for(int i=0; i<s.size(); i++)
        {
            auto iter = map.find(s[i]);
            if(iter != map.end())
                iter->second++;
        }
        for(int i=0; i<t.size(); i++)
        {
            auto iter = map.find(t[i]);
            if(iter != map.end())
                iter->second--;
        }

        bool res = true;
        for(auto&[k,v]:map)
        {
            if(v != 0)
            {
                res = false;
                break;
            }
        }
        return res;
    }
};