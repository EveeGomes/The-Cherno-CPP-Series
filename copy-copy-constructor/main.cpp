#include <iostream>
#include <string>

class String
{
private:
   char* m_Buffer;
   unsigned int m_Size;
public:
   // The constructor will take a const char that we'll call string:
   String(const char* string)
   {
      // we need the size of the string to allocate enough memory and copy the content to m_Buffer
      m_Size = strlen(string);
      m_Buffer = new char[m_Size]; // here we need [m_Size + 1] to give space for the null terminator character but for now it's left without it to test what happens
      
      // now we can copy what's in the string pointer into the m_Buffer pointer
      // this could be done using a for loop going through each char element but we can use memcpy:
      memcpy(m_Buffer, string, m_Size); // the size is in bytes! We use m_Size because we're dealing with char
   }
};

int main()
{

   std::cin.get();
}