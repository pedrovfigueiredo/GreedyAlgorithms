//
//  min_heap.hpp
//  GreedyAlgorithms
//
//  Created by Pedro Figueirêdo on 29/09/17.
//  Copyright © 2017 Lavid. All rights reserved.
//

#ifndef min_heap_hpp
#define min_heap_hpp

struct comparator {
    bool operator()(const Vertex* i, const Vertex* j) {
        return i->cost > j->cost;
    }
};

#include <queue>
#include "vertex.hpp"
template< class T, class Container = std::vector<T>, class Compare = comparator>
class MinHeap : public std::priority_queue<T, Container, Compare>
{
public:
    typedef typename
    std::priority_queue<T,Container,Compare>::container_type::const_iterator const_iterator;
    
    const_iterator find(const T&val) const
    {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        while (first!=last) {
            if (*first==val) return first;
            ++first;
        }
        return last;
    }
    
    const_iterator last()const{
        return this->c.cend();
    }
};

#endif /* min_heap_hpp */
