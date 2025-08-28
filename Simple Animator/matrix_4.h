#ifndef _MATRIX_4_H_
#define _MATRIX_4_H_

struct Matrix4
{
public:
	Matrix4();
	Matrix4(const Matrix4& copy);

	float x[4] = { 1.0f, 0.0f, 0.0f, 0.0f };
	float y[4] = { 0.0f, 1.0f, 0.0f, 0.0f };;
	float z[4] = { 0.0f, 0.0f, 1.0f, 0.0f };;
	float w[4] = { 0.0f, 0.0f, 0.0f, 1.0f };;

	void identity();


	void operator=(const Matrix4& copy);
};

#endif