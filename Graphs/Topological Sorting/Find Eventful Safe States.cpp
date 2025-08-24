#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size());
        vector<int>outdegree(graph.size(),0);
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int v=graph[i][j];
                adj[v].push_back(i);
            }
             outdegree[i]=graph[i].size();
             if(outdegree[i]==0)q.push(i);
        }
        vector<int>ans;
       while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto adjnode:adj[node]){
            outdegree[adjnode]--;
            if(!outdegree[adjnode])q.push(adjnode);
        }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};