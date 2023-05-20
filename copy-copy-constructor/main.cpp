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

   // Copy constructor takes as arg a reference to an object of the same class (here we create another object that'll take the same content as the other one)
   String(const String& other)
      :m_Size(other.m_Size) //shallow copy m_Size because it's just an integer!
   {
      // however, we need more than just a shallow copy. We need don't just need the pointer, but the memory at the pointer!
      // so we allocate memory for this new object
      m_Buffer = new char[m_Size + 1];
      memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // + 1 can be placed here becase we already know the reference object has a null terminator character (since it's a String and we've put that in the contructor! :) )

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