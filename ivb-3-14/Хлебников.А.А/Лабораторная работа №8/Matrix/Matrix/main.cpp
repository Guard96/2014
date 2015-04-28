#include <iostream>
#include <string>
#include "matrix.h"

int
main(int argc, char **argv)
{
    Matrix<int> m1(100, 100, 0);
    Matrix<int> m2(100, 100, 0);
    std::cout << m1 << std::endl;
    auto m = m1 - m2;
    m = m1 ^ 2;
    m = m1 * 3;
    system("pause");
    return EXIT_SUCCESS;
}
