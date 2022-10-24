#include <ostream>
#include <iostream>

#include "vector.hh"


Vector::Vector()
{
    size = NDIM;
    for(size_t i = 0;i < size; i++)
        data[i] = 0;
}

Vector::Vector(std::initializer_list<value> l)
{
    size = l.size();
    size_t i = 0;
    for(auto & val : l)
    {
        data[i++] = val;
    }
}

size_t Vector::getSize() const
{
    return size;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    for (int i = 0; i < rhs.getSize(); i++)
        data[i] += rhs[i];
    return *this;
}



Vector& Vector::operator-=(const Vector& rhs)
{
    for (int i = 0; i < rhs.getSize(); i++)
        data[i] -= rhs[i];
    return *this;
}

Vector Vector::operator+(const Vector& rhs)
{
    auto v = Vector();
    for (int i = 0; i < rhs.getSize(); i++)
        v[i] = rhs[i] + (*this)[i];
    return v;
}

Vector Vector::operator-(const Vector& rhs)
{
    auto v = Vector();
    for (int i = 0; i < rhs.getSize(); i++)
        v[i] = rhs[i] - (*this)[i];
    return v;
}

value Vector::operator*(const Vector& rhs)
{
    value v = 0;
    for (int i = 0; i < rhs.getSize(); i++)
        v += rhs[i] * (*this)[i];
    return v;
}

value Vector::operator[](size_t i) const
{
    return data[i];
}

value& Vector::operator[](size_t i)
{
    return data[i];
}

Vector operator*(Vector& rhs,const value val)
{
    auto v = Vector();
    for (int i = 0; i < rhs.getSize(); i++)
        v[i] = rhs[i] * val;
    return v;
}

Vector operator*=(Vector& rhs, const value a)
{
    for (int i = 0; i < rhs.getSize(); i++)
        rhs[i] *= a;
    return rhs;
}


Vector operator+=(Vector& rhs, const value a)
{
    for (int i = 0; i < rhs.getSize(); i++)
        rhs[i] += a;
    return rhs;
}

std::ostream& operator<<(std::ostream &os, const Vector& rhs)
{
    os << "{";
    for (int i = 0; i < rhs.getSize(); i++)
        os << rhs[i] << (i == rhs.getSize() - 1 ? "" : ",");
    return os << "}";
}