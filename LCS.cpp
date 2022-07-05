//Bottom - Up
#include<bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int n, int m) {
    if(n == 0 || m == 0)
       return 0;
    if(a[n-1] == b[m-1]) {
        return 1 + lcs(a, b, n - 1, m - 1);
    } else {
        return max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
    }
}

int main() {
    string a, b;
    cin>>a>>b;
    return lcs(a, b, a.size(), b.size());
}

//Top - Down
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin>>a>>b;
    int m = a.size(), n = b.size();
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i - 1] == b[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout<<dp[m][n];
}
