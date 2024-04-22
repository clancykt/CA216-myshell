User Manual

Welcome to shell.

Introduction

What is shell?

The shell is a way of communicating with your system’s operating system; it’s essentially a computer program that understands certain ‘commands’ that will perform operations for you.

You can move from one directory to another to. Each directory is like a place in your computer that contains different files.

To access files that live in a certain directory on your system, you must first navigate into that directory (using simple commands).

When you first run shell, you will be in your home directory.

This manual intends to assist you in finding your way around the shell, understating how to talk to it, and how to carry out certain tasks in it.

Commands

ls

To see what is contained in your current directory, enter ’ls’.
What you should receive in response is a grid-like display of the contents of that directory.
If nothing is contained in that directory, the prompt should be returned, ready to receive anothercommand.
To see a list representation of the contents, type ‘ls -l’.

cd

To change to a different directory, simply type ‘cd’ followed by the name of the place you wish to redirect to, e.g. ‘cd ca216’ would bring me to the directory named ca216.

Simply typing ‘cd’ by itself will instruct the shell to display the current directory you are in.

clear

To clear the screen of all content above the current prompt, type ‘clear’.

env

If you want to gain information about your current login session [1], input ’env’, which will return environment variables; essentially a description of everything in the environment; the type of terminal in use, the current path etc.

echo

To make the shell repeat your argument (the word(s) or numbers you put beside the echo command), type ‘echo’ followed by whatever you wish, for example ‘echo hello world’ would return ‘hello world’.

help

To retrieve this user manual from the command line, type ‘help’.
What you should get is a well structured, filtered version of this manual.

pause

To pause the current running process in the shell, whether that be the execution of a program or command, type ‘pause’.

quit

To exit your current running session in the shell, type ‘quit’.


Concepts

I/O Redirection

This is a concept that comes in very handy when working with the contents of files and the input and output streams of programs.

Let’s say for example I wanted to copy the contents of one file into another. My method would go something like: direct to the file and open it in the editor, select all the contents, copy them, close the editor, open a new file, paste the contents.

This works fine when dealing with files that do not have many lines of content. However, when dealing with larger files that have a substantialy large volumes of content, we can do things like the following:

‘file1 > file2’

This simple command is telling your computer to redirect the contents of ‘file1’ into a second file, ‘file2’.

The less-than, greater-than and pipe operands enable us to perform many commans like this, resulting in greater efficiency, saving us a lot of time and allowing us to avoid small errors that may be made when directing files and programs.

To make use of these operands to fulfuill the task at hand, we must first understand what each one does to avoid making a mistake that will take great effort and time to correct.

The greater-than symbol when used in a command will redirect the output.
The less-than symbol when used in a command will redirect the input.

The examples below[2] illustrate the basic functioning of each operand:

If I wish to place a string from the command line into a file, I would enter ‘echo My String > file’ into the terminal.
If I am running a program and wish for the output of the program to be pasted into a file, ‘program_output > file’ would complete this for me.
If I would like to do the opposite of this and have my program receive input from a file, the command I would use would be: ‘program_input < file’.
If I would like to use the output of one program as the input for another, I would make use of the pipe symbol, and type ‘program1_output | program2_input’.

There are certain things we must be mindful of when using these commands to improve our efficiency, for example, when redirecting data into a file, the file should be new; the filename should not exist already. Should the filename already exist i.e. the file is currently in existence and it contains data, when we redirect our new data into the file, the existing data will be lost[2].

Program Environment

When you run a program in shell, a unique environment is generated for that particular program[3].
The environment is completely suited to the program; it ensures everyting needed for the program to run is in check and basically adapts the system so that the program is executing as if nothing else is executing in conjunction with it[3].

Process Concepts

Each time we input a command via the command line, a new process begins[3], from the simplest and shortest of commands to the most complex.
Process ID’s (or PIDs) are used to keep track of each of these processes. A brand new one is created for each individual process[3].
The ways to execute processes can be categorized by the following processing methods; background and foreground process execution.

Foreground Program Execution

When executing a program or command in the foreground, the user can see it running and cannot use the shell for any other purpose while it is running. The running process essentially takes over the system and the user must wait until execution is complete to carry out any other program or command. This method of execution is useful when you do not need to execute any other tasks during its running, and mainly for programs and commands that have a smaller execution period.

Background Program Execution

A background process is exactly what it says it is; a process that runs in the background, meaning the user can’t see it running and does not interact with it when it’s running.
What this means for the shell, is that the user can’t see the program running in the shell, and can actually continue to use the shell for other things while the program or process runs[4].

This can be particularly useful when running programs or executing commands that you know are going to take a significant amount of time (e.g. a sorting algorithm program or installing items on your system).

To utilize this concept, the ampersand ‘&’ operator is used with the command or with the program call on the command line;

‘Sort_list_nums.py &’

If you wish to see the program at any point to check on it’s progress, running the ‘fg’ command will do so (fg stands for foreground, meaning it will bring your program to the foreground of the terminal)[4].
To terminate the process from running, simply emter ‘kill PID’ into the terminal[4].

The shell will indicate the completion of execution by returning the command line prompt when executed.



References

Descripton of environment variables
What are environment variables in bash?
Link: https://opensource.com/article/19/8/what-are-environment-variables
** used to understand environment variables and the command to view them.

I/O Redirection explanation and command examples
Output redirection
Input redirection
Command & Description
Link: https://www.tutorialspoint.com/unix/unix-io-redirections.htm
** used as a source to understand and interpret redirection and example commands.

Unix / Linux - Process Management
Process management
Foreground processes
Background processes
Link: https://www.tutorialspoint.com/unix/unix-processes.htm
** used to understand processes in unix environments to explain process concepts and program environments.

Unix Tutorial for Beginners
Tutorial One
‘The shell’
‘Listing files and directories’
‘Changing to a different directory’
‘The directories . and ..’
‘Summary’
Link: http://www.ee.surrey.ac.uk/Teaching/Unix/unix1.html
** used as basis for understanding and explaining shell.

Run a unix process in the background
Link: https://kb.iu.edu/d/afnz
** used to understand and explain background processes, commands associated with it.

Name: Katie Clancy

Student Number: 19452724

Acknowledgement of the DCU Academic Integrity Policy:

I acknowledge that I am required to follow the Academic Integrity Policy set by DCU and can confirm that I have indicated all instances where I have used the work of others to assist me in my completion of this assignment, all else is my own.


