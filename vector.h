// vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <string> // Include the string header

class vector {
private:
    std::string* data; // Change the data type to string
    int size;

public:
    // Constructors
    vector();
    vector(int size);
    vector(int size, const std::string& value); // Change double to string
    vector(const vector& other);

    // Methods
    int getSize() const;
    void setValue(int index, const std::string& value); // Change double to string
    std::string getValue(int index) const; // Change return type to string

    // Operator overloading
    vector& operator=(const vector& other);
    vector operator+(const vector& other) const;
    vector operator-(const vector& other) const;
    double operator*(const vector& other) const; 
    vector operator*(double scalar) const; 

    friend vector operator-(const vector& v1 , const vector& v2);
};

#endif
