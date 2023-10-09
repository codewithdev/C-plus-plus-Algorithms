#include <iostream>

/* The following code is an example which use cin to write the captured input via the terminal to the input stream 
   and then displays the captured input via cout to the output stream. 
   
   link: https://en.cppreference.com/w/cpp/header/iostream  
*/

int main() {
  int price;

  // Writes to the standard C output stream 
  std::cout << "Enter the price: ";
  
  // Reads from the standard C input stream 
  std::cin >> price;

  std::cout << "User entered the price " << price << std::endl;
}
