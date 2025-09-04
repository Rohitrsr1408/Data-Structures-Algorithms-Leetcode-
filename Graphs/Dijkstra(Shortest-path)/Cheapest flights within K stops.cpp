class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int fair=flights[i][2];
            adj[u].push_back({v,fair});
        }
        vector<int>distance(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        distance[src]=0;
       while(!q.empty()){
        auto ob=q.front();
        q.pop();
        int stops=ob.first;
        int node=ob.second.first;
        int val=ob.second.second;
        
        if(stops>k)continue;
         for(auto adjnode:adj[node]){
            int wt=adjnode.second;
            int newnode=adjnode.first;
            if(val+wt<distance[newnode]){
                distance[newnode]=val+wt;
                q.push({stops+1,{newnode,distance[newnode]}});
            }
         }
       }
        return (distance[dst]==1e9)?-1:distance[dst];
    }
};

#include<bits/stdc++.h> 
using namespace std;