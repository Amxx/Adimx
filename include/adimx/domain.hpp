/******************************************************************************
 *                          C O N S T R U C T O R S                           *
 ******************************************************************************/
template<typename T, std::size_t D>
adimx::Domain<T,D>::Domain(const Domain& cpy)
{
	this->operator[](0) = cpy.min();	
	this->operator[](1) = cpy.max();
}

template<typename T, std::size_t D>
adimx::Domain<T,D>::Domain(const Point<T,D>& p1, const Point<T,D>& p2)
{
	this->operator[](0) = Point<T,D>::min(p1, p2);
	this->operator[](1) = Point<T,D>::max(p1, p2);
}

/******************************************************************************
 *                               M E T H O D S                                *
 ******************************************************************************/
template<typename T, std::size_t D>
bool
adimx::Domain<T,D>::is_in(const adimx::Point<T,D>& p) const
{
	bool value = true;
	for (size_t i=0; i<D;++i)
		value &= (p[i] >= min()[i]) && (p[i] < max()[i]);
	return value;
}