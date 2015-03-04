#include <iostream>
#include <vector>
#include <numeric>

#include <adimx/point.hh>
#include <adimx/operators.hh>

int main()
{
	using vec2 = adimx::Point<float,2>;
	using vec3 = adimx::Point<float,3>;
	using vec4 = adimx::Point<float,4>;
	using rgba = adimx::Point<float,4>;


	std::cout << vec3(1.f) << std::endl;
	std::cout << rgba(.5f) << std::endl;


	vec3 b[4];
	b[0] = {{0.f, 0.f, 0.f}};
	b[1] = {{1.f, 0.f, 0.f}};
	b[2] = {{0.f, 1.f, 0.f}};
	b[3] = {{0.f, 0.f, 1.f}};

	std::cout << adimx::operators::cross(b[1], b[2]) << std::endl;
	std::cout << adimx::operators::determinant(b[1], b[2], b[3]) << std::endl;
	std::cout << adimx::operators::circumcenter(b[0], b[1], b[2], b[3]) << std::endl;
	std::cout << adimx::operators::circumradius(b[0], b[1], b[2], b[3]) << std::endl;


	vec3 u(1.f);
	adimx::Point<float,5> v(u);
	std::cout << "single: " << u << std::endl;
	std::cout << "resize: " << v << std::endl;
	std::cout << "min:    " << vec3::min(b[0], b[1]) << std::endl;
	std::cout << "max:    " << vec3::max(b[0], b[1]) << std::endl;



	vec3 z = b[0];
	
	std::cout << "std::accumulate 1: " << std::accumulate(&b[0], &b[4], b[0], vec3::max) << std::endl;

	std::vector<vec2> vec(4);
	std::cout << "size:  " << vec.size() << std::endl;
	std::cout << "front: " << vec.front() << std::endl;
	std::cout << "std::accumulate 2: " << std::accumulate(vec.begin(), vec.end(), vec.front(), vec2::max) << std::endl;
	// std::cout << "std::accumulate 2: " << vec[0] << std::endl;
	// std::cout << "std::accumulate 2: " << vec.front() << std::endl;

	return 0;
}