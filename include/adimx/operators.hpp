// -----------------------------------------------------------------------------
template<typename T>
adimx::Point<T,3>
adimx::operators::cross(const adimx::Point<T,3>& p1,
												const adimx::Point<T,3>& p2)
{
	return adimx::Point<T,3>({p1.y()*p2.z() - p1.z()*p2.y(),
														p1.z()*p2.x() - p1.x()*p2.z(),
														p1.x()*p2.y() - p1.y()*p2.x() });
}

// -----------------------------------------------------------------------------
template<typename T>
T
adimx::operators::determinant(const adimx::Point<T,3>& p1,
															const adimx::Point<T,3>& p2,
															const adimx::Point<T,3>& p3)
{
	return  p1.x()*p2.y()*p3.z() - p1.x()*p3.y()*p2.z()
				+ p2.x()*p3.y()*p1.z() - p2.x()*p1.y()*p3.z() 
				+ p3.x()*p1.y()*p2.z() - p3.x()*p2.y()*p1.z();
}

// -----------------------------------------------------------------------------
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

// -----------------------------------------------------------------------------
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