#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Student {
private:
    string name;
public:
    Student(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    virtual double Solve(double a, double b, double c) = 0;
};

class GoodStudent : public Student {
public:
    GoodStudent(string name) : Student(name) {}
    double Solve(double a, double b, double c) {
        double d = (b * b) - (4 * a * c);
        if (d >= 0) {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            return x1;
        }
    }
};



class MiddleStudent : public Student {
public:
    MiddleStudent(string name) : Student(name) {}
    double Solve(double a, double b, double c) {
        double d = (b * b) - (4 * a * c);
        srand(time(NULL));
        if (d >= 0) {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            if (rand() % 2 == 1) {
                return x1;
            }
            else
                return x2;
        }
    }

};

class BadStudent : public Student {
public:
    BadStudent(string name) : Student(name) {}
    double Solve(double a, double b, double c) {
        return  NAN;
    }
};

class Teacher {
private:
    vector<pair<Student*, int>> students;

public:

    void addStudent(Student* student) {
        students.push_back(make_pair(student, 0));
    };

    void checkMessage(string filename) {

        ifstream file(filename);

        if (file) {
            string line;
            while (getline(file, line)) {
                vector<string> coefficients = splitString(line);
                double a = stod(coefficients[0]);
                double b = stod(coefficients[1]);
                double c = stod(coefficients[2]);
                double x = stod(coefficients[3]);
                string nameStudent = coefficients[4];

                for (auto& student : students) {
                    if ((student.first->getName() == nameStudent)&&(student.first->Solve(a, b, c) == x) ) {
                        student.second ++;
                       
                    }
                }
            }
        }
        else {
            cout << "File not found!" << endl;
        }
    }

    void printStudents() {
        for (auto& student : students) {
            cout << student.first->getName() << ": " << student.second << endl;
        }
    }

    vector<string> splitString(string line) {
        vector<string> resualt;
        string part;
        for (char symbol : line) {
            if (symbol == ' ') {
                resualt.push_back(part);
                part = "";
            }
            else {
                part += symbol;
            }
        }
        resualt.push_back(part);
        return resualt;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    GoodStudent* gs1 = new GoodStudent("Кузнецов");
    GoodStudent* gs2 = new GoodStudent("Смирнов");
    MiddleStudent* ms1 = new MiddleStudent("Андреев");
    MiddleStudent* ms2 = new MiddleStudent("Лебедев");
    BadStudent* bs1 = new BadStudent("Иванов");
    BadStudent* bs2 = new BadStudent("Петров");

    Teacher* teacher = new Teacher();
    teacher->addStudent(gs1);
    teacher->addStudent(gs2);
    teacher->addStudent(ms1);
    teacher->addStudent(ms2);
    teacher->addStudent(bs1);
    teacher->addStudent(bs2);

    teacher->checkMessage("quadratic_equations.txt");
    teacher->printStudents();

    delete gs1;
    delete gs2;
    delete ms1;
    delete ms2;
    delete bs1;
    delete bs2;
    delete teacher;

    return 0;
}

