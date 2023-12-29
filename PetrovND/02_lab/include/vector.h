#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

template <typename ValueType> class Vector {
protected:
    int size;
    int startIndex;
    ValueType* pVector;
public:
    Vector(int size = 0, int startIndex = 0);
    Vector(const Vector& v);
    ~Vector();

    int getSize() const;
    int getStartIndex() const;

    ValueType& operator[](const int index);
    int operator==(const Vector& v) const;
    int operator!=(const Vector& v) const;
    const Vector& operator=(const Vector& v);
    Vector<ValueType> operator+(const ValueType vt);
    Vector<ValueType> operator-(const ValueType vt);
    Vector<ValueType> operator*(const ValueType vt);
    Vector<ValueType> operator+(const Vector& v);
    Vector<ValueType> operator-(const Vector& v);
    ValueType operator*(const Vector& v);

    friend std::istream& operator>>(std::istream& in, Vector& v) {
        for (int i = 0; i < v.size; ++i) {
            in >> v.pVector[i];
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
        for (int i = 0; i < v.size; ++i) {
            out << v.pVector[i] << " ";
        }
        out << std::endl;
        return out;
    }
};

template <typename ValueType>
Vector<ValueType>::Vector(int size, int startIndex) : size(size) {
	if (startIndex < 0) throw std::invalid_argument("Negative start index.");
	this->startIndex = startIndex;
    pVector = new ValueType[size];
}

template <typename ValueType>
Vector<ValueType>::Vector(const Vector& v) : size(v.size), startIndex(v.startIndex) {
    pVector = new ValueType[size];
    for (int i = 0; i < size; ++i) {
        pVector[i] = v.pVector[i];
    }
}

template <typename ValueType>
Vector<ValueType>::~Vector() {
    delete[] pVector;
}

template <typename ValueType>
int Vector<ValueType>::getSize() const { return size; }

template <typename ValueType>
int Vector<ValueType>::getStartIndex() const { return startIndex; }

template <typename ValueType>
ValueType& Vector<ValueType>::operator[](const int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index is out of range");
    return pVector[index];
}

template <typename ValueType>
int Vector<ValueType>::operator==(const Vector& v) const {
    if (size != v.size) return 0;
    for (int i = 0; i < size; ++i) {
        if (pVector[i] != v.pVector[i]) {
            return 0;
        }
    }
    return true;
}

template <typename ValueType>
int Vector<ValueType>::operator!=(const Vector& v) const {
    return !(*this == v);
}

template <typename ValueType>
const Vector<ValueType>& Vector<ValueType>::operator=(const Vector& v) {
    if (this == &v) return *this;
    delete[] pVector;
    size = v.size;
    startIndex = v.startIndex;
    pVector = new ValueType[size];
    for (int i = 0; i < size; ++i) {
        pVector[i] = v.pVector[i];
    }
    return *this;
}

template <typename ValueType>
Vector<ValueType> Vector<ValueType>::operator+(const ValueType vt) {
    Vector result(*this);
    for (int i = 0; i < size; ++i) {
        result.pVector[i] += vt;
    }
    return result;
}

template <typename ValueType>
Vector<ValueType> Vector<ValueType>::operator-(const ValueType vt) {
    Vector result(*this);
    for (int i = 0; i < size; ++i) {
        result.pVector[i] -= vt;
    }
    return result;
}

template <typename ValueType>
Vector<ValueType> Vector<ValueType>::operator*(const ValueType vt) {
    Vector result(*this);
    for (int i = 0; i < size; ++i) {
        result.pVector[i] *= vt;
    }
    return result;
}

template <typename ValueType>
Vector<ValueType> Vector<ValueType>::operator+(const Vector& v) {
    if (size != v.size) throw std::invalid_argument("Vectors must have the same size for addition.");

    Vector result(*this);
    for (int i = 0; i < size; ++i) {
        result.pVector[i] = pVector[i] + v.pVector[i];
    }
    return result;
}

template <typename ValueType>
Vector<ValueType> Vector<ValueType>::operator-(const Vector& v) {
    if (size != v.size) throw std::invalid_argument("Vectors must have the same size for subtraction.");

    Vector result(*this);
    for (int i = 0; i < size; ++i) {
        result.pVector[i] = pVector[i] - v.pVector[i];
    }
    return result;
}

template <typename ValueType>
ValueType Vector<ValueType>::operator*(const Vector& v) {
    if (size != v.size) throw std::invalid_argument("Vectors must have the same size for dot product.");

    ValueType result = 0;
    for (int i = 0; i < size; ++i) {
        result += pVector[i] * v.pVector[i];
    }
    return result;
}

#endif // !__VECTOR_H__