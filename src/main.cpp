#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

int main()
{
	fs::path hosts_filepath("C:/Windows/System32/drivers/etc/hosts");

	std::ofstream hosts_file(hosts_filepath, std::ofstream::out | std::ofstream::trunc);

	if (!hosts_file.is_open()) {
		std::cerr << "failed to open " << hosts_filepath;
		return EXIT_FAILURE;
	}

	for (auto& path : fs::recursive_directory_iterator("./files"))
	{
		if(!path.is_regular_file())
			continue;

		std::cout << path << std::endl;

		std::ifstream file(path, std::ios::binary);
		if (!hosts_file.is_open())
			std::cerr << "failed to open " << path;

		hosts_file << file.rdbuf();
		hosts_file << '\n';

	}
}