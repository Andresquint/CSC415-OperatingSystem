Name  : Zhewei Zhang
Date  : 10/26/2017
Class : CSC 415.02

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
  Since these threads are unsynchronized, there is a possibility of race conditions occurring.
  The progran uses nanosleep() to induce as many race conditions as possible.
  During the execation, the program will produce a trace of output from each thread showing the actual interleaved order of execution.
  It waits for all the threads to complete, and finally prints out the final value of the global counter, which is as far away from 100 as possible.

Annotated output:

  hello I’m thread #0's message:
  hello I’m thread #1's message:
  hello I’m thread #2's message:
  hello I’m thread #3's message:
  hello I’m thread #4's message:
  hello I’m thread #5's message:
  Thread id: 0, local thread variable: 0         //Race condition is occurring. Before the global counter was assigned to the local thread variable for thread #0, thread #1 to #5 have already stated execuating.
  hello I’m thread #6's message:
  hello I’m thread #7's message:
  Thread id: 1, local thread variable: 0         //Race condition is occurring. Before the global counter was assigned to the local thread variable for thread #1, thread #6 and #7 have already stated execuating.
  hello I’m thread #8's message:
  Thread id: 2, local thread variable: 0         //Race condition is occurring. Before the global counter was assigned to the local thread variable for thread #2, thread #8 has already stated execuating.
  hello I’m thread #9's message:                 //The final thread #9 starts execuating. Now all the threads have already started execuating.
  Thread id: 3, local thread variable: 0         //Race condition is occurring. After the final thread starts, the global counter was assigned to the local thread variables for thread #3 to #9.
  Thread id: 5, local thread variable: 0
  Thread id: 6, local thread variable: 0
  Thread id: 7, local thread variable: 0
  Thread id: 8, local thread variable: 0
  Thread id: 9, local thread variable: 0
  Thread id: 1, new local thread variable: 10   //Race condition is occurring. Before all the local thread variables increments by 10, the global counter have already been assigned to all the local thread variables.
  Thread id: 0, new local thread variable: 10
  Thread id: 2, new local thread variable: 10
  Thread id: 3, new local thread variable: 10
  Thread id: 4, new local thread variable: 10
  Thread id: 5, new local thread variable: 10   //Since the threads are not concurrent but parallel, all the local thread variables #0 to #9 have already been assigned as 0 by the global counter.
  Thread id: 6, new local thread variable: 10   //Therefore, the new local variables will always be 10 because the old ones always start by 0.
  Thread id: 7, new local thread variable: 10
  Thread id: 8, new local thread variable: 10
  Thread id: 9, new local thread variable: 10
  Final global counter: 10                      //The final output is 10, because every time a thread is execuating, the gobal counter is over written by the local variable 10.
