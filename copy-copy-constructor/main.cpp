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
      // proving it's copied:
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

void PrintStringByValue(String string)
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
   String string = "Cherno";  //Constructor
   String second = string;    //Copy constructor

   second[2] = 'a';

   // use PrintStringByValue instead and we see copies are done because we're passing by value, which is NOT what we want! We want as less copies as possible in our program!
   PrintStringByValue(string);   //Copy constructor, then Cherno and Destructor for the copy made in PrintStringByValue()
   PrintStringByValue(second);   //Copy constructor, then Charno and Destructor for the copy made in PrintStringByValue()

   /*std::cout << string << std::endl;
   std::cout << second << std::endl;*/

   
} //Destructor called for each and every object that are still in the program