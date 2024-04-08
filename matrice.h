// matrice.h
#ifndef MATRICE_H
#define MATRICE_H

#include "vector.h"
#include <string> 

class matrice {
private:
    int rows;
    int cols;
    vector* data;

public:
    // Constructors
    matrice();
    matrice(int rows, int cols);
    matrice(int rows, int cols, const std::string& value); // Change double to string
    matrice(const matrice& other);

    // Methods
    int getRows() const;
    int getCols() const;
    void setValue(int row, int col, const std::string& value); // Change double to string
    std::string getValue(int row, int col) const; // Change return type to string
    void print() const;

    // Operator overloading
    matrice& operator=(const matrice& other);
    matrice operator+(const matrice& other) const;
    matrice operator-(const matrice& other) const;
    
    matrice operator*(const matrice& other) const;
    matrice operator*(double scalar) const;
    vector operator*(const vector& vec) const;
};

#endif