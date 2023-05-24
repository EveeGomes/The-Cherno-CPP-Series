#include <iostream>

class Log
{
public:
   const int LogLevelError = 0;
   const int LogLevelWarning = 1;
   const int LogLevelInfo = 2;

private:
   int m_LogLevel = LogLevelInfo;

public:
   void SetLevel(int level)
   {
      m_LogLevel = level;
   }

   // add in each of these methods an if statement to validate whether the message should be printed!
   // We gotta check if m_LogLevel is set to the appropriate log level of that particular method.

   void Error(const char* message)
   {
      if(m_LogLevel >= LogLevelError) 
         std::cout << "[ERROR]: " << message << std::endl;
   }

   void Warn(const char* message)
   {
      if (m_LogLevel >= LogLevelWarning)
         std::cout << "[WARNING]: " << message << std::endl;
   }

   void Info(const char* message)
   {
      if (m_LogLevel >= LogLevelInfo)
         std::cout << "[INFO]: " << message << std::endl;
   }
};

int main()
{
   Log log;
   log.SetLevel(log.LogLevelWarning);
   log.Warn("Hello!");
   log.Error("Hello!");
   log.Info("Hello!");

   std::cin.get();
}