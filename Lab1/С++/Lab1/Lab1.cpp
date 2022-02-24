#include <fstream>
#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
    string path1;
    cout << "Name of the first file: ";
    cin >> path1;
    inFile(path1);

    string path2;
    cout << "Name of the second file: ";
    cin >> path2;
    inFile(path2);

    string path3;
    cout << "Name of the third file: ";
    cin >> path3;
    cout << endl;
    int count_string = 0;
    compare(path1, path2, path3, count_string);
    cout << "The first text: " << "\n";
    outFile(path1);
    cout << endl;
    cout << "The second text: " << "\n";
    outFile(path2);
    cout << endl;
    cout << "The third text: " << "\n";
    outFile(path3);
    cout << "The numer of lines: " << count_string;

}

