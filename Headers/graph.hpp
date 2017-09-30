//
//  graph.hpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 29/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp
#include <map>
#include <vector>
#include <iostream>
#include "vertex.hpp"

class Graph
{
public:

    Graph();
    ~Graph();

    void addVertex(Vertex* vertex);
    void addEdge(int from, int to, double cost);
    void addBidirectionalEdge(int from, int to, double cost);

    std::map<int, Vertex*> vertexes;
    std::vector<std::vector<std::pair<double, Vertex*> > > adj;
};

#endif /* graph_hpp */
