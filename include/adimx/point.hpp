/******************************************************************************
 *                          C O N S T R U C T O R S                           *
 ******************************************************************************/
template <typename T, std::size_t N>
adimx::Point<T,N>::Point(T v)
{
	for (size_t i=0; i<N; ++i) operator[](i) = v;
}

template <typename T, std::size_t N>
template<typename ...Args>
adimx::Point<T,N>::Point(Args&&... args) : std::array<T,N>{{args...}}
{
}

template <typename T, std::size_t N>
template <typename U, std::size_t M>
adimx::Point<T,N>::Point(const Point<U,M>& p)
{
	for (size_t i=0; i<std::min(N, M); ++i) operator[](i) = p[i];
	for (size_t i=M; i<N;              ++i) operator[](i) = value_type();
}

/******************************************************************************
 *                               M E T R I C S                                *
 ******************************************************************************/
template <typename T, std::size_t N>
T adimx::Point<T,N>::norm() const
{
	static_assert(std::is_floating_point<T>::value, "Point::norm needs foating Point");
	return std::sqrt(this->sqsum());
}

template <typename T, std::size_t N>
T adimx::Point<T,N>::sum() const
{
	T result = operator[](0);
	for (size_t i=1; i<N; ++i) result += operator[](i);
	return result;
}

template <typename T, std::size_t N>
T adimx::Point<T,N>::prod() const
{
	T result = operator[](0);
	for (size_t i=1; i<N; ++i) result *= operator[](i);
	return result;
}

template <typename T, std::size_t N>
T adimx::Point<T,N>::sqsum() const
{
	T result = operator[](0)*operator[](0);
	for (size_t i=1; i<N; ++i) result += operator[](i)*operator[](i);
	return result;
}

template <typename T, std::size_t N>
T adimx::Point<T,N>::infnorm() const
{
	T result = operator[](0);
	for (size_t i=1; i<N; ++i) result = std::max(result, operator[](i));
	return result;
}

/******************************************************************************
 *                        S T A T I C   M E T H O D S                         *
 ******************************************************************************/
template <typename T, std::size_t N>
adimx::Point<T,N> adimx::Point<T,N>::min(const adimx::Point<T,N>& p1, const adimx::Point<T,N>& p2)
{
	adimx::Point<T,N> p;
	for (size_t i=0; i<N; ++i) p[i] = std::min(p1[i], p2[i]);
	return p;
}
template <typename T, std::size_t N>
adimx::Point<T,N> adimx::Point<T,N>::max(const adimx::Point<T,N>& p1, const adimx::Point<T,N>& p2)
{
	adimx::Point<T,N> p;
	for (size_t i=0; i<N; ++i) p[i] = std::max(p1[i], p2[i]);
	return p;
}

/******************************************************************************
 *                    A L G E B R I C   O P E R A T O R S                     *
 ******************************************************************************/
template<typename T, std::size_t N>
adimx::Point<T,N> adimx::Point<T,N>::cross(const adimx::Point<T,N>& p1, const adimx::Point<T,N>& p2)
{
	static_assert(N == 3, "Point::cross valid only if in 3N");
	return adimx::Point<T,N>(p1.y()*p2.z() - p1.z()*p2.y(),
															p1.z()*p2.x() - p1.x()*p2.z(),
															p1.x()*p2.y() - p1.y()*p2.x());
}

template<typename T, std::size_t N>
T adimx::Point<T,N>::determinant(const adimx::Point<T,N>& p1, const adimx::Point<T,N>& p2, const adimx::Point<T,N>& p3)
{
	static_assert(N == 3, "Point::determinant valid only if in 3N");
	return	p1.x()*p2.y()*p3.z() - p1.x()*p3.y()*p2.z()
				+ p2.x()*p3.y()*p1.z() - p2.x()*p1.y()*p3.z() 
				+ p3.x()*p1.y()*p2.z() - p3.x()*p2.y()*p1.z();
}

/******************************************************************************
 *                             O P E R A T O R S                              *
 ******************************************************************************/
// operator+
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator+(const adimx::Point<U,N>& p) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) + p[i];
	return r;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator+(const U& f) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) + f;
	return r;
}
// operator-
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator-(const adimx::Point<U,N>& p) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) - p[i];
	return r;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator-(const U& f) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) - f;
	return r;
}
// operator*
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator*(const adimx::Point<U,N>& p) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) * p[i];
	return r;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator*(const U& f) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) * f;
	return r;
}
// operator/
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator/(const adimx::Point<U,N>& p) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) / p[i];
	return r;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator/(const U& f) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) / f;
	return r;
}
// operator%
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator%(const adimx::Point<U,N>& p) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) % p[i];
	return r;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N> adimx::Point<T,N>::operator%(const U& f) const
{
	adimx::Point<T,N> r;
	for (size_t i=0; i<N; ++i) r[i] = operator[](i) % f;
	return r;
}









// operator+=
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator+=(const adimx::Point<U,N>& p)
{
	for (size_t i=0; i<N; ++i) operator[](i) += p[i];
	return *this;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator+=(const U& f)
{
	for (size_t i=0; i<N; ++i) operator[](i) += f;
	return *this;
}
// operator-=
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator-=(const adimx::Point<U,N>& p)
{
	for (size_t i=0; i<N; ++i) operator[](i) -= p[i];
	return *this;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator-=(const U& f)
{
	for (size_t i=0; i<N; ++i) operator[](i) -= f;
	return *this;
}
// operator*=
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator*=(const adimx::Point<U,N>& p)
{
	for (size_t i=0; i<N; ++i) operator[](i) *= p[i];
	return *this;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator*=(const U& f)
{
	for (size_t i=0; i<N; ++i) operator[](i) *= f;
	return *this;
}
// operator/=
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator/=(const adimx::Point<U,N>& p)
{
	for (size_t i=0; i<N; ++i) operator[](i) /= p[i];
	return *this;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator/=(const U& f)
{
	for (size_t i=0; i<N; ++i) operator[](i) /= f;
	return *this;
}
// operator%=
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator%=(const adimx::Point<U,N>& p)
{
	for (size_t i=0; i<N; ++i) operator[](i) %= p[i];
	return *this;
}
template <typename T, std::size_t N>
template <typename U>
adimx::Point<T,N>& adimx::Point<T,N>::operator%=(const U& f)
{
	for (size_t i=0; i<N; ++i) operator[](i) %= f;
	return *this;
}








