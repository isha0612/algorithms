#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> graph[N];
vector<bool> vis(N);

void dfs(int vertex) {
    vis[vertex] = true;
    cout<<vertex<<endl;
    for(auto child : graph[vertex]) {
        cout<<"par : "<<vertex<<", child : "<<child<<endl;
        if(vis[child]) continue;
        dfs(child);
    }

}

int main() {
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
}