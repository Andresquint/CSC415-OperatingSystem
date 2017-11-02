1. How to build the program:

  To build the program, I need to open a command prompt and go to the directory where I have saved the file hello.c.
  Then, I type "gcc hello.c" and press enter to compile the code.
  If there are no errors, the command prompt will take me to the next line and would generate a.out executable file.

  After a.out file is generated, I also need to create a make file to control compilation.
  To create the make file, I just open a text editor and create a new file called "Makefile".
  Then, I type in:

    hello: hello.o
      gcc hello.o -o hello

    hello.o: hello.c
      gcc -c hello.c

    clean:
      rm -rf *o hello

  and save the file. Then, I open a command prompt and go to the directory where I have saved the make file.
  I type "make", and the command prompt will generate an object file called "hello.o" and an executable file called "hello".

2. How to run the program:

  To run the program, type "./a.out" to execute the program. Then, I see the output "CSC415, This program written by Zhewei Zhang".
  There is also another way to run the program. I can also type "./hello" and I will also get the same output.

3. What the program does:

  The program basically reads and formats the String "CSC415, This program written by Zhewei Zhang" into a buffer by using sprintf() function,
  then, the program outputs the String "CSC415, This program written by Zhewei Zhang" from the buffer we created by using write() function.
  That's it.
