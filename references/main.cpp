#include <iostream>

#define LOG(x) std::cout << x << std::endl;

// So instead of changing the copy (and end up with the real variable unchanged), we need to access what's stored in the specific address and made a change there! 
// ie. we need the address to be passed as arg of the function to perfom the real change.
// so we gotta work with a pointer (since it holds addresses):
void increment(int* value) // the parameter is a pointer; when calling this function the argument passed will be an address of the variable we want
{
   // we'll need to dereference the pointer; this is done by the * operator before the pointer identifier: *ptr
   // to dereference means we'll get the value from the address pointed by the pointer
   // if we do: *value++; due to the order of operations the increment will happen first, meaning we would be incrementing the POINTER
   // so to avoid that and actually increment the value, we'll use () to first dereference the pointer and then with the value return by that dereference we perfom the increment operation!
   (*value)++;
}

int main()
{
   int a = 5;
   // and here, we'll gotta pass the address of a variable to increment():
   increment(&a);
   LOG(a);

}