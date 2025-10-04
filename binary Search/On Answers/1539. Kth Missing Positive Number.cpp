class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int p = 0;   // pointer for arr
        int i = 1;   // current number to check
        
        while (true) {
            if (p < arr.size() && arr[p] == i) {
                p++; // number present in arr
            } else {
                k--; // number is missing
                if (k == 0) return i; // found kth missing
            }
            i++;
        }
    }
};

#include <bits/stdc++.h>
using namespace std;