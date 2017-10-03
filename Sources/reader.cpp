//
//  reader.cpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 29/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "../Headers/reader.hpp"

const void Reader::parseGraphFromFile(const std::string& fileName, Graph& g){
    
    FILE *arq;
    int number, n;
    std::vector<int> costs;
    
    arq = std::fopen(fileName.c_str(), "r");
    
    if(arq == NULL)
        std::cout << "Error opening file" << std::endl;
    
    while(!feof(arq)){
        fscanf(arq, "%d", &number);
        costs.push_back(number);
    }
    
    fclose(arq);
    
    n = costs[0];
    costs.erase(costs.begin());
    costs.erase(costs.end() - 1);
    
    
    for (int i = 0; i < n; i++)
        g.addVertex(new Vertex(i));
    
    int k = n - 1;
    int j = 0;
    while(!costs.empty()){
        for (int i = j + 1; i < n; i++)
            if (costs[i - (j + 1)])
                g.addBidirectionalEdge(j, i, costs[i - (j + 1)]);
        
        costs.erase(costs.begin(), costs.begin() + k);
        k--;
        j++;
    }
}


