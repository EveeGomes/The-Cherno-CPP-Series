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
   String second = string; // try to copy but this won't work because it'll perform a shallow copy and when the code comes to the end and destructor is called, it'll try to delete the same allocated memory (pointer by m_Buffer) twice!

   std::cout << string << std::endl;
   std::cout << second << std::endl;

   //std::cin.get();
}