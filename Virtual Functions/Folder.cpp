#include<iostream>
#include <string>
#include<vector>
#include "Folder.h"
using namespace std;

void Folder::DeleteFile(File* file)
{
	for(unsigned i = 0; i < this->files.size(); i++)
		if(this->files[i] == file)
			this->files.erase(this->files.begin() + i);
}

void Folder::DeleteFolder(Folder* folder)
{
	for(unsigned i = 0; i < this->folders.size(); i++)
		if(this->folders[i] == folder)
			this->folders.erase(this->folders.begin() + i);
}

void Folder::MoveFileTo(File* file, Folder* newFolder)
{
	newFolder->AddFile(file);
	this->DeleteFile(file);
}