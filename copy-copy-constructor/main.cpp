#include <iostream>
#include <string>

class String
{
private:
   char* m_Buffer;
   unsigned int m_Size;
public:
   String(const char* string)
   {
      m_Size = strlen(string);
      m_Buffer = new char[m_Size + 1]; // add 1 to allocate space for the null terminator character
  
      memcpy(m_Buffer, string, m_Size); // we could use strcpy which already includes the null terminator character!
      // and now add the null character (manually):
      m_Buffer[m_Size] = 0;
   }

   friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
   stream << string.m_Buffer;
   return stream;
}

int main()
{
   String string = "Cherno";
   std::cout << string << std::endl;
   std::cin.get();
}