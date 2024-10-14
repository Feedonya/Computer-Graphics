#pragma once
#include "Matrix.h"
#include <math.h>
mat3 translate(float Tx, float Ty) {
	mat3* res = new mat3(1.f);// создали единичную матрицу
	(*res)[0][2] = Tx;// поменяли
	(*res)[1][2] = Ty;// значения в последнем столбце
	return *res;
}
mat3 scale(float Sx, float Sy) {
	mat3* res = new mat3(1.f); // создали единичную матрицу
	(*res)[0][0] = Sx; // поменяли
	(*res)[1][1] = Sy; // значения на главной диагонали
	return *res;
}
mat3 scale(float S) {
	return scale(S, S);
}
mat3 rotate(float theta) {
	mat3* res = new mat3(1.f);
	(*res)[0][0] = (*res)[1][1] = (float)cos(theta);
	(*res)[0][1] = (float)sin(theta);
	(*res)[1][0] = -(*res)[0][1];
	return *res;
}


mat3 mirrorX() {
	return scale(1.f, -1.f);//меняем знаки у координат Y точек
}
mat3 mirrorY() {
	return scale(-1.f, 1.f);//меняем знаки у координат X точек
}