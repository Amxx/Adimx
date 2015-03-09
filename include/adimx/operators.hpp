/******************************************************************************
 *                               Linear algebra                               *
 ******************************************************************************/
template<typename T>
adimx::Point<T,3>
adimx::operators::cross(const adimx::Point<T,3>& p1,
                        const adimx::Point<T,3>& p2)
{
	return adimx::Point<T,3>({p1.y()*p2.z() - p1.z()*p2.y(),
	                          p1.z()*p2.x() - p1.x()*p2.z(),
	                          p1.x()*p2.y() - p1.y()*p2.x() });
}

template<typename T>
T
adimx::operators::determinant(const adimx::Point<T,3>& p1,
                              const adimx::Point<T,3>& p2,
                              const adimx::Point<T,3>& p3)
{
	return p1.x()*p2.y()*p3.z() - p1.x()*p3.y()*p2.z()
	     + p2.x()*p3.y()*p1.z() - p2.x()*p1.y()*p3.z() 
	     + p3.x()*p1.y()*p2.z() - p3.x()*p2.y()*p1.z();
}

/******************************************************************************
 *                                Tetrahedron                                 *
 ******************************************************************************/
template<typename T>
T
adimx::operators::circumradius(const adimx::Point<T,3>& p1,
                               const adimx::Point<T,3>& p2,
                               const adimx::Point<T,3>& p3,
                               const adimx::Point<T,3>& p4)
{
	const adimx::Point<T,3> t   = p2 - p1;
	const adimx::Point<T,3> u   = p3 - p1;
	const adimx::Point<T,3> v   = p4 - p1;
	const adimx::Point<T,3> cuv = adimx::operators::cross(u, v) * t.sqsum();
	const adimx::Point<T,3> cvt = adimx::operators::cross(v, t) * u.sqsum();
	const adimx::Point<T,3> ctu = adimx::operators::cross(t, u) * v.sqsum();

	return (cuv+cvt+ctu).norm() / (T(2) * adimx::operators::determinant(t,u,v));
}
template<typename T>
adimx::Point<T,3>
adimx::operators::circumcenter(const adimx::Point<T,3>& p1,
                               const adimx::Point<T,3>& p2,
                               const adimx::Point<T,3>& p3,
                               const adimx::Point<T,3>& p4)
{
	const adimx::Point<T,3> t   = p2 - p1;
	const adimx::Point<T,3> u   = p3 - p1;
	const adimx::Point<T,3> v   = p4 - p1;
	const adimx::Point<T,3> cuv = adimx::operators::cross(u, v) * t.sqsum();
	const adimx::Point<T,3> cvt = adimx::operators::cross(v, t) * u.sqsum();
	const adimx::Point<T,3> ctu = adimx::operators::cross(t, u) * v.sqsum();

	return p1 + (cuv+cvt+ctu) / (T(2) * adimx::operators::determinant(t,u,v));
}

/******************************************************************************
 *                                Homogeneous                                 *
 ******************************************************************************/
template<typename T>
adimx::Point<T,4>
adimx::operators::toHomogeneous(const adimx::Point<T,3>& p)
{
	static_assert(std::is_floating_point<T>::value, "homogeneous space only valid for floating point");
	return adimx::Point<T,4>({ p.x(), p.y(), p.z(), T(1.0) });
}
template<typename T>
adimx::Point<T,3>
adimx::operators::fromHomogeneous(const adimx::Point<T,4>& p)
{
	static_assert(std::is_floating_point<T>::value, "homogeneous space only valid for floating point");
	return adimx::Point<T,3>({ p.x() / p.w(), p.y() / p.w(), p.z() / p.w() });
}

/******************************************************************************
 *                             Floating operators                             *
 ******************************************************************************/

template<typename T, std::size_t D>
adimx::Point<T,D>
adimx::operators::floor(const adimx::Point<T,D>& p)
{
	static_assert(std::is_floating_point<T>::value, "floor operator only valid for floating point");
	adimx::Point<T,D> r;
	for (size_t i=0; i<D; ++i)
		r[i] = std::floor(p[i]);
	return r;	
}

template<typename T, std::size_t D>
adimx::Point<T,D>
adimx::operators::ceil(const adimx::Point<T,D>& p)
{
	static_assert(std::is_floating_point<T>::value, "ceil operator only valid for floating point");
	adimx::Point<T,D> r;
	for (size_t i=0; i<D; ++i)
		r[i] = std::ceil(p[i]);
	return r;
}

template<typename T, std::size_t D>
adimx::Point<T,D>
adimx::operators::round(const adimx::Point<T,D>& p)
{
	static_assert(std::is_floating_point<T>::value, "ceil operator only valid for floating point");
	adimx::Point<T,D> r;
	for (size_t i=0; i<D; ++i)
		r[i] = std::floor(p[i] + T(0.5)); // avoid biais for negatives
		// r[i] = std::round(p[i]);
	return r;
}



