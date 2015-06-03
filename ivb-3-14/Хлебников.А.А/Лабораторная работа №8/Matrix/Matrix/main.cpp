#include <iostream>
#include <string>
#include "matrix.h"
#include <ctime>
#include <cstring>

void
__test_isSymmetric()
{
	Matrix<int> m(4, 4, 0);

	/** Симметричная. Вариант 12*/
	/**	Кривошея Михаил **/
	std::cout << "Матрица: " << std::endl << m;
	std::cout << "Симметрична: " << (m.isSymmetric() ? "Нет" : "Да") << std::endl << std::endl;
}

void
__test_operatorPlus()
{
	/* Сложение матриц. Вариант 2 */
	/** Avshalumov H.N. **/
	Matrix<int> a(3, 3, 2);
	Matrix<int> b(3, 3, 3);
	std::cout << "Матрица A:" << std::endl << a;
	std::cout << "Матрица B:" << std::endl << b;
	std::cout << "Матрица A+B:" << std::endl << a + b << std::endl;
}

void
__test_operatorMinus()
{
	/* Вычитание матриц. Вариант 3 */
	/** Allyamov I.Z. **/
	Matrix<int> a(3, 2, 2);
	Matrix<int> b(2, 2, 8);
	std::cout << "Матрица A:" << std::endl << a;
	std::cout << "Матрица B:" << std::endl << b;
	std::cout << "Матрица A-B:" << std::endl << a - b << std::endl;
}

void
__test_transposition ()
{
	/** Транспониромание. Вариант 7 **/
	/** Богомазов Степан **/
	Matrix <int> a(8, 4, 1);
	a.put(5, 1, 2);
	a.put(2, 3, 1);
	a.put(2, 2, 2);
	std::cout << "Матрица: " << std::endl << a << std::endl;
	std::cout << "Transp.: " << std::endl;
}

void
__test_determinant()
{
	/**Определитель матрицы. Вариант 10 (2)*/
+	/*Лавринович  Иван*/
	/*Zalyaliev R.R.*/
	Matrix <int> a(3, 3, 0);
	a.put(0, 0, 5);
	a.put(1, 1, 3);
	a.put(2, 2, 2);
	std::cout << "Матрица A:" << std::endl << a;
	std::cout << "det(A)=" << a.determinant() << std::endl;
}

void
__test_isMinor()
{
	/** Минор. Вариант 13*/
	/**	Панасенко Андрей **/
	Matrix <int> m(4, 4, 0);
	for (int i = 0, i2 = 0; i < m.getRowCount(); i++, i2++) {
		for (int j = 0, j2 = 0; j < m.getColCount(); j++, j2++) {
			m.put(i2, j2, m.get(i, j));
		}
	}

	int row = 3, col = 3;
	std::cout << "Матрица: " << std::endl << m;
	std::cout << "Минор (" << row << "," << col << ") = " << m.minor(row, col) << std::endl << std::endl;
}

void
__test_pow ()
{
	/** Возведение в степень. 6 вариант*/
	/** Коротков Даниил **/
	Matrix <int> m(1, 2, 3);
	int test = 2;
	std::cout << "Матрица: " << std::endl << m << std::endl;
	std::cout << m^(test) << std::endl;
}

void
__test_operatorMultByNumber()
{
	/* Safronov.I.A */
	/** Умножение на число. Вариант 4*/
	Matrix<int> a(3, 3, 3);
	std::cout << "Матрица A:" << std::endl << a;
	std::cout << "Матрица A*5:" << std::endl << a * 5 << std::endl;
}

int
main(int argc, char **argv)
{
	setlocale(0, "Russian");
	__test_isSymmetric();
	__test_operatorPlus();
	__test_operatorMinus();
	__test_determinant();
	__test_isMinor();
	__test_pow();
	__test_operatorMultByNumber();
	system("pause");
	return EXIT_SUCCESS;
}
