#include <iostream>
#include <vector>
#include <numeric>

#include <adimx/point.hh>
#include <adimx/operators.hh>

int main()
{
	using vec3 = adimx::Point<float,3>;
	using rgba = adimx::Point<float,4>;


	std::cout << vec3(1.f) << std::endl;
	std::cout << rgba(.5f) << std::endl;


	adimx::Point<float,3> b[4];
	b[0] = {0.f, 0.f, 0.f};
	b[1] = {1.f, 0.f, 0.f};
	b[2] = {0.f, 1.f, 0.f};
	b[3] = {0.f, 0.f, 1.f};

	std::cout << adimx::operators::cross(b[1], b[2]) << std::endl;
	std::cout << adimx::operators::determinant(b[1], b[2], b[3]) << std::endl;
	std::cout << adimx::operators::circumcenter(b[0], b[1], b[2], b[3]) << std::endl;
	std::cout << adimx::operators::circumradius(b[0], b[1], b[2], b[3]) << std::endl;


	adimx::Point<float,3> u(1.f);
	adimx::Point<float,5> v = adimx::Point<float,5>::resize(u);
	std::cout << "single: " << u << std::endl;
	std::cout << "resize: " << v << std::endl;
	std::cout << "min:    " << vec3::min(b[0], b[1]) << std::endl;
	std::cout << "max:    " << vec3::max(b[0], b[1]) << std::endl;



	adimx::Point<float,3> z = b[0];
	
	std::cout << "std::accumulate: " << std::accumulate(&b[0], &b[4], b[0], vec3::max) << std::endl;

	return 0;
}