#include<iostream>
#include"graph.h"
#include"path_result.h"

using namespace std;

pair<PathResult,bool> bellmanFord(const Graph &g, int src){
    int V = g.V;

    PathResult result;

    result.dist.resize(V,INT_MAX);
    result.parent.resize(V,-1);

    result.dist[src] = 0;



    for(int i=0; i<V-1; i++){
        for(int u=0; u<V; u++){
            for(auto& v : g.adj[u]){
                if(result.dist[i]!=INT_MAX && result.dist[v.first]>result.dist[i]+v.second){
                    result.dist[v.first] = result.dist[i]+v.second;
                    result.parent[v.first] = u;
                    result.visitedOrder.push_back(v.first);
                }
            }
        }

        
    }

    //Detect negative cycles

    for(int u=0; u<V; u++){
        for(auto &v : g.adj[u]){
            if(result.dist[u]!=INT_MAX && result.dist[v.first]>result.dist[u]+v.second){
                return {result,true};
            }
        }
        
    }
    return {result,false};
}