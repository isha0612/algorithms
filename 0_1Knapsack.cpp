// Top-Down
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

// Bottom-Up
#include <bits/stdc++.h>
using namespace std; 

int main() {
    vector<pair<int, int>> k;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin>>w>>v;
        k.push_back({w, v});
    }
    int w; cin>>w;
    int dp[n + 1][w + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(k[i - 1].first > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], k[i - 1].second + dp[i - 1][j - k[i - 1].first]);
            }
        }
    }
    cout<<dp[n][w]<<endl;
}
