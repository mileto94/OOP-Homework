#ifndef BMPFILE_H_GUARD
#define BMPFILE_H_GUARD

#include<iostream>
#include "ImageFile.h"


class BmpFile : public ImageFile
{
public:
	BmpFile(std::string name, int width, int height) : ImageFile(name, width, height) 
	{
		this->type = "bmp";
		this->data = new int[this->width * this->height];
	}
	
	virtual void Open();

	virtual int* GetData();

	virtual void PrintData();

	~BmpFile() {}
};

#endif //BMPFILE_H_GUARD