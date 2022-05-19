#include "Header.h"

Text::Text() {
    cout << "Enter the text. To stop typing, press Ctrl + X" << endl;
    string temp;
    getline(cin, temp);
    while (temp[0] != 24) {
        text.push_back(temp);
        getline(cin, temp);
    }
}

void Text::AddString(string line) {
    text.push_back(line);
}

double Text::CountGivenSymbols(char symbol) {
    double totalsumofsymbols = 0, sumofgivensymbols = 0;
    for (auto s : text) {
        totalsumofsymbols += s.size();
        sumofgivensymbols += count(begin(s), end(s), symbol);
    }
    if (!totalsumofsymbols) return 0;
    return sumofgivensymbols / totalsumofsymbols;
}

void Text::DisplayText() {
    cout << "------------------------" << endl;
    for (auto s : text) {
        cout << s << endl;
    }
    cout << "------------------------" << endl << endl;
}

char FindTheMostCommonSymbolInGivenTexts(Text* text, int size) {
    int ascii[255]{};
    for (size_t i = 0; i < size; i++) {
        for (auto m : text[i].text) {
            for (auto n : m) {
                ascii[(int)n]++;
            }
        }
    }
    int max = *max_element(ascii, ascii + 255);
    for (size_t i = 0; i < 255; i++) {
        if (ascii[i] == max) {
            return (char)i;
        }
    }
}