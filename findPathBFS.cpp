#include <bits/stdc++.h>
using namespace std;
const int N = 6;
vector<int> graph[N];
vector<int> vis(N);

bool bfs(int source, int destination) {
    vis[source] = true;
    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int parent = q.front();
        q.pop();
        if(parent == destination) return true;
        for(auto child : graph[parent]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
            }
        }
    }
    return false;
}

int main() {
    int m;
    cin>>m;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i = 1; i <= 5;i ++) {
        cout<<i<<"->";
        for(auto x : graph[i]) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    int source, destination;
    cin>>source>>destination;
    if(bfs(source, destination)) 
       cout<<"Yes path exists";
    else
       cout<<"No path exits";
}