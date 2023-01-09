/*******************************************************************************
* This file is part of psx-comBINe. Please see the github:
* https://github.com/ADBeta/psx-comBINe
*
* psx-comBINe is a simple program to combine multiple .bin files into a single
* file, and modified the .cue file indexing, this is ideal for PSX/PS1 CD-ROMs
* e.g. Rayman to get them ready for cue2pops or some emulators. I also find it 
* improves reliabilty when buring to a disk to only have one .bin file.
*
* (c) ADBeta
* v0.4.4
* 08 Jan 2023
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

#include <boost/filesystem.hpp>

#include "common.h"
#include "TeFiEd.h"
#include "fileHandler.h"

//Input and output .cue file TeFiEd pointers. Both get set and used later. 
//declared in common.h to be global for each module.
TeFiEd *cueFileIn, *cueFileOut;

//Vector of filenames pulled from the cueFile. Global to all modules.
std::vector<std::string> binFile;

int main(int argc, char *argv[]){
	
	boost::filesystem::create_directory("./test");

	//Test the user input is correct ** TODO
	if(argc == 1) {
		std::cout << "not enough args" << std::endl;
		return 1;
	}
	
	
	//If argv[1] is a valid file, create a new TeFiEd using that filename, and
	//assign it to cueFile, then read cueFile into the vector.
	cueFileIn = new TeFiEd(argv[1]);
	if(cueFileIn->read() != 0) return 1;
	
	
	//Check each line that has FILE in it
	size_t matchLineNo;
	while(( matchLineNo = cueFileIn->findNext("FILE") )) {
		//Keep the current string rather than keep calling getLine()
		std::string cLineStr = cueFileIn->getLine(matchLineNo);
		
		if(isLineValid(cLineStr)) {
			//Push the filename string to the vector.
			binFile.push_back(cueFileIn->parentDir()
			                                  + getFilenameFromLine(cLineStr));
		}
	}
	
	
	//TODO
	for (auto i: binFile)
		std::cout << i << std::endl;
	
	//Create output directory, and setup .cue and .bin output file objects.
	
		
	return 0;
}
