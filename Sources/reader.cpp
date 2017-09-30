//
//  reader.cpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 29/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "../Headers/reader.hpp"

const void Reader::parseGraphFromFile(const std::string& fileName, Graph& g){
    std::ifstream rendering_file;
    std::stringstream conversion_sstream;
    std::string buffer;

    rendering_file.open(fileName);
    conversion_sstream << (rendering_file.rdbuf());
    buffer = conversion_sstream.str();

    std::string n;

    for (auto character : buffer)
        if (character != '\n')
            n.push_back(character);
        else
            break;
    buffer.erase(buffer.begin(), buffer.begin() + n.size() + 1);

    std::vector<int> costs;
    std::string aux;

    for (auto character : buffer){
        if (character != '\n' && character != ' ')
            aux.push_back(character);
        else{
            costs.push_back(std::stoi(aux));
            aux.clear();
        }
    }

    int n_ = std::stoi(n);

    for (int i = 0; i < n_; i++)
        g.addVertex(new Vertex(i));

    int k = n_ - 1;
    int j = 0;
    while(!costs.empty()){
        for (int i = j + 1; i < n_; i++)
            if (costs[i - (j + 1)])
                g.addBidirectionalEdge(j, i, costs[i - (j + 1)]);

        costs.erase(costs.begin(), costs.begin() + k);
        k--;
        j++;
    }
}
