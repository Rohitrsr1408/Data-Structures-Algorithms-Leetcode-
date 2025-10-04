class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=1;
        int r=m*n;
       
        while(l<=r){
            int mid=l+(r-l)/2;
            int i,j;
            if(mid%n==0){
                i=(mid/n)-1;
                j=n-1;
            }
            else{
                i=mid/n;
                j=(mid%n)-1;
            }
            if(matrix[i][j]==target)return true;
            if(matrix[i][j]<target)l=mid+1;
            else r=mid-1;
       }
       return false;
    }
};
#include <bits/stdc++.h>
using namespace std;