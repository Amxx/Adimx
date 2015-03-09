#ifndef ADIMX__DOMAIN__HH
#define ADIMX__DOMAIN__HH

#include "point.hh"

namespace adimx
{
	/****************************************************************************
	 *                              Domain object                               *
	 ****************************************************************************/
	template<typename T, std::size_t D>
	class Domain : public std::array<Point<T,D>,2>
	{
		public:
			// ---------------------------- Constructors -----------------------------
			Domain() = default;
			Domain(const Domain&);
			Domain(const Point<T,D>&, const Point<T,D>&);
			
			// ------------------------------- Access --------------------------------
			const Point<T,D>& min() const { return this->operator[](0); }
			const Point<T,D>& max() const { return this->operator[](1); }

			// ------------------------------- Methods -------------------------------
			bool is_in(const Point<T,D>&) const;
	};
}

#include "domain.hpp"

#endif