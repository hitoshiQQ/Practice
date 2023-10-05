#include "iostream"
#include "vector"
#include "filesystem"

namespace fs = std::filesystem;

auto recursiveGetFilmName = [](const fs::path& path, const std::string& extension) {

	std::vector<std::string> file_names;

	for (auto& p : fs::recursive_directory_iterator(path)) {

		if (is_regular_file(p.path()) && p.path().extension().compare(extension) == 0) {

			file_names.push_back(p.path().filename().string());
		}
	}
	return file_names;
};

int main() {

	const std::string extension = ".txt";
	fs::path searchPath = "(C:\\Users\\hitoshiQQ\\Downloads)";

	auto file_names = recursiveGetFilmName(searchPath, extension);
	for (auto& file : file_names) {

		std::cout << file << " ";
	}
	std::cout << "\n";

	return 0;
}
