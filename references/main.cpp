#include <iostream>

#define LOG(x) std::cout << x << std::endl;

// now, we can achieve the exactly SAME behavior using reference instead of pointer!
// the code syntax will look cleaner so that's why references are mostly used
// a reference works as an alias, and is also similar to how pointers work: they go to the address of the variable we want to perform some change/to access
void increment(int& value) // now the parameter is a reference of the variable being passed to the function!
{
   value++; // and here we can go back to a cleaner syntax since we already have the "real" variable in the function
}

int main()
{
   int a = 5;
   // also, when calling the function that has reference as parameter, we can pass the arg just as the variable identifier
   increment(a);
   LOG(a);

}