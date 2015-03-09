#include <iostream>
#include <vector>
#include <numeric>

#include <adimx/point.hh>
#include <adimx/domain.hh>
#include <adimx/grid.hh>
#include <adimx/field.hh>
#include <adimx/operators.hh>

int main()
{
	using vec2 = adimx::Point<float,2>;
	using vec3 = adimx::Point<float,3>;
	using vec4 = adimx::Point<float,4>;
	using rgba = adimx::Point<float,4>;


	std::cout << "vec3(1.f)         : " << vec3(1.f) << std::endl;
	std::cout << "rgba(.5f)         : " << rgba(.5f) << std::endl;


	vec3 b[4];
	b[0] = {{0.f, 0.f, 0.f}};
	b[1] = {{1.f, 0.f, 0.f}};
	b[2] = {{0.f, 1.f, 0.f}};
	b[3] = {{0.f, 0.f, 1.f}};

	std::cout << "cross             : " << adimx::operators::cross(b[1], b[2]) << std::endl;
	std::cout << "determinant       : " << adimx::operators::determinant(b[1], b[2], b[3]) << std::endl;
	std::cout << "circumcenter      : " << adimx::operators::circumcenter(b[0], b[1], b[2], b[3]) << std::endl;
	std::cout << "circumradius      : " << adimx::operators::circumradius(b[0], b[1], b[2], b[3]) << std::endl;


	vec3 u(1.f);
	adimx::Point<float,5> v(u);
	std::cout << "single            : " << u << std::endl;
	std::cout << "resize            : " << v << std::endl;
	std::cout << "min               : " << vec3::min(b[0], b[1]) << std::endl;
	std::cout << "max               : " << vec3::max(b[0], b[1]) << std::endl;

	vec3 z = b[0];
	
	std::cout << "std::accumulate 1 : " << std::accumulate(&b[0], &b[4], b[0], vec3::max) << std::endl;

	std::vector<vec2> vec;
	for (float i = 0.17f; i<10.f; i+=0.42f)
		vec.push_back({{ i, i }});

	std::cout << "size              : " << vec.size() << std::endl;
	std::cout << "front             : " << vec.front() << std::endl;
	std::cout << "std::accumulate 2 : " << std::accumulate(vec.begin(), vec.end(), vec.front()) << std::endl;


	adimx::Domain<float,3> domain( {{-0.75f, -0.75f, -0.75f}}, {{ +0.75f, +0.75f, +0.75f}} );
	adimx::Domain<float,3> bounds( {{-0.75f, -0.75f, -0.75f}}, {{ +0.00f, +0.00f, +0.00f}} );
	adimx::Point<size_t,3> size(10);

	adimx::Grid<float,3> grid    = adimx::Grid<float,3>(domain, size);
	adimx::Grid<float,3> subgrid = grid.subGrid(bounds);

	
	std::cout << "grid domain()     : " << grid.domain().min() << " -- " << grid.domain().max() << std::endl;
	std::cout << "grid step()       : " << grid.step() << std::endl;
	std::cout << "grid size()       : " << grid.size() << std::endl;
	std::cout << "grid physOffset() : " << grid.physOffset() << std::endl;
	std::cout << "grid gridOffset() : " << grid.gridOffset() << std::endl;

	std::cout << "grid domain()     : " << subgrid.domain().min() << " -- " << subgrid.domain().max() << std::endl;
	std::cout << "grid step()       : " << subgrid.step() << std::endl;
	std::cout << "grid size()       : " << subgrid.size() << std::endl;
	std::cout << "grid physOffset() : " << subgrid.physOffset() << std::endl;
	std::cout << "grid gridOffset() : " << subgrid.gridOffset() << std::endl;


	adimx::Field<float,float,3> field(grid);
	std::cout << "field stride      : " << field.stride() << std::endl;
	std::cout << "field size        : " << field.size() << std::endl;
	std::cout << "field unit        : " << field.unit() << std::endl;


	adimx::Field<float,float,3> pfield(grid, {{ 1, 1, 0, }});
	std::cout << "pfield stride     : " << pfield.stride() << std::endl;
	std::cout << "pfield size       : " << pfield.size() << std::endl;
	std::cout << "field unit        : " << pfield.unit() << std::endl;


	return 0;
}