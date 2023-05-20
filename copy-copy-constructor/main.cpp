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

   // Copy constructor takes as arg a reference to an object of the same class
   String(const String& other)   
   {
      // or the same:
      memcpy(this, &other, sizeof(String));
   }

   ~String()
   {
      delete[] m_Buffer;
   }

   char& operator[](unsigned int index)
   {
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

   second[2] = 'a';

   std::cout << string << std::endl;
   std::cout << second << std::endl;

   //std::cin.get();
}