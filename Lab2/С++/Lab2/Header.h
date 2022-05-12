#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h> 

using namespace std;

class Client {
public:
	char sec_name[255];
	char sex;
	char date_of_birth[255];
	int amount;
	int spent;
	Client(string = "none n 01:01:1970 0");
	int GetAge(); 
};

int StoreProfit(string);
void outFile(string);
void inFile(string, bool);
void inNewFile(string, string);
vector<string> split(string, char sep = ' '); 