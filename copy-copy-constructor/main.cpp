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
      m_Buffer = new char[m_Size + 1];
      memcpy(m_Buffer, string, m_Size);
      m_Buffer[m_Size] = 0;
   }

   ~String()
   {
      delete[] m_Buffer;
   }

   char& operator[](unsigned int index)
   {
      // we won't do validation/safety check to see if it's inside the bounds...
      return m_Buffer[index];
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
   String second = string;

   // to try this:
   second[2] = 'a';
   // we need to overload the [] operator
   // this operator needs to return a char reference in order to be set to a value we want (in this case a)
   // in fact when we use like that it'll call the overloaded function we'll write that will do the operations we need here, which is set a char value to another value we're passing
   // so the overloaded [] operator function will accept an integer and return a character in the m_Buffer string at the location represented by the integer!

   std::cout << string << std::endl;
   std::cout << second << std::endl;

   //std::cin.get();
}