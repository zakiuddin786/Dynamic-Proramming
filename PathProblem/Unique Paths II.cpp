// link to the question https://leetcode.com/problems/unique-paths-ii/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
         int row=A.size();
    int col=A[0].size();
    int dp[row][col];
    for(int i=0;i<col;i++)
    {
        if(A[0][i]==1)
        {
            while(i<col)
            {
                dp[0][i]=0;
                i++;
            }
            break;
        }
        dp[0][i]=1;
    }
    for(int i=0;i<row;i++)
    {
        if(A[i][0]==1)
        {
            while(i<row)
            {
                dp[i][0]=0;
                i++;
            }
            break;
        }
        else
        dp[i][0]=1;
    }
   
     
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
             dp[i][j]=0;
            if(A[i][j]!=1)
            {   
                if(A[i][j-1]!=1)
                 dp[i][j]+=dp[i][j-1];
                if(A[i-1][j]!=1)
                 dp[i][j]+=dp[i-1][j];
            }
        }
        
    }
    
    return dp[row-1][col-1];
        
    }
};