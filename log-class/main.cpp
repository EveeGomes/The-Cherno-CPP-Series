#include <iostream>

class Log
{
private:
   // this member variable will maintain what level the log is set
   int m_LogLevel;

public:
   void SetLevel(int level)
   {
      m_LogLevel = level;
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