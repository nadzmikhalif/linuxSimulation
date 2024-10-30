# linuxSimulation

This is a simulation of the Linux environment to better understand how Linux commands work. This project is made in C++ code so any additional library regarding the langugage must be installed before-hand.

The commands implemented in the project are:
  -> mkdir 
    Input Format : command path/directoryName (i.e., mkdir root/path/to/dir)
    Function: Make new directory
    
  -> touch
    Input Format : command path/fileName (i.e.,touch root/path/to/file)
    Function: Create an empty file
    
  -> echo
    Input Format : command path/fileName content (i.e., echo root/path/to/file hello world)
    Function: Overwrite the file content with the value provided or if the file does not exist, it creates a new one with the contents given
  
  -> ls
    Input Format : command path/directoryName (i.e., ls root/path/to/dir)
    Function: Print all files and directories in that directory
    
  -> tree
    Input Format : command path/directory (i.e., tree root/path/to/dir)
    Function: Print all files and directories under the given directory
    
  -> cat
    Input Format : command path/fileName (i.e., cat root/path/to/file)
    Function: Print the content of that file
    
  -> mv
    Input Format : command source_path/(fileName||directoryName) destination_ path/directoryName  (i.e., mv root/path/to/src_dir root/path/to/dst_dir)
    Function:  Move source file or directory to the destination directory
    
  -> cp
    Input Format : command source_path/(fileName||directoryName) destination_ path/directoryName (i.e., cp root/path/to/src_dir root/path/to/dst_dir)
    Function:  Copy the source file or directory to the destination directory
    
  -> rmdir
    Input Format : command path/directoryName (i.e., rmdir root/path/to/dir)
    Function:  Remove the given directory
    
  -> rm
    Input Format : command path/fileName (i.e., rm root/path/to/file)
    Function:  Remove the given file if the file exists in the specified path

To run the project, utilise the Makefile by typing as shown below:
  1) make runSimulation
  2) ./runSimulation
