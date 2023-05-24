#include <iostream>

class Log
{
public:
   void SetLevel(int level)
   {

   }

   void Warn(const char* message)
   {

   }
};

int main()
{
   Log log;
   log.SetLevel(LogLevelWarning);
   log.Warn("Hello!");

   std::cin.get();
}