#ifndef ALGORITHM_H

#include <iostream>
#include <vector>
#include <algorithm>

// Step 1: Algorithm Interface
class SortAlgorithm 
{
    public:
        virtual void sort(std::vector<int>& arr) = 0;
};


#endif // ALGORITHM_H
