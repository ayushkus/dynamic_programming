//  Unique Paths II
// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

class Solution {
public:
   int find_ans(int n,int m,vector<vector<int>>& og,vector<vector<int>>&dp)
   {
       if(n>=0 && m>=0 && og[n][m]==1)
       return 0;
    if(n==0 && m==0)
     return 1;
    if(n<0 || m<0)
     return 0;
    if(dp[n][m]!=-1)
    return dp[n][m];
    int top=find_ans(n-1,m,og,dp);
    int left=find_ans(n,m-1,og,dp);
    return dp[n][m]=top+left;
    }



    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return find_ans(n-1,m-1,obstacleGrid,dp);
    }
};