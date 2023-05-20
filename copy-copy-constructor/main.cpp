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
      m_Buffer = new char[m_Size];
      
      memcpy(m_Buffer, string, m_Size);
   }
};

// To be able to print an object of String class, we overload the "print" operator (shift left <<)
std::ostream& operator<<(std::ostream& stream, const String& string)
{
   // first we call a method to put information into stream and then we return stream
   stream << string.GetBuffer();
   return stream;
}

int main()
{

   std::cin.get();
}