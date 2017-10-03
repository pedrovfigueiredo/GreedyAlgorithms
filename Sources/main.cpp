//
//  main.cpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 28/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include "../Headers/vertex.hpp"
#include "../Headers/graph.hpp"
#include "../Headers/min_heap.hpp"
#include "../Headers/reader.hpp"

void printSolvedGraph(Graph& g, std::string nome, std::string fileName){
    std::cout <<  "\n| " << nome << "\t" << fileName << " |" << std::endl << std::endl;
    for( auto vertex : g.vertexes){
        if (vertex.second->parent){
            if(vertex.second->cost > 1000)
                std::cout << "| " << "Atual: "<< vertex.second->id << "\tCusto: " << vertex.second->cost << "\tPai: " << vertex.second->parent->id << " |" << std::endl;
            else
                std::cout << "| " << "Atual: "<< vertex.second->id << "\tCusto: " << vertex.second->cost << "\tPai: " << vertex.second->parent->id << " |" << std::endl;
        }
        else
            std::cout << "| " << "Atual: "<< vertex.second->id << "\tCusto: " << vertex.second->cost << "\tPai: " << -1 << "|" << std::endl;
    }
    std::cout << std::endl;
}

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

bool compare(const Vertex* i, const Vertex* j) {
        return i->cost < j->cost;
};

void prim(Graph& g, Graph& solved_graph){

    //MinHeap<Vertex*> q;
    std::vector<Vertex*> q;
    Vertex* u;
    const int first_node = 0;

    g.vertexes[first_node]->cost = 0;

    for (auto node : g.vertexes)
        q.push_back(node.second);

    while (!q.empty()) {
        std::sort(q.begin(), q.end(), compare);
        u = q[0];
        
        for (auto v : g.adj[u->id]) {
            double peso_u_v = v.first;
            auto it = std::find(q.begin(), q.end(), v.second);
            if (it != q.end() && peso_u_v < v.second->cost) {
                v.second->parent = u;
                v.second->cost = peso_u_v;
            }
        }
        q.erase(q.begin());
    }

    buildSolvedGraph(g, solved_graph);
}


int main(int argc, const char * argv[]) {

    Graph g1, g2, solved_graph_prim, solved_graph_djijkstra;
    int cost = 0;
    std::string fileName = "dij50.txt";

    Reader::parseGraphFromFile(fileName, g1);
    
    Reader::parseGraphFromFile(fileName, g2);

    prim(g1,solved_graph_prim);
    djijkstra(g2, solved_graph_djijkstra);

    printSolvedGraph(solved_graph_prim, "Prim", fileName);
    for (auto vertex : solved_graph_prim.vertexes)
        cost += vertex.second->cost;
    std::cout << "Custo total: " << cost << std::endl << std::endl;
    
    printSolvedGraph(solved_graph_djijkstra, "Djijkstra", fileName);
    std::cout << "Custo total: " << solved_graph_djijkstra.vertexes[solved_graph_djijkstra.vertexes.size() - 1]->cost << std::endl << std::endl;

    return 0;
}
