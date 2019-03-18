#include<iostream>
#define SIZE 20
using namespace std;
class Student {
	int roll_no, marks1, marks2, marks3, total;
	char *name, grade;
public:
	Student() {
	}
	void set_data(const char *str, int r, int m1, int m2, int m3) {
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
		roll_no = r;
		marks1 = m1;
		marks2 = m2;
		marks3 = m3;
	}
	friend void generate_results(Student[], int);
	friend ostream& operator<<(ostream&, Student);
};
ostream& operator<<(ostream& cout, Student S) {
	cout << "Name :" << S.name << " Roll_no :" << S.roll_no << " Marks :" << S.marks1 << " " << S.marks2 << " " << S.marks3 << "\n";
	return cout;
}
void generate_results(Student S[], int n) {
	for (int i = 0;i < n;i++)
		cout << S[i];
}
int main() {

	Student *S;
	char name[SIZE];
	int studentCnt, rollNo, marks1, marks2, marks3;
	cout << "\nEnter no. of students\n";
	cin >> studentCnt;
	S = new Student[studentCnt];
	while (studentCnt != 0) {
		for (int id = 0;id < studentCnt;id++) {
			cout << "\nEnter student name : ";
			cin >> name;
			cout << "\nEnter roll no. ,marks of 3 subjects :";
			cin >> rollNo >> marks1 >> marks2 >> marks3;
			S[id].set_data(name, rollNo, marks1, marks2, marks3);
		}
		generate_results(S, studentCnt);
		delete[]S;
		cout << "Enter no. of students\n";
		cin >> studentCnt;
		S = new Student[studentCnt];
	}
	delete[]S;
	getchar();
	return 0;
}