//
// Created by hartlab on 12.05.19.
//

#include <glob.h>
#include "Gaussian.h"
#include <iostream>
#include <cmath>
#include <algorithm>

Gaussian::Gaussian(double *matrix[], double *vector, int sizeRows, int sizeCols) {
    _sizeMatrixRows = sizeRows;
    _sizeMatrixCols = sizeCols;

    _vector = new double[sizeRows];
    _matrix = new double[sizeRows * sizeCols];

    for (int row = 0; row < sizeRows; row++) {
        for (int col = 0; col < sizeCols; col++) {
            _matrix[index(row, col)] = matrix[row][col];
        }
    }

    for (int row = 0; row < sizeRows; row++) {
        _vector[row] = vector[row];
    }
}

Gaussian::~Gaussian() {
    delete[] _matrix;
    delete[] _vector;
}

size_t Gaussian::index(int row, int col) const {
    return row + _sizeMatrixRows * col;
}

void Gaussian::printMatrix() {
    for (int row = 0; row < _sizeMatrixRows; row++) {
        for (int col = 0; col < _sizeMatrixCols; col++) {
            std::cout << _matrix[index(row, col)] << " ";
        }
        std::cout << std::endl;
    }
}

void Gaussian::printVector() {
    for (int row = 0; row < _sizeMatrixRows; row++) {
        std::cout << _vector[row] << std::endl;
    }
}

bool Gaussian::doGauss(double *result, bool showSteps) {
    //Step through each row
    int pivotRow;
    double left, temp, value = 0;
    for (int k = 0; k < _sizeMatrixRows; k++) {

        //Do Pivot search
        pivotRow = k;
        for (int j = k; j < _sizeMatrixRows; j++) {
            temp = fabs(_matrix[index(j, k)]);
            if (temp > value) {
                value = temp;
                pivotRow = j;
            }
        }

        if (showSteps) {
            std::cout << "Pivot-Element in Reihe " << pivotRow << " für Reihe " << k << std::endl;
        }

        if (pivotRow != k) {

            if (showSteps) {
                std::cout << "Reihen vertauschung von Reihe " << pivotRow << " und " << k << std::endl
                          << "Matrix-Vorher:" << std::endl;
                printMatrix();
                std::cout << std::endl << "Vector-Vorher" << std::endl;
                printVector();
            }
            //Swap Rows
            for (int col = 0; col < _sizeMatrixCols; col++) {
                std::swap(_matrix[index(k, col)], _matrix[index(pivotRow, col)]);
                std::swap(_vector[k], _vector[pivotRow]);
            }

            if (showSteps) {
                std::cout << std::endl << "Matrix-Nachher:" << std::endl;
                printMatrix();
                std::cout << std::endl << "Vector-Nachher:" << std::endl;
                printVector();
            }
        }

        for (int i = k + 1; i < _sizeMatrixRows; i++) {
            left = _matrix[index(i, k)] / _matrix[index(k, k)];

            for (int j = k; j < _sizeMatrixCols; j++) {
                _matrix[index(i, j)] = _matrix[index(i, j)] - left * _matrix[index(k, j)];
            }

            _vector[i] = _vector[i] - left * _vector[k];


        }

        if (showSteps) {
            std::cout << "Matrix nach Gaußschritt" << std::endl;
            printMatrix();
            std::cout << "Vector nach Gaußschritt" << std::endl;
            printVector();
            std::cout << std::endl;
        }
    }

    if (showSteps) {
        std::cout << std::endl << std::endl << "Matrix nach Gauß Eliminierung" << std::endl;
        printMatrix();
        std::cout << "Vector nach Gauß Eliminierung" << std::endl;
        printVector();
        std::cout << std::endl;

    }

    for (int l = _sizeMatrixRows - 1; l >= 0; l--) {
        for (int i = _sizeMatrixCols - 1; i > l; i--) {
            _vector[l] = _vector[l] - _matrix[index(l, i)] * _vector[i];
            _matrix[index(l, i)] = _matrix[index(l, i)] - _matrix[index(l, i)] * _matrix[index(i,i)];
        }
        _vector[l] = _vector[l] / _matrix[index(l, l)];
        _matrix[index(l, l)] = 1;

        if (showSteps) {
            std::cout << "Matrix nach Rückwärts einsetzen in der Reihe " << l << std::endl;
            printMatrix();
            std::cout << "Vector nach Rückwärts einsetzen in der Reihe " << l << std::endl;
            printVector();
            std::cout << std::endl;
        }
    }

    if (showSteps) {
        std::cout << "Matrix nach Gauß" << std::endl;
        printMatrix();
        std::cout << "Vector nach Gauß" << std::endl;
        printVector();
        std::cout << std::endl;
    }

    for (int m = 0; m < _sizeMatrixRows; m++) {
        result[m] = _vector[m];
    }

    return true;
}