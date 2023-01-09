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
*
* This file contains extern variables and declarations of types used between 
* program modules.
*******************************************************************************/
#include <iostream>
#include <vector>

#include "TeFiEd.h"

#ifndef COMMON_H
#define COMMON_H

//Input and output .cue file TeFiEd pointers. Both get set and used later. 
extern TeFiEd *cueFileIn, *cueFileOut;

//Vector of filenames pulled from the cueFile.
extern std::vector<std::string> binFile;

#endif
