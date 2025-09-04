#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        
        vector<vector<int>> distance(n, vector<int>(n, 1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({1,{0,0}});
        distance[0][0] = 1;
        
        vector<int> rowdir = {-1,-1,-1,0,0,1,1,1};
        vector<int> coldir = {-1,0,1,-1,1,-1,0,1};
        
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            int d = p.first;
            int r = p.second.first;
            int c = p.second.second;
            
            if(r==n-1 && c==n-1) return d;  // ✅ early stop
            
            for(int i=0;i<8;i++){
                int newr = r + rowdir[i];
                int newc = c + coldir[i];
                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0){
                    if(d+1 < distance[newr][newc]){
                        distance[newr][newc] = d+1;
                        pq.push({d+1,{newr,newc}});
                    }
                }
            }
        }
        
        return -1; // ✅ simplified
    }
};
