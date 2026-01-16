#ifndef GRAPH_H
#define GRAPH_H

#include<list>
// using namespace std;

class Graph{
public:

    int V;
    bool directed;
    std:: vector<std::list <std::pair<int,int>>> adj;


    Graph(int V, bool directed);

    void addEdges(int u, int v, int wt);

    void print();
};

#endif
