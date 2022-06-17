#include "Header.h"
using namespace std;

Vector::Vector(double _Ro, int _Theta, int _Phi) {
    Ro = _Ro;
    Theta = _Theta;
    Phi = _Phi;
}

Vector::Vector(string line) {
    Ro = stod(split(line)[0]);
    Theta = stoi(split(line)[1]);
    Phi = stoi(split(line)[2]);
}

Vector::Vector(Vector& vec) {
    Ro = vec.Ro;
    Theta = vec.Theta;
    Phi = vec.Phi;
}

double Vector::GetRo() {
    return Ro;
}

int Vector::GetTheta() {
    return Theta;
}

int Vector::GetPhi() {
    return Phi;
}

double Vector::FindX() {
    return (Ro * sin(Theta)) * cos(Phi);
}

double Vector::FindY() {
    return (Ro * sin(Theta)) * sin(Phi);
}

double Vector::FindZ() {
    return Ro * cos(Theta);
}

Vector Vector::operator+= (int deg) {
    this->Theta += deg;
    return *this;
}

bool operator!= (Vector& a, Vector& b) {
    return (a.GetRo() / b.GetRo() > 0) && (a.GetTheta() == b.GetTheta()) && (a.GetPhi() == b.GetPhi());
}

vector<string> split(string line) {
    vector<string> coords;
    char sep = ' ';
    line += sep;
    string buffer = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == sep) {
            if (buffer.length() > 0)
                coords.push_back(buffer);
            buffer = "";
        }
        else
            buffer += line[i];
    }
    return coords;
}