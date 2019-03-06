#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void str_rev(string &str) {
	char temp;
	for (int i = 0,j=str.length()-1;i < j;i++,j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

string performOperation(string lhs, string rhs,char operation) {
	int lNum = 0, rNum = 0, res, digit;
	for (int idx =0;idx <lhs.length();idx++) {
		lNum = lNum * 10 + (lhs[idx] - '0');
	}
	for (int idx =0;idx <rhs.length();idx++) {
		rNum = rNum * 10 + (rhs[idx] - '0');
	}
	switch (operation) {
	case '/':	res = lNum / rNum;
				break;
	case '*':	res = lNum * rNum;
				break;
	case '+':	res = lNum + rNum;
				break;
	case '-':	res = lNum - rNum;
				break;
	}

	string resStr;

	while (res != 0) {
		digit = res % 10;
		resStr.push_back(((char)digit + '0'));
		res = res / 10;
	}
	str_rev(resStr);

	return resStr;
}
void evaluateExpression(string &exp) {

	char operation[4] = { '/','*','+','-' };

	for (int oper_idx = 0;oper_idx < 4;oper_idx++) {
		int i = 0, j, k, cnt = 0;

		for (int idx = 0;idx < exp.length();idx++) {
			if (exp[idx] == operation[oper_idx])
				cnt++;
		}

		while (i < exp.length() && cnt>0) {
			if (exp[i] == operation[oper_idx]) {
				j = i - 1;
				k = i + 1;
				while (j >= 0 && isdigit(exp[j]))
					j--;
				while (k < exp.length() && isdigit(exp[k]))
					k++;
				int start = j + 1;
				int end = k - 1;
				exp.replace(start, end - start + 1, performOperation(exp.substr(start, i - (start)), exp.substr(i + 1, end - i), operation[oper_idx]));
				i = start;
				cnt--;
			}
			i++;
		}
	}
}

int main() {
	/*((23+(2-78))+-----1*234/23)+(12-8)
	45+65-78/77*-78-+78;
	---3*/

	string str="  5+4*68/4/3*2-1";
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

	cout << str << endl;
	evaluateExpression(str);
	cout << str << endl;
	


	getchar();
	return 0;
}