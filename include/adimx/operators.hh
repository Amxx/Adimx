#ifndef ADIMX__OPERATORS__HH
#define ADIMX__OPERATORS__HH

#include <functional>

#include "point.hh"

namespace adimx
{
	namespace operators
	{

		template<typename T, std::size_t D, std::size_t E>
		using projectionFunc = std::function<Point<T,E>(const Point<T,D>&)>;
		
		namespace projection
		{
			template<typename T>
			Point<T,2> x(const Point<T,3>& p) { return Point<T,2>({ p.y(), p.z() }); }
			template<typename T>
			Point<T,2> y(const Point<T,3>& p) { return Point<T,2>({ p.x(), p.z() }); }
			template<typename T>
			Point<T,2> z(const Point<T,3>& p) { return Point<T,2>({ p.x(), p.y() }); }
		}

		// ---------------------------- Linear algebra -----------------------------
		template<typename T>
		Point<T,3> cross(const Point<T,3>&, const Point<T,3>&);
		template<typename T>
		T determinant(const Point<T,3>&, const Point<T,3>&, const Point<T,3>&);

		// ------------------------------ Tetrahedron ------------------------------
		template<typename T>		
		T circumradius(const Point<T,3>&, const Point<T,3>&, const Point<T,3>&, const Point<T,3>&);
		template<typename T>		
		Point<T,3> circumcenter(const Point<T,3>&, const Point<T,3>&, const Point<T,3>&, const Point<T,3>&);

		// ------------------------------ Homogeneous ------------------------------
		template<typename T>
		Point<T,3> fromHomogeneous(const Point<T,4>&);
		template<typename T>
		Point<T,4> toHomogeneous(const Point<T,3>&);

		// -------------------------- Floating operators ---------------------------
		template<typename T, std::size_t D>
		Point<T,D> floor(const Point<T,D>&);
		template<typename T, std::size_t D>
		Point<T,D> ceil(const Point<T,D>&);
		template<typename T, std::size_t D>
		Point<T,D> round(const Point<T,D>&);

	}
}

#include "operators.hpp"

#endif