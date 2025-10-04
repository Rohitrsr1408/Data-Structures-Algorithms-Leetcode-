class Solution {
private: int check(vector<int>&nums,int val){
    int ans=0;
    for(int i=0;i<nums.size();i++){
        int c=nums[i]/val;
        if(nums[i]%val!=0)c++;
        ans+=c;
        
    }
    return ans;
}
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            int ans=check(nums,mid);
            if(ans<=threshold){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
#include <bits/stdc++.h>
using namespace std;