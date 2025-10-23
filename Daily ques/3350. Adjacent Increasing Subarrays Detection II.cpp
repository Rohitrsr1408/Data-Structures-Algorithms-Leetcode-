class Solution {
private:
    bool solve(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> inc(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                inc[i] = inc[i - 1] + 1;
        }

        for (int i = 0; i + k < n; i++) {
            if (inc[i] >= k && inc[i + k] >= k)
                return true;
        }
        return false;
    }

public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int l = 1, r = nums.size() / 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (solve(nums, m))
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }
};

#include<bits/stdc++.h>
using namespace std;