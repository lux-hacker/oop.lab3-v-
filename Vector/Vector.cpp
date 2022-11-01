#include "Vector.h"

namespace Collection{
    Vector::Vector() {
        this->size = 0;
        this->data = nullptr;
    }

    Vector::Vector(int elem) {
        this->size = 1;
        this->data = new int[this->size];
        for(int i = 0; i < size; i++){
            this->data[i] = elem;
        }
    }

    Vector::Vector(int size, int *data) {
        if(size < 0)
            throw std::invalid_argument("VectorException::NegativeSize");
        this->size = size;
        this->data = data;
    }

    int *Vector::realloc(const int *mass, int old_size, int new_size) {
        int *arr = new int[new_size];
        for(int i = 0; i < old_size; i++){
            arr[i] = mass[i];
        }
        if(old_size != 0) delete[] mass;
        return arr;
    }

    Vector::Vector(const Vector &vector) {
        this->size = vector.size;
        if(this->size != 0) this->data = new int[this->size];
        else this->data = nullptr;
        for(int i = 0; i < this->size; i++){
            this->data[i] = vector.data[i];
        }
    }

    Vector::~Vector() {
        delete[] this->data;
    }

    std::istream &operator>>(std::istream &in, Vector &vec) {
        for(int i = 0; i < vec.size; i++)
            in >> vec.data[i];
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const Vector &vec) {
        out << "{";
        for(int i = 0; i < vec.size-1; i++)
            out << vec.data[i] << ", ";
        if(vec.size != 0) out << vec.data[vec.size - 1] << "}";
        else out << "}";
        return out;
    }

    int& Vector::operator[](int i) const {
        if(i < 0 || i >= this->size)
            throw std::out_of_range("VectorException::OutOfRange");
        return this->data[i];
    }

    Vector &Vector::operator=(const Vector &other){
        if(this == &other)
            return *this;

        delete[] this->data;

        this->size = other.size;
        this->data = new int[this->size];
        for(int i = 0; i < this->size; i++)
            this->data[i] = other.data[i];

        return *this;
    }

    Vector Vector::operator+(const Vector &other){
        Vector new_vec(*this);
        new_vec.data = this->realloc(new_vec.data, new_vec.size, new_vec.size + other.size);

        for(int i = new_vec.size; i < new_vec.size + other.size; i++)
            new_vec.data[i] = other.data[i - new_vec.size];
        new_vec.size += other.size;

        return new_vec;
    }

    Vector Vector::operator+(int a){
        Vector a1(*this), a2(a);
        return a1 + a2;
    }

    Vector Vector::findFirstSub(bool d) const {
        Vector answer;
        if(d){
            for(int i = 2; i < this->size; i++)
                if(this->data[i] > this->data[i-1] && this->data[i-1] > this->data[i-2]){
                    answer = answer + this->data[i-2];
                    answer = answer + this->data[i-1];
                    answer = answer + this->data[i];
                    for(int j = i+1; j < this->size; j++){
                        if(this->data[j] > this->data[j-1]){
                            answer = answer + this->data[j];
                        }
                    }
                    break;
                }
        } else {
            for(int i = 2; i < this->size; i++)
                if(this->data[i] < this->data[i-1] && this->data[i-1] < this->data[i-2]){
                    answer = answer + this->data[i-2];
                    answer = answer + this->data[i-1];
                    answer = answer + this->data[i];
                    for(int j = i+1; j < this->size; j++){
                        if(this->data[j] < this->data[j-1]){
                            answer = answer + this->data[j];
                        }
                    }
                    break;
                }
        }
        return answer;
    }

    int Vector::countUniq() const {
        Vector buf;
        for(int i = 0; i < this->size; i++){
            if(buf.count(this->data[i]) == 0)
                buf = buf + this->data[i];
        }
        return buf.size;
    }

    int Vector::count(int a) const {
        int c = 0;
        for(int i = 0; i < this->size; i++){
           if(this->data[i] == a)
               c++;
        }
        return c;
    }

    bool Vector::operator==(const Vector &other) const {
        if(this->size != other.size) return false;
        for(int i = 0; i < this->size; i++)
            if(this->data[i] != other[i])
                return false;
        return true;
    }

    int Vector::getSize() const {
        return this->size;
    }

    void Vector::setSize(int newSize) {
        if(newSize < 0)
            throw std::invalid_argument("VectorException::NegativeSize");
        this->data = this->realloc(this->data, this->size, newSize);
        this->size = newSize;
    }


}
