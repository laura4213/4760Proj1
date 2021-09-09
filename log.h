#include <time.h>

typedef struct data_struct
{
	time_t time; //time stamp
	char type;  //message type
	char * string; //message string
} data_t;

int addmsg ( const char type, const char * msg);
void clearlog();
char * getlog();
int savelog (char * filename);
