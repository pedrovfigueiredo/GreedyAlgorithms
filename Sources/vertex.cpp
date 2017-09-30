//
//  vertex.cpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 29/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#include "../Headers/vertex.hpp"

Vertex::Vertex(int id):id(id),cost(std::numeric_limits<double>::infinity()),parent(nullptr){}
Vertex::~Vertex(){}
