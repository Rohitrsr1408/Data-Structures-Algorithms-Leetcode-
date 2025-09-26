#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
       
         for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int sum=nums[i]+nums[j];
                int l=j+1;
                int r=nums.size()-1;
                int res=nums.size();
                while(l<=r){
                    int mid=(l+r)/2;
                    if(nums[mid]>=sum){
                         res=mid;
                         r=mid-1;  
                    }
                    else{
                        l=mid+1;
                    }
                } 
               
                 ans=ans+res-j-1;
            
           
                }
               
            }
        
         return ans;
    }
};