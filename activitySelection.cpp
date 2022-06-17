#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> as;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int s, e;
        cin>>s>>e;
        as.push_back({e, s});
    }
    sort(as.begin(), as.end());
    int curEnd = -1, ans = 0;
    for(int i = 0; i < n; i++) {
        if(as[i].second > curEnd) {
            ans++;
            curEnd = as[i].first;
        }
    }
    cout<<ans<<endl;
}