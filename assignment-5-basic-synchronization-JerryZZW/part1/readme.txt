Name  : Zhewei Zhang
Date  : 11/08/2017
Class : CSC415-02

Compile Instructions:

  To compile my project, I need to open a command prompt and go to the directory where I have saved the file pthread_race.c.
  Then, I type "gcc pthread_race.c" and press enter to compile the code.
  If there are no errors, the command prompt will take me to the next line and would generate a.out executable file.

  To control compilation, I just need to open a text editor and type in "make".
  The command prompt will generate an executable file called "threadracer".

Run Instructions:

  To run my porject, type "./a.out" to execute the project.Then, I just need to follow the output.
  There is also another way to run the project. I can also type "./threadracer" and I will also get the same output.

Project Description:

  The program basically creates a group of 10 threads that share a single integer variable.
  Each thread will increment the shared variable by 10.
  Since these threads are synchronized, there is no possibility of race conditions occurring.
  The progran uses mutex to ensure the data are synchronized. 
  During the execation, the program will produce a trace of output from each thread showing the actual order of execution.
  It waits for all the threads to complete, and finally prints out the final value of the global counter, which is 100.
