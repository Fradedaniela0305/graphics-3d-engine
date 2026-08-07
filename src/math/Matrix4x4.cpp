/**
 * @file Matrix4x4.cpp
 */

#include "math/Matrix4x4.hpp"

/**
 * Constructor to create a 4x4 matrix
 * @param c1 - column 1 of the matrix
 * @param c2 - column 2 of the matrix
 * @param c3 - column 3 of the matrix
 * @param c4 - column 4 of the matrix
 */
Matrix4x4::Matrix4x4(Vec4 c1, Vec4 c2, Vec4 c3, Vec4 c4)
{
    cols[0] = c1;
    cols[1] = c2;
    cols[2] = c3;
    cols[3] = c4;
}

/**
 * Getter for column one
 */
Vec4 Matrix4x4::getC1()
{
    return cols[0];
}

/**
 * Getter for column two
 */
Vec4 Matrix4x4::getC2()
{
    return cols[1];

}

/**
 * Getter for column three
 */
Vec4 Matrix4x4::getC3()
{
    return cols[2];
}
/**
 * Getter for column four
 */
Vec4 Matrix4x4::getC4()
{
    return cols[3];
}
