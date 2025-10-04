class Solution {
private: int check(vector<int>&weights,int c){
      int i=0;
      int d=0;
      int sum=0;
      while(i<weights.size()){
        sum+=weights[i];
        if(sum>c){
            d++;
            sum=0;
        }
        else{
          i++;
        }  
      }
      d++;
  return d;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int l=*max_element(weights.begin(),weights.end());
       int r=0;
       for(int i=0;i<weights.size();i++){
          r+=weights[i];
       }
       while(l<=r){
          int mid=l+(r-l)/2;
          if(check(weights,mid)>days){
              l=mid+1;
          }
          else{
            r=mid-1;
          }
       }
       return l;
    }
};
#include <bits/stdc++.h>
using namespace std;