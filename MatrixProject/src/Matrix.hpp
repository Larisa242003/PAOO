#pragma once
#include <algorithm>
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    double* data;

public:
 
    Matrix(int r = 0, int c = 0);

    Matrix(const Matrix& other);

    Matrix& operator=(const Matrix& other);

    ~Matrix();

    double& at(int r, int c);
    const double& at(int r, int c) const;

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    void print() const;
};
