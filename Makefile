
all: skku_sh 
skku_sh: main.o File.o Directory.o Entry.o      
	g++ -W -Wall -o skku_sh main.o File.o Directory.o Entry.o
main.o: main.cc         
	g++ -W -Wall -c -o main.o main.cc
File.o: File.cc         
	g++ -W -Wall -c -o File.o File.cc
Directory.o: Directory.cc         
	g++ -W -Wall -c -o Directory.o Directory.cc
Entry.o: Entry.cc         
	g++ -W -Wall -c -o Entry.o Entry.cc  
clean:         
	rm -rf *.o skku_sh
