#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string thedate)
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()) 
    {
        std::cout << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    } 

    std::string junk, date;
    getline(fin, junk);

    double eastSt, eastEl,westEl,westSt;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');
        if (date == thedate)
        {
            fin.close();
            return eastSt;
        }
       
    }

return 0;
}

double get_min_east()
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()) 
    {
        std::cout << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    } 

    std::string junk, date;
    getline(fin, junk);

    double eastSt, eastEl,westEl,westSt;
    double min = INT_MAX;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');
        if (eastSt < min)
        {
            min = eastSt;
        }
    }
    fin.close();
    return min;
}


double get_max_east()
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()) 
    {
        std::cout << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    } 

    std::string junk, date;
    getline(fin, junk);

    double eastSt, eastEl,westEl,westSt;
    double max = INT_MIN;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');
        if (eastSt > max)
        {
            max = eastSt;
        }
    }
    fin.close();
    return max;
}

std::string compare_basins(std::string thedate)
{
std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()) 
    {
        std::cout << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    } 

    std::string junk, date, result;
    getline(fin, junk);
    double eastSt, eastEl,westEl,westSt;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
    { 
        fin.ignore(INT_MAX, '\n');
        if (date == thedate)
        {
            fin.close();
            if (eastEl < westEl)
            {
                return "West";
            }
            else if (eastEl > westEl)
            {
                return "East";
            } 
            else 
            {
                return "Equal";
            
            }
       
        }
    }

return 0;
}







