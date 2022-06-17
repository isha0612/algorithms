#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> graph[N];
vector<bool> vis(N);
vector<int> level(N);

void bfs(int vertex) {
    vis[vertex] = true;
    queue<int> q;
    q.push(vertex);
    while(!q.empty()) {
        int par = q.front();
        q.pop();
        cout<<par<<endl;
        for(auto child : graph[par]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
    cout<<endl;
}

int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
    for(int i = 1; i < n; i++) {
        cout<<i<<" : "<<level[i]<<endl;
    }
}