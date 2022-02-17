#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reserveorder.h"


void reverse_order(std::string date1, std::string date2)
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()) 
    {
        std::cout << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    } 

    std::string junk, date;
    getline(fin, junk);
    array[363];

    double eastSt, eastEl,westEl,westSt;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');
        
       
    }
fin.close();
return 0;
}

