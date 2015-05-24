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
	test_is_Minor();
	system("pause");
	return EXIT_SUCCESS;
}
