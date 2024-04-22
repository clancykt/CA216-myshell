// shell management file
// name: katie Clancy
// student no: 19452724
// ** acknowledgement of DCU Academic Integrity Policy **

#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

// change directory function
void change_dir(char *cng)
{
	chdir(cng);
}

// make directory function
void mkdirect(char *dir)
{
	mkdir(dir, 0777);
}


// help manual print function
void help_manual()
{
	// changing directories
	// first exit cwd
	chdir("..");
	
	// enter directory called 'manual'
	chdir("manual");
	
	char *str;
	
	FILE *file;
	
	// open file called 'help' & read entire file to stdout
	file = fopen("help", "r");
	
	while ((str = fgetc(file)) !=EOF)
	{
		printf("%s", str);
	}
	
	// must close file when execution is done
	// and change directories again
	fclose(file);
	
	chdir("..");
	chdir("src");
	
}

// pause shell function
void pause_exec()
{
	// pause until user presses enter key
	while(getchar() != 0x0A)
		sleep(1);
}

