#include <iostream>
#include "math.h"

using namespace std;

template<typename T>
T calcTaylorSum(int);

template <typename T>
void calcLim(int, int, int, int);

template <typename T>
T _calcLim(int, int);

int main() {
    int x = -20;
    auto a = calcTaylorSum<float>(x);
    auto b = 1.0/ calcTaylorSum<float>(-x);
    cout << "e^(" << x << ") with double: " << a << endl
         << "1 / e^" << -x << " with double: " << b << endl;
    calcLim<double>(x, 10000000, 1000000, 10000001);
    cout << endl << endl << "--------" << endl << "With math.h is exp(" << x << ") = " << exp(x) << " and 1/exp(" << -x <<") = " << 1.0/exp(-x) << endl;
    return 0;
}

template<typename T>
T calcTaylorSum(int x) {
    int i = 1;
    T myX = x;
    T last_result = -1.0;
    T result = 1.0;
    T termToAdd = 1.0;
    while (last_result != result) { // i is greater than 1
        last_result = result;
        termToAdd *= myX / i++;
        result += termToAdd;
    }
    return result;
}


template <typename T>
void calcLim(int x, int start, int step, int end) {
    for (int i = start; i < end; i += step) {
        cout << "i is " << i << " and lim is " << _calcLim<T>(i, x) << endl;
    }
}

template <typename T>
T _calcLim(int n, int x) {
    T step = 1;
    for (int counter = 0; counter < n; counter++) {
        step *= (T) 1 + ((T) x / (T) n);
    }
    return step;
}