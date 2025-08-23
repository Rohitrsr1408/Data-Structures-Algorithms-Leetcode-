#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
         vector<vector<int>>adj(numCourses);
         for(int i=0;i<prerequisites.size();i++){
               int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
         }
         for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            indegree[v]++;
         } 
         queue<int>q;
         for(int i=0;i<numCourses;i++){
            if(!indegree[i]) q.push(i);
         }
         vector<int>topo;
         while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
      

            for(auto adjnode:adj[node]){
              
                indegree[adjnode]--;
                if(!indegree[adjnode])q.push(adjnode);
            }
         }
         if(topo.size()==numCourses)return topo;
         return {};
    }
};