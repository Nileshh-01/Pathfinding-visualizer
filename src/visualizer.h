#ifndef VISUALIZER_H
#define VISUALIZER_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>

class Visualizer{
    sf::RenderWindow window;
    std::vector<sf::CircleShape> nodes;
    std::unordered_map<int, sf::Vector2f> nodePos;
    std::vector<std::pair<int,int>> edges;

    sf:: Font font;
    std::vector<sf::Text> nodeNums;

    int visitIdx = 0;
    std::vector<int> visitedOrder;

    bool showShortestPath = false;
    std::vector<int> shortestPath;

public:

    Visualizer(int height, int width);

    void addEdges(int u, int v);
    void createNodes(int V);
    
    void setVisitedOrder(std::vector<int> &visitedOrder);
    void setShortestPath(std::vector<int> &shortestPath);
    void run();
};

#endif