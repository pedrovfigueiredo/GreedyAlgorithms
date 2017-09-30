//
//  vertex.hpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 29/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef vertex_hpp
#define vertex_hpp
#include <vector>
#include <string>
#include <limits>

class Vertex
{
public:
    Vertex(int id);
    ~Vertex();
    
    double cost;
    int id;
    Vertex* parent;
};

#endif /* vertex_hpp */
