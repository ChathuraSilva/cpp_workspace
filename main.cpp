#include "Array.h"
#include <ctime>
#include <fstream>

int main() 
{
    // Create a file to write the data to plot time taken to sort the array
    std::ofstream file;
    file.open("BubbleSort.csv", std::ios_base::app);
    file << "i_ArrSize(n)" << "," << "d_ArrSize(kB)" << "," << "time(ms)" << "," << "time(s)" << "\n";

    //increase i_ArrSize from 10 to 1000000
    int i_Max = 100000;
    int i_Step = 10000;
    int i_Start = 10000;
    for (int i_temp = i_Start; i_temp < i_Max + i_Step; i_temp+= i_Step)
    {
        Array arr_test;
        int i_ArrSize = i_temp;
        for (int i = 0; i < i_ArrSize; i++) 
        {
            // Generate a random number between -i_ArrSize and i_ArrSize
            int random = rand() % (2 * i_ArrSize) - i_ArrSize;
            arr_test.push_back(random);
        }
        
        double d_ArrSize = (sizeof(int) * i_ArrSize) / 1024.0;

        BubbleSort bubbleSort;

        arr_test.set_sort_algorithm(&bubbleSort);

        // Start a clock
        clock_t t;
        t = clock();

        arr_test.sort();

        // calculate the time in microseconds taken by sort() function
        t = clock() - t;
        printf("ArrSize - %d(%.3fkB) |time taken - %d mSec (%f seconds).\n", i_ArrSize, d_ArrSize, (int)t, ((float)t)/CLOCKS_PER_SEC);

        //write to csv file

        file << i_ArrSize << "," << d_ArrSize << "," << (int)t << "," << ((float)t)/CLOCKS_PER_SEC << "\n";
        
    }

    file.close();
    return 0;
}
