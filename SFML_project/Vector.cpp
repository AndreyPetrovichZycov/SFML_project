#include "Vector.h"


Vector::Vector() {

}


Vector::Vector(int size) {
	vect.resize(size);
}


Vector::Vector(std::vector<float> vect) {
	this->vect = vect;
}



Vector Vector::operator+(Vector v) {
	Vector tmp(v.vect.size());
	if (v.vect.size() == vect.size())
	{
		for (int i = 0; i < vect.size(); i++) {
			tmp.vect[i] = (vect[i] + v.vect[i]);
		}
	}
	return tmp;
}


float Vector::operator*(Vector v) {
	float res = 0;
	for (int i = 0; i < vect.size(); i++) {
		res += vect[i] * v.vect[i];
	}
	return res;
}



Vector Vector::operator*(float a) {
	Vector tmp(vect.size());
	for (int i = 0; i < vect.size(); i++) {
		tmp.vect[i] = a * vect[i];
	}
	return tmp;
}


Vector Vector::operator*(Matrix M) {
	Vector v;
	if (vect.size() == M.Matr[0].size())
	{
		float s = 0;
		Vector Res(std::min(vect.size(), M.Matr.size()));
		for (int i = 0; i < M.Matr.size(); i++) {
			for (int j = 0; j < vect.size(); j++) {
				s += vect[j] * M.Matr[i][j];
			}
			Res.vect[i] = s;
			s = 0;
		}
		return Res;
	}
	else return v;
}


void Vector::operator=(Vector v1) {
	this->vect = v1.vect;
}


float Vector::X() {
	return vect[0];
}

float Vector::Y() {
	return vect[1];
}


float Vector::norma() {
	float res = 0;
	for (float i : vect) {
		res += i * i;
	}
	return sqrt(res);
}


bool Vector::operator==(Vector v) {
	if (v.vect.size() == vect.size()) {
		int flag = 0;
		for (int i = 0; i < v.vect.size(); i++) {
			if (vect[i] != v.vect[i]) flag = 1;
		}
		if (flag == 0) return 1;
		else return 0;
	}
	else return 0;
}


bool Vector::operator==(std::vector<float> v) {
	if (v.size() == vect.size()) {
		int flag = 0;
		for (int i = 0; i < v.size(); i++) {
			if (vect[i] != v[i]) flag = 1;
		}
		if (flag == 0) return 1;
		else return 0;
	}
	else return 0;
}


void Show(Vector v) {
	for (int i = 0; i < v.vect.size(); i++) {
		std::cout << v.vect[i] << " ";
	}
}
