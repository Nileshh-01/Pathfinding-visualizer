#include"graph.h" 
#include"path_result.h"
#include"dijkstra.h"
#include"bfs.h"
#include"bellman_ford.h"
#include"visualizer.h"
#include<fstream>
#include<iostream>
using namespace std;

int main(){
    
    ifstream file("../test_cases/test6.txt"); 

    if(!file){
        cout<<"text file not accessible"<<endl;
        return 0;
    }

    int V;
    int E;

    file>>V>>E; 

    Graph g(V,false);
    Visualizer vis(600,800);

    int hasNegativeWeights = false;

    for(int i=0; i<E; i++){
        int u,v,w;

        file >> u >> v >> w;
        g.addEdges(u,v,w);
        vis.addEdges(u,v);
        if(w<0){
            hasNegativeWeights = true;
        }
    }   

    int src = 0;
    int dest = V-1;

    // g.print();
    int choice;
    cout<<"Select an algorithm: "<<endl;
    cout<<"1 : Dijsktra"<<endl;
    cout<<"2 : Bellman Ford"<<endl;
    cout<<"3 : BFS"<<endl;
    cout<<"4 : DFS"<<endl;
    cin>>choice;

    PathResult ans;
    pair<PathResult,bool> result; //for bellman ford

    switch(choice){
        case 1: 
            if(hasNegativeWeights){
                cout<<"Dijkstra is not applicable.";
                return -1;
            }
            ans = dijkstra(g,src);
            break;
        
        case 2:
            result = bellmanFord(g,src);
            if(result.second){
                cout<<"Negative cycle exists.";
                return -1;
            } 
            ans = result.first;
            break;
            
        case 3: 
            ans = bfs(g,src);  
            break;  
            return 0;

        case 4:
            break;    
        
        default: 
            cout<<"Invalid case.";
            return 0;
    }
    int curr = dest;
    vector<int> path;
    while(curr!=-1){
        path.push_back(curr);
        curr = ans.parent[curr];
    }
    reverse(path.begin(),path.end());     

    if(ans.dist[dest]==LLONG_MAX) return -1;
    
    cout<<"Shortest path : ";
    
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    cout<<"Shortest distance : "<<ans.dist[dest]<<endl;

    vis.setVisitedOrder(ans.visitedOrder);
    vis.setShortestPath(path);
    vis.createNodes(V);
    vis.run();     
}