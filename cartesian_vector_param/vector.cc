#include <ostream>
#include <iostream>

#include "vector.hh"


Vector::Vector()
{
    lng = NDIM;
    for(size_t i = 0;i < lng ; i++)
        donne[i] = 0;
}

Vector::Vector(std::initializer_list<value> l)
{
    lng = l.size();
    size_t i = 0;
    for(auto & nbr : l)
    {
        donne[i++] = nbr;
    }
}

size_t Vector::getSize() const
{
    return lng;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    for (int i = 0; i < rhs.getSize(); i++)
        donne[i] += rhs[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    for (int i = 0; i < rhs.getSize(); i++)
        donne[i] -= rhs[i];
    return *this;
}

Vector Vector::operator+(const Vector& rhs)
{
    auto b = Vector();
    for (int i = 0; i < rhs.getSize(); i++)
        b[i] = rhs[i] + (*this)[i];
    return b;
}

Vector Vector::operator-(const Vector& rhs)
{
    auto c = Vector();
    for (int i = 0; i < rhs.getSize(); i++)
        c[i] = rhs[i] - (*this)[i];
    return c;
}

value Vector::operator*(const Vector& rhs)
{
    value d = 0;
    for (int i = 0; i < rhs.getSize(); i++)
        d += rhs[i] * (*this)[i];
    return d;
}

value Vector::operator[](size_t i) const
{
    return donne[i];
}

value& Vector::operator[](size_t i)
{
    return donne[i];
}

Vector operator*(Vector& rhs,const value val)
{
    auto e = Vector();
    for (int i = 0; i < rhs.getSize(); i++)
        e[i] = rhs[i] * val;
    return e;
}

Vector operator*=(Vector& rhs, const value f)
{
    for (int i = 0; i < rhs.getSize(); i++)
        rhs[i] *= f;
    return rhs;
}


Vector operator+=(Vector& rhs, const value g)
{
    for (int i = 0; i < rhs.getSize(); i++)
        rhs[i] += g;
    return rhs;
}

std::ostream& operator<<(std::ostream &os, const Vector& rhs)
{
    os << "{";
    for (int i = 0; i < rhs.getSize(); i++)
        os << rhs[i] << (i == rhs.getSize() - 1 ? "" : ",");
    return os << "}";
}