#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include<iostream>
#include<vector>
using namespace std;
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


int string_matrix_func(vector<int>&);
int full_matrix_func(vector<vector<int> >&, int, int);
void necessary_matrix(vector<vector<int> >&, int, int);

int main()
{
	int i, j, size11, size12, size21, size22;
	cout << "Vvedite razmernost matritsy:\n";
	cin >> size11 >> size12;
	vector<vector<int> > matrix1(size11, vector<int>(size12));
	cout << "Zapolnite matritsu:\n";
	for(i = 0; i < size11; i++)
		for(j = 0; j < size12; j++)
		{
			cout << "\n matrix1[" << i << "][" << j <<"] = ";
			cin >> matrix1[i][j];
		}

	cout << "Vvedite razmernost matritsy:\n";
	cin >> size21 >> size22;
	vector<vector<int> > matrix2(size21, vector<int>(size22));
	cout << "Zapolnite matritsu:\n";
	for(i = 0; i < size21; i++)
		for(j = 0; j < size22; j++)
		{
			cout << "\n matrix2[" << i << "][" << j <<"] = ";
			cin >> matrix2[i][j];
		}
	int max1 = full_matrix_func(matrix1, size11, size12);
	int max2 = full_matrix_func(matrix2, size21, size22);
	if (max1 >= max2)
		necessary_matrix(matrix1, size11, size12);
	else
		necessary_matrix(matrix2, size21, size22);
	cin >> i;
	return 0;
}
int string_matrix_func(vector<int> &matrix)
{
	int max = matrix[0];
	int size = matrix.size();
	for(int i = 0; i < size; i++)
		if(max < matrix[i]) 
			max = matrix[i];
	return max;
}
int full_matrix_func(vector<vector<int> > &matrix, int size1, int size2)
{
	int i, j;
	int max = 1;
	for(i = 0; i < size1; i++)
		for(j = 0; j < size2; j++)
		{
			if (matrix[i][j] != 0)
				max = max*matrix[i][j];
		}
	return max;
}
void necessary_matrix(vector<vector<int> >& matrix, int size1, int size2)
{
	cout << "\n Output matrix:\n";
	int i;
	vector<int> string_m(size2);
	for(i = 0; i < size1; i++)
		{
			for(int j = 0; j < size2; j++)
				string_m[j] = matrix[i][j];
			cout << "\n " << string_matrix_func(string_m);
		}
}
