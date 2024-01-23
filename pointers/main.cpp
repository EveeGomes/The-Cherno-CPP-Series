#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main()
{

   int var = 8;

   // typeless pointer
   //void* ptr = nullptr;
   
   int* ptr = nullptr;
   
   // use & to extract the address of a variable and store into a pointer:
   ptr = &var;
   LOG(ptr);

   // use * with the pointer to extract the value that's inside the address it holds = dereference the pointer
   // however that only works if the pointer is of a certain type!!!!
   LOG(*ptr);

   // dereferencing the pointer also allows us to read or write from the memory address it holds?:
   *ptr = 10;
   LOG(*ptr);

   /*
   * The var is being created in the stack memory! Below we will be creating memory in the heap:
   */

   char* buffer = new char[8]; // 8 bytes of memory on the heap
   memset(buffer, '-', 8); // set these 8 bytes to hold '-'

   // pointer to a pointer: a double pointer that holds the address of another pointer
   char** cptr = &buffer;

   //LOG(*buffer); // -
   LOG(cptr);
   LOG(&buffer);

   //for (int i = 0; i < 8; i++) {
   //   LOG(*buffer); // - 8 times!
   //}


   // now delete the data allocated on the heap memory
   delete[] buffer;

}