#include <cmath>
#include "vec.h"

template<int dim, typename T>
Vec<dim, T>::Vec() {
	//TODO: optimize to memset
	for (int i = 0; i < dim; i++) {
		data[i] = 0;
	}
}


template<int dim, typename T>
Vec<dim, T>::Vec(const std::initializer_list<T>& list) {
	int pos = 0;
	for (auto it = list.begin(); it != list.end(); it++) {
		data[pos++] = *it;
	}
}


template<int dim, typename T>
void Vec<dim, T>::set(int pos, T value) {
	data[pos] = value;
}

template<int dim, typename T>
T Vec<dim, T>::get(int pos) const {
	return data[pos];
}

template<int dim, typename T>
T Vec<dim, T>::scalar_product(const Vec<dim, T>& other) const {
	T result = 0;
	for (int i = 0; i < dim; i++) {
		result += data[i] * other.data[i];
	}
	return result;
}

template<int dim, typename T>
T Vec<dim, T>::magnitude2() const {
	return scalar_product(*this);
}

template<int dim, typename T>
double Vec<dim, T>::magnitude() const {
	return sqrt((double)magnitude2());
}

template<int dim, typename T>
float Vec<dim, T>::magnitudef() const {
	return sqrtf((float)magnitude2());
}

template<int dim, typename T>
Vec<dim, T> Vec<dim, T>::scale(T factor) const {
	Vec<dim, T> copy = *this;
	for (int i = 0; i < dim; i++) {
		copy.data[i] *= factor;
	}
	return copy;
}

template class Vec<2, int>;
template class Vec<2, double>;
template class Vec<2, float>;

template class Vec<3, int>;
template class Vec<3, double>;
template class Vec<3, float>;

template class Vec<4, int>;
template class Vec<4, double>;
template class Vec<4, float>;
