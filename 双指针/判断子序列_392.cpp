class Solution {
public:
    bool isSubsequence(string s, string t) 
    {   
        if(s.size() == 0)   return true;
        int sIndex = 0;
        int tIndex = 0; 
        for( ; tIndex<t.size(); tIndex++)
        {
            if(t[tIndex] == s[sIndex])
            {
                if(sIndex == s.size()-1)
                    return true;
                else
                    sIndex++;
            }
        }
        return false;
    }
};