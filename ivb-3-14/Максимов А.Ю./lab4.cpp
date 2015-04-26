//#pragma warning(disable: 4996)
#include <cstdio>
#include <clocale>

#define EXIT_SUCCESS 0;
//#include <cstdlib>
//#include <cctype>
//#include <cstring>
//#include <sstream>
//#include <iostream>

static const char * const InputFileName = "input_4.txt";
static const char * const OutputFileName = "output_4.txt";


int
main(int argc, char **)
{
	FILE *fd;
	setlocale(LC_ALL, "Russian");

	 fd = fopen ( InputFileName , "r" );
	 if( fd != NULL) {
	 	long int inp[2];
	 	
	 	fscanf(fd, "%li %li %li", &inp[0], &inp[1], &inp[2]);
		fclose(fd);
		long int max, min = inp[0];
		
		for (int i = 1; i <= 2; i++) 
		{
			if (max < inp[i]) {
				max = inp[i];
			};
			if (min > inp[i]) {
				min = inp[i];
			};
		}

		FILE *fd_2; //Something used to smash stack. Wtf.
		fd_2 = fopen ( OutputFileName , "w");
		if (fd_2 != NULL) 
		{
			long answer = max - min;
			fprintf(fd_2, "%li", answer );
		}
	} else {
		fprintf(stderr, "Входной файл \"%s\" не найден.\n", InputFileName);
	}
	fprintf(stdout, "Нажмите любую клавишу для продолжения...");
	fgetc(stdin);
	return EXIT_SUCCESS;
}



