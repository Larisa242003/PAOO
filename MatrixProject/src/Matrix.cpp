#include "Matrix.hpp"
#include <cstring>

// Constructor
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new double[rows * cols];
    std::fill(data, data + rows * cols, 0.0);
}

// Copy constructor (Deep Copy)
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double[rows * cols];
    std::copy(other.data, other.data + rows * cols, data);
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) // Self-assignment check
        return *this;

    delete[] data;

    rows = other.rows;
    cols = other.cols;

    data = new double[rows * cols];
    std::copy(other.data, other.data + rows * cols, data);

    return *this; // Return *this for chaining
}

// Destructor
Matrix::~Matrix() {
    delete[] data;
}

// Element access

double& Matrix::at(int r, int c) {
    return data[r * cols + c];
}

const double& Matrix::at(int r, int c) const {
    return data[r * cols + c];
}

// Utility: print matrix
void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i * cols + j] << " ";
        }
        std::cout << "\n";
    }
}
