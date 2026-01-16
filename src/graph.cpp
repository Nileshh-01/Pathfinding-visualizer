#include"graph.h"
#include<iostream>
using namespace std;

Graph::Graph(int V, bool directed){
    this->V = V;
    this->directed = directed;
    adj.resize(V);
}

void Graph::addEdges(int u, int v, int wt){
    adj[u].push_back({v,wt});
    if(!directed){
        adj[v].push_back({u,wt});
    }
}

void Graph::print(){
    for(int i=0; i<V; i++){
        cout<<i<<" : ";
        for(auto neigh : adj[i]){
            cout<<" ("<<neigh.first<<neigh.second<<") ";
        }
        cout<<endl;
    }
}
