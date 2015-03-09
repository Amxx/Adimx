#ifndef ADIMX__GRID__HH
#define ADIMX__GRID__HH

#include "domain.hh"
#include "operators.hh"

namespace adimx
{
	/****************************************************************************
	 *                               Grid object                                *
	 ****************************************************************************/
	template<typename T, std::size_t D>
	class Grid
	{
		public:
			using physPoint = Point<T,D>;
			using gridPoint = Point<int,D>;

			// ---------------------------- Constructors -----------------------------
		private:
			Grid() = default;
		public:
			Grid(const Domain<T,D>&, const gridPoint&);

			// ------------------------------- Methods -------------------------------		
			Grid<T,D> subGrid  (const Domain<T,D>&) const;
			gridPoint phys2grid(const physPoint&)   const;
			physPoint grid2phys(const gridPoint&)   const;
			
			// ------------------------------- Access --------------------------------
			const Domain<T,D>& domain    () const { return _domain;      }
			const physPoint&   step      () const { return _step;        }
			const gridPoint&   size      () const { return _size;        }
			const physPoint&   physOffset() const { return _phys_offset; }
			const gridPoint&   gridOffset() const { return _grid_offset; }

		private:
			Domain<T,D> _domain;
			physPoint   _step;
			gridPoint   _size;
			physPoint   _phys_offset;
			gridPoint   _grid_offset;
	};
}

#include "grid.hpp"

#endif