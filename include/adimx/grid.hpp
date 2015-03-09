/******************************************************************************
 *                          C O N S T R U C T O R S                           *
 ******************************************************************************/
template<typename T, std::size_t D>
adimx::Grid<T,D>::Grid(const Domain<T,D>& domain, const gridPoint& size)
{
	_domain      = domain;
	_step        = (domain.max() - domain.min()) / size;
	_size        = size;
	_phys_offset = _step / T(2) + domain.min();
	_grid_offset = gridPoint(0);
}

// template<typename T, std::size_t D>
// adimx::Grid<T,D>::Grid(const Grid<T,D>& main, const Domain<T,D>& subdomain)
// {
// 	_domain     = subdomain;
// 	_step       = main.step();

// 	physPoint grid_b = adimx::operators::ceil ((_domain.min() - main.physOffset()) / _step);
// 	physPoint grid_e = adimx::operators::floor((_domain.max() - main.physOffset()) / _step);
	
// 	_size        = grid_e - grid_b + 1;
// 	_phys_offset = grid_b * _step + main.physOffset();
// 	_grid_offset = grid_b         + main.gridOffset();
// }

/******************************************************************************
 *                               M E T H O D S                                *
 ******************************************************************************/

template<typename T, std::size_t D>
adimx::Grid<T,D>
adimx::Grid<T,D>::subGrid(const Domain<T,D>& subdomain) const
{
	Grid<T,D> subgrid;
	
	subgrid._domain      = subdomain;
	subgrid._step        = this->step();
	physPoint grid_b     = adimx::operators::ceil ((subdomain.min() - this->physOffset()) / this->step());
	physPoint grid_e     = adimx::operators::floor((subdomain.max() - this->physOffset()) / this->step());
	subgrid._size        = grid_e - grid_b + 1;
	subgrid._phys_offset = grid_b * this->step() + this->physOffset();
	subgrid._grid_offset = grid_b                + this->gridOffset();

	return subgrid;
}


template<typename T, std::size_t D>
typename adimx::Grid<T,D>::gridPoint
adimx::Grid<T,D>::phys2grid(const physPoint& phys) const
{
	return adimx::operators::round((phys-_phys_offset)/_step);
}

template<typename T, std::size_t D>
typename adimx::Grid<T,D>::physPoint
adimx::Grid<T,D>::grid2phys(const gridPoint& grid) const
{
	return physPoint(grid)*_step+_phys_offset;
}