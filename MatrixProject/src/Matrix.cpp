#include "Matrix.hpp"
#include <cstring>

Matrix::Matrix(int r, int c) : rows(r), cols(c) 
{
    data = new double[rows * cols];
    std::fill(data, data + rows * cols, 0.0);
}


Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) 
{
    data = new double[rows * cols];
    std::copy(other.data, other.data + rows * cols, data);
}


Matrix& Matrix::operator=(const Matrix& other) 
{
    if (this == &other)
        return *this;

    delete[] data;

    rows = other.rows;
    cols = other.cols;

    data = new double[rows * cols];
    std::copy(other.data, other.data + rows * cols, data);

    return *this; 
}


Matrix::~Matrix()
{
    delete[] data;
}



double& Matrix::at(int r, int c) 
{
    return data[r * cols + c];
}


const double& Matrix::at(int r, int c) const 
{
    return data[r * cols + c];
}


void Matrix::print() const 
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i * cols + j] << " ";
        }
        std::cout << "\n";
    }
}

