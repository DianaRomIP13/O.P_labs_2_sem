#include "Header.h"

int main() {
	string path1, path2;
	bool format;
	cout << "Enter the file name: "; cin >> path1;
	cout << "Choose the input format (0 - create new; 1 - append)" << endl; cin >> format;
	inFile(path1, format);
	outFile(path1);
	cout << '\n' << "Store profit: " << StoreProfit(path1) << '\n';
	cout << '\n' << "Enter the new file name: "; cin >> path2;
	inNewFile(path1, path2);
	outFile(path2);
}