1. How to build my project:

  To build my project, I need to open a command prompt and go to the directory where I have saved the file file_copy.c.
  Then, I type "gcc file_copy.c" and press enter to compile the code.
  If there are no errors, the command prompt will take me to the next line and would generate a.out executable file.

  To control compilation, I just open a text editor and create a new file called "Makefile".Then, I type in:

    file_copy: file_copy.o
      gcc file_copy.o -o file_copy

    file_copy.o: file_copy.c
      gcc -c file_copy.c

    clean:
      rm -rf *o file_copy

  Save the make file. Then, I open a command prompt and go to the directory where I have saved the make file.
  I type "make", and the command prompt will generate an object file called "file_copy.o" and an executable file called "file_copy".

2. How to run my porject:

  To run my porject, type "./a.out" to execute the project.Then, I just need to follow the output.
  There is also another way to run the project. I can also type "./file_copy" and I will also get the same output.

3. What my porject does:

  The project basically allows the user to copy the content of a file to another file.
  Firtsly, The project prompts the user to enter the input file name.
  If the input file exists, prompt the user to enter the output file name.
  If the output file doesn't exist, the project just copies the content of the input file to output file.
  Finally, display the number of bytes copied.

4. Explain the output of starce of my project:

  (Noted: the number of times each syscall used is at the bottom!!! Since we can't use "strace" on Mac, so I use "dtruss".)
  (Noted: I use "dstruss" instead of "strace", but there is something wrong with "Dtrace" on Mac, and Apple hasn't fixed that yet, so you will see lots of "Dtrace" errors down below.)

  SYSCALL(args) 		 = return                                                     //Initialize all the system calls and program
  Welcome to the File Copy Program by Zhewei Zhang
  Enter the name of the file to copy from:
  open("/dev/dtracehelper\0", 0x2, 0x7FFF552258F0)		 = 3 0                      //From here, trace the states of all the system calls used
  ioctl(0x3, 0x80086804, 0x7FFF55225878)		 = 0 0                                //Display the calls, which includes their addresses of args and return values
  close(0x3)		 = 0 0
  thread_selfid(0x3, 0x80086804, 0x7FFF55225878)		 = 41247478 0
  bsdthread_register(0x7FFF96B64080, 0x7FFF96B64070, 0x2000)		 = 1073741919 0
  ulock_wake(0x1, 0x7FFF552250AC, 0x0)		 = -1 Err#2
  issetugid(0x1, 0x7FFF552250AC, 0x0)		 = 0 0
  mprotect(0x10A9DE000, 0x88, 0x1)		 = 0 0
  mprotect(0x10A9E0000, 0x1000, 0x0)		 = 0 0
  mprotect(0x10A9F6000, 0x1000, 0x0)		 = 0 0
  mprotect(0x10A9F7000, 0x1000, 0x0)		 = 0 0
  mprotect(0x10AA0D000, 0x1000, 0x0)		 = 0 0
  mprotect(0x10AA0E000, 0x1000, 0x1)		 = 0 0
  mprotect(0x10A9DE000, 0x88, 0x3)		 = 0 0
  mprotect(0x10A9DE000, 0x88, 0x1)		 = 0 0
  getpid(0x10A9DE000, 0x88, 0x1)		 = 40494 0                                   //You can see lots of "dtrace" errors below, since we are using "dtruss" instead of "strace"
  stat64("/AppleInternal/XBS/.isChrooted\0", 0x7FFF55224F68, 0x1)		 = -1 Err#2
  stat64("/AppleInternal\0", 0x7FFF55225000, 0x1)		 = -1 Err#2
  csops(0x9E2E, 0x7, 0x7FFF55224A90)		 = -1 Err#22
  dtrace: error on enabled probe ID 2158 (ID 552: syscall::sysctl:return): invalid kernel access in action #10 at DIF offset 40
  ulock_wake(0x1, 0x7FFF55225010, 0x0)		 = -1 Err#2
  csops(0x9E2E, 0x7, 0x7FFF55224370)		 = -1 Err#22
  getrlimit(0x1008, 0x7FFF55226778, 0x7FFF55224370)		 = 0 0
  fstat64(0x1, 0x7FFF55226798, 0x7FFF55224370)		 = 0 0
  ioctl(0x1, 0x4004667A, 0x7FFF552267DC)		 = 0 0
  dtrace: error on enabled probe ID 2133 (ID 942: syscall::write_nocancel:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2133 (ID 942: syscall::write_nocancel:return): invalid kernel access in action #12 at DIF offset 92
  fstat64(0x0, 0x7FFF55226408, 0x2A)		 = 0 0
  ioctl(0x0, 0x4004667A, 0x7FFF5522644C)		 = 0 0
  input.txt                                                                     //Input the file name
  Enter the name of the file to copy to:
  dtrace: error on enabled probe ID 2135 (ID 940: syscall::read_nocancel:return): invalid kernel access in action #12 at DIF offset 92
  open("input.txt\0", 0x0, 0x12068)		 = 3 0
  dtrace: error on enabled probe ID 2133 (ID 942: syscall::write_nocancel:return): invalid kernel access in action #12 at DIF offset 92
  output.txt                                                                    //Input another file name
  File Copy Successful, 181 bytes copied
  dtrace: error on enabled probe ID 2135 (ID 940: syscall::read_nocancel:return): invalid kernel access in action #12 at DIF offset 92
  open("output.txt\0", 0xA01, 0x180)		 = 4 0                                  //Can't trace the contents copied into another file, there is something wrong with "Dtrace" on Mac OS
  dtrace: error on enabled probe ID 2134 (ID 154: syscall::read:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2132 (ID 156: syscall::write:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2134 (ID 154: syscall::read:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2132 (ID 156: syscall::write:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2134 (ID 154: syscall::read:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2132 (ID 156: syscall::write:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2134 (ID 154: syscall::read:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2132 (ID 156: syscall::write:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2134 (ID 154: syscall::read:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2132 (ID 156: syscall::write:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2134 (ID 154: syscall::read:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2132 (ID 156: syscall::write:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2134 (ID 154: syscall::read:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2132 (ID 156: syscall::write:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2134 (ID 154: syscall::read:return): invalid kernel access in action #12 at DIF offset 92
  dtrace: error on enabled probe ID 2133 (ID 942: syscall::write_nocancel:return): invalid kernel access in action #12 at DIF offset 92
  close(0x3)		 = 0 0
  close(0x4)		 = 0 0                                                            //Excution done, close the two files

  CALL                                        COUNT
  bsdthread_register                              1
  exit                                            1
  getpid                                          1
  getrlimit                                       1
  issetugid                                       1
  sysctl                                          1
  thread_selfid                                   1
  csops                                           2
  fstat64                                         2
  read_nocancel                                   2
  stat64                                          2
  ulock_wake                                      2
  close                                           3
  ioctl                                           3
  open                                            3
  write_nocancel                                  4
  write                                           7
  mprotect                                        8
  read                                            8
