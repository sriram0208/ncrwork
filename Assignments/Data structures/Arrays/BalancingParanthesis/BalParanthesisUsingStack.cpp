#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkIsParan(string str) {
	for (int i = 0;i < str.length();i++) {
		switch (str[i]) {
			case '(':
			case ')':
			case '[':
			case ']':
			case '{':
			case '}':
				break;
			default:return 0;
		}
	}
	return 1;
}
bool balancedParan(string paran) {
	stack<char> s;
	int topParan;
	for (int i = 0;i < paran.length();i++) {
		if (paran[i] == '(' || paran[i] == '[' || paran[i] == '{') {
			s.push(paran[i]);
			continue;
		}
		if (s.empty())
			return false;
		switch (paran[i]) {
		case ')':	topParan = s.top();
			s.pop();
			if (topParan != '(')
				return false;
			break;
		case '}':	topParan = s.top();
			s.pop();
			if (topParan != '{')
				return false;
			break;
		case ']':   topParan = s.top();
			s.pop();
			if (topParan != '[')
				return false;
			break;
		}
	}
	return s.empty();
}
int main() {
	string paran;
	char choice;
	cout << "Enter your choice :\n1)Enter paranthesis string\n0)Exit\n\n";
	cin >> choice;
	while (choice == '1') {
		cout << "Enter paranthesis string : ";
		cin >> paran;
		if (checkIsParan(paran))
		{
			if (balancedParan(paran))
				cout << "Given paranthesis is valid\n\n";
			else
				cout << "Given paranthesis is invalid\n\n";
		}
		else
			cout << "String contains other than paranthesis\n\n";
		cout << "Enter your choice :\n1)Enter paranthesis string\n0)Exit\n\n";
		cin >> choice;
	}
	getchar();
}