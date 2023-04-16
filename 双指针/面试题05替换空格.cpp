class Solution {
public:
    string replaceSpace(string s) 
    {
        int len_s = s.size();
        int num_space = 0;
        for(int i=0; i<len_s; i++)
        {
            if(s[i] == ' ')
                num_space++;
        }
        int new_len_s = len_s + 2 * num_space;
        s.resize(new_len_s);
        for(int i=len_s-1, j=new_len_s-1; i<j; i--,j--)
        {
            if(s[i] != ' ')
                s[j] = s[i];
            else
            {
                s[j-2] = '%';
                s[j-1] = '2';
                s[j] = '0';
                j-=2; 
            }
        }
        return s;
    }
};