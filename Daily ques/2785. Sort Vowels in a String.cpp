#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        vector<int>indices;
        string str="";
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='A' || c=='a' || c=='E' || c=='e'|| c=='I' || c=='i' || c=='O' || c=='o'|| c=='U'||c=='u'){
                indices.push_back(i);
                str+=c;
            }
        }
        sort(str.begin(),str.end());
        for(int i=0;i<indices.size();i++){
            s[indices[i]]=str[i];
        }
        return s;
    }
};