#include "Entry.h"

Entry::~Entry() = default;

//overload << operator here
std::ostream& operator<<(std::ostream& os, const Entry& entry)
{
  //Implement your code here
  //...
  os << "* " << entry.name() << std::endl;
  
  std::string directories = entry.content();
  
  os << "   * " << directories << std::endl;
  
  return os;
}


