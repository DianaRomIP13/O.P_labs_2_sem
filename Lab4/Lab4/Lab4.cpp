#include "Header.h"
using namespace std;

int main() {
	double _ro;
	int _theta, _phi;
	cout << "1) Enter coordinates: ";
	cout << "\tRo: "; cin >> _ro; cout << endl;
	cout << "\t\t\tTheta: "; cin >> _theta; cout << endl;
	cout << "\t\t\tPhi: "; cin >> _phi; cout << endl;
	Vector B1(_ro, _theta, _phi);
	cout << "Vector B1: (" << B1.GetRo() << ", " << B1.GetTheta() << ", " << B1.GetPhi() << ")\n";
	string line;
	cout << "2) Enter coords: ";
	cin.ignore();
	getline(cin, line, '\n');
	Vector B2(line);
	cout << "Vector B2: (" << B2.GetRo() << ", " << B2.GetTheta() << ", " << B2.GetPhi() << ")\n";
	Vector B3(B1);
	cout << "Vector B3: (" << B3.GetRo() << ", " << B3.GetTheta() << ", " << B3.GetPhi() << ")\n";
	int value;
	cout << "Enter value to increase Theta of B1: "; cin >> value;
	B1 += value;
	cout << "Changed B1: (" << B1.GetRo() << ", " << B1.GetTheta() << ", " << B1.GetPhi() << ")\n";
	cout << "Cartesian coords of B1: (" << B1.FindX() << ", " << B1.FindY() << ", " << B1.FindZ() << ")\n";
	cout << "Is B2 collinear to B3? " << (B2 != B3) << endl;
}