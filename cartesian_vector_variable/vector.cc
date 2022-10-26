#include <ostream>
#include <memory>

#include "vector.hh"


Vector::Vector(const Vector& rhs)
        : lng(rhs.lng)
        , donne(new value[lng])
{
    for (size_t i = 0; i < lng; ++i)
    {
        donne[i] = rhs.donne[i];
    }
}


Vector& Vector::operator=(const Vector& rhs)
{
    if (this != &rhs)
    {
        lng = rhs.lng;
        donne.reset(new value[lng]);
        for (size_t i = 0; i < lng; ++i)
        {
            donne[i] = rhs.donne[i];
        }
    }
    return *this;
}


Vector::Vector(size_t N) : lng(lng), donne(new value[lng]) {
    for (size_t i = 0; i < N; ++i)
    {
        donne[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> l) : lng(l.size()), donne(new value[lng]) {
    size_t i = 0;
    for (auto& v : l)
    {
        donne[i++] = v;
    }
}

size_t Vector::size() const {
    return lng;
}


Vector& Vector::operator+=(const Vector& rhs) {
    assert(lng == rhs.lng);
    for (size_t i = 0; i < lng; ++i)
    {
        donne[i] += rhs.donne[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    assert(lng == rhs.lng);
    for (size_t i = 0; i < lng; ++i)
    {
        donne[i] -= rhs.donne[i];
    }
    return *this;
}


Vector& Vector::operator+=(value v) {
    for (size_t i = 0; i < lng; ++i)
    {
        donne[i] += v;
    }
    return *this;
}

Vector& Vector::operator*=(value v) {
    for (size_t i = 0; i < lng; ++i)
    {
        donne[i] *= v;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    Vector result(*this);
    result += rhs;
    return result;
}

Vector Vector::operator+(value v) const {
    Vector result(*this);
    result += v;
    return result;
}

value Vector::operator*(const Vector& rhs) const {
    assert(lng == rhs.lng);
    value result = 0;
    for (size_t i = 0; i < lng; ++i)
    {
        result += donne[i] * rhs.donne[i];
    }
    return result;
}

Vector Vector::operator*(value v) const {
    Vector result(*this);
    result *= v;
    return result;
}

value& Vector::operator[](size_t idx) {
    assert(idx < lng);
    return donne[idx];
}

value Vector::operator[](size_t idx) const {
    assert(idx < lng);
    return donne[idx];
}

Vector operator*(const value& s, const Vector& v) {
    return v * s;
}

Vector operator+(const value& s, const Vector& v) {
    return v + s;
}

std::ostream& operator<<(std::ostream& o, const Vector& v) {
    o << "{";
    for (size_t i = 0; i < v.size(); ++i)
    {
        o << v[i];
        if (i != v.size() - 1)
        {
            o << ",";
        }
    }
    o << "}";
    return o;
}