// vector.cpp
#include "vector.h"

// Constructors
vector::vector() : data(nullptr), size(0) {}

vector::vector(int size) : size(size) {
    data = new std::string[size];
    for (int i = 0; i < size; ++i) {
        data[i] = "";
    }
}

vector::vector(int size, const std::string& value) : size(size) {
    data = new std::string[size];
    for (int i = 0; i < size; ++i) {
        data[i] = value;
    }
}

vector::vector(const vector& other) : size(other.size) {
    data = new std::string[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Methods
int vector::getSize() const {
    return size;
}

void vector::setValue(int index, const std::string& value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

std::string vector::getValue(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        return ""; // Returning an empty string as default for out-of-range index
    }
}

// Operator overloading
vector& vector::operator=(const vector& other) {
    if (this != &other) {
        if (size != other.size) {
            delete[] data;
            size = other.size;
            data = new std::string[size];
        }
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

vector vector::operator+(const vector& other) const {
    if (size != other.size) {
        // Returning an empty vector if sizes don't match
        return vector();
    }
    vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// vector vector::operator-(const vector& other) const {
//     if (size != other.size) {
//         // Returning an empty vector if sizes don't match
//         return vector();
//     }
//     vector result(size);
//     for (int i = 0; i < size; ++i) {
//         result.data[i] = data[i] - other.data[i];
//     }
//     return result;
// }

double vector::operator*(const vector& other) const {
    if (size != other.size) {
        // Returning 0 if sizes don't match for dot product
        return 0.0;
    }
    double dotProduct = 0.0;
    for (int i = 0; i < size; ++i) {
        // Assuming the string values cannot be directly used for multiplication,
        // so returning 0.0 for dot product in case of string vectors.
        return 0.0;
    }
    return dotProduct;
}

vector vector::operator*(double scalar) const {
    // No meaningful scalar multiplication can be performed on string vectors,
    // so returning an empty vector.
    return vector();
}

vector operator-(const vector& v1, const vector& v2)  {
    if (v1.size != v2.size) {
        // Returning an empty vector if sizes don't match
        return vector();
    }
    vector result(v1.size);
    for (int i = 0; i < v1.size; ++i) {
        // Assuming subtraction of string values is not defined,
        // so returning an empty vector.
        return vector();
    }
    return result;
}
