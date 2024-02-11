#include "BubbleSort.h"

class Array 
{
    private:
        std::vector<int> data;
        SortAlgorithm* algorithm;
    public:
        Array() {}
        Array(std::initializer_list<int> list) : 
        data(list), 
        algorithm(nullptr) 
        {

        }

        void set_sort_algorithm(SortAlgorithm* alg) 
        {
            algorithm = alg;
        }

        void push_back(int value) 
        {
            data.push_back(value);
        }

        void sort() 
        {
            if (algorithm != nullptr) 
            {
                algorithm->sort(data);
            } 
            else 
            {
                std::cout << "Sorting algorithm not set." << std::endl;
            }
        }

        void print() 
        {
            for (int i : data) 
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
};