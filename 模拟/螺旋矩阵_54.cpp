#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int startx = 0, starty = 0;
        int minimum = min(m,n);
        int loop = minimum / 2;
        int offset = 1;
        while(loop--)
        {
            int i = startx;
            int j = starty;
            for(; j<n-offset; j++)
            {
                res.push_back(matrix[startx][j]);
            }
            for(; i<m-offset; i++)
            {
                res.push_back(matrix[i][j]);
            }
            for(; j>starty; j--)
            {
                res.push_back(matrix[i][j]);
            }
            for(; i>startx; i--)
            {
                res.push_back(matrix[i][j]);
            }

            startx++;
            starty++;

            offset++;
        }

        // 如果短边是奇数，则会剩一行或一列没有遍历
        if(minimum % 2 == 1) 
        {
            if(minimum == m)
            {
                for(int j=starty; j<n-offset+1; j++) // 左闭右闭
                {
                    res.push_back(matrix[startx][j]);
                }
            }
            else
            {
                for(int i=startx; i<m-offset+1; i++)
                {
                    res.push_back(matrix[i][starty]);
                }
            }
        }

        return res;
    }
};