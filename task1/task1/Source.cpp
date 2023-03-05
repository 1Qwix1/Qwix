#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double a, b, c;
double x1, x2;

void initialization(const char* file_name);
int solve_out(const char* file_name);

int main() {
    initialization("input.txt");
    solve_out("output.txt");
    return 1;
}

void initialization(const char* file_name) {
    ifstream fin(file_name);
    if (!(fin.is_open())) {
        cout << "File not find\n";
        exit(1);
    }
    for (int i = 1; i <= 3; i++) {

        if (i == 1) {
            fin >> a;
          
        }

        else if (i == 2) {
            fin >> b;
           
        }

        else if (i == 3) {
            fin >> c;

        }
    }
    fin.close();
}

int solve_out(const char* file_name) {
    ofstream fout(file_name);
    double D;
    D = pow(b, 2) - 4 * a * c;
    if (D > 0)
    {
        x1 = ((-b) + sqrt(D)) / (2 * a);
        x2 = ((-b) - sqrt(D)) / (2 * a);
        fout << "x1 = " << x1 << endl;
        fout << "x2 = " << x2 << endl;
        return 2;
    }
    else if (D == 0)
    {
        fout << "Only one solution: " << endl;
        x1 = -(b / (2 * a));
        fout << "x= " << x1 << endl;
        return 1;
    }
    else if (D < 0) {
        fout << "D < 0, There are no real roots of the equation" << endl;
        return 0;
    }
    fout.close();
}
