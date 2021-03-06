// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reserveorder.h"



int main()
{
std::cout << "01/01/2018:" << get_east_storage("01/01/2018") << " billon gallons\n";
std::cout << "03/01/2018:" << get_east_storage("03/01/2018") << " billon gallons\n";
std::cout << "02/06/2018:" << get_east_storage("02/06/2018") << " billon gallons\n";
std::cout << "\n";

std::cout << "minimum storage in East basin:" << get_min_east() << " billon gallons\n";
std::cout << "maximum storage in East basin:" << get_max_east() << " billon gallons\n";
std::cout << "\n";

std::cout << "01/01/2018 " << compare_basins("01/01/2018") << std::endl;
std::cout << "01/06/2018 " << compare_basins("01/06/2018") << std::endl;
std::cout << "\n";

std::cout << "Reserve Order from 05/29/2018 to 06/02/2018" << std::endl;
reverse_order("05/29/2018", "06/02/2018");  

  return 0;
}