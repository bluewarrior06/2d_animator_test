#ifndef _MATRIX_2X3_H_
#define _MATRIX_2X3_H_

struct Matrix2x3
{
	Matrix2x3();
	Matrix2x3(const Matrix2x3& copy);
	~Matrix2x3();

	float x[2] = { 0.0f, 1.0f};
	float y[2] = { 1.0f, 0.0f};
	float z[2] = { 0.0f, 0.0f};

	void operator=(const Matrix2x3& copy);
};

#endif