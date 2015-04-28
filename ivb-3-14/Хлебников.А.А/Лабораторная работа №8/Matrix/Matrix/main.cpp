#include <iostream>
#include <string>
#include "matrix.h"

void
__test_isSymmetric()
{
    Matrix<int> m(100, 100, 0);
    
    /** Симметричная. Вариант 12*/
    /**	Кривошея Михаил **/
    std::cout << "Матрица " << m << std::endl;
    std::cout << "Симметрична: " << (m.isSymmetric() ? "Нет" : "Да") << std::endl;


}

void
test_is_Minor()
{
	/** Минор. Вариант 13*/
	/**	Панасенко Андрей **/
	Matrix<int> m(5, 5, 0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			m.get(i, j);
	}
	int row = 4, col = 4;
	std::cout << "Матрица " << m << std::endl;
	std::cout << "Минор: " << m.minor(row, col) << std::endl;
}

int
main(int argc, char **argv)
{
    __test_isSymmetric();
	test_is_Minor();
    system("pause");
    return EXIT_SUCCESS;
}
