#include <iostream>
#include <string>
#include "lab8.h"
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
test_is_Minor()
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

int
main(int argc, char **argv)
{
	setlocale(0, "Russian");
	__test_isSymmetric();
	__test_operatorPlus();
	__test_operatorMinus();
	test_is_Minor();
	system("pause");
	return EXIT_SUCCESS;
}
