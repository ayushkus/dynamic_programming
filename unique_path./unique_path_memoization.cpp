// 62. Unique Paths
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int find_ans(int m,int n,vector<vector<int>>&dp)
    {
      if(m==0 && n==0)
        return 1;
        if(m<0 ||n<0)
         return 0;
        if(dp[m][n]!=-1)
        return dp[m][n];
       
        int top=find_ans(m-1,n,dp);
        int left=find_ans(m,n-1,dp);
        return dp[m][n]=top+left;
    } 
    

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return find_ans(m-1,n-1,dp);
    }
    int main()
   {
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n);
    return 0;
   }