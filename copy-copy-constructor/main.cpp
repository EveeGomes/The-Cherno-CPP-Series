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
      std::cout << "Constructor" << std::endl;
      m_Size = strlen(string);
      m_Buffer = new char[m_Size + 1];
      memcpy(m_Buffer, string, m_Size);
      m_Buffer[m_Size] = 0;
   }

   String(const String& other)
      :m_Size(other.m_Size)
   {
      std::cout << "Copy constructor!" << std::endl;
      m_Buffer = new char[m_Size + 1];
      memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
   }

   ~String()
   {
      std::cout << "Destructor" << std::endl;
      delete[] m_Buffer;
   }

   char& operator[](unsigned int index)
   {
      return m_Buffer[index];
   }

   friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

void PrintStringByReference(const String& string)
{
   std::cout << string << std::endl;
}

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

   PrintStringByReference(string);
   PrintStringByReference(second);

   /*std::cout << string << std::endl;
   std::cout << second << std::endl;*/  
}