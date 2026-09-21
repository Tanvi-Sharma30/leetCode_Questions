class Solution {
public:
    int solve(int i, int j1,int j2,vector<vector<int>>& grid ,vector<vector<vector<int>>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        if(j1<0 || j1>m-1 || j2<0 || j2>m-1) return 0;
        if(i==n-1){
            if(j1==j2) 
              return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        } 
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=INT_MIN;
        for(int j=-1;j<=1;j++){
            for(int k=-1;k<=1;k++){
                if(j1==j2){
                    ans= max(ans, grid[i][j1] + solve(i+1,j1+j,j2+k,grid,dp));
                }else {
                    ans= max(ans, grid[i][j1] +grid[i][j2]+ solve(i+1,j1+j,j2+k,grid,dp));
                }
            }
        }
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,grid,dp);
    }
};