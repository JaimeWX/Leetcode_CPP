#include <vector>
#include <string>
using namespace std;

class Solution 
{   
    public:
        vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
        {
            int i,j;
            int length = heights.size() - 1;
            for(i=0; i<length; i++)
            {
                for(j=length-1; j>=i; j--)
                {
                    if(heights[j] < heights[j+1])
                    {
                        int h_tmp = heights[j];
                        heights[j] = heights[j+1];
                        heights[j+1] = h_tmp;

                        string n_tmp = names[j];
                        names[j] = names[j+1];
                        names[j+1] = n_tmp;
                    }
                }
            }
            
            return names;
        }
};