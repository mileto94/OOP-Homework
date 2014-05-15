#ifndef FOLDER_H_GUARD
#define FOLDER_H_GUARD

#include<iostream>
#include<string>
#include<vector>
#include"File.h"


class Folder
{
protected:
	std::string name;
	std::vector<File*> files;
	std::vector<Folder*> folders;

public:
	Folder(std::string name) : name(name) {}

	std::string GetName() const
	{
		return this->name;
	}

	//needs implementation
	Folder** GetFiles() const;

	//needs implementation
	Folder** GetFolders() const;

};
#endif //FOLDER_H_GUARD