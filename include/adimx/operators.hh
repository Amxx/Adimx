#ifndef ADIMX__OPEARTORS__HH
#define ADIMX__OPERATORS__HH

#include "point.hh"

namespace adimx
{
	namespace operators
	{
		template<typename T>
		Point<T,3> cross(const Point<T,3>&, const Point<T,3>&);

		template<typename T>
		T determinant(const Point<T,3>&, const Point<T,3>&, const Point<T,3>&);

		template<typename T>		
		T circumradius(const Point<T,3>&, const Point<T,3>&, const Point<T,3>&, const Point<T,3>&);

		template<typename T>		
		Point<T,3> circumcenter(const Point<T,3>&, const Point<T,3>&, const Point<T,3>&, const Point<T,3>&);
	}
}

#include "operators.hpp"

#endif