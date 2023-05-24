#include <iostream>

class Log
{
public:
   // these variables help us on not having to memorize what each 0, 1, 2 mean!
   const int LogLevelError = 0;
   const int LogLevelWarning = 1;
   const int LogLevelInfo = 2;

private:
   int m_LogLevel = LogLevelInfo; // by default everything should get printed

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