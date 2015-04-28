#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>


class A
{
public:
	virtual void print(){}
};

class num : public A
{
	double value;

	void print()
	{
		printf("����� %.1f\n", value);
	}
public:
	num(double v)
	{
		value = v;
	}
};

class Litera : public Item
{
	char * value;

	void print()
	{
		printf("������ \"%s\"\n", value);
	}
public:
	Litera(char * v)
	{
		value = v;
	}
	~Litera()
	{
		free(value);
	}
};

class Symbol : public Item
{
	char value;

	void print()
	{
		printf("������ '%c'\n", value);
	}
public:
	Symbol(char v)
	{
		value = v;
	}
};

bool isNumber(char c)
{
	return c >= '0' && c <= '9';
}

bool isLitera(char c)
{
	return	c >= 'A' && c <= 'Z' ||
		c >= 'a' && c <= 'z';
}

bool isSymbol(char c)
{
	return !isNumber(c) && !isLitera(c);
}

int main()
{
	setlocale(0, "Russian");

	std::vector <Item *> items;

	char * input = _strdup("testing+322 l / 2,2 wat = 75,3,14");
	int len = strlen(input);
	char c;
	bool flag_number = false;
	bool use_tochka = false;
	std::vector<char> buff;

	printf("�������� ������:\n%s\n\n", input);

	for (int i = 0; i <= len; i++)
	{
		c = input[i];
		if (flag_number && c == ',' && !use_tochka) {
			use_tochka = true;
			buff.push_back(c);
		}
		else
		{
			if (isSymbol(c))
			{
				if (buff.size() != 0) {
					char * temp = new char[buff.size() + 1];
					int _y = 0;
					for (auto y = buff.begin(); y != buff.end(); y++, _y++)
						temp[_y] = *y;
					temp[_y] = 0;

					if (flag_number) {
						items.push_back(new Num(atof(temp)));
						flag_number = false;
						use_tochka = false;
						delete temp;
					}
					else
						items.push_back(new Litera(temp));

					buff.clear();
				}
				if (c != 0)
					items.push_back(new Symbol(c));
			}
			else
			{
				if (flag_number || buff.size() == 0)
					flag_number = isNumber(c);

				buff.push_back(c);
			}
		}
	}

	for (auto i = items.begin(); i != items.end(); i++)
		(*i)->print();



	for (auto i = items.begin(); i != items.end(); i++)
		delete *i;
	items.clear();
	free(input);

	system("pause");
	return EXIT_SUCCESS;
}