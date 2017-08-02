#include <filesystem>
#include <vector>
#include <string>
#include <stdexcept>

//namespace for the file system
namespace file = std::experimental::filesystem;

//basically straight from 
//http://www.cplusplus.com/forum/windows/189681/
// when actually coding maybe look at boost for a file library
// retrieves all the file names in a folder
std::vector <std::string> getFilenames(std::string path) {

	std::vector <std::string> filenames;
	const file::directory_iterator end{};

	//iterate through everything in the directory
	for (file::directory_iterator iter{ path }; iter != end; ++iter) {
		// push back files into the vector
		if (file::is_regular_file(*iter)) {
			filenames.push_back(iter->path().string());
		}
	}

	// return all file names
	return filenames;
}