class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int l=0;
        int r=nums.size()-2;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid%2==0){
                if(nums[mid+1]==nums[mid])l=mid+1;
                else if(mid>0 && nums[mid-1]==nums[mid])r=mid-1;
                else return nums[mid];
        }
        else{
             if(nums[mid+1]==nums[mid])r=mid-1;
                else if(mid >0 && nums[mid-1]==nums[mid])l=mid+1;
                else return nums[mid];
        }
        }
        return nums[l];
    }
};
#include <bits/stdc++.h>
using namespace std;