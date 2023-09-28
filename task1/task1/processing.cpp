#include "processing.h"



vector <double> initialization(string file_name) {
    ifstream fin(file_name);

    if (!(fin.is_open())) {
        cout << "File not find\n";
        exit(1);
    }

    vector <double> index;
    double n;
    while (fin >> n) {
        index.push_back(n);
    }
    fin.close();
    return index;
}

int solve_out(string file_name, vector <double> index) {
    ofstream fout(file_name);
    double x1, x2;
    double D;
    D = pow(index[1], 2) - 4 * index[0] * index[2];
    if (D > 0)
    {
        x1 = ((-index[1]) + sqrt(D)) / (2 * index[0]);
        x2 = ((-index[1]) - sqrt(D)) / (2 * index[0]);
        fout << "x1 = " << x1 << endl;
        fout << "x2 = " << x2 << endl;
        return 2;
    }
    else if (D == 0)
    {
        fout << "Only one solution: " << endl;
        x1 = -(index[1] / (2 * index[0]));
        fout << "x= " << x1 << endl;
        return 1;
    }
    else if (D < 0) {
        fout << "D < 0, There are no real roots of the equation" << endl;
        return 0;
    }
    fout.close();
}