Не доделал

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <typeinfo>

/* Лаб. работа 5
 Вариант 6
 ИВБ-3-14
 Богомазов Степан */

typedef std::vector<std::vector<double>> matrix;

template <typename Type>
class NumberFromFileParser
{
	char                _ch;
	FILE               *_fd;
	std::string         _buffer;
public:
	NumberFromFileParser() : _ch(0), _fd(nullptr){}

	bool eof() const
	{
		return feof(_fd) > 0;
	}
	bool next()
	{
		_ch = fgetc(_fd);
		return _ch != EOF;
	}
	bool isWhitespace() const
	{
		return isspace((int)_ch) > 0;
	}
	bool isDigit() const
	{
		return isdigit((int)_ch) > 0;
	}
	bool isDot() const
	{
		return _ch == '.' ||
			_ch == ',';
	}
	bool isSign() const
	{
		return _ch == '-' ||
			_ch == '+';
	}
	bool isEndOfLine() const
	{
		return _ch == '\r' ||
			_ch == '\n';
	}
	void skipWhitespace()
	{
		while (!eof() && isWhitespace() && next());
	}
	void skipEndOfLine()
	{
		while (!eof() && isEndOfLine() && next());
	}
	void parseNumber()
	{
		skipWhitespace();
		while (!eof() && !isWhitespace() &&
			(isSign() || isDot() || isDigit())) {
			put();
			next();
		}
	}
	void put()
	{
		_buffer.push_back(_ch);
	}

	std::vector<std::vector<Type>> parse(std::string  name)
	{
		std::vector<std::vector<Type>> matrix;
		matrix.clear();
		std::vector<Type> row;
		if (_fd == nullptr)
			_fd = fopen(name.c_str(), "r");
		if (_fd == nullptr)
			return matrix;
		next();
		while (!eof()) {
			_buffer.clear();
			parseNumber();
			if (_buffer.size() > 0) {
				row.push_back(atof(_buffer.c_str()));
			}
			if (isEndOfLine()) {
				skipEndOfLine();
				matrix.push_back(row);
				row.clear();
			}
		}
		if (row.size() > 0)
			matrix.push_back(row);
		fclose(_fd);
		_fd = nullptr;
		return matrix;
	}
};

static void PrintMatrix(matrix m);
static int GetCountZeroElement(matrix m);
static int GetCountNegativeElement(matrix m);

int main()
{
	setlocale(0, "Russian");

	NumberFromFileParser<double> parser;
	matrix m1 = parser.parse(std::string("mat1.txt"));
	matrix m2 = parser.parse(std::string("mat2.txt"));

	PrintMatrix(m1);
	PrintMatrix(m2);

	int zeroCount1 = GetCountZeroElement(m1);
	int zeroCount2 = GetCountZeroElement(m2);

	if (zeroCount1 < zeroCount2)
		printf("В первой матрице %i равных нулю.\n", GetCountNegativeElement(m1));
	else
		printf("Во второй матрице %i равных нулю.\n", GetCountNegativeElement(m2));

	system("pause");
	return EXIT_SUCCESS;

