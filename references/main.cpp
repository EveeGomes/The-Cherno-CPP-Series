#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void increment(int value)
{
   // passing by value is the same as the creating a copy of the value inside the function and using this copy instead of the variable passed
   // int value = 5;
   value++;
}

int main()
{
   int a = 5;
   increment(a);
   LOG(a);

}