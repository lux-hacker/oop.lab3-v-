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
        Vector(int);
        Vector(int, int*);
        Vector(const Vector&);
        Vector(Vector &&) noexcept ;

        ~Vector();

        int & operator[] (int) const;
        Vector &operator=(const Vector&);
        Vector &operator=(Vector&&) noexcept ;


        [[nodiscard]] Vector findFirstSub(bool = true) const;
        [[nodiscard]] int countUniq() const;
        [[nodiscard]] int count(int) const;
        [[nodiscard]] int getSize() const;

        void setSize(int);

        friend std::istream &operator>>(std::istream &in, Vector &vec);
        friend std::ostream &operator<<(std::ostream &out, const Vector &vec);
        friend Vector operator+ (const Vector&, const Vector&);
    };
    std::istream &operator>>(std::istream &in, Vector &vec);
    std::ostream &operator<<(std::ostream &out, const Vector &vec);
    Vector operator+ (const Vector&, const Vector&);
}

#endif //OOP_LAB3_VECTOR_H
