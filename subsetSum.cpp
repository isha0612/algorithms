#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &v, int n, int target) {
    if(target == 0) return true;
    if(n == 0) return false;
    
    if(v[n - 1] > target)
        return subsetSum(v, n - 1, target);
    else 
        return max(subsetSum(v, n - 1, target), subsetSum(v, n - 1, target - v[n - 1]));
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    int target;
    cin>>target;
    cout<<subsetSum(v, n, target);
}
