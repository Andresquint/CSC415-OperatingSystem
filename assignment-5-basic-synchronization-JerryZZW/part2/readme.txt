Name  : Zhewei Zhang
Date  : 11/09/2017
Class : CSC415-02

Compile Instructions:

    To compile my project, I need to open a command prompt and go to the directory where I have saved the file pandc.c.
    Then, I type "gcc pandc.c" and press enter to compile the code.
    If there are no errors, the command prompt will take me to the next line and would generate a.out executable file.

    To control compilation, I just need to open the command prompt and type in "make".
    The command prompt will generate an executable file called "pandc".

Run Instructions:

    To run my porject, type "./a.out" to execute the project.Then, I just need to follow the output.
    There is also another way to run the project. I can also type "./pandc" and I will also get the same output.

Project Description:

    It basically implements a Producer-­­Consumer model with a bounded buffer queue of N elements, P producer threads and C consumer threads.
    N, P and C are command line arguments, along with three additional parameters, X, Ptime and Ctime.
    Each Producer thread enqueues X different numbers onto the queue (spin-­­waiting for Ptime cycles in between each call to Enqueue).
    Each Consumer thread dequeues P*X/C items from the queue (spin-­­waiting for Ctime cycles in between each call to Dequeue).
    The main program creates/initializes the Bounded Buffer Queue, print a timestamp, spawn off C consumer threads & P producer threads.
    Finally, it waits for all of the threads to finish and then print off another timestamp & the duration of execution.

Testing Strategy:

    The testing strategy is to have a single atomic counter to generate numbers for Producer threads.
    Then have the main routine combine the output from all of the Consumer threads.
    Sort it and verify that all of the input numbers appeared as output.

Annotated output:

    
