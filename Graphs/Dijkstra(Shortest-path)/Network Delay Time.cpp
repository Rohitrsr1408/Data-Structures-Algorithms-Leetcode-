class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>distance(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        distance[k]=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int val=p.first;
            int node=p.second;
            for(auto adjnode:adj[node]){
                int nextnode=adjnode.first;
                int nodeval=adjnode.second;
              
                if(nodeval+val<distance[nextnode]){
                    distance[nextnode]=nodeval+val;
                    pq.push({nodeval+val,nextnode});
                }
            }
        }
      int maxi=0;
      for(int i=1;i<=n;i++){
        if(distance[i]==1e9)return -1;
        maxi=max(maxi,distance[i]);
      }
     return maxi;
    }
};

#include<bits/stdc++.h> 
using namespace std;