/******************************************************************************
 *                          C O N S T R U C T O R S                           *
 ******************************************************************************/
template<typename W, 	typename T, std::size_t D>
adimx::Field<W,T,D>::Field(const Grid<T,D>& grid, const gridPoint& axis) :
	_grid(grid)
{
	size_t size = 1;
	for (size_t i=0; i<D; ++i)
	{
		_stride[i] = axis[i]?0:size;
		size      *= axis[i]?1:_grid.size()[i];
	}
	container::resize(size);
}

/******************************************************************************
 *                            A L I G N E M E N T                             *
 ******************************************************************************/
template<typename W, 	typename T, std::size_t D>
size_t
adimx::Field<W,T,D>::offset(const gridPoint& p)
{
	return (p * _stride).sum();
}

template<typename W, 	typename T, std::size_t D>
size_t
adimx::Field<W,T,D>::offset(const physPoint& p)
{
	return offset(_grid.phys2grid(p));
}