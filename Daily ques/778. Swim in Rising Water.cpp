class Solution {
private: bool bfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int time,bool&found){
    
        int n=grid.size();
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0]=1;
        vector<int>xdir={-1,0,1,0};
        vector<int>ydir={0,1,0,-1};
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            if(grid[x][y]==time)found=true;
            if(x==n-1 && y==n-1)return true;
            for(int k=0;k<4;k++){
                int newx=x+xdir[k];
                int newy=y+ydir[k];
                if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]<=time && !visited[newx][newy]){
                    q.push({newx,newy});
                    visited[newx][newy]=1;
                }
            }
        }
        return false;

}
public:
    int swimInWater(vector<vector<int>>& grid) {
      
        int n=grid.size();
        int l=grid[0][0];
        int r=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                r=max(r,grid[i][j]);
            }
        } 
        int ans=0;
      while(l<=r){
        vector<vector<int>>visited(n,vector<int>(n,0));
        int mid=l+(r-l)/2;
        bool found=false;
        if(bfs(grid,visited,mid,found)){
            if(found){
             ans=mid;
            }
            r=mid-1;
        }
        else{
            l=mid+1;
        }
      }
     return ans;
    }
};
#include <bits/stdc++.h>    
using namespace std;