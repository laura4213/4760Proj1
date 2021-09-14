/*
 *Date Changed: 9/13/2021
 *
 *Author: Laura Stroud
 *
 */
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
		fprintf(stderr, "Usage: Driver [-h] [-t sec] [logfile] \n");
		
		break;
	case 't':
		savelog("messages.log");
		clearlog();
		break;

	default: 
		savelog("messages.log");
	
	}
	

	exit(EXIT_SUCCESS);
}
}

