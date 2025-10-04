class Solution {
private: int check(vector<int>&bloomDay,int k,int val){
  int b=0;
  int n=0;
  for(int i=0;i<bloomDay.size();i++){
    if(bloomDay[i]<=val){
        n++;
        if(n==k){
            b++;
            n=0;
        }
    }
    else{
        n=0;
    }
  }
  return b;
}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int c=0;
          for(int i=1;i<=k;i++){
            c=c+m;
            if(c>bloomDay.size())return -1;
          }
        //if(m*k>bloomDay.size())return -1;
       int l=1;
       int r=*max_element(bloomDay.begin(),bloomDay.end());
       while(l<=r){
        int mid=l+(r-l)/2;
        int b=check(bloomDay,k,mid);
        if(b>=m){
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