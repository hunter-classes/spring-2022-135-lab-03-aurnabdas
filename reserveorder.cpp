#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reserveorder.h"


void reverse_order(std::string date1, std::string date2)
{
    //opens the file
    std::ifstream fin("Current_Reservoir_Levels.tsv");

    // gives this error if file cant be open
    if (fin.fail()) 
    {
        std::cout << "File cannot be opened for reading." << std::endl;
        exit(1); 
    } 

    //removes the first line that does not have the the information we need
    std::string junk, date;
    getline(fin, junk);

    double day = 0;
    bool pass;
    double elevation[365];
    int counter = 0;
    double eastSt, eastEl,westEl,westSt;
    
    //loops through and labels what each value is represents up until the west elevation
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
    { 
    // ignores all the information after west elevation
        fin.ignore(INT_MAX, '\n');

    // given the first date within the function parameter if its within the the file pass the information through to the next step
        if (date == date1)
        {
            pass = true;
        }
    // the first date will repersent the index 0 in the array that was made before 
    // every value starting from the first date is put an index. the counter represents the position from the first value to whatever the last value is
    // the values of the corresponding west elevation values are then put in with the apporaite index's which represents 
        if (pass == true)
        {
            elevation[counter] = westEl;
            counter++;
        }
    // the second date represents the last date. therfore the last value that is being put
    // so everything after this date should not be put in the array 
        if (date == date2)
        {
            pass = false;

        }
    }
    // this loop prints out the array in desending order 
    for (int i = counter-1 ; i >= 0; i--)
        {
        std::cout << elevation[i] << std::endl;
        }
}


