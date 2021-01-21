#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "converter.h"
/*
 * Global Variables
 */ 
char * mario[4] = {"It's-a", "me", "Mario!", "Wa-hoo!"};

/*
 * usage function
 *
 * Arguments: name program called with
 * Operation: print program usage summary to sderr
 * Return: Exits program with EXIT_FAILURE;
 */
void usage(char * name) {
	fprintf(stderr, "usage: %s [-m] [arg ...]\n", name);
	exit(EXIT_FAILURE);
}


//main print function
//argc = number of command line arguments
//argv = array containing command line arguments
int main(int argc, char * argv[]) {
	char * ptr;
	int opt;
	int m_flag;
	int err_opt;
	int count;
	int i;


	/*
	 * option processing for -c only as the FIRST arg (why the +c passed to getopt)
	 * common practice is to check all args to find al errors in the command then exit
	 */
	err_opt = 0;
	m_flag = 0;
	while ((opt = getopt(argc, argv, "+m")) != -1) {
		switch(opt) {
			case 'm':
				m_flag = 1;
				break;
			default:
				err_opt = 1;
				break;
		}
	}
	if(err_opt == 1) {
		usage(argv[0]);
	}

	else if (m_flag == 1) {
		for(i = 2; i < argc; i++) {
			count = (i-2) % 4;
			printf("%s", mario[count]);

		
			//prints spaces after each argument except the last one
			if ((argc - i) != 1) {
				printf("%s", " ");
			}
			//prints newline when arguments are done
			else {
				printf("\n");
			}
		}
	}
			                                               	
	
	else {
		for (i = 1; i < argc; i++) {
		printf("%s", argv[argc - i]);

		//prints spaces after each argument except the last one
		if ((argc - i) != 1) {
			printf("%s", " ");
		}
		//prints newline when arguments are done
		else {
			printf("\n");
		}

	}
	}
}
