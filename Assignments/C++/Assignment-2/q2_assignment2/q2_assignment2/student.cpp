#include<iostream>
using namespace std;
class Student {
	int roll_no, marks1,marks2,marks3, total;
	char *name, grade;
public:
	Student() {
	}
	void set_data(const char *str, int r, int m1,int m2,int m3) {
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
		roll_no = r;
		marks1 = m1;
		marks2 = m2;
		marks3 = m3;
	}
	friend void generate_results(Student [], int);
	friend ostream& operator<<(ostream&, Student);
};
ostream& operator<<(ostream& cout, Student S) {
	cout << "Name :" << S.name << " Roll_no :" << S.roll_no << " Marks :" << S.marks1 <<" "<< S.marks2<<" " << S.marks3 << "\n";
	return cout;
}
void generate_results(Student S[], int n) {
	for(int i=0;i<n;i++)
		cout << S[i];
}
void main() {
	Student S[3];
	S[0].set_data("ram", 96, 23,24,25);
	S[1].set_data("raj", 34, 23, 23, 24);
	S[2].set_data("yash", 67, 28, 29, 27);

	generate_results(S, 3);
	getchar();
}