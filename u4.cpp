#include <iostream>
#include <cmath>

using namespace std;

#define size 10

void gauissan() {


    // Create Matrix and Vector
    double vector[size], controlVector[size];
    double matrix[size][size], controlMatrix[size][size];

    //Init Matrix and vector with values between 0 and 4.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            controlMatrix[i][j] =  matrix[i][j] = rand() % 5;
        }
        controlVector[i] = vector[i] = rand() % 5;
    }


    int index;
    double value, left;
    //Gaussian
    for (int k = 0; k < size - 1;  k++) {
        index = k;
        value = 0;

        //Pivot search
        for (int j = k; j < size; j++) {
            if (fabs(matrix[j][k]) > value) {
                index = j;
                value = fabs(matrix[j][k]);
            }
        }

        //Swap rows in matrix and vector
        if (k != index) {
            swap(matrix[k], matrix[index]);
            swap(vector[k], vector[index]);
        }
        //Pivot search completed

        for (int i = k+1; i < size; i++) {
            left = matrix[i][k] / matrix[k][k];

            for (int j = k; j < size; j++) {

                matrix[i][j] = matrix[i][j] - left * matrix[k][j];
            }

            vector[i] = vector[i] - left * vector[k];
        }
    }

    //upper matrix and vector are calc, calc values of variables
    for (int l = size; l >= 0; l--) {


        for (int i = size; i > l; i--) {
            vector[l] = vector[l] - matrix[l][i]* vector[i];
        }

        vector[l] = vector[l] / matrix[l][l];
        matrix[l][l] = 1;
    }

    double tempVector[size] = {0};

    for (int n = 0; n < size; ++n) {
        for (int i = 0; i < size; i++) {
            tempVector[n] += controlMatrix[n][i] * vector[i];
        }
    }


    cout << "calculated vector | control vector" << endl;
    for (int m = 0; m < size; m++) {
        //cout << vector[m] << endl;
        cout << "Index -> " << m << ": " << tempVector[m] << " | " << controlVector[m] << endl;
    }


}

int main() {
    for (int i = 0; i < 10; ++i) {
        gauissan();
        cout << endl << endl;
    }
    return 0;
}