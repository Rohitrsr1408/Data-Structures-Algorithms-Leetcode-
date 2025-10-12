#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        unordered_set<char> present;

        // track used characters
        for (auto &w : words)
            for (char c : w)
                present.insert(c);

        // build adjacency list
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            int len = min(s1.length(), s2.length());

            // invalid case: prefix
            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2)
                return "";

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        // calculate indegree
        vector<int> indegree(26, 0);
        for (int i = 0; i < 26; i++) {
            for (auto node : adj[i]) {
                indegree[node]++;
            }
        }

        // Kahn’s Algorithm
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && present.count(i + 'a')) {
                q.push(i);
            }
        }

        string topo = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo += (node + 'a');

            for (auto adjnode : adj[node]) {
                indegree[adjnode]--;
                if (indegree[adjnode] == 0)
                    q.push(adjnode);
            }
        }

        // if topo doesn't include all characters → cycle → invalid
        if (topo.size() != present.size()) return "";

        return topo;
    }
};
