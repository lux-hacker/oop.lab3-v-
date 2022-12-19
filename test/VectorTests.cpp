#include "gtest/gtest.h"
#include "../Vector/Vector.h"

TEST(RatConstruction, DefaultConstruction){
    Collection::Vector v;
    ASSERT_EQ(v.getSize(), 0);
}

TEST(RatConstruction, InitConstruction){
    Collection::Vector v1(10);
    for(int i = 0; i < 1; i++){
        ASSERT_EQ(v1[i], 10);
    }

    Collection::Vector v2(v1);
    for(int i = 0; i < 1; i++){
        ASSERT_EQ(v1[i], v2[i]);
        v2[i]++;
    }

    Collection::Vector v3 = v2;
    for(int i = 0; i < 1; i++){
        ASSERT_EQ(v2[i], v3[i]);
    }

    int* p = new int[10];
    for(int i = 0; i < 10; i++){
        p[i] = i;
    }
    Collection::Vector v4(10, p);
    for(int i = 0; i < 10; i++){
        ASSERT_EQ(v4[i], i);
    }
}

TEST(RatConstruction, TestException){
    int* p = new int[10];
    for(int i = 0; i < 10; i++){
        p[i] = i;
    }
    Collection::Vector v4(10, p);
    ASSERT_ANY_THROW(v4[-1]);
    ASSERT_ANY_THROW(v4[10]);

    ASSERT_ANY_THROW(Collection::Vector(-1, p));

    ASSERT_ANY_THROW(v4.setSize(-1));
}

TEST(RatConstruction, Test){
    Collection::Vector v;
    ASSERT_EQ(v.getSize(), 0);

    v = v + 1;

    ASSERT_EQ(v.getSize(), 1);
    ASSERT_EQ(v[0], 1);

    int* p = new int[10];
    for(int i = 0; i < 10; i++){
        p[i] = i;
    }
    Collection::Vector v2(10, p);
    v = v + v2;

    ASSERT_EQ(v.getSize(), 11);
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

