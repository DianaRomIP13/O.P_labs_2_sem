#include "Header.h"

int main() {
    int n; cout << "Enter the number of texts: ";
    cin >> n; cin.ignore();
    if (n == 0) return 0;
    Text* arr = new Text[n];
    for (size_t i = 0; i < n; i++) {
        arr[i].DisplayText();
    }
    for (size_t i = 0; i < n; i++) {
        string response;
        cout << "Add rows to " << i + 1 << " text. To stop entering or skipping this text, enter <skip> " << "\n";
        getline(cin, response);
        while (response.compare("skip")) {
            arr[i].AddString(response);
            getline(cin, response);
        }
        char symbol;
        cout << "Enter the character whose number of occurrences in " << i + 1 << "text must be retrieved ";
        cin >> symbol; cin.ignore();
        cout << arr[i].CountGivenSymbols(symbol) * 100 << '%' << endl;
    }
    for (size_t i = 0; i < n; i++) {
        arr[i].DisplayText();
    }
    cout << "The most common symbol in texts: " << FindTheMostCommonSymbolInGivenTexts(arr, n) << endl;
}
