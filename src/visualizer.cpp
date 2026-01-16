#include"visualizer.h"
#include<SFML/Graphics.hpp>

Visualizer::Visualizer(int height, int width)
    :window(sf::VideoMode(sf::Vector2u(width,height)),"visualizer"){
        if(!font.openFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")){
            throw std::runtime_error("Font not found");
        }
}

void Visualizer::addEdges(int u, int v){
    edges.push_back({u,v});
}

void Visualizer::createNodes(int V){
    nodes.clear();
    nodePos.clear();

    int rad = 25.f;

    float startX = 80.f;
    float startY = 80.f;
    float spacingX = 120.f;
    float spacingY = 120.f;

    int columns = std::ceil(std::sqrt(V));

    for(int i=0; i<V; i++){
        int row = i/columns;
        int col = i % columns;

        float x = startX + col * spacingX;
        float y = startY + row * spacingY;
        
        //nodes circles
        sf::CircleShape node(rad);
        node.setFillColor(sf::Color(109, 116, 117));
        node.setPosition({x,y});
        nodes.push_back(node);
        nodePos[i] = {x,y};

        //node nums
        sf::Text num(font,std::to_string(i),22);
        num.setFillColor(sf::Color::White);

        sf::FloatRect bounds = num.getLocalBounds();
        num.setOrigin(sf::Vector2f(bounds.position.x+bounds.size.x/2, bounds.position.y+bounds.size.y/2));
        num.setPosition(sf::Vector2f(x+rad,y+rad));
        nodeNums.push_back(num);

    }
}

void Visualizer::setVisitedOrder(std::vector<int> &visitedOrder){
    this->visitedOrder = visitedOrder;
    visitIdx = 0;
}

void Visualizer::setShortestPath(std::vector<int> &shortestPath){
    showShortestPath = true;
    this->shortestPath = shortestPath;
}

void Visualizer::run(){
    int rad = 25.f;
    
    sf::Clock clock;
    float delay = 0.5;
            
    while(window.isOpen()){
        while(auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        static int lastNode = -1;
        if(visitIdx<visitedOrder.size()){
            if(clock.getElapsedTime().asSeconds()>=delay){

                if(lastNode!=-1){
                    nodes[lastNode].setFillColor(sf::Color(224, 164, 13));
                }

                int node = visitedOrder[visitIdx];
                nodes[node].setFillColor(sf::Color(13, 172, 224));

                lastNode = node;
                visitIdx++;
                clock.restart();
            }
        }

        if(visitIdx>=visitedOrder.size() && showShortestPath){
            for(int node : shortestPath){
                nodes[node].setFillColor(sf::Color(219, 83, 20));
            }
        }

        window.clear(sf::Color::Black);

        for(auto& e : edges){
            int u = e.first;
            int v = e.second;

            // sf::VertexArray line(sf::PrimitiveType::Lines,2);

            // line[0].position = nodePos[u] + sf::Vector2f(rad,rad);
            // line[1].position = nodePos[v] + sf::Vector2f(rad,rad);
            // line[0].color = sf::Color::White;
            // line[1].color = sf::Color::White;

            sf::Vector2f p1 = nodePos[u] + sf::Vector2f(rad,rad);
            sf::Vector2f p2 = nodePos[v] + sf::Vector2f(rad,rad);

            sf::Vector2f dist = p2-p1;
            float length = std::sqrt(dist.x * dist.x + dist.y * dist.y);

            sf::RectangleShape edge(sf::Vector2f(length,2.5));
            edge.setFillColor(sf::Color::White);
            edge.setPosition(p1);

            float angle = std::atan2(dist.y,dist.x)*180/3.14159;
            edge.setRotation(sf::degrees(angle));

            window.draw(edge);
        }

        for(auto &node : nodes){
            window.draw(node);
        }

        for(auto &nums : nodeNums){
            window.draw(nums);
        }

        window.display();
    }
}