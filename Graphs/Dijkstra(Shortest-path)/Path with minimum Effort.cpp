
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        
        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        distance[0][0] = 0;
        
        vector<int> xdir = {-1,0,1,0};
        vector<int> ydir = {0,1,0,-1};
        
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            int val = p.first;
            int i = p.second.first;
            int j = p.second.second;
            
            if(i == n-1 && j == m-1) return val;  // destination reached
            
            for(int l=0; l<4; l++){   // fixed l++
                int newi = i + xdir[l];
                int newj = j + ydir[l];
                
                if(newi>=0 && newi<n && newj>=0 && newj<m){
                    int diff = abs(heights[newi][newj] - heights[i][j]);
                    int effort = max(val, diff);
                    
                    if(effort < distance[newi][newj]){
                        distance[newi][newj] = effort;   // use effort
                        pq.push({effort, {newi,newj}});
                    }
                }
            }
        }
        return distance[n-1][m-1];
    }
};

#include<bits/stdc++.h>
using namespace std;