#pragma once
#include "Vec4.hpp"

/**
 * Represents a 4x4 matrix
 */
class Matrix4x4 {

    public:

    /**
     * Constructor to create a 4x4 matrix
     * @param c1 - column 1 of the matrix
     * @param c2 - column 2 of the matrix
     * @param c3 - column 3 of the matrix
     * @param c4 - column 4 of the matrix
     */
    Matrix4x4(Vec4 c1, Vec4 c2, Vec4 c3, Vec4 c4);

    /**
     * Getter for column one
     */
    Vec4 getC1();

    /**
     * Getter for column two
     */
    Vec4 getC2();

    /**
     * Getter for column three
     */
    Vec4 getC3();
    /**
     * Getter for column four
     */
    Vec4 getC4();


    private:

    Vec4 cols[4];

     

};


