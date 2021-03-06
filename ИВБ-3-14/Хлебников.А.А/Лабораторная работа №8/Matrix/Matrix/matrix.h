#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <vector>
#include <map>
#include <exception>
#include <algorithm>
#include <ostream>

class MatrixException : public std::exception
{
    const char *_msg;
public:
    MatrixException(const char *msg)
        : _msg(msg)
    {}

    virtual const char* what() const throw()
    {
        return _msg;
    }
};

template<typename _Type>
class Matrix {
    typedef std::vector<_Type>      MatrixLine;
    typedef std::vector<MatrixLine> MatrixValue;

    MatrixValue _value;
public:    
    Matrix(int rows, int cols, _Type def)
    {
        clear(rows, cols, def);
    }

    void clear(int rows, int cols, _Type def)
    {
        _value.clear();
        for (auto i = 0; i < rows; i++) {
            auto line = MatrixLine(cols);
            std::fill(line.begin(), line.end(), def);
            _value.push_back(line);
        }
    }

    /**Сравнение матриц. Вариант 1*/
    bool operator==(const Matrix<_Type> &other)
    {
        return false;
    }

    bool operator>=(const Matrix<_Type> &other)
    {
        return false;
    }

    bool operator<=(const Matrix<_Type> &other)
    {
        return false;
    }

    bool operator!=(const Matrix<_Type> &other)
    {
        return false;
    }

    /* Сложение матриц. Вариант 2 */
    Matrix<_Type> & operator+(const Matrix<_Type> &that)
    {
        return *this;
    }

    /** Вычитание матриц. Вариант 3*/
    Matrix<_Type> & operator-(const Matrix<_Type> &that)
    {
        return *this;
    }

    /** Умножение на число. Вариант 4*/
    Matrix<_Type> & operator*(_Type number)
    {
        return *this;
    }

    /** Умножение матриц. Вариант 5 */
    Matrix<_Type> & operator*(const Matrix<_Type> &that)
    {
        return *this;
    }

    /** Возведение в степень. Вариант 6*/
    Matrix<_Type> & operator^(_Type number)
    {
        return *this;
    }

    /** Транспониромание. Вариант 7 (2)*/
    Matrix<_Type> & transposition()
    {
        return *this;
    }

    /**Обратная матрица. Вариант 8 (2)*/
    Matrix<_Type> & invert()
    {
        return *this;
    }

    /**Ступенчатая матрица. Вариант 9 (2)*/
    Matrix<_Type> & speed()
    {
        return *this;
    }

    /**Определитель матрицы. Вариант 10 (2)*/
    _Type determinant() const
    {
        return _Type();
    }

    /** Вырожденная. Вариант 11*/
    bool isDegenerate() const
    {
        return false;
    }

    /** Ступенчатая. Вариант 11*/
    bool isSpeed() const
    {
        return false;
    }

    /** Единичная. Вариант 11*/
    bool isIdentity() const
    {
        return false;
    }

    /** Треугольная. Вариант 11*/
    bool isTriangular() const
    {
        return false;
    }

    /** Симметричная. Вариант 12*/
    bool isSynnetric() const
    {
        return false;
    }

    /**Минор. Вариант 13 (2)*/
    _Type minor(int row, int col) const
    {
        return _Type();
    }


    _Type get(int row, int col) const
    {
        if (row >= _value.size())
            throw MatrixException("Row");
        auto line = _value[row];
        if (col >= line.size())
            throw MatrixException("Col");
        return line[col];
    }

    void put(int row, int col, _Type value)
    {
        if (row >= _value.size())
            throw MatrixException("Row");
        auto line = _value[row];
        if (col >= line.size())
            throw MatrixException("Col");
        line[col] = value;
    }
private:
    template<typename U> friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& m);
};

template<typename _Type>
std::ostream &operator<<(std::ostream &output, const Matrix<_Type> &m)
{
    /** Вариант 14 */
    throw std::exception("Не реализовано");
    return output;
}

#endif /** _MATRIX_H_ */
