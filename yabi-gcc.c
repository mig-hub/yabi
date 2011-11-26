#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static char data_highway[30000];
static char *p;

int main(int argc, char **argv) {
	
	char command, ignoring;
  long pos;
	FILE *input;
	static void *op[] = {
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&plus, &&comma, &&minus, &&dot, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&lt, &&next, &&gt, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&lb, &&next, &&rb, &&next, &&next, &&next, &&next, &&next, &&next,
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next,
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, 
    &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next, &&next,
    &&next, &&next, &&next, &&next, &&next, &&next 
  };

  if (argc > 1) {
	  if(!strcmp(argv[1],"-")) {
	    input = stdin;
	  } else {
	    input = fopen(argv[1],"r");
	    if (NULL==input) {
	      fprintf(stderr, "Unable to open \"%s\"\n", argv[1]);
	      exit(EXIT_FAILURE);
	    }
	  }
  } else {
  	input = stdin;
  }

	p = &data_highway[0];
	
  goto next;

  gt:
		++p;
		goto next;
	lt:
		--p;
		goto next;
	plus:
		++*p;
		goto next;
	minus:
		--*p;
		goto next;
	dot:
		putchar(*p);
		goto next;
	comma:
		*p = getchar();
		goto next;
	lb:
		pos = ftell(input);
    if ((*p) == 0) ignoring = 1;
    goto next;
  rb:
    ignoring = 0;
    if ((*p) != 0) fseek(input, pos, SEEK_SET);
    goto next;

	next:
  command = getc(input);
  if (ignoring==1 && command!=']') goto next;
  if (command!=EOF) goto *op[command];
	quit:
	return 0;
}