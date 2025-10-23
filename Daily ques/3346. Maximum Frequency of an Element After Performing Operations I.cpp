class Solution {


public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int>mpp;
        int maxele=*max_element(begin(nums),end(nums));
        int maxlimit=maxele+k;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
       for(int i=1;i<=maxlimit;i++){
        mpp[i]+=mpp[i-1];
       }
       int maxi=1;
       
       for(int target=0;target<=maxele;target++){
        if(mpp[target]==0)continue;
        int l=max(0,target-k);
        int r=min(maxlimit,target+k);
        int total=mpp[r]-((l>0)?mpp[l-1]:0);
        int targetfreq=mpp[target]-((target>0)?mpp[target-1]:0);
        int reqconv=min(numOperations,total-targetfreq);
        maxi=max(maxi,targetfreq+reqconv);
       }
      return maxi;
    }
};
#include<bits/stdc++.h>
using namespace std;