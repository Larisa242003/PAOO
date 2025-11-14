#pragma once
#include <algorithm>
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    double* data;

public:
    // Constructor
    Matrix(int r = 0, int c = 0);

    // Copy constructor (deep copy)
    Matrix(const Matrix& other);

    // Assignment operator
    Matrix& operator=(const Matrix& other);

    // Destructor
    ~Matrix();

    // Element access
    double& at(int r, int c);
    const double& at(int r, int c) const;

    // Utility
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    void print() const;
};
