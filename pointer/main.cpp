#include <iostream>

// Showing that in parameter a copy is created
void printAddresses( const int* arrPtr )
{
    std::cout << "Value ptr is pointing to:                        " << *arrPtr
              << std::endl;
    std::cout << "Address of the Variable that ptr is pointing to: " << arrPtr
              << std::endl;
    std::cout << "Address of ptr itself:                           " << &arrPtr
              << std::endl;
    std::cout << "------\n";
}

int main()
{
    // Creating array with 9 elements
    int32_t  arr[ 9 ]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };


    // Creating a pointer pointing to the second element
    int* arrPtr0 = &arr[ 0 ];
    int* arrPtr1 = &arr[ 1 ];
    int* arrPtr2 = &arr[ 2 ];
    int* arrPtr3 = &arr[ 3 ];
    int* arrPtr4 = &arr[ 4 ];

    printAddresses( arrPtr0 );
    printAddresses( arrPtr1 );
    printAddresses( arrPtr2 );
    printAddresses( arrPtr3 );
    printAddresses( arrPtr4 );

    return 0;
}
