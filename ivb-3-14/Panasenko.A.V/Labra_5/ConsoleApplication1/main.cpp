#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <vector>
#include <iostream>
// version alfa 1.0
/* ������������ ������ �5
* ������� 16
* ���-3-14
* ��������� ������
���� ��� ������� ������� �������.
��� ��� �� ������, � ������� ������ ������� �������������� ������������� ���������, ��������� ������� �������������
��������� � ������ ������ */

typedef std::vector<std::vector<double>> MATRIX;

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
	bool isPoint() const
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
			(isSign() || isPoint() || isDigit())) {
			put();
			next();
		}
	}
	void put()
	{
		_buffer.push_back(_ch);
	}

	std::vector<std::vector<Type>> parse(const char * const  name)
	{
		std::vector<std::vector<Type>> MATRIX;
		MATRIX.clear();
		std::vector<Type> row;
		if (_fd == nullptr)
			_fd = fopen(name, "r");
		if (_fd == nullptr)
			return MATRIX;
		next();
		while (!eof()) {
			_buffer.clear();
			parseNumber();
			if (_buffer.size() > 0) {
				row.push_back(atof(_buffer.c_str()));
			}
			if (isEndOfLine()) {
				skipEndOfLine();
				MATRIX.push_back(row);
				row.clear();
			}
		}
		if (row.size() > 0)
			MATRIX.push_back(row);
		fclose(_fd);
		_fd = nullptr;
		return MATRIX;
	}
};

static void PrintMatrix(MATRIX m);
static int CountPositiveElement(MATRIX m);
static int CountNegativeElement(MATRIX m);
static int __exception(const char * const szMessage);

int main(int argc, char **argv)
{
	setlocale(0, "Russian");
	if (argc < 3)
		return __exception("��� ������� ������");

	NumberFromFileParser<double> parser;
	MATRIX m1 = parser.parse(argv[1]);
	MATRIX m2 = parser.parse(argv[2]);

	PrintMatrix(m1);
	PrintMatrix(m2);

	int c1 = CountPositiveElement(m1);
	int c2 = CountPositiveElement(m2);

	if (c1 > c2) {
		printf("� ������ ������� ������� �������������� ������������� ��������� ����� .\n", CountPositiveElement(m1));
		printf("� ������ ������� %i ������������� ��������� .\n", CountNegativeElement(m1));
	}
	else {
		printf("�� ������ ������� ������� �������������� ������������� ��������� ����� .\n", CountPositiveElement(m2));
		printf("� ������ ������� %i ������������� ��������� .\n", CountNegativeElement(m2));
	}
	system("pause");
	return EXIT_SUCCESS;
}

int __exception(const char * const szMessage)
{
	fprintf(stderr, "%s\n", szMessage);
	return EXIT_FAILURE;
}

void PrintMatrix(MATRIX m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		for (auto j = i->begin(); j != i->end(); j++)
			printf("%3.1f\t", *j);
		printf("\n");
	}
	printf("\n");
}

int CountPositiveElement(MATRIX m)
{
	int n = 0;
	double sum = 0;
	for (auto i = m.begin(); i != m.end(); i++)
	for (auto j = i->begin(); j != i->end(); j++)
	if (*j > 0) {
		sum += *j;
		n++;
	}
	double result = sum / n;
	return result;
}

int CountNegativeElement(MATRIX m)
{
	int count = 0;
	for (auto i = m.begin(); i != m.end(); i++)
	for (auto j = i->begin(); j != i->end(); j++)
	if (*j < 0)
		count++;

	return count;
}