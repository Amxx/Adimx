#include <iostream>

#include <adimx/point.hh>

int main()
{
	using vec3 = adimx::Point<float,3>;
	using rgba = adimx::Point<float,4>;


	std::cout << vec3(1.f) << std::endl;
	std::cout << rgba(.5f) << std::endl;


	adimx::Point<int,5> v1 = {0, 1, 1, 2, 3};
	// std::array<int,5> v1 = {0, 1, 1, 2, 3};
	std::cout << v1 << std::endl;

	return 0;
}