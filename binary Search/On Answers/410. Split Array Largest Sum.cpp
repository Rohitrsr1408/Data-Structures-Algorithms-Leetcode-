class Solution {
private: int check(vector<int>&nums,int s){
       int sum=0;
       int i=0;
       int d=0;
       while(i<nums.size()){
          sum+=nums[i];
          if(sum>s){
            d++;
            sum=0;
          }
          else{
            i++;
          }
       }
       d++;
       return d;
}
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=0;
        for(int i=0;i<nums.size();i++){
            r+=nums[i];
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(nums,mid)>k){
            l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};
#include <bits/stdc++.h>
using namespace std;