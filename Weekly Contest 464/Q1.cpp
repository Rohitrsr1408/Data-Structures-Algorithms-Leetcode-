
//3658. GCD of Odd and Even Sums
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
      int sumodd=0;
        int sumeven=0;
        for(int i=1;i<=2*n;i++){
            if(i%2==0)sumeven+=i;
            else sumodd+=i;
        }
        
        return gcd(sumodd,sumeven);
    }
};