#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<pair<int, int>> k, int w, int n, int dp[]) {
    if(w == 0 || n == 0)
       return 0;
    if(k[n-1].first > w) {
        return dp[n] = knapsack(k, w, n - 1, dp);
    }
    else {
        return dp[n] = max(knapsack(k, w, n - 1, dp), k[n - 1].second + knapsack(k, w - k[n - 1].first, n - 1, dp));
    }
}

int main() {
    vector<pair<int, int>> k;
    int n; cin>>n;
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
        int w, v;
        cin>>w>>v;
        k.push_back({w, v});
    }
    int weight; cin>>weight;
    int ans = 0;
    cout<<knapsack(k, weight, n, dp);
}