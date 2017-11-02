Name  : Zhewei Zhang
Date  : 10/17/2017
Class : CSC 0415-02

Compile Instructions:

  To compile my project, I need to open a command prompt and go to the directory where I have saved the file myshell.c.
  Then, I type "gcc myshell.c.c" and press enter to compile the code.
  If there are no errors, the command prompt will take me to the next line and would generate a.out executable file.

  To control compilation, I just need to open a text editor and type in "make".
  The command prompt will generate an executable file called "myshell".


Run Instructions:

  To run my porject, type "./a.out" to execute the project.Then, I just need to follow the output.
  There is also another way to run the project. I can also type "./myshell" and I will also get the same output.

Project Description:

  The project basically allows the user to run a simple shell by specifing the commands on their own.
  The shell reads lines of user input into a 256-­­byte buffer, then parse and execute the commands.
  The shell support the following functions:

    1.Execute a single command with up to four command line arguments
      (including command line arguments with associated flags). For example: Myshell> ./ls –l
      Myshell> cat myfile
      Myshell> ls –al /usr/src/linux

    2.Execute a command in background. For example:
      Myshell> ./ls -­­l &
      Myshell> ls –al /usr/src/linux &

    3.Redirect the standard output of a command to a file. For example:
      Myshell> ./ls -­­l > outfile
      Myshell> ./ls -­­l >> outfile
      Myshell> ls –al /usr/src/linux > outfile2 Myshell> ls –al /usr/src/linux >>outfile2

    4.Redirect the standard input of a command to come from a file. For example:
      Myshell> grep disk < outfile
      Myshell> grep linux < outfile2

    5.Execute multiple commands connected by a single shell pipe. For example:
      Myshell> ls –al /usr/src/linux | grep linux

Extra Credit Description: <if not attempted leave this here, otherwise replace>
