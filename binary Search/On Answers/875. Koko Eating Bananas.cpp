class Solution {
private: long check(vector<int>&piles,int k){
    long h=0;
      for(int i=0;i<piles.size();i++){
        if(piles[i]<k)h++;
        else{
            h=h+(piles[i]/k);
            if(piles[i]%k)h++;
        }
      }
      return h;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       sort(piles.begin(),piles.end());
       int r=piles[piles.size()-1];
       int l=1;
       while(l<=r){
        int mid=l+(r-l)/2;
        long hours=check(piles,mid);
     
       
        if(hours>h){
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