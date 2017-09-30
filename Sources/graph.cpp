//
//  graph.cpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 29/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "../Headers/graph.hpp"

Graph::Graph(){}
Graph::~Graph(){};

void Graph::addVertex(Vertex *vertex){
    auto itr = vertexes.find(vertex->id);
    if (itr == vertexes.end()){
        vertexes[vertex->id] = vertex;
        adj.resize(adj.size() + 1);
        return;
    }
    std::cout << "Vertex already exists!" << std::endl;
}

void Graph::addEdge(int from, int to, double cost){
    Vertex* t = vertexes.find(to)->second;

    adj[from].push_back(std::make_pair(cost, t));
}

void Graph::addBidirectionalEdge(int from, int to, double cost){
    Vertex* f = vertexes.find(from)->second;
    Vertex* t = vertexes.find(to)->second;

    adj[from].push_back(std::make_pair(cost, t));
    adj[to].push_back(std::make_pair(cost, f));
}
