#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float functionFloat(int, int);

double functionDouble(int, int);

int main() {
    float floatResult[11];
    double doubleResult[11];
    int i;
    for (i = 0; i < 11; i++) {
        floatResult[i] = functionFloat(1000, i);
        doubleResult[i] = functionDouble(1000, i);
    }

    cout << "--- Float Werte ---" << endl;
    for (i = 0; i < 11; i++) {
        if (floatResult[i] == 1.0) {
            cout << "+  |";
        } else {
            cout << "-  |";
        }
        cout << " i = " << setfill(' ') << setw(2) << i << ": " << setprecision(10) << floatResult[i] << endl;
    }

    cout << endl << endl << "--- Double Werte ---" << endl;
    for (i = 0; i < 11; i++) {
        if (doubleResult[i] == 1) {
            cout << "+  |";
        } else {
            cout << "-  |";
        }
        cout << " i = " << setfill(' ') << setw(2) << i << ": " << setprecision(10) << doubleResult[i] << endl;
    }
    return 0;
}

float functionFloat(int a, int bCounter) {
    float result;
    float b = pow(10, -bCounter);
    result = pow(a + b, 2) - pow(a, 2) - 2 * a * b;
    result /= pow(b, 2);
    return result;
}

double functionDouble(int a, int bCounter) {
    double result;
    double b = pow(10, -bCounter);
    result = (pow(a + b, 2) - pow(a, 2) - 2 * a * b);
    result /= pow(b, 2);
    return result;
}