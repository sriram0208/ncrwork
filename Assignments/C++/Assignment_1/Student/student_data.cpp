#include<iostream>
using namespace std;
class Student {
	char name[20];
	int marks1, marks2, marks3;
	float average;
	char grade[10];
public:
	void set_data(const char *sname, int m1, int m2, int m3) {
		strcpy_s(name, sname);
		marks1 = m1;
		marks2 = m2;
		marks3 = m3;
	}
	void calculateAverage() {
		average = (marks1 + marks2 + marks3) / 3.0;
	}
	void computeGrade() {
		if (average > 60)
			strcpy_s(grade, "first class");
		else if (average > 50)
			strcpy_s(grade, "second class");
		else if (average > 40)
			strcpy_s(grade, "thirsd class");
		else
			strcpy_s(grade, "Fail");
	}
	void display_details() {
		cout << "St_Name\t" << "Marks1\t" << "Marks2\t" << "Marks3\t" << "Avg\t" << "Grade\t" << endl;
		cout << name << "\t" << marks1 << "\t" << marks2 << "\t" << marks3 << "\t" << average << "\t" << grade << endl;
	}
};
int main() {
	Student S;
	S.set_data("sriram", 40, 50, 60);
	S.computeGrade();
	S.display_details();
	getchar();
}