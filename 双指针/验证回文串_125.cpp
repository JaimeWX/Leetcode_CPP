class Solution {
public:
    bool isPalindrome(string s) 
    {   
        string s_tmp;
        for(char i : s)
        {
            if(isalnum(i))
                s_tmp += tolower(i);
        }

        int s_tmp_size = s_tmp.size();
        for(int i=0, j=s_tmp_size-1; i<j; i++, j--)
        {
            if(s_tmp[i] != s_tmp[j])
                return false;
        }
        return true;
    }
};