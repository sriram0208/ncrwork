#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<regex>

using namespace std;

int add(int, int);
int sub(int, int);
int mul(int, int);
int divn(int, int);

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
	case '/':	
				res = divn(lNum, rNum);
				break;
	case '*':	
				res = mul(lNum, rNum);
				break;
	case '+':	
				res = add(lNum, rNum);
				break;
	case '-':	
				res = sub(lNum, rNum);
				break;
	}

	if (res < 0)
		tempRes = -res;
	else
		tempRes = res;

	string resStr;

	while (tempRes != 0) {
		digit = tempRes % 10;
		resStr.push_back(((char)digit + '0'));
		tempRes = tempRes / 10;
	}

	str_rev(resStr);

	return resStr;
}

//This function takes the expression within paranthesis,
//evaluates it and returns the resultant string

string  evaluateExpWithoutParan(string exp) {

	char operation[4] = { '/','*','+','-' };

	//Evaluates all div's first, then mul's, then sums, then sub's--BODMAS--.
	for (int oper_idx = 0;oper_idx < 4;oper_idx++) {
		int i = 0, j, k, cnt = 0;

		//counts no. of operators
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
				string res = performOperation(exp.substr(start, i - (start)), exp.substr(i + 1, end - i), operation[oper_idx]);
				exp.replace(start, end - start + 1,res );
				i = start;
				cnt--;
			}
			i++;
		}
	}
	return exp;
}

bool checkValidExpression(string str) {

	//Checking for division by zero
	int found = str.find("/0");
	if (found != string::npos){
		cout << "Division by zero ocuured\n";
		return false;
	}
	else
		return true;
}


//Returns the index of closing paranthesis
int searchForClosingParanthesis(string str, int startIdx) {
	while (str[startIdx] != ')') {
		startIdx++;
	}
	return startIdx;
}

//This function takes reference of the given string as input
//The string may have paranthesis , this function calls evaluateExpWithoutParan()
//to remove paranthesis
void evaluateExpWithParan(string &parStr) {
	int cnt = 0,idx,start,end;

	//counts no. of paranthesis
	for (idx = 0;idx < parStr.length();idx++) {
		if (parStr[idx] == '(')
			cnt++;
	}

	if (cnt == 0) {
		start = 0;
		end= parStr.length() - 1;
		string temp = evaluateExpWithoutParan(parStr.substr(start, end - start + 1));
		
		parStr.replace(start, parStr.length(), temp);
	}

	else {
		//search for opening paranthesis from right ,and pass the expression within paranthesis
		//to evaluateExpWithoutParan() function
		idx = parStr.length() - 1;
		while (idx >= 0 && cnt != 0) {
			if (parStr[idx] == '(') {
				start = idx + 1;
				end = searchForClosingParanthesis(parStr, start) - 1;
				string temp = evaluateExpWithoutParan(parStr.substr(start, end - start + 1));
				parStr.replace(start - 1, (end + 1) - (start - 1) + 1, temp);
				idx = start;
				cnt--;
			}
			idx--;
		}
		start = 0;
		end = parStr.length() - 1;
		string temp = evaluateExpWithoutParan(parStr.substr(start, end - start + 1));
		parStr.replace(start, parStr.length(), temp);
	}
}
int main() {
	
	string str;
	char proceed;
	do {
		cout << "Enter the expression to be evaluated\n";
		cin >> str;
		str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		if (false == checkValidExpression(str))
			cout << "Invalid expression\n";
		else {
			evaluateExpWithParan(str);
			cout << str << endl;
		}
		cout << "Do you want to continue?(Y/N) : ";
		cin >> proceed;
	} while (proceed == 'Y' || proceed=='y');
	getchar();
	getchar();

	return 0;
}