#include "Header.h"

Person::Person(string line) {
    name = split(line)[0] + ' ' + split(line)[1] + ' ' + split(line)[2];
    date_of_birth = split(line)[3];
}

string Person::getName() {
    return name;
}

double Person::monthly_income(double hours) {
    return (150 * hours); 
}

string Person::count_age() {
    SYSTEMTIME current_date;
    GetLocalTime(&current_date);
    int birth_year = stoi(split(date_of_birth, ':')[2]);
    int birth_month = stoi(split(date_of_birth, ':')[1]);
    int birth_day = stoi(split(date_of_birth, ':')[0]);
    int d_day, d_month, d_year;
    d_year = current_date.wYear - birth_year;
    if (current_date.wMonth < birth_month) { d_month = current_date.wMonth + 12 - birth_month; }
    else { d_month = current_date.wMonth - birth_month; }
    if (current_date.wDay < birth_day) { d_day = current_date.wDay + 30 - birth_day; }
    else { d_day = current_date.wDay - birth_day; }
    if (current_date.wMonth < birth_month || current_date.wMonth == birth_month && current_date.wDay < birth_day) {
        d_year--;
    }
    string age = "";
    age += to_string(d_year) + "year(s)" + to_string(d_month) + "month(s)" + to_string(d_day) + "day(s)\n";
    return age;
}

Student::Student(string line1, string line2) : Person(line1) {
    group_id = stoi(split(line2)[0]);
    average_grade = stod(split(line2)[1]);
}

double Student::monthly_income(double grants)
{
    if (average_grade >= 95) {
        status = 'h';
        return grants * 1.4;
    }
    if (average_grade >= 85) {
        status = 'd';
        return grants;
    }
    status = 'n';
    grants = 0;
    return 0;
}

Teacher::Teacher(string line1, string line2) : Person(line1) {
    subject = split(line2)[0];
    hours = stoi(split(line2)[1]);
}

int Teacher::getHours() {
    return hours;
}

double Teacher::monthly_income(double payment)
{
    return (payment * this->getHours());
}

vector<string> split(string line, char sep) {
    vector<string> words;
    string temp_word = "";
    line += sep;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == sep) {
            if (temp_word.length() > 0) {
                words.push_back(temp_word);
            }
            temp_word = "";
        }
        else {
            temp_word += line[i];
        }
    }
    return words;
}