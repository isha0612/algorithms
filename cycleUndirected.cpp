#include <bits/stdc++.h>
using namespace std;
const int N = 6;
vector<int> graph[N];
vector<bool> vis(N, 0);

bool dfs(int v, int par) {
    vis[v] = true;
    for(auto child : graph[v]) {
        if(!vis[child]) {
            if(dfs(child, v)) 
              return true;
        }
        else if(par != child)
           return true;
    }
    return false;
}

bool isCycle() {
    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            if(dfs(i, -1))
               return true;
        }
    }
    return false;
}

int main() {
    for(int i = 0; i < 3; i++) {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    if(isCycle())
      cout<<"CYCLE EXISTS";
    else
      cout<<"NO CYCLE EXISTS";
}
