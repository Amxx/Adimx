#ifndef ADIMX__FIELD__HH
#define ADIMX__FIELD__HH

#include "grid.hh"

namespace adimx
{
	/****************************************************************************
	 *                               Field object                               *
	 ****************************************************************************/
	template<typename W, 	typename T, std::size_t D>
	class Field : public std::vector<W>
	{
		public:
			using container = std::vector<W>;
			using physPoint = typename Grid<T,D>::physPoint;
			using gridPoint = typename Grid<T,D>::gridPoint;

			// ---------------------------- Constructors -----------------------------
		public:
			Field(const Grid<T,D>&, const gridPoint& = gridPoint(0));

			// ------------------------------- Access --------------------------------
			W&       at        (size_t i)                 { return container::at(i);                 }
			const W& at        (size_t i)           const { return container::at(i);                 }
			W&       operator[](size_t i)                 { return container::operator[](i);         }
			const W& operator[](size_t i)           const { return container::operator[](i);         }

			W&       at        (const gridPoint& p)       { return container::at(offset(p));         }
			const W& at        (const gridPoint& p) const { return container::at(offset(p));         }
			W&       operator[](const gridPoint& p)       { return container::operator[](offset(p)); }
			const W& operator[](const gridPoint& p) const { return container::operator[](offset(p)); }

			W&       at        (const physPoint& p)       { return container::at(offset(p));         }
			const W& at        (const physPoint& p) const { return container::at(offset(p));         }
			W&       operator[](const physPoint& p)       { return container::operator[](offset(p)); }
			const W& operator[](const physPoint& p) const { return container::operator[](offset(p)); }

			// ----------------------------- Alignement ------------------------------
			size_t offset(const gridPoint&);
			size_t offset(const physPoint&);

			// --------------------------- Members access ----------------------------
			const Grid<T,D>& grid  () const { return _grid;             }
			const gridPoint& stride() const { return _stride;           }
			size_t           size  () const { return container::size(); }
			T                unit  () const { return _unit;             }

		private:
			Grid<T,D> _grid;
			gridPoint _stride;
			T					_unit;
	};
}

#include "field.hpp"

#endif