class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            bool first=true;
            bool second=true;
            int len1=0;
            int len2=0;
           int j=i+1;
           while(j<nums.size() && j<i+k){
              if(nums[j]<=nums[j-1]){
                first=false;
                break;
              }
              len1++;
              j++;
            }
            j++;
            if(first && len1==k-1){
               while(j<nums.size() && j<i+2*k){
                if(nums[j]<=nums[j-1]){
                second=false;
                break;
              }
              len2++;
              j++;
               }
               if(first && second && len1==k-1 && len2==k-1){
                return true;
               }
            }
        }
        return false;
    }
};

#include<bits/stdc++.h>
using namespace std;