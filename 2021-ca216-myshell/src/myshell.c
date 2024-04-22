// unix comaptible shell
// name: Katie Clancy
// student no: 19452724
// ** acknowledgement of DCU Academic Integrity Policy **

#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>


#define MAX_BUFFER 1024
#define MAX_ARGS 64

// will be used for seperating input using whitespaces
#define SEPARATORS " \t\n"

void read_input ( char cmd[], char *par[])
{
	char line[1024];
	int count = 0, i = 0, j = 0;
	char *array[100], *pch;
	
	// read one line
	for ( ;; )
	{
		int c = fgetc ( stdin );
		line[count++] = (char) c;
		if ( c == '\n' ) break;
	}
	if ( count == 1) return;
	pch = strtok ( line, "\n" );
	
	// parse the line into words
	while ( pch != NULL )
	{
		array[i++] = strdup ( pch );
		pch = strtok ( NULL, "\n");
	}
	// first word is the command
	strcpy ( cmd, array[0] );
	
	// others are parameters
	for ( int j = 0; j < i; j++ )
		par[j] = array[j];
	par[i] = NULL; // NULL terminates the parameter list
	
}

void user_prompt()
{
	static int first = 1;
	if ( first ) {
		//clear screen for the first time
		const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
		write(STDOUT_FILENO,CLEAR_SCREEN_ANSI,12);
		first = 0;
	}
	printf("clancyk2@katies-shell PATH $ "); // display prompt
}

int main (int argc, char ** argv)
{
	char buff[MAX_BUFFER];
	
	// string input pointer
	char * point[MAX_ARGS];
	
	// working directory print
	char curr_wd[256];
	
	// pointer that goes through input
	char ** through;
	
	// prompt that will appear on screen to user
	char * prompter = "clancyk2@katies-shell $ " ;
	
	printf("WELCOME TO SHELL | TO QUIT ENTER 'quit'\n");

	while (!feof(stdin))
	{
		getcwd (curr_wd, sizeof(curr_wd));
		fputs (curr_wd, stdout);
		// display prompt
		fputs (prompter, stdout);
		
		if (fgets (buff, MAX_BUFFER, stdin ))
		{
			// display prompt
			through = point;
			
			// use seperators on input entered
			*through++ = strtok(buff,SEPARATORS);
			
			while ((*through++ = strtok(NULL,SEPARATORS)));
			
			// check for commands (int & ext)
			if (!strcmp(point[0],"clear"))
			{
				// implementation of 'clear' for clear screen
				system("clear");
				continue;
			}
			
			// implementation of 'quit' command
			if (!strcmp(point[0],"quit"))
				// exit while loop
				break;
			
			// implementation of 'dir' command
			if (!strcmp(point[0], "dir"))
			{
				signal(SIGINT, SIG_DFL);
				if (fork() == 0) exit(execl("/bin/ls", "ls", NULL));
				signal(SIGINT, SIG_IGN);
			}
			
			// implementation of the 'cd' command
			if (!strcmp(point[0], "cd"))
			{
				cd(point[1]);
				continue;
			}
			
			// implementation of 'pause' command
			if (!strcmp(point[0], "pause"))
				// calling my pause_exec function
				pause_exec();
			
			// implementation of 'mkdir' function
			if (!strcmp(point[0], "mkdir"))
				// calling my mkdirect function
				mkdirect(point[1]);
			
			// implementation of 'help' command
			if (!strcmp(point[0], "help"))
				// calling my help_manual function
				help_manual();
			
			// implementation of 'echo' function
			int num = 1;
			if (!strcmp(point[0], "echo"))
			{
				// args = 0
				while (point[num] != NULL)
				{
					// everything following command gets printed
					printf("%s ", point[num]);
					num++;
				}
				printf("/n");
				continue;
			}
			
			int no;
			if (!strcmp(point[0], "env"))
			{
				for(no = 0; ecvt[no] != NULL; no++)
				    printf("\n%s", ecvt[no]);
				printf("\n");
			}
			
			// refer to the op system for the command
			// or print out command if not implemented
			through = point;
			
			while (*through) fprintf(stdout,"%s ",*through++);
				fputs ("\n", stdout);
		}
	}
	return 0;
}

