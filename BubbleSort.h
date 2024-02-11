#include "SortAlgorithm.h"

class BubbleSort : public SortAlgorithm 
{
public:
    void sort(std::vector<int>& arr) override 
    {
        bool swapped;
        do 
        {
            swapped = false;
            for (size_t i = 1; i < arr.size(); ++i) 
            {
                if (arr[i - 1] > arr[i]) 
                {
                    std::swap(arr[i - 1], arr[i]);
                    swapped = true;
                }
            }
        } 
        while (swapped);
    }
};