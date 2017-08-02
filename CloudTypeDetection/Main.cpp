// The Main page of the project 

#include <opencv2/opencv.hpp>

//project files
#include "FileManager.h"
#include "Viewer.h"

//probably just for debugging
#include <iostream>

int main(int argc, char** argv)
{
	for (const auto& name : getFilenames(argv[1]))
		std::cout << name << '\n';

	std::vector <std::string> name = getFilenames(argv[1]);

	WindowMaker(name);


	return(0);
}