#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target || nums[l]==target || nums[r]==target)return true;
            // while(l<r && nums[mid]==nums[l] && nums[l]==nums[r] ){
            //    l++;
            //    r--;
            //    if(nums[l]==target || nums[r]==target)return true;
            //    continue;
            // }
            if(nums[mid]>nums[l] && nums[mid]>nums[r]){
                if(target<nums[l] || target>nums[mid]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }

            else if(nums[mid]<nums[l] && nums[mid]<nums[r]){
                if(target>nums[r] || target<nums[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                l++;
                r--;
            }
        }
        return false;
    }
};