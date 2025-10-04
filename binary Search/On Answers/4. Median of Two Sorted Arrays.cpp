class Solution {
private: void merge(vector<int>&nums1,vector<int>&nums2,vector<int>&combined){
    int p1=0;
    int p2=0;
    while(p1<nums1.size() && p2<nums2.size()){
        if(nums1[p1]<nums2[p2]){
            combined.push_back(nums1[p1]);
            p1++;
        }
        else{
            combined.push_back(nums2[p2]);
            p2++;
        }
    }
    while(p1<nums1.size()){
        combined.push_back(nums1[p1]);
        p1++;
    }
    while(p2<nums2.size()){
        combined.push_back(nums2[p2]);
        p2++;
    }
}
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>combined;
        merge(nums1,nums2,combined);
        if((m+n)%2==0){
            int f=(m+n)/2-1;
            int s=((m+n)/2);
            float n1=combined[f];
            float n2=combined[s];
            cout<<n1<<n2;
            float ans=(n1+n2)/2;
            return ans;
        }
        else{
            int ind=(m+n)/2;
            double ans=combined[ind];
            return ans;
        }
        return 0;
    }
};
#include <bits/stdc++.h>
using namespace std;