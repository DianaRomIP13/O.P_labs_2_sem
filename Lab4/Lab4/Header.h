#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


class Vector {
private:
    double Ro;
    int Theta;
    int Phi;
public:
    Vector(double _Ro, int _Theta, int _Phi);
    Vector(string line);
    Vector(Vector& pt);

    double GetRo();
    int GetTheta();
    int GetPhi();

    double FindX();
    double FindY();
    double FindZ();

    Vector operator+= (int deg);
    friend bool operator!= (Vector& a, Vector& b);
};

void FindAngle(int& degree);
std::vector<std::string> split(std::string);