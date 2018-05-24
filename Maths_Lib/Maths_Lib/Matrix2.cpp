#include "Matrix2.h"
#include <math.h>


//default constructor
Matrix2::Matrix2()
{
	//cycles through the 2x2 matrix and increments it
	for (int i = 0; i < 4; i++)
	{
		//takes the matrix with index i which holds all the values in the 2x2 matrix such as 4
		m[i] = 0;
	}
}

//sets the index values to each position
Matrix2::Matrix2(float a_x, float a_y, float b_x, float b_y)
{   //                                                     2x2
	//matrix index |0| = a_x     matrix index |1| = a_y     | 0  1 |
	//matrix index |2| = b_x     matrix index |3| = b_y     | 2  3 |
	m[0] = a_x;
	m[1] = a_y;
	m[2] = b_x;
	m[3] = b_y;


}

//Setting the axis's and the indexes to a constant type which will never change
//The axis's meaning the points of the matrix
Matrix2::Matrix2(const Matrix2 & other)
{
	m[0] = other.m[0];
	m[1] = other.m[1];
	m[2] = other.m[2];
	m[3] = other.m[3];

}

//Returns the matrix's index
float Matrix2::operator[](int index)
{
	return m[index];
}

//Returns the matrix
Matrix2::operator float*()
{
	return m;
}

//sets up an unrotated scaled matrix
void Matrix2::setScaled(const Vector2& v)
{
	//set scale of the axis
	*this = { v.m_x, 0,
		      0, v.m_y};
}

//where to set the value of how big you want the object to be
void Matrix2::scale(const Vector2 & v)
{
	Matrix2 m;
	m.setScaled(v);
	*this = *this * m;
}

///////////////////////////////////////////////////////////////////////////// ROTATION /////////////////////////////////////////
//Sets the rotate for the X axis
void Matrix2::setRotateX(float radians)
{
	//leave X axis and elements unchanged
	*this = { 1, 0, 
		      0, cosf(radians) };

}

//Sets the rotate for the Y axis
void Matrix2::setRotateY(float radians)
{
	*this = { cosf(radians), 0,
		      0, 1 };
}

//You add the value at which you would like to rotate the X axis in this function
void Matrix2::rotateX(float radians)
{
	Matrix2 m;
	m.setRotateX(radians);
	*this = *this * m;
}

void Matrix2::rotateY(float radians)
{
	Matrix2 m;
	m.setRotateY(radians);
	*this = *this * m;
}
/////////////////////////////////////////////////////////////////// ROTATION //////////////////////////////////////////////////////


//Identity matrix is a square matrix with main diagonal elements as 1 and the rest is 0
//This is a 2x2 identity matrix
Matrix2 Matrix2::Identity()
{
	return Matrix2(1.0f, 0.0f,
		           0.0f, 1.0f);
}

//This is the columns and rows of a 2x2 matrix 
Matrix2 Matrix2::Transpose()
{
	return Matrix2(m[0], m[1],
		           m[2], m[3]);
}

 //This multiplies the matrix itself 
Matrix2 Matrix2::operator*(const Matrix2 & a_mat) const
{
	return Matrix2(	m[0] * a_mat.m[0] + m[1] * a_mat.m[2],            //=====MATRIX MULTIPLICATION 2X2======//           Step 1: Multiply the first matrix row by the whole second matrix   
		            m[0] * a_mat.m[1] + m[3] * a_mat.m[2],            // | m[0]  m[1] |     | a_m[0]  a_m[1] |           Step 2: Multiply the second matrix row by the whole second matrix 
		            m[1] * a_mat.m[3] + m[2] * a_mat.m[0],            // | m[2]  m[3] |  *  | a_m[2]  a_m[3] |           
		            m[2] * a_mat.m[1] + m[3] * a_mat.m[3]);           
	                                                                  // | 0x0 + 1x2 + 0x1 + 1x3 + | <--- first row
	                                                                  // | 2x0 + 3x2 + 2x1 + 3x3   | <--- second row
}

//Multiplying a matrix with a vector
Vector2 Matrix2::operator*(const Vector2 & a_vec) const
{
	return Vector2(m[0],
		           m[1]);
}

//deconstructor
Matrix2::~Matrix2()
{
}

