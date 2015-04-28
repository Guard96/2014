#include <iostream>
#include <cstring>
#include <clocale>
#include <cstdlib>
#include <stack>
//.....................................................................
using namespace std;

int main(); // главная функция
int error(char *s); //функция вывода ошибки
void calculate(stack<double>& stack); //ф-ция вычисляющая значение выражения путем RPN

int
error(char *s) {
	cout << "\n" << s;
	system("pause");
	return -1;
}

char
parce(char str) {
	stack.
}
void 
calculate(stack<double>& stack) {
	char x;
	while (cin >> x && x != '\0') {
		switch (x) {
			
			case ' ': break;

			case '+':{
						 double a = stack.top();
						 stack.pop();
						 double b = stack.top();
						 stack.pop();
						 stack.push(a + b);
			} break;

			case '-':{
						 double a = stack.top();
						 stack.pop();
						 double b = stack.top();
						 stack.pop();
						 stack.push(a - b);
			} break;

			case '*':{
						 double a = stack.top();
						 stack.pop();
						 double b = stack.top();
						 stack.pop();
						 stack.push(a * b);
			} break;

			case '/':{
						double a = stack.top();
						stack.pop();
						double b = stack.top();
						stack.pop();
						stack.push(a / b);
			} break;

			case ':':{
						 double a = stack.top();
						 stack.pop();
						 double b = stack.top();
						 stack.pop();
						 stack.push(a / b);
			} break;
	
			default:{
						stack.push(x);
						calculate(stack);
			}
		}
	}
}
int
main() {
	setlocale(LC_ALL, "Russian");
	stack <double> stack;
	cout << "Калькулятор, версия 1.0.0\n\n";
	cout << "Эта программа может вычислять выражения любой длины вида: \n\n"
		 << "a + b * c - (a + b * c) / d (знак ' ') не обязателен. \n\n"
		 << "Доступные арифметические действия: \n"
		 << "1) Умножение (*) \n"
		 << "2) Деление (/ или :) \n"
		 << "3) Сложение (+) \n"
		 << "4) Вычитание (-) \n\n"
		 << "Для выхода из программы введите знак q (quit) \n";
	cout << "Введите выражение: \n";
	char x;
	calculate(stack);
	cout << stack.top() << endl;
	return 0;
}
