#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include<iostream>
#include"graph.h"
#include"path_result.h"

std::pair<PathResult,bool> bellmanFord(const Graph &g, int src);


#endif