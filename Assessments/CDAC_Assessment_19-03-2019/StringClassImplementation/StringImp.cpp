#include<iostream>
#include<string.h>
using namespace std;


class MyString {
	char *strPtr;
	int len;
public:
	//Default constructor
	MyString() {
		strPtr = NULL;
		len = 0;
	}

	//Parameterized constructor
	MyString(const char *paramStr) {
		len = strlen(paramStr);
		strPtr = (char *)malloc((len + 1) * sizeof(char));
		strcpy_s(strPtr,len+1, paramStr);
	
	}

	//Deep copy--overloaded = operator
	MyString operator=(MyString copyStr) {
		if (strPtr != NULL) {
			free(strPtr);
		}
		len = strlen(copyStr.strPtr);
		strPtr = (char *)malloc((len + 1) * sizeof(char));
		strcpy_s(strPtr,len+1, copyStr.strPtr);
		//strPtr[len] = '\0';
		return (*this);
	}

	//Destructor
	~MyString() {
		if (strPtr != NULL)
			free(strPtr);
	}

	//Concatenation of strings--overloaded + operator
	MyString operator+(MyString secondStr) {
		MyString temp;
		temp.len = len + secondStr.len+1;
		if (temp.strPtr != NULL)
			free(temp.strPtr);
		temp.strPtr = (char *)malloc((temp.len + 1) * sizeof(char));
		strcpy_s(temp.strPtr,temp.len+1, strPtr);
		for (int tempIdx = len,secondIdx=0;secondIdx < secondStr.len;tempIdx++,secondIdx++) {
			temp.strPtr[tempIdx] = secondStr.strPtr[secondIdx];
		}
		return temp;
	}

	//friend function for extraction operator
	friend ostream& operator<<(ostream&, MyString);

	//friend function for insertion operator
//	friend ostream& operator>>(ostream&, &MyString);

	void displayStr() {
		for (int i = 0;i < len;i++)
			cout << strPtr[i];
		cout << "\n";
	}
};
ostream& operator<<(ostream& cout, MyString readStr) {
	cout << readStr.strPtr;
	return cout;
}

//istream& operator>>(istream& cin, MyString writeStr) {
//	char ch;
//	while(ch!='\n')
//		cin >> temp;
//}
int main() {
	MyString testStr1("sriram"),testStr2("reddy"),res;
	testStr1 + testStr2;
	res.displayStr();
	getchar();
	return 0;
}