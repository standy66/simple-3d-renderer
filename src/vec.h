#pragma once

#include <initializer_list>


template<int dim, typename T>
class Vec {
public:
	Vec();
	Vec(const std::initializer_list<T>& list);

	void set(int pos, T value);
	T get(int pos) const;
	T scalar_product(const Vec<dim, T>& other) const;
	T magnitude2() const;
	double magnitude() const;
	float magnitudef() const;

	Vec<dim, double> normalize() const;
	Vec<dim, float> normalizef() const;

	Vec<dim, T> scale(T factor) const;

private:
	T data[dim];

};

typedef Vec<2, int> Vec2i;
typedef Vec<3, int> Vec3i;
typedef Vec<4, int> Vec4i;
typedef Vec<2, double> Vec2d;
typedef Vec<3, double> Vec3d;
typedef Vec<4, double> Vec4d;
typedef Vec<2, float> Vec2f;
typedef Vec<3, float> Vec3f;
typedef Vec<4, float> Vec4f;