#include "Entry.h"
#include "Directory.h"
#include "File.h"

#include <sstream>
#include <string>

//This function finds directory with the given name(2nd argument) from the given path(1st argument)
//For example below finds "world" directory from the root directory
//find_directory(&root, "world");
Entry* find_directory(Directory* root, const std::string& path)
{
    //Implement your code here.
    //Leverage find member function.
    //...
	if (path == root->name()){
	return root;
	}
    
	Entry* result = root->find(path);

return result;
}

void makeTree(Entry* root, int offset = 0){
Directory* directtype = dynamic_cast<Directory*>(root);
File* filetype = dynamic_cast<File*>(root);
	
	if (directtype!= NULL){
		
		if (directtype->count() == 0){
			offset+=3;
			for (int loop=0; loop<offset; loop++)
				std::cout << " ";
			std::cout << "* " << directtype->name() <<std::endl;
		}
		
		else {
			Entry* out;
			std::string refer,temp;
			refer = directtype->content();
			std::string entryCheck[9];
  			int posit=-1,start=0,location=0;
  			temp="/";
  			location=refer.find(temp);
  	
  			if (location == -1){
  				posit++;
  				entryCheck[posit]=refer;
  			}
  	
  			else {
  				while (location != -1){
  					posit++;
  					entryCheck[posit]=refer.substr(start,location-start);
  					start = location+1;
  					location=refer.find(temp,location+1);
  				}
  			posit++;
  			entryCheck[posit]=refer.substr(start, refer.size()-start+1);
  			}
  			
  			offset+=3;
  			for (int loop=0; loop<offset; loop++)
					std::cout << " ";
  			std::cout << "* " << directtype->name() <<std::endl;
  			
  			for (int loop=0; loop<=posit; loop++){
  				out = find_directory(directtype,entryCheck[loop]);
  				makeTree(out,offset);
  			}
		}
	}
	
	else if (filetype != NULL){
		offset+=2;
		for (int loop=0; loop<offset; loop++)
				std::cout << " ";
  		std::cout << "* " << filetype->name() <<std::endl;
	}
	
	else
		std::cout << "error create tree" << std::endl;
}

void exec_cmd(Directory* root,std::string cmd)
{
  //*****Do NOT MODIFY START*****
  std::istringstream iss1(cmd),iss2(cmd);
  std::string token;
  std::getline(iss2,token,' ');
  std::getline(iss1,token,' ');
  //*****DO NOT MODIFY END*****

  //Implement your code here
  //...
  std::string locate, target,temp=" ";
  int location=iss1.str().find(temp), secLocat;
  secLocat = iss2.str().find(temp,location+1);
  
  if (location != -1 && secLocat != -1){
  locate = iss1.str().substr(location+1,secLocat-location-1);
  target = iss2.str().substr(secLocat+1, iss2.str().length()-secLocat);
  }
  
  else if (location != -1 && secLocat == -1){
  locate = iss1.str().substr(location+1,iss1.str().length()-location);
  }
  
  if (token=="ls"){ 
  Entry* res;
  
  	std::string direction[9];
  	int pos=-1,initial=0;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	Directory* temp = root;
	if (direction[0] == root->name()){ 
		
		if (pos > 0){ 
			res = find_directory(temp,direction[1]);
			Directory* direct = dynamic_cast<Directory*>(res);
			for (int loop=2; loop <=pos; loop++){ 
				res = find_directory(direct,direction[loop]);
				direct = dynamic_cast<Directory*>(res);
			}
			
			File* printing;
			Entry* transfer;
			Directory* copied;
			copied = direct;
			
			if (copied != NULL){
				if (copied->count()>0){
					for (int loop=0; loop< (int)copied->count(); loop++){
						if (direct != NULL){
  							direct->print(std::cout,loop);
  						}
  				
  						else if (direct == NULL){ 
  							transfer = dynamic_cast<Entry*>(direct);
							printing = dynamic_cast<File*>(transfer);
					
							if (printing != NULL){
								printing->print(std::cout,loop);
							}
					
							else
								std::cout << "invalid file type" << std::endl;
  						}	
  					}
  				}
  			
  				else
  					std::cout << std::endl;
  			}
  			
  			else
  				goto jump;
		}
		
		else if (pos == 0){
  			res = find_directory(temp,direction[0]);
  			Directory* direct = dynamic_cast<Directory*>(res); 


  			File* printing;
			Entry* transfer;
			Directory* copied = direct;
			
			if (copied != NULL){
				if (copied->count()>0){
					for (int loop=0; loop<(int)copied->count(); loop++){
						if (direct != NULL){
  							direct->print(std::cout,loop);
  						}
  				
  						else if (direct == NULL){ 
  							transfer = dynamic_cast<Entry*>(direct);
							printing = dynamic_cast<File*>(transfer);
					
							if (printing != NULL){
								printing->print(std::cout,loop);
							}
					
							else
								std::cout << "invalid file type" << std::endl;
  						}	
  					}
  				}
  			
  				else
  					std::cout << std::endl;
  			}
  			
  			else
  				goto jump;
  		}
  	}
  	
  	else{
  		jump:
  		std::cout << "no such directory" << std::endl;
  	}
  std::cout << std::endl;
  }
  
  else if (token=="mkdir"){
  Entry* res;
  	std::string direction[9];
  	int pos=-1,initial=0;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	Directory* copied = root;
  	if (direction[0] == root->name() && pos>0){
  		res = find_directory(copied,direction[0]);
  		Directory* direct = dynamic_cast<Directory*>(res);
  		
  		for (int rep=1; rep <=pos-1; rep++){
  			res = find_directory(direct,direction[rep]);
  			direct = dynamic_cast<Directory*>(res);
  		}
  		

  		direct = dynamic_cast<Directory*>(res);
  		
  		if (direct != NULL){
  			std::string refer;
			refer = direct->content();
			std::string entryCheck[9];
  			int posit=-1,start=0;
  			temp="/";
  			location=refer.find(temp);
  	
  			if (location == -1){
  				posit++;
  				entryCheck[posit]=refer;
  			}
  	
  			else {
  				while (location != -1){
  					posit++;
  					entryCheck[posit]=refer.substr(start,location-start);
  					start = location+1;
  					location=refer.find(temp,location+1);
  				}
  				posit++;
  				entryCheck[posit]=refer.substr(start, locate.size()-start+1);
  			}
  			
  			for (int loop=0; loop < (int)direct->count(); loop++){
  				if (direction[pos] == entryCheck[loop]){
  					std::cout << "directory already exists" << std::endl;
  					goto hop;
  				}
  			} 
			
  			direct->add(new Directory(direction[pos]));
  			hop:
  			temp="/"; //dummy
  		}
  		
  		else
  			std::cout << "invalid directory" << std::endl;
  	}
  	
  	else
  		std::cout << "can't create new root" << std::endl;
  }
  
  else if (token=="tree"){
  	Entry* res;
  	std::string direction[9];
  	int pos=-1,initial=0;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	Directory* copied = root;
	if (direction[0] == root->name()){
		res = find_directory(copied,direction[0]);
		Directory* direct = dynamic_cast<Directory*>(res);
		for (int loop=1; loop <=pos; loop++){
			res = find_directory(direct,direction[loop]);
			direct = dynamic_cast<Directory*>(res);
		}
		
		if (direct!=NULL){
			copied = direct;                                              
			std::string refer;
			refer = direct->content();
			std::string entryCheck[9];
  			int posit=-1,start=0;
  			temp="/";
  			location=refer.find(temp);
  	
  			if (location == -1){
  				posit++;
  				entryCheck[posit]=refer;
  			}
  	
  			else {
  				while (location != -1){
  					posit++;
  					entryCheck[posit]=refer.substr(start,location-start);
  					start = location+1;
  					location=refer.find(temp,location+1);
  				}
  			posit++;
  			entryCheck[posit]=refer.substr(start, refer.size()-start+1);
  			}                                                            
  		
			std::cout << "* " << direct->name() << std::endl;
			
			res = find_directory(copied,copied->name());
			direct = dynamic_cast<Directory*>(res);
			
			if (direct!=NULL){
				File* printing;
				for (int loop=0; loop <= posit; loop++){
					res = find_directory(copied,entryCheck[loop]);
					direct = dynamic_cast<Directory*>(res);
				
					if (direct != NULL){
						makeTree(res);
					}
				
					else {
						printing = dynamic_cast<File*>(res);
				
						if (printing != NULL){
							makeTree(res);
						}
					
						else
							std::cout <<  std::endl;
					}
				}
			}
			
			else
				goto no;
		}
		
		else
			goto no;
	}
	
	else{
		no:
		std::cout << "no such directory" << std::endl;
	}
	
	std::cout << std::endl;
  }
  
  else if (token=="cat"){
  	Entry* res;
  	std::string direction[9];
  	int pos=-1,initial=0;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	Directory* copied = root;
  	if (direction[0] == root->name() && pos>0){
  		res = find_directory(copied,direction[0]);
  		Directory* direct = dynamic_cast<Directory*>(res);
  		
  		for (int rep=1; rep <=pos-1; rep++){
  		res = find_directory(direct,direction[rep]);
  		direct = dynamic_cast<Directory*>(res);
  		}
  	
  		if (direct->count()>0){
  			std::string refer;
			refer = direct->content();
			std::string entryCheck[9];
  			int posit=-1,start=0;
  			temp="/";
  			location=refer.find(temp);
  	
  			if (location == -1){
  				posit++;
  				entryCheck[posit]=refer;
  			}
  	
  			else {
  				while (location != -1){
  					posit++;
  					entryCheck[posit]=refer.substr(start,location-start);
  					start = location+1;
  					location=refer.find(temp,location+1);
  				}
  				posit++;
  				entryCheck[posit]=refer.substr(start, locate.size()-start+1);
  			}
  			
  			for (int loop=0; loop<(int)direct->count();loop++){
  				if (entryCheck[loop] == direction[pos]){
  					Entry* out = find_directory(direct, direction[pos]);
  					File* printing = dynamic_cast<File*>(out);
  					
  					if (printing != NULL){
  						std::cout << printing->content() << std::endl;
  						goto here;
  					}
  				}	
  			}
  			
  			goto unavailable;
  			here:
  			temp="/"; //dummy
  		}
  		
  		else
  			goto unavailable;
  	}
  	
  	else{
  		unavailable:
  		std::cout << "no such file" << std::endl;
  	}
  std::cout << std::endl;
  }
  
  else if (token=="touch"){
  	Entry* res;
  	std::string direction[9];
  	int pos=-1,initial=0;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	Directory* copied = root;
	if (direction[0] == root->name()){
		res = find_directory(copied,direction[0]);
		Directory* direct = dynamic_cast<Directory*>(res);
		for (int loop=1; loop <=pos-1; loop++){
			res = find_directory(direct,direction[loop]);
			direct = dynamic_cast<Directory*>(res);
		}
		
		if (direct != NULL){
			std::string refer;
			refer = direct->content();
			std::string entryCheck[9];
	  		int posit=-1,start=0;
	  		temp="/";
	  		location=refer.find(temp);
	  	
	  		if (location == -1){
	  			posit++;
	  			entryCheck[posit]=refer;
	  		}
	  	
	  		else {
	  			while (location != -1){
	  				posit++;
	  				entryCheck[posit]=refer.substr(start,location-start);
	  				start = location+1;
	  				location=refer.find(temp,location+1);
	  			}
	  			posit++;
	  			entryCheck[posit]=refer.substr(start, locate.size()-start+1);
	  		}
	  		
	  		if (pos > 0){
				for (int loop=0; loop <(int)direct->count(); loop++){
					if (direction[pos] == entryCheck[loop]){
						std::cout << "file already exists" << std::endl;
						goto skip;
					}
				}
				
				Entry* convert;
				File* insert = new File(direction[pos]);
				convert = dynamic_cast<Entry*>(insert);
				direct->add(convert);
			}
			
			else
				std::cout << "Insert file name" << std::endl;
			
			skip:
			temp="/"; //dummy
		}
		
		else
			std::cout << "invalid directory" << std::endl;
	}
	
	else
		std::cout << "invalid root" << std::endl;
  }
  
  else if (token=="echo"){
	Entry* res;
  	std::string direction[9];
  	int pos=-1,initial=0;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	Directory* copied = root;
	if (direction[0] == root->name()){
		res = find_directory(copied,direction[0]);
		Directory* direct = dynamic_cast<Directory*>(res);
		for (int loop=1; loop <=pos-1; loop++){
			res = find_directory(direct,direction[loop]);
			direct = dynamic_cast<Directory*>(res);
		}
		
		if (direct != NULL){
			std::string refer;
			refer = direct->content();
			std::string entryCheck[9];
	  		int posit=-1,start=0;
	  		temp="/";
	  		location=refer.find(temp);
	  	
	  		if (location == -1){
	  			posit++;
	  			entryCheck[posit]=refer;
	  		}
	  	
	  		else {
	  			while (location != -1){
	  				posit++;
	  				entryCheck[posit]=refer.substr(start,location-start);
	  				start = location+1;
	  				location=refer.find(temp,location+1);
	  			}
	  			posit++;
	  			entryCheck[posit]=refer.substr(start, locate.size()-start+1);
	  		}
	  		
	  		if (pos > 0){
				for (int loop=0; loop <(int)direct->count(); loop++){
					if (direction[pos] == entryCheck[loop]){
						res = find_directory(direct,direction[pos]);
						File* update = dynamic_cast<File*>(res);
						update->content(target);                                        
						std::cout << "Content updated!" << std::endl;
						std::cout << std::endl;
						goto proceed;
					}
				}
				
				Entry* convert;
				File* insert = new File(direction[pos],target);
				convert = dynamic_cast<Entry*>(insert);
				direct->add(convert);
			}
			
			else
				std::cout << "Insert file name" << std::endl;
			
			proceed:
			temp="/"; //dummy
		}
		
		else
			std::cout << "invalid directory" << std::endl;
	}
	
	else
		std::cout << "invalid root" << std::endl;	
  }
  
  else if (token=="rm"){
  	Entry* res;
  	std::string direction[9];
  	int pos=-1,initial=0;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	Directory* copied = root;
	if (direction[0] == root->name()){
		res = find_directory(copied,direction[0]);
		Directory* direct = dynamic_cast<Directory*>(res);
		for (int loop=1; loop <=pos-1; loop++){
			res = find_directory(direct,direction[loop]);
			direct = dynamic_cast<Directory*>(res);
		}
		
		if (direct != NULL){
			std::string refer;
			refer = direct->content();
			std::string entryCheck[9];
	  		int posit=-1,start=0;
	  		temp="/";
	  		location=refer.find(temp);
	  	
	  		if (location == -1){
	  			posit++;
	  			entryCheck[posit]=refer;
	  		}
	  	
	  		else {
	  			while (location != -1){
	  				posit++;
	  				entryCheck[posit]=refer.substr(start,location-start);
	  				start = location+1;
	  				location=refer.find(temp,location+1);
	  			}
	  			posit++;
	  			entryCheck[posit]=refer.substr(start, locate.size()-start+1);
	  		}
	  		
	  		
	  		if (pos > 0){
				for (int loop=0; loop <(int)direct->count(); loop++){
					if (direction[pos] == entryCheck[loop]){
						res = find_directory(direct,direction[pos]);
						File* update = dynamic_cast<File*>(res);
						
						if (update!=NULL){
							direct->remove(direction[pos]);
							delete update;
							update = nullptr;
							
							goto ahead;
						}	
					}
				}
				
				std::cout << "no such file" << std::endl;
			}
			
			else
				std::cout << "Insert file name" << std::endl;
			
			ahead:
			temp="/"; //dummy
		}
		
		else
			std::cout << "invalid directory" << std::endl;
	}
	
	else
		std::cout << "no such file" << std::endl;
  }
  
  else if (token=="rmdir"){
  	Entry* res;
  	std::string direction[9];
  	int pos=-1,initial=0;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	Directory* copied = root;
	if (direction[0] == root->name()){
		res = find_directory(copied,direction[0]);
		Directory* direct = dynamic_cast<Directory*>(res);
		for (int loop=1; loop <=pos-1; loop++){
			res = find_directory(direct,direction[loop]);
			direct = dynamic_cast<Directory*>(res);
		}
		
		if (direct != NULL){
			std::string refer;
			refer = direct->content();
			std::string entryCheck[9];
	  		int posit=-1,start=0;
	  		temp="/";
	  		location=refer.find(temp);
	  	
	  		if (location == -1){
	  			posit++;
	  			entryCheck[posit]=refer;
	  		}
	  	
	  		else {
	  			while (location != -1){
	  				posit++;
	  				entryCheck[posit]=refer.substr(start,location-start);
	  				start = location+1;
	  				location=refer.find(temp,location+1);
	  			}
	  			posit++;
	  			entryCheck[posit]=refer.substr(start, locate.size()-start+1);
	  		}
	  		
	  		
	  		if (pos > 0){
				for (int loop=0; loop <(int)direct->count(); loop++){
					if (direction[pos] == entryCheck[loop]){
						res = find_directory(direct,direction[pos]);
						Directory* update = dynamic_cast<Directory*>(res);
						
						if (update!=NULL){
							direct->remove(direction[pos]);
							delete update;
							update = nullptr;
							
							goto forward;
						}
						
						std::cout << "no such directory" << std::endl;
						goto forward;	
					}
				}
				
				std::cout << "no such directory" << std::endl;
			}
			
			else
				std::cout << "Insert directory name" << std::endl;
			
			forward:
			temp="/"; //dummy
		}
		
		else
			std::cout << "invalid directory" << std::endl;
	}
	
	else
		std::cout << "invalid root" << std::endl;
  }
  
  else if (token=="cp"){
  	Entry* res;
  	std::string direction[9];
  	int pos=-1,initial=0,location;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	std::string place[9];
  	int amt=-1,origin=0,check=0;
  	temp="/";
  	location=target.find(temp);
  	
  	if (location == -1){
  	amt++;
  	place[amt]=target;
  	}
  	
  	else {
  		while (location != -1){
  		amt++;
  		place[amt]=target.substr(origin,location-origin);
  		origin = location+1;
  		location=target.find(temp,location+1);
  		}
  		
  		amt++;
  		place[amt]=target.substr(origin, target.size()-origin);
  	}
  	
  	Directory* copied = root;
	if (direction[0] == root->name()){
		res = find_directory(copied,direction[0]);
		Directory* direct = dynamic_cast<Directory*>(res);
		for (int loop=1; loop <=pos; loop++){
			if (direct == NULL){
				check=1;
				break;
			}
			res = find_directory(direct,direction[loop]);
			direct = dynamic_cast<Directory*>(res);
		}
		File* hold = dynamic_cast<File*>(res);
		
		if (direct != NULL){
			
			if (place[0] == root->name()){
				res = find_directory(copied,place[0]);
				Directory* move = dynamic_cast<Directory*>(res);
				for (int loop=1; loop <=amt; loop++){
					res = find_directory(move,place[loop]);
					move = dynamic_cast<Directory*>(res);
				}
				
				if (move != NULL){
					move->add(dynamic_cast<Directory*>(direct->clone()));
				}
				
				else
					goto other;
			}
			
			else
				goto other;
		}
		
		else{
			if (hold != NULL && check ==0){
				if (place[0] == root->name()){
					res = find_directory(copied,place[0]);
					Directory* move = dynamic_cast<Directory*>(res);
					for (int loop=1; loop <=amt; loop++){
						res = find_directory(move,place[loop]);
						move = dynamic_cast<Directory*>(res);
					}
					
					if (move != NULL){
						move->add(dynamic_cast<Entry*>(hold->clone()));
					}
					
					else
						goto other;
				}
				
				else
					goto other;
			}
			
			else{
				check=0;
				other:
				std::cout << "no such file or directory" << std::endl;
			}	
		}
	}
	
	else
		std::cout << "no such file or directory" << std::endl;
  }
  
  else if (token=="mv"){
  	Entry* res;
  	std::string direction[9];
  	int pos=-1,initial=0,location;
  	temp="/";
  	location=locate.find(temp);
  	
  	if (location == -1){
  	pos++;
  	direction[pos]=locate;
  	}
  	
  	else {
  		while (location != -1){
  		pos++;
  		direction[pos]=locate.substr(initial,location-initial);
  		initial = location+1;
  		location=locate.find(temp,location+1);
  		}
  		
  		pos++;
  		direction[pos]=locate.substr(initial, locate.size()-initial);
  	}
  	
  	std::string place[9];
  	int amt=-1,origin=0,check=0;
  	temp="/";
  	location=target.find(temp);
  	
  	if (location == -1){
  	amt++;
  	place[amt]=target;
  	}
  	
  	else {
  		while (location != -1){
  		amt++;
  		place[amt]=target.substr(origin,location-origin);
  		origin = location+1;
  		location=target.find(temp,location+1);
  		}
  		
  		amt++;
  		place[amt]=target.substr(origin, target.size()-origin);
  	}
  	
  	Directory* copied = root;
	if (direction[0] == root->name()){
		res = find_directory(copied,direction[0]);
		Directory* direct = dynamic_cast<Directory*>(res);
		for (int loop=1; loop <= pos; loop++){
			if (direct == NULL){
				check=1;
				break;
			}
			res = find_directory(direct,direction[loop]);
			direct = dynamic_cast<Directory*>(res);
		}
		File* hold = dynamic_cast<File*>(res);
		
		if (direct != NULL){
			Entry* transfer = direct->clone();                                                 
			
			Entry* res2 = find_directory(copied,direction[0]);
			Directory* direct2 = dynamic_cast<Directory*>(res2);
			for (int loop=1; loop < pos; loop++){
				res2 = find_directory(direct2,direction[loop]);
				direct2 = dynamic_cast<Directory*>(res2);
			}
			
			
			if (place[0] == root->name()){
				res = find_directory(copied,place[0]);
				Directory* move = dynamic_cast<Directory*>(res);
				for (int loop=1; loop <=amt; loop++){
					res = find_directory(move,place[loop]);
					move = dynamic_cast<Directory*>(res);
				}
				
				if (move != NULL){
					move->add(dynamic_cast<Directory*>(transfer));
					direct2->remove(direction[pos]);
				}
				
				else
					goto last;
			}
			
			else
				goto last;
		}
		
		else{
			if (hold != NULL && check ==0){
				Entry* res2 = find_directory(copied,direction[0]);
				Directory* direct2 = dynamic_cast<Directory*>(res2);
				for (int loop=1; loop < pos; loop++){
					res2 = find_directory(direct2,direction[loop]);
					direct2 = dynamic_cast<Directory*>(res2);
				}
				
				if (place[0] == root->name()){
					res = find_directory(copied,place[0]);
					Directory* move = dynamic_cast<Directory*>(res);
					for (int loop=1; loop <=amt; loop++){
						res = find_directory(move,place[loop]);
						move = dynamic_cast<Directory*>(res);
					}
					
					if (move != NULL){
						move->add(dynamic_cast<Entry*>(hold->clone()));
						direct2->remove(direction[pos]);
					}
					
					else
						goto last;
				}
				
				else
					goto last;
			}
			
			else{
				check=0;
				last:
				std::cout << "no such file or directory" << std::endl;
			}	
		}
	}
	
	else
		std::cout << "no such file or directory" << std::endl;
  }
  
  else if (token=="quit"){
  exit(0);
  }
  
  else{
  	std::cout << "invalid instruction" << std::endl;
  	std::cout << std::endl;
  }
}


int main()
{
  //*****Do NOT MODIFY START*****
    Directory root("root");
    root.add(new Directory("hello"));
    std::cout << root << std::endl; //this prints all the directories and files in root directory. (the result of tree command)

    std::string inputBuffer;
    while(1){
      std::getline(std::cin,inputBuffer);
      if(inputBuffer.compare("exit")==0) break;
      exec_cmd(&root,inputBuffer);
    }
  //*****DO NOT MODIFY END*****

}
