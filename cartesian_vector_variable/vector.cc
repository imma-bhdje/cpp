#include "vector.hh"


Vector::Vector(const Vector &v) {
    this->data = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size() ; ++i) data[i] = v[i];
    lng = v.size();
}

Vector& Vector::operator=(const Vector &v) {
    this->data = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size() ; ++i) data[i] = v[i];
    lng = v.size();
    return *this;
}

Vector::Vector(size_t N) {
    data = std::make_unique<value[]>(N);
    for (int i = 0; i < N; i++) {
        data[i] = 0;
    }
    lng = N;
}

Vector::Vector(std::initializer_list<value> l) {
    lng = l.size();
    data = std::make_unique<value[]>(l.size());
    value e = 0;
    for (value element : l) {
        data[e] = element;
        e++;
    }
}

size_t Vector::size() const {
    return lng;
}


Vector& Vector::operator+=(const Vector& rhs) {
    if (lng != rhs.size())
        std::runtime_error("erreur");
    for (int i = 0; i < rhs.size(); i++) {
        data[i] += rhs[i];
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& rhs){
    if (lng != rhs.size())
        std::runtime_error("erreur");
    for (int i = 0; i < rhs.size(); i++) {
        data[i] -= rhs[i];
    }
    return *this;
}

Vector& Vector::operator+=(value v) {
    for (int i = 0; i < lng; i++) {
        data[i] += v;
    }
    return *this;
}

Vector& Vector::operator*=(value v){
    for (int i = 0; i < lng; i++) {
        data[i] *= v;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    if (lng != rhs.size())
        std::runtime_error("erreur");
    for (int i = 0; i < rhs.size(); i++) {
        data[i] += rhs[i];
    }
    return *this;
}

Vector Vector::operator+(value v) const {
    for (int i = 0; i < lng; i++) {
        data[i] += v;
    }
    return *this;
}

value Vector::operator*(const Vector& rhs) const {
    if (lng != rhs.size())
        std::runtime_error("erreur");
    value d = 0;
    for (int i = 0; i < rhs.size(); i++) {
        d += data[i] * rhs[i];
    }
    return d;
}

Vector Vector::operator*(value v) const {
    for (int i = 0; i < lng; i++) {
        data[i] *= v;
    }
    return *this;

}

value& Vector::operator[](size_t idx) {
    if (lng < idx)
        std::runtime_error("erreur ");
    return data[idx];
}

value Vector::operator[](size_t idx) const {
    if (lng < idx)
        std::runtime_error("erreur ");
    return data[idx];
}



// Nonmember function operators go here
Vector operator*(const value& s, const Vector& v) {
    Vector b = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        b[i] = v[i] * s;
    }
    return b;
}

Vector operator+(const value& s, const Vector& v) {
    Vector b = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        b[i] = v[i] + s;
    }
    return b;
}

std::ostream& operator<<(std::ostream& o, const Vector& v) {
    o<<'{';
    int i = 0;
    for (; i < v.size() - 1; i++) {
        o<<v[i]<<',';
    }
    o<<v[i]<<"}";
    return o;
}

//test