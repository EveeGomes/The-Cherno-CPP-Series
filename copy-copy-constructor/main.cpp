#include <iostream>
#include <string>

int main()
{
   int a = 2;
   int b = a; // this is a copy. But both variables are different!
   //They each have an address in memory. The proof is that if changing the value of b, a won't be affected:
   b = 5;
}