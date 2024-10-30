#include "Directory.h"

#include <iomanip>
#include <sstream>

//DO NOT MODIFY THIS START
Entry* Directory::clone() const
{
    return new Directory(*this);
}
//DO NOT MODIFY THIS END

//Implement constructor, destructor, member functions of the Directory class.
//...

bool Directory::add(Entry* entry){
count_++;
entries_[count_-1]=entry;
return true;
}

size_t Directory::count() const{
return count_;
}

void Directory::print(std::ostream& os, size_t indent) const{
os << entries_[indent]->name()<<std::endl;
}

std::string Directory::content() const{
std::string result;
 
for (int loop=0;loop<(int)count_;loop++){
result+=entries_[loop]->name();
result+="/";
}

result = result.substr(0,result.length()-1);
  
return result;
}

const std::string& Directory::name() const{
return name_;
}

Directory::~Directory(){
for (int l=0; l<int(count_); l++){
	delete entries_[l];
	entries_[l] = nullptr;
}
}

Directory::Directory(const std::string& name){
name_ = name;
count_=0;
}

Directory::Directory(const Directory& o){
name_ = o.name();
for (int y=0;y<(int)o.count();y++){
this->entries_[y]= o.entries_[y]->clone();
}
this->count_ = o.count();
}

Entry* Directory::find(const std::string& name){

for (int z=0;z<(int)count_;z++){
	if (entries_[z]->name() == name){
		return entries_[z];
		}
}
return nullptr;
}

Entry* Directory::remove(const std::string& name){
int l,z=0,check=0;
	for (l=0; l<int(count_); l++){
		if (entries_[l]->name() == name){
			check=1;
			break;
		}
	}
	
	if (check == 1){
		Entry* temp = dynamic_cast<Entry*>(entries_[l]);
		for (z=l; z<int(count_); z++){
			if (entries_[z+1] != NULL)
				entries_[z] = entries_[z+1];
		}
		delete entries_[z];
		entries_[z] = nullptr;
		count_--;
		check =0;
		return temp;
	}
	
	return nullptr;
}



