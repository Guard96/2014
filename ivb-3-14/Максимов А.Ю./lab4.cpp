#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <clocale>
#include <cstring>
#include <sstream>
#include <iostream>

static const char * const InputFileName = "input_4.txt";

#define SKIPWHS() \
		while (!feof(fd)) { \
            ch = fgetc(fd); \
            if (!isspace(ch)) \
               break; \
		}

int convert(std::stringstream a, int pos) {}

int
main(int argc, char **)
{
	FILE *fd;
	setlocale(LC_ALL, "Russian");

	long FileSize;
	char *buffer;

	 fd = fopen ( InputFileName , "r" );
	 if( fd != NULL) {
	
		 fseek( fd , 0L , SEEK_END);
		 FileSize = ftell( fd );
		 rewind( fd );

	    /* allocate memory for entire content */
		 buffer = (char*) calloc( 1, FileSize+1 );
		 if( !buffer ) { //an error while allocating memory
			 fclose(fd);
			 fprintf(stderr, "memory allocation fails");
			 return EXIT_FAILURE;
		 };

	    /* copy the file into the buffer */
		 if( 1!=fread( buffer , FileSize, 1 , fd) ){ //an error while allocating memory
			 fclose(fd);
			 fprintf(stderr, "error while reading");
			 return EXIT_FAILURE;
		 };

		 fclose(fd);
		 //now the file is in buffer variable
		 int curpos = 0;
		 int prevpos=0;
		 int sal[2];
		 for (i = 0; i <=2; ++i) {
			while (!isspace && curpos <= FileSize) {};
			char *salary = calloc (1, curpos-prevpos)
			
			atoi()				
		}
		 
		 
		 
		 
		 
	} else {
		fprintf(stderr, "Входной файл \"%s\" не найден.\n", InputFileName);
	}
	fprintf(stdout, "Нажмите любую клавишу для продолжения...");
	fgetc(stdin);
	return EXIT_SUCCESS;
}



