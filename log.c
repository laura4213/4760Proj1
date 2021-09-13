/*
 *Date Changed: 9/12/2021
 *Author: Laura Stroud
 *
 *
 *
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "log.h"

typedef struct list_struct {
	data_t item;
	struct list_struct *next;
}log_t;

static log_t *headptr = NULL;
static log_t *tailptr = NULL;

int addmsg(const char type, const char *msg) {
	
        FILE *rfile;
        rfile = fopen("logs.txt", "r");
        if(rfile == NULL){
                perror("Driver: Error: Cannot open logs.txt");
                return -1;
        }

	fseek(rfile, 0L, SEEK_END);
	long int size = ftell(rfile);

	fclose(rfile);

	struct data {
		time_t time;
		char type;
		char *string;
	}d_t;

	log_t *node;
	
	if((node = (log_t *)(malloc(size))) == NULL) {
		perror("Driver: Error: couldn't add logs.");
		return -1;
	}	

	node->item.time = d_t.time;
	node->item.string = (char *)node + sizeof(log_t);
	strcpy(node->item.string, d_t.string);
	node->next = NULL;

	if(headptr == NULL){
		headptr = node;
	}
	else {
		tailptr->next = node;
	}
	
	tailptr = node;
	
	return 0;
}

void clearlog(void){
	log_t *clear;

	if(headptr != NULL) {
		clear = headptr->next;
		free(clear);
		headptr = clear;
	}	

	headptr = NULL;
}

char *getlog(void){
	char *logs = malloc(500 *  sizeof(char));
	log_t *get;

	if(logs == NULL) {
		perror("Driver: Error: Cannot allocate space to get the logs");
		return NULL;
	}
	else {
		strcpy(logs, "");
		if(get != NULL) {
			strcat(logs, (get->item).string);
			strcat(logs, "\n");
			get = get->next;
		}
	}
	
	return NULL;
}

char (*get)();

int savelog(char *filename){
	FILE *wfile;

	get = getlog;
	
	wfile = fopen("messages.log", "w");
	if(wfile == NULL){
		perror("Driver: Error: Cannot open messages.log");
		exit(0);
	}

	get(wfile);

	fclose(wfile);
	
	return 0;
}

