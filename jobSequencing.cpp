#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> jb;
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int p, d;
        cin>>p>>d;
        jb.push_back({p, d});
    }
    sort(jb.begin(), jb.end(), greater<pair<int, int>>());
    int m = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(jb[i].second > m)
          m = jb[i].second;
    }
    int temp[m], ans = 0;
    memset(temp, -1, sizeof(temp));
    for(int i = 0; i < n; i++) {
        int j = jb[i].second - 1;
        while(j >= 0 && temp[j] != -1)
           j--;
        if(j >= 0 && temp[j] == -1) {
            temp[j] = i;
            ans += jb[i].first;
        }
    }
    cout<<ans<<endl;
}