class Solution {

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int>diff;
        unordered_map<int,int>freq;
        int maxele=*max_element(begin(nums),end(nums));
        
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            int l=max(0,nums[i]-k);
            int r=min(maxele,nums[i]+k);
            diff[l]++;
            diff[r+1]--;
            diff[nums[i]]+=0;
        }

       int maxi=1;
       int cumm=0;
       for(auto it:diff){
           int target=it.first;
           it.second+=cumm;
           int needconv=it.second-freq[target];
           int req=min(numOperations,needconv);
           maxi=max(maxi,freq[target]+req);

           cumm=it.second;
       }
      return maxi;
    }
};
#include<bits/stdc++.h>
using namespace std;