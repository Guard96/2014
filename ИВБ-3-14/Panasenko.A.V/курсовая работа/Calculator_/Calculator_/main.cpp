#include <iostream>
#include <cstring>
#include <clocale>
#include <cstdlib>
#include <stack>
//.....................................................................
using namespace std;

int main(); // ������� �������
int error(char *s); //������� ������ ������
void calculate(stack<double>& stack); //�-��� ����������� �������� ��������� ����� RPN

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
	cout << "�����������, ������ 1.0.0\n\n";
	cout << "��� ��������� ����� ��������� ��������� ����� ����� ����: \n\n"
		 << "a + b * c - (a + b * c) / d (���� ' ') �� ����������. \n\n"
		 << "��������� �������������� ��������: \n"
		 << "1) ��������� (*) \n"
		 << "2) ������� (/ ��� :) \n"
		 << "3) �������� (+) \n"
		 << "4) ��������� (-) \n\n"
		 << "��� ������ �� ��������� ������� ���� q (quit) \n";
	cout << "������� ���������: \n";
	char x;
	calculate(stack);
	cout << stack.top() << endl;
	return 0;
}
