#include<iostream>
using namespace std;
class employee {

	char name[20];
	int emp_no, sal;
public:
	employee() {
	}
	employee(const char *str, int e, int s) {
		strcpy_s(name, strlen(str) + 1, str);
		emp_no = e;
		sal = s;
	}
	void set_data() {
		cout << "Enter name :" << "\n";
		cin >> name;
		cout << "Enter employee no. , salary" << "\n";
		cin >> emp_no >> sal;
	}
	void read_data() {
		cout << "Name :" << name << "\temp_no :" << emp_no << "\tsalary :" << sal << "\n";
	}
	friend istream& operator>>(istream&, employee&);

};
istream& operator>>(istream& cin, employee &e) {
	cin >> e.name >> e.emp_no >> e.sal;
	return cin;
}
void main() {
	employee e1("sriram", 96, 45000);
	e1.read_data();
	employee em[5];
	for (int i = 0;i < 2;i++) {
		cin >> em[i];
	}
	for (int i = 0;i < 2; i++) {
		em[i].read_data();
	}
	getchar();
	getchar();
}