//
// Created by hartlab on 12.05.19.
//

#ifndef NM_GAUSSIAN_H
#define NM_GAUSSIAN_H


class Gaussian {
private:
    int _sizeMatrixRows, _sizeMatrixCols;
    double *_vector;
    double *_matrix;
    size_t index(int row, int col) const;
public:
    Gaussian(double *matrix[], double *vector, int sizeMatrixRows, int sizeMatrixCols);
    ~Gaussian();
    bool doGauss(double *result, bool showSteps);
    void printMatrix();
    void printVector();
};


#endif //NM_GAUSSIAN_H