#include "Header.h"

int main() {
    vector <Student> base_of_students;
    vector <Teacher> base_of_teachers;
    int n, m;
    string str1, str2;
    cout << "Enter amount of students: "; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "[Surname Name Patronymic DD::MM:YYYY]\n";
        getline(cin, str1);
        cout << "[id grades]\n";
        getline(cin, str2);
        base_of_students.push_back(Student(str1, str2));
    }
    cout << "Enter amount of teachers: "; cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++) {
        cout << "[Surname Name Patronymic DD::MM:YYYY]\n";
        getline(cin, str1);
        cout << "[subject hours]\n";
        getline(cin, str2);
        base_of_teachers.push_back(Teacher(str1, str2));
    }
    double grants; cout << "Enter the grants amount: ";
    cin >> grants;
    cout << "Students:" << endl;
    for (auto& s : base_of_students) {
        cout << s.getName() << ": " << s.monthly_income(grants) << " UAH" << endl;
    }
    double salary; cout << "Enter the teachers' salary per hour: ";
    cin >> salary;
    cout << "Teachers:" << endl;
    Teacher richest;
    if (base_of_teachers.size() > 0) {
        richest = base_of_teachers[0];
    }
    for (int i = 0; i < m; i++) {
        cout << base_of_teachers[i].getName() << ": " << base_of_teachers[i].monthly_income(salary) << " UAH" << endl;
        if (base_of_teachers[i].monthly_income(salary) > richest.monthly_income(salary)) richest = base_of_teachers[i];
    }
    cout << "The teacher with the biggest salary : " << richest.getName() << "\nHis age: " << richest.count_age();
    return 0;
}