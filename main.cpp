#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
T calcBinom(int a, int bCounter) {
    T result;
    T b = 1;
    for (int i = 1; i <= bCounter; i++) {
        b /= 10;
    }
    result = (a + b) * (a + b) - a * a - 2 * a * b;
    result /= b * b;
    return result;
}

int main() {
    float floatResult[11];
    double doubleResult[11];
    int i;
    for (i = 0; i < 11; i++) {
        floatResult[i] = calcBinom<float>(1000, i);
        doubleResult[i] = calcBinom<double>(1000, i);
    }

    cout << "--- Float Werte ---" << endl;
    for (i = 0; i < 11; i++) {
        if (floatResult[i] == 1.0) {
            cout << "+  |";
        } else {
            cout << "-  |";
        }
        cout << " i = " << setfill(' ') << setw(2) << i << ": " << floatResult[i] << endl;
    }

    cout << endl << endl << "--- Double Werte ---" << endl;
    for (i = 0; i < 11; i++) {
        if (doubleResult[i] == 1) {
            cout << "+  |";
        } else {
            cout << "-  |";
        }
        cout << " i = " << setfill(' ') << setw(2) << i << ": " << doubleResult[i] << endl;
    }
    return 0;
}