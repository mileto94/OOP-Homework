#ifndef IMAGEFILE_H_GUARD
#define IMAGEFILE_H_GUARD


#include<iostream>
#include<string>
#include "File.h"


class ImageFile : public File
{
protected:
	int width;
	int height;

	std::string type;

	int* data;

public:
	ImageFile(std::string name, int width, int height) : File(name)
	{
		this->name = name;
		this->width = width;
		this->height = height;
		this->type = "image";
	}

	std::string GetType() 
	{
		return this->type;
	}

	virtual ~ImageFile() 
	{
		delete[] data;
	}
	
	virtual void Open() = 0;
	
	virtual int* GetData() = 0;

	virtual void PrintData() = 0;
};

#endif //IMAGEFILE_H_GUARD