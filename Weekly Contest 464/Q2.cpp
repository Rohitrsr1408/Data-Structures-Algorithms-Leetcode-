//3659. Partition Array Into K-Distinct Groups
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        
        if(nums.size()%k!=0)
            return false;
        unordered_map<int,int> mpp;
        for (int i=0;i<nums.size();i++ ) 
            {
                mpp[nums[i]]++;
            }

        int maxFreq = 0;
        for (auto it : mpp) 
        {
            maxFreq = max(maxFreq, it.second);
        }

        int groups = nums.size() / k;
        return maxFreq <= groups;
 }
};