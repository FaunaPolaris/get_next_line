## get_next_line
### 42 network second project

char    *get_next_Line(int fd); 

### DESCRIPTION  

get_next_line() attempts to read from *fd* up to the next '\n' (newline) character.  

Only one file descriptor can be read at a time, once it reaches its final line, delimited by a '\0', get_next_line() will be able to read from a new fd.  
The macro BUFFER_SIZE is defined, it will tell the function the size of the buffer to use while calling the function read(); all remaining characters read will be stored into a static char.  

### RETURN  
    
On success, the next line of the current fd will be returned, or null after the last line is read or if the fd is invalid.  

### MAKE  

The Makefile for this project will have the all, clean and fclean rules, which will respectivelly:  
    - Compile a tester program which will receive a single parameter, open it as if it were a file and write it into STDOUT one line at a time;  
    - clean all objects created during compilation;  
    - clean all objects created during compilation as well as the program itslef.  

## Version History:  

- 1.0.0 final version to vogsphere
- 0.4.4 third.restart  
- 0.4.3 new_structure  
- 0.4.2 invalid_read  
- 0.4.1 no_nl.identifying  
- 0.3.4 memory.no_bytes_left  
- 0.3.2 memory.missingfree  
- 0.3.1 memory.grinding  
- 0.2.2 separation.Equallines  
- 0.2.1 structuring.Currentvalue  
- 0.1.3 learn_to_read.Schoolclosed  
- 0.1.2 learn_to_read.BUFFER_SIZE  
- 0.1.1 learn_to_read.Makefile  
