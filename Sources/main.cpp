//
//  main.cpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 28/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include <iostream>
#include <queue>
#include "../Headers/vertex.hpp"
#include "../Headers/graph.hpp"
#include "../Headers/min_heap.hpp"
#include "../Headers/reader.hpp"

void buildSolvedGraph(Graph& g, Graph& solved){
    solved.vertexes = g.vertexes;
    solved.adj.resize(solved.vertexes.size());

    for(auto node : solved.vertexes){
        Vertex* current = node.second;
        if (current->parent)
            solved.addBidirectionalEdge(current->parent->id, current->id, current->cost);
    }
}

void djijkstra(Graph& g, Graph& solved_graph){

    MinHeap<Vertex*> q;
    Vertex* u;
    const int first_node = 0;

    g.vertexes[first_node]->cost = 0;

    for (auto node : g.vertexes)
        q.push(node.second);

    while (!q.empty()) {
        u = q.top();
        for (auto v : g.adj[u->id]) {
            double peso_u_v = v.first;
            if (v.second->cost > u->cost + peso_u_v) {
                v.second->parent = u;
                v.second->cost = peso_u_v + u->cost;
            }
        }
        q.pop();
    }

    buildSolvedGraph(g, solved_graph);
}

void prim(Graph& g, Graph& solved_graph){

    MinHeap<Vertex*> q;
    Vertex* u;
    const int first_node = 0;

    g.vertexes[first_node]->cost = 0;

    for (auto node : g.vertexes)
        q.push(node.second);

    while (!q.empty()) {
        u = q.top();
        for (auto v : g.adj[u->id]) {
            double peso_u_v = v.first;
            if (q.find(v.second) != q.last() && peso_u_v < v.second->cost) {
                v.second->parent = u;
                v.second->cost = peso_u_v;
            }
        }
        q.pop();
    }

    buildSolvedGraph(g, solved_graph);
}


int main(int argc, const char * argv[]) {

    Graph g1, g2, solved_graph_prim, solved_graph_djijkstra;
    int cost = 0;

    Reader::parseGraphFromFile("/Users/PedroFigueiredo/Google Drive/5 Período/Análise e Projeto de Algoritmos/Algoritmos APA/GreedyAlgorithms/GreedyAlgorithms/input.txt", g1);

    Reader::parseGraphFromFile("/Users/PedroFigueiredo/Google Drive/5 Período/Análise e Projeto de Algoritmos/Algoritmos APA/GreedyAlgorithms/GreedyAlgorithms/input.txt", g2);

    prim(g1,solved_graph_prim);
    djijkstra(g2, solved_graph_djijkstra);

    for (auto vertex : solved_graph_prim.vertexes)
        cost += vertex.second->cost;
    std::cout << "Prim: " << cost << std::endl;

    cost = 0;
    for (auto vertex : solved_graph_djijkstra.vertexes)
        cost += vertex.second->cost;
    std::cout << "Djijkstra: " << cost << std::endl;

    return 0;
}
