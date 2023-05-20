#include <iostream>
#include <string>

struct Vector2
{
   float x, y;
};

int main()
{
   Vector2 a = { 2, 3 };
   Vector2 b = a;
   b.x = 5;

   std::cin.get(); // the program waits us to press enter to close :)
}