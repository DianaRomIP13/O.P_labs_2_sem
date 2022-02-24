#include <fstream>
#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

void inFile(string path)
{
    ofstream fout;
    fout.open(path);
    if (!fout.is_open()) {
        cout << "Cnnot open file!" << endl;
    }
    else {
        string text = "";
        string s;
        cout << "Enter your text. To finish entering Ctrl + X.\n";
        cin.ignore();
        getline(cin, s);
        while (s[0] != 24)
        {
            fout << s;
            getline(cin, s);
            if (s[0] != 24) {
                fout << '\n';
            }
        }
    }
    fout.close();
}

void compare(string path1, string path2, string path3, int& count_string) {

    ofstream fout;
    fout.open(path3);
    ifstream fin1;
    ifstream fin2;
    fin1.open(path1);


    string text = "";

    if (!fin1.is_open()) {
        cout << "Cnnot open file!" << endl;
    }
    else {
        string str1, str2;

        while (!fin1.eof()) {
            fin2.open(path2);
            bool is_string_in = false;
            getline(fin1, str1);
            while (!fin2.eof()) {
                getline(fin2, str2);
                if (str1 == str2) {
                    is_string_in = true;
                    break;
                }
            }
            if (!is_string_in) {
                fout << str1 << '\n';
                count_string = count_string + 1;
            }
            fin2.close();
        }
    }
    fin1.close();

    fout.close();
}

void outFile(string path) {
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        cout << "Cnnot open file!" << endl;
    }
    else {
        string str;
        while (!fin.eof()) {
            str = "";
            getline(fin, str);
            cout << str << endl;
        }
    }
    fin.close();

}