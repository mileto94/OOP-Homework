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

	std::vector<File*>& GetFiles()
	{
		return this->files;
	}

	std::vector<Folder*>& GetFolders()
	{
		return this->folders;
	}
	
	void AddFolder(Folder* folder)
	{
		this->folders.push_back(folder);
	}

	void DeleteFolder(Folder* folder);

	void AddFile(File* file)
	{
		this->files.push_back(file);
	}

	void DeleteFile(File* file);

	void MoveFileTo(File* file, Folder* newFolder);

	~Folder() {}

};
#endif //FOLDER_H_GUARD