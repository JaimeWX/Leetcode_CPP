#include <string>
using namespace std;

class Solution {
private:
    void reverse(string& s, int start, int end)
    {
        int left = start;
        int right = end;
        for(;left<right;left++,right--)
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
        }
    }
public:
    string reverseStr(string s, int k) 
    {
        //分别处理三种情况
        int size = s.size();
        for(int i=0; i<size; i+=2*k)
        {
            if(size - i < k)
                reverse(s, i, size-1);
            else if(k <= size - i < 2*k)
                reverse(s, i, i+k-1);
            else
                reverse(s, i, i+k-1);
        }
        return s;
    }
};