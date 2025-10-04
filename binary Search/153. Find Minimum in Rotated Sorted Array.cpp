class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int ans = nums[0];

        while (l <= r) {
            // if current subarray is already sorted
            if (nums[l] <= nums[r]) {
                ans = min(ans, nums[l]);
                break;
            }

            int mid = l + (r - l) / 2;
            ans = min(ans, nums[mid]);

            // decide which side to go
            if (nums[mid] >= nums[l]) {
                // left part is sorted
                l = mid + 1;
            } else {
                // right part is unsorted
                r = mid - 1;
            }
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;