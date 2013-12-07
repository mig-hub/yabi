#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static char data_highway[30000];
static char *p;

int do_command(char command, FILE *input)
{
	char c;
	long pos;

	switch(command) {
	case '>':
		++p;
		break;
	case '<':
		--p;
		break;
	case '+':
		++*p;
		break;
	case '-':
		--*p;
		break;
	case '.':
		putchar(*p);
		break;
	case ',':
		*p = getchar();
		break;
	case '[':
		pos = ftell(input);
		if ((*p) == 0) {
			int loopc = 0;
			for(;;)
			{
				c = getc(input);
				if (loopc == 0 && c == ']') break;
				if (c == ']') loopc--;
				if (c == '[') loopc++;
			}
		} else while((*p) != 0) {
			fseek(input, pos, SEEK_SET);
			c = getc(input);
			while( c!=']' && c!=EOF) {
				do_command(c,input);
				c = getc(input);
			}

		}

	}

}

int main(int argc, char **argv) {
	
	char command;
	FILE *input;

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
	
	while((command = getc(input)) != EOF) {
		do_command(command, input);
	}
	
	return 0;
}
