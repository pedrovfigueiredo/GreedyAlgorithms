//
//  reader.hpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 29/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef reader_hpp
#define reader_hpp
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include "graph.hpp"

class Reader
{
public:
    Reader();
    ~Reader();
    
    static const void parseGraphFromFile(const std::string& fileName, Graph& g);
    
};

#endif /* reader_hpp */
