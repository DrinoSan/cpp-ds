#include <iostream>

class A
{
  public:
    char y;
    char y1;
    char y2;
    char y3;
    char y4;
    int  x;

    void getXAddress() { std::cout << "Address of y: " << &y << std::endl; }
};

struct S
{
    char   m0;
    double m1;
    short  m2;
    char   m3;
};

int main( int argc, char* argv[] )
{
    int  a    = 123;
    int* aPtr = &a;


    std::cout << "Address: " << aPtr << " Value: " << *aPtr << std::endl;
    aPtr += 4;   // Getting 16 bytes up in the memory.
                 // Command line arguments and env variables are in higher
                 // addresses than stack

    *aPtr = 3333;   // Setting argc (command line argument) to 3333
    std::cout << "Address: " << aPtr << " Value: " << *aPtr << std::endl;

    std::cout << "Argc: " << argc << " Argc Address: " << &argc << std::endl;
    std::cout << "Argc: " << argc << " Prog Address: " << &argv[ 0 ]
              << " Value: " << argv[ 0 ] << std::endl;
    std::cout << "Argc: " << argc << " Prog Address: " << &argv[ 1 ]
              << std::endl;

    std::cout << "---------------------" << std::endl;

    A aClass;
    std::cout << "Address of aClass: " << &aClass << std::endl;
    aClass.x  = 321;
    aClass.y  = 'S';
    aClass.y1 = 'S';
    aClass.y2 = 'S';
    aClass.y3 = 'S';
    std::cout << "Address of aClass.x: " << &( aClass.x ) << std::endl;
    std::cout << "Address of aClass.y: " << static_cast<void*>( &aClass.y )
              << std::endl;

    aPtr = &aClass.x;
    std::cout << "aPtr: " << *aPtr << std::endl;

    std::cout << "offset of char   m0 = " << offsetof( A, y ) << '\n'
              << "offset of double m1 = " << offsetof( A, x ) << '\n';
    std::cout << "--------------------------------" << std::endl;
    char* addressOfX = reinterpret_cast<char*>( &aClass ) + offsetof( A, x );
    std::cout << "AddressOfX: " << static_cast<void*>( addressOfX )
              << std::endl;

    std::cout << "offset of char   m0 = " << offsetof( S, m0 ) << '\n'
              << "offset of double m1 = " << offsetof( S, m1 ) << '\n'
              << "offset of short  m2 = " << offsetof( S, m2 ) << '\n'
              << "offset of char   m3 = " << offsetof( S, m3 ) << '\n';


    // Note: Padding happens in 4 byte steps.
    // Remove some y members and see that the starting of x will be moved 4bytes up or down
}