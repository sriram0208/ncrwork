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
	int lNum = 0, rNum = 0, res,tempRes, digit;
	for (int idx =0;idx <lhs.length();idx++) {
		if(isdigit(lhs[idx]))
			lNum = lNum * 10 + (lhs[idx] - '0');
	}
	if (lhs.find('-'))
		lNum = -lNum;
	for (int idx =0;idx <rhs.length();idx++) {
		if (isdigit(rhs[idx]))
			rNum = rNum * 10 + (rhs[idx] - '0');
	}
	if (rhs.find('-'))
		rNum = -rNum;

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

	if (res < 0)
		tempRes = -res;

	string resStr;

	while (tempRes != 0) {
		digit = tempRes % 10;
		resStr.push_back(((char)digit + '0'));
		tempRes = tempRes / 10;
	}

	str_rev(resStr);

	return resStr;
}
string  evaluateExpWithoutParan(string exp) {

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
	return exp;
}

//bool checkValidExpression(string str) {
//
//}

int searchForClosingParanthesis(string str, int startIdx) {
	while (str[startIdx] != ')') {
		startIdx++;
	}
	return startIdx;
}
void evaluateExpWithParan(string &parStr) {
	int cnt = 0,idx,start,end;
	for (idx = 0;idx < parStr.length();idx++) {
		if (parStr[idx] == '(')
			cnt++;
	}
	idx = parStr.length()-1;
	while (idx >= 0 && cnt != 0) {
		if (parStr[idx] == '(') {
			start = idx+1;
			end = searchForClosingParanthesis(parStr, start)-1;
			string temp=evaluateExpWithoutParan(parStr.substr(start, end - start + 1));
			parStr.replace(start-1, (end+1) - (start-1) + 1,temp);
			idx=start;
			cnt--;
		}
		idx--;
	}
}
int main() {
	/*((23+(2-78))+-----1*234/23)+(12-8)
	45+65-78/77*-78-+78;
	---3*/

	string str;//="  5+4*68/4/3*(2-1)";
	cin >> str;
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	evaluateExpWithParan(str);
	cout << str << endl;
	


	getchar();
	getchar();

	return 0;
}