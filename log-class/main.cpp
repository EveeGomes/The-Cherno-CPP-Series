#include <iostream>

class Log
{

};

int main()
{
   // The best way to start writing a class is to think of its usage! What you need this class to do?
   // try making some examples in main function on how we'd might use this class!!

   // 1. instantiated
   Log log;
   // 2. set a log level
   log.SetLevel(LogLevelWarning); // warnings or errors, not tracing messages!
   // 3. log a warn
   log.Warn("Hello!");

   std::cin.get();
}