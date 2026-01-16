#include<iostream>
#include<queue>
#include<vector>
#include"graph.h"
#include"path_result.h"
using namespace std;

PathResult dijkstra(const Graph &g, int src){
    int V = g.V;
    PathResult result;

    result.dist.resize(V,LLONG_MAX);
    result.parent.resize(V,-1);
    
    result.dist[src] = 0;

    priority_queue< pair<long long,int>,
                    vector<pair<long long,int>>,
                    greater<pair<long long,int>> > pq;  //dist,node
    pq.push({0,src});

    while(!pq.empty()){
        int currNode = pq.top().second; 
        int currDist = pq.top().first; 
        pq.pop();

        if(currDist>result.dist[currNode]) continue;
        result.visitedOrder.push_back(currNode);

        for(auto& edge : g.adj[currNode]){
            int v = edge.first;
            int wt = edge.second;

            if(result.dist[v] > result.dist[currNode] + wt){
                result.dist[v] = result.dist[currNode] + wt;
                result.parent[v] = currNode;
                pq.push({result.dist[v],v});
            }
        }
    }
    return result;
}
