#include "matrice.h"
#include <iostream>
#include "vector.cpp"

// Constructors
matrice::matrice() : rows(0), cols(0), data(nullptr) {}

matrice::matrice(int rows, int cols) : rows(rows), cols(cols) {
    data = new vector[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = vector(cols);
    }
}

matrice::matrice(int rows, int cols, const std::string& value) : rows(rows), cols(cols) {
    data = new vector[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = vector(cols, value);
    }
}

matrice::matrice(const matrice& other) : rows(other.rows), cols(other.cols) {
    data = new vector[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = other.data[i];
    }
}


// Methods
int matrice::getRows() const {
    return rows;
}

int matrice::getCols() const {
    return cols;
}

void matrice::setValue(int row, int col, const std::string& value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row].setValue(col, value);
    } else {
        std::cerr << "Index out of range" << std::endl;
    }
}

std::string matrice::getValue(int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return data[row].getValue(col);
    } else {
        std::cerr << "Index out of range" << std::endl;
        return "";
    }
}

void matrice::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i].getValue(j) << " ";
        }
        std::cout << std::endl;
    }
}

// Operator overloading
matrice& matrice::operator=(const matrice& other) {
    if (this != &other) {
        if (rows != other.rows || cols != other.cols) {
            delete[] data;
            rows = other.rows;
            cols = other.cols;
            data = new vector[rows];
        }
        for (int i = 0; i < rows; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

matrice matrice::operator+(const matrice& other) const {
    if (rows == other.rows && cols == other.cols) {
        matrice result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    } else {
        std::cerr << "Matrix dimensions don't match for addition" << std::endl;
        return matrice();
    }
}

matrice matrice::operator-(const matrice& other) const {
    if (rows == other.rows && cols == other.cols) {
        matrice result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    } else {
        std::cerr << "Matrix dimensions don't match for subtraction" << std::endl;
        return matrice();
    }
}

matrice matrice::operator*(const matrice& other) const {
    if (cols == other.rows) {
        matrice result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                double sum = 0.0;
                for (int k = 0; k < cols; ++k) {
                    sum += std::stod(data[i].getValue(k)) * std::stod(other.data[k].getValue(j));
                }
                result.setValue(i, j, std::to_string(sum));
            }
        }
        return result;
    } else {
        std::cerr << "Matrix dimensions don't match for multiplication" << std::endl;
        return matrice();
    }
}

matrice matrice::operator*(double scalar) const {
    matrice result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i].setValue(j, std::to_string(std::stod(data[i].getValue(j)) * scalar));
        }
    }
    return result;
}

vector matrice::operator*(const vector& vec) const {
    if (cols != vec.getSize()) {
        std::cerr << "Matrix and vector dimensions don't match for multiplication" << std::endl;
        return vector();
    }
    vector result(rows);
    for (int i = 0; i < rows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < cols; ++j) {
            sum += std::stod(data[i].getValue(j)) * std::stod(vec.getValue(j));
        }
        result.setValue(i, std::to_string(sum));
    }
    return result;
}