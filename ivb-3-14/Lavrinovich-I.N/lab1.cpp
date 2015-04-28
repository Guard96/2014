#pragma warning(disable : 4996)
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MATRIX1 4
#define MATRIX2 2
#define MATRIX3 6

static double m1[] = { 1., 1., 1., 1. };

static double m2[] = { 1., 1. };

static double m3[] = { 4., 4., 4., 4., 4., 4. };

static double
calculate(double matrix[], int elements)
{
	double result = 0;
	int i;
	for (i = 0; i < elements; i++) {
		result += matrix[i];
	}
	return result;
}
 void out_put(double mr1, double mr2, double mr3)
{
	 const int x = 4;
	 if ((mr1 && mr2) > x) 
		 fprintf(stdout, "Matrix1 == Matrix2\n");
	 if ((mr1 && mr3) > x)
		 fprintf(stdout, "Matrix1 == Matrix3\n");
	 if ((mr2 && mr3) > x)
		 fprintf(stdout, "Matrix2 == Matrix3\n");
	 if ((mr2 && mr3 && mr1) > x)
		 fprintf(stdout, "Matrix1 == Matrix2 == Matrix3\n");
}
int main(int argc, char **argv)
{
	double mr1 = calculate(m1, MATRIX1);
	double mr2 = calculate(m2, MATRIX2);
	double mr3 = calculate(m3, MATRIX3);
	out_put(mr1, mr2, mr3);
	system("pause");
	return EXIT_SUCCESS;
}