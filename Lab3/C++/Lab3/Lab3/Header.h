#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Text {
private:
	vector <string> text;
public:
	Text();
	void AddString(string);
	double CountGivenSymbols(char);
	void DisplayText();
	friend char FindTheMostCommonSymbolInGivenTexts(Text*, int);
};

char FindTheMostCommonSymbolInGivenTexts(Text*, int);