# A basic command shell in Linux

The program was written as part of a lab assignment in the Operating Systems Lab. The aim was to write our own command shell to gain experience with file descriptors, signals and pipes.

<b>How to run the program?</b>

To compile the shell, type the following in the terminal: 

$ gcc –o shell shell.c –lreadline 

-lreadline links the readline library while compiling. 

Then run it using, 

$ ./shell 

1. In the start, the shell prints the name of the user and the current working directory. 

  Example: avijit:/home/avijit/6th_Sem/OS_Lab $ 

2. The input is taken through GNU Readline function which supports editing in the console. 

3. All the built-in commands and other shell features as mentioned in the assignment are supported. 

