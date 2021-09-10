#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include "log.h"

main(int argc, char *argv[])
{

int flags, opt;

while((opt = getopt(argc, argv, "ht:")) != -1) {

	switch (opt) {
	case 'h':
		fprintf(stderr, "Usage: Driver [-h] [-t sec] [logfile] %b\n");
		
		break;
	case 't':
		printf("test t");
		break;

	default: /* '?' */
		printf("test defualt");
		exit(EXIT_FAILURE);
	}


	exit(EXIT_SUCCESS);
}
}

