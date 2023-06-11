#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> res(n,vector<int>(n,0));
        int loop = n/2;
        int startx = 0, starty = 0;
        int number = 1;
        int offset = 1;
        int mid = n/2;
        int i,j;
        while(loop--)
        {
            i = startx;
            j = starty;

            for(; j < n-offset; j++)
            {
                res[startx][j] = number++;
            }
            for(; i < n-offset; i++)
            {
                res[i][j] =number++;
            }
            for(; j > starty; j--)
            {
                res[i][j] = number++;
            }
            for(; i > startx; i--)
            {
                res[i][j] = number++;
            }

            startx++;
            starty++;

            offset++;
        }
        if(n%2==1)
                res[mid][mid] = number;
        return res;
    }
};