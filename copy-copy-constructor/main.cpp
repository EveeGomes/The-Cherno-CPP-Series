#include <iostream>
#include <string>

struct Vector2
{
   float x, y;
};

int main()
{
   // do heap allocation with new keyword
   Vector2* a = new Vector2();
   // now the below code is copying the pointer instead of the value, so it's a different thing!
   Vector2* b = a;

   // so if we access b and change any value there, it'll also affect a because they're pointers pointing to the same address:
   b->x = 2; // will affect a.x value as well!

   std::cin.get();
}