#include<iostream>
#include<queue>
#include"graph.h"
#include"path_result.h"

using namespace std;

PathResult bfs(const Graph &g, int src){
    int V = g.V;

    queue <int> q;
    q.push(src);

    PathResult result;  
    result.dist.resize(V,LLONG_MAX);
    result.parent.resize(V,-1);

    result.dist[src] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        result.visitedOrder.push_back(u);

        for(auto &v : g.adj[u]){
            if(result.dist[v.first]>result.dist[u]+1){
                result.dist[v.first] = result.dist[u]+1;
                result.parent[v.first] = u;
                q.push(v.first);
            }
        }
    }
    return result;
}
