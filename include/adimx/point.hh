#ifndef ADIMX__POINT__HH
#define ADIMX__POINT__HH

#include <array>
#include <utility>
#include <type_traits>
#include <ostream>


namespace adimx
{
	/****************************************************************************
	 *                               Point object                               *
	 ****************************************************************************/
	template <typename T, std::size_t N>
	class Point : public std::array<T,N>
	{
		public:
			using container  = std::array<T,N>;
			using value_type = T;

		public:
			// ---------------------------- Constructors -----------------------------
			Point() = default;
			Point(T v);
			Point(const std::array<T,N>&);
			template <typename U, std::size_t M>
			Point(const Point<U,M>&);
			
			// ------------------------------- ACCESS --------------------------------
			T&          x()                        { static_assert(N>0, "x() required N >= 1"); return operator[](0); }
			const T&    x()                  const { static_assert(N>0, "x() required N >= 1"); return operator[](0); }
			T&          y()                        { static_assert(N>1, "y() required N >= 2"); return operator[](1); }
			const T&    y()                  const { static_assert(N>1, "y() required N >= 2"); return operator[](1); }
			T&          z()                        { static_assert(N>2, "z() required N >= 3"); return operator[](2); }
			const T&    z()                  const { static_assert(N>2, "z() required N >= 3"); return operator[](2); }
			T&          at(size_t i)               { return container::at(i);                                         }
			const T&    at(size_t i)         const { return container::at(i);                                         }
			T&          operator[](size_t i)       { return container::operator[](i);                                 }
			const T&    operator[](size_t i) const { return container::operator[](i);                                 }
			std::size_t getdim()             const { return N;                                                        }

			// ------------------------------- METRICS -------------------------------
			T norm()    const;
			T sum()     const;
			T prod()    const;
			T sqsum()   const;
			T infnorm() const;

			// ------------------------------- STATIC --------------------------------
			static Point min        (const Point&, const Point&);
			static Point max        (const Point&, const Point&);

			// ------------------------------ OPERATOR -------------------------------
			template <typename U> Point  operator+ (const Point<U,N>&) const;
			template <typename U> Point  operator+ (const U&         ) const;
			template <typename U> Point  operator- (const Point<U,N>&) const;
			template <typename U> Point  operator- (const U&         ) const;
			template <typename U> Point  operator* (const Point<U,N>&) const;
			template <typename U> Point  operator* (const U&         ) const;
			template <typename U> Point  operator/ (const Point<U,N>&) const;
			template <typename U> Point  operator/ (const U&         ) const;
			template <typename U> Point  operator% (const Point<U,N>&) const;
			template <typename U> Point  operator% (const U&         ) const;
			
			template <typename U> Point& operator+=(const Point<U,N>&);
			template <typename U> Point& operator+=(const U&         );
			template <typename U> Point& operator-=(const Point<U,N>&);
			template <typename U> Point& operator-=(const U&         );
			template <typename U> Point& operator*=(const Point<U,N>&);
			template <typename U> Point& operator*=(const U&         );
			template <typename U> Point& operator/=(const Point<U,N>&);
			template <typename U> Point& operator/=(const U&         );
			template <typename U> Point& operator%=(const Point<U,N>&);
			template <typename U> Point& operator%=(const U&         );

	};

	/****************************************************************************
	 *                             Stream operators                             *
	 ****************************************************************************/
	template <typename T, std::size_t N>
	std::istream& operator>>(std::istream &in, Point<T,N>& pt)
	{
		for (size_t i=0; i<N; ++i) in >> pt[i];
		return in;
	}
	template <typename T, std::size_t N>
	std::ostream& operator<<(std::ostream &out, const Point<T,N>& pt)
	{
		for (size_t i=0; i<N; ++i) out << pt[i] << ' ';
		return out;
	}
}

#include "point.hpp"

#endif