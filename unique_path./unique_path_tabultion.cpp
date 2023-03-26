#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
 
 
 int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
     for(int i=0;i<m;i++)
     {
        for(int j=0;j<n;j++)
        {
           if(i==0 && j==0)
            dp[i][j]=1;
            else
            {  int right=0;
            int down=0;
                if(i>0)
                {
                    down=dp[i-1][j];
                }
                if(j>0)
                right=dp[i][j-1];
                dp[i][j]=right+down;
            }
        }
     }
     return dp[m-1][n-1];   
    }
    int main()
   {
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n);
    return 0;
   }