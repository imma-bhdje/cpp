#include <ostream>
#include <iostream>

#include "vector.hh"


Vector::Vector(const Vector &v)
{
    this->donne = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size() ; ++i)
        donne[i] = v[i];
    lng = v.size();
}


Vector& Vector::operator=(const Vector &v) {
    this->donne = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size() ; ++i) donne[i] = v[i];
    lng = v.size();
    return *this;
}

Vector::Vector(std::initializer_list<value> l)
{
    lng = l.size();
    value i = 0;
    donne = std::make_unique<value[]>(l.size());
    for (value val : l) {
        donne[i++] = val;
    }
}

Vector::Vector(size_t N) {
    donne = std::make_unique<value[]>(N);
    for (int i = 0; i < N; i++) {
        donne[i] = 0;
    }
    lng = N;
}

Vector& Vector::operator+=(const Vector& rhs) {
    if (lng != rhs.size())
        std::runtime_error("erreur taille");
    for (int i = 0; i < rhs.size(); i++) {
        donne[i] += rhs[i];
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& rhs){
    if (lng != rhs.size())
        std::runtime_error("erreur taille");
    for (int i = 0; i < rhs.size(); i++) {
        donne[i] -= rhs[i];
    }
    return *this;
}

Vector& Vector::operator+=(value v) {
    for (int i = 0; i < lng; i++) {
        donne[i] += v;
    }
    return *this;
}

Vector& Vector::operator*=(value v){
    for (int i = 0; i < lng; i++) {
        donne[i] *= v;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    if (lng != rhs.size())
        std::runtime_error("Incompatible size");
    for (int i = 0; i < rhs.size(); i++) {
        donne[i] += rhs[i];
    }
    return *this;
}

Vector Vector::operator+(value v) const {
    for (int i = 0; i < lng; i++) {
        donne[i] += v;
    }
    return *this;
}

value Vector::operator*(const Vector& rhs) const {
    if (lng != rhs.size())
        std::runtime_error("Incompatible size");
    value c = 0;
    for (int i = 0; i < rhs.size(); i++) {
        c += rhs[i] * (*this)[i];
    }
    return c;
}

Vector Vector::operator*(value x) const {
    for (int i = 0; i < lng; i++) {
        donne[i] *= x;
    }
    return *this;

}

value& Vector::operator[](size_t idx) {
    if (lng < idx)
        std::runtime_error("Incompatible size");
    return donne[idx];
}

value Vector::operator[](size_t idx) const {
    if (lng < idx)
        std::runtime_error("Incompatible size");
    return donne[idx];
}


Vector operator+(const Vector& v,const value& x) {
    Vector vec = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        vec[i] = v[i] + x;
    }
    return vec;
}

Vector operator*(const Vector& v,const value& x) {
    Vector vec = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        vec[i] = v[i] * x;
    }
    return vec;
}

std::ostream& operator<<(std::ostream &o, const Vector& v)
{
    o << "{";
    for (int i = 0; i < v.size(); i++)
        o << v[i] << (i == v.size() - 1 ? "" : ",");
    return o << "}";
}