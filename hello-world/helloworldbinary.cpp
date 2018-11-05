#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

int main()
{
	std::string binary_representation = "011010000110010101101100011011000110111100100000011101110110111101110010011011000110010000100001";
	std::string hello_world_binary;

	std::istringstream in(binary_representation);
	std::bitset<8> bitset;

	while (in >> bitset)
		hello_world_binary += bitset.to_ulong();


	std::cout << hello_world_binary << std::endl;

	std::cin.get();
	return 0;
}
