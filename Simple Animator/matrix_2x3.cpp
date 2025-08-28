#include "matrix_2x3.h"

Matrix2x3::Matrix2x3()
{

}
Matrix2x3::Matrix2x3(const Matrix2x3& copy)
{

}
Matrix2x3::~Matrix2x3()
{

}

void Matrix2x3::operator=(const Matrix2x3& copy)
{
	this->x[0] = copy.x[0];
	this->x[1] = copy.x[1];

	this->y[0] = copy.y[0];
	this->y[1] = copy.y[1];

	this->z[0] = copy.z[0];
	this->z[1] = copy.z[1];
}