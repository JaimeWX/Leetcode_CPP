#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) 
    {
        //如何给字符串扩容？
        int space_count = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
                space_count++;
        }
        int s_oldSize = s.size();
        s.resize(s_oldSize+2*space_count);

        //双指针如何使用？
        int oldTail = s_oldSize-1;
        int newTail = s.size()-1;
        for(;oldTail<newTail;oldTail--,newTail--)
        {
            if(s[oldTail] == ' ')
            {
                s[newTail] = '0';
                s[newTail-1] = '2';
                s[newTail-2] = '%';
                newTail -= 2;
            }
            else
            {
                s[newTail] = s[oldTail];
            }
        }
        return s;
    }
};