#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int ans=0;
        unordered_map<int,int>mpp;
        unordered_set<int>sadusers;
        for(int i=0;i<friendships.size();i++){
            int f1=friendships[i][0];
            int f2=friendships[i][1];
            unordered_set<int>st;
            bool temp=true;
            for(int j=0;j<languages[f1-1].size();j++){
                st.insert(languages[f1-1][j]);
            }
             for(int j=0;j<languages[f2-1].size();j++){
                if(st.find(languages[f2-1][j])!=st.end()){
                    temp=false;
                    break;
                }
            }
            if(temp){
                sadusers.insert(f1);
                sadusers.insert(f2);
            }
            
        }
        int maxcnt=0;
        for(auto user:sadusers){
            for(int lan:languages[user-1]){
                mpp[lan]++;
                maxcnt=max(maxcnt,mpp[lan]);
            }
        }
        ans=sadusers.size()-maxcnt;
        return ans;
    }
};