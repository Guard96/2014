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


int
main(int argc, char **argv)
{
    __test_isSymmetric();
    system("pause");
    return EXIT_SUCCESS;
}
