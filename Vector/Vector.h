#ifndef OOP_LAB3_VECTOR_H
#define OOP_LAB3_VECTOR_H

#include <iostream>

namespace Collection{
    class Vector{
    private:
        int size;
        int* data;

        static int* realloc(const int*, int, int);
    public:
        Vector();
        explicit Vector(int);
        Vector(int, int*);
        Vector(const Vector&);

        ~Vector();

        int & operator[] (int) const;
        Vector &operator=(const Vector&);
        Vector operator+(const Vector&);
        Vector operator+(int);
        bool operator==(const Vector&) const;

        [[nodiscard]] Vector findFirstSub(bool = true) const;
        [[nodiscard]] int countUniq() const;
        [[nodiscard]] int count(int) const;
        [[nodiscard]] int getSize() const;

        void setSize(int);

        friend std::istream &operator>>(std::istream &in, Vector &vec);
        friend std::ostream &operator<<(std::ostream &out, const Vector &vec);
    };
    std::istream &operator>>(std::istream &in, Vector &vec);
    std::ostream &operator<<(std::ostream &out, const Vector &vec);
}

#endif //OOP_LAB3_VECTOR_H
