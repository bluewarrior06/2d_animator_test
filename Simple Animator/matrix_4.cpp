#include "matrix_4.h"

Matrix4::Matrix4()
{

}
Matrix4::Matrix4(const Matrix4& copy)
{
	this->x[0] = copy.x[0];
	this->x[1] = copy.x[1];
	this->x[2] = copy.x[2];
	this->x[3] = copy.x[3];

	this->y[0] = copy.y[0];
	this->y[1] = copy.y[1];
	this->y[2] = copy.y[2];
	this->y[3] = copy.y[3];

	this->z[0] = copy.z[0];
	this->z[1] = copy.z[1];
	this->z[2] = copy.z[2];
	this->z[3] = copy.z[3];

	this->w[0] = copy.w[0];
	this->w[1] = copy.w[1];
	this->w[2] = copy.w[2];
	this->w[3] = copy.w[3];
}

void Matrix4::identity()
{
	this->x[0] = 0;
	this->x[1] = 0;
	this->x[2] = 0;
	this->x[3] = 0;

	this->y[0] = 0;
	this->y[1] = 0;
	this->y[2] = 0;
	this->y[3] = 0;

	this->z[0] = 0;
	this->z[1] = 0;
	this->z[2] = 0;
	this->z[3] = 0;

	this->w[0] = 0;
	this->w[1] = 0;
	this->w[2] = 0;
	this->w[3] = 0;
}

void Matrix4::operator=(const Matrix4& copy)
{
	this->x[0] = copy.x[0];
	this->x[1] = copy.x[1];
	this->x[2] = copy.x[2];
	this->x[3] = copy.x[3];

	this->y[0] = copy.y[0];
	this->y[1] = copy.y[1];
	this->y[2] = copy.y[2];
	this->y[3] = copy.y[3];

	this->z[0] = copy.z[0];
	this->z[1] = copy.z[1];
	this->z[2] = copy.z[2];
	this->z[3] = copy.z[3];

	this->w[0] = copy.w[0];
	this->w[1] = copy.w[1];
	this->w[2] = copy.w[2];
	this->w[3] = copy.w[3];
}