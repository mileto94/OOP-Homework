#ifndef PNGFILE_H_GUARD
#define PNGFILE_H_GUARD

#include<iostream>
#include "ImageFile.h"


class PngFile : public ImageFile
{
public:
	PngFile(std::string name, int width, int height) : ImageFile(name, width, height) 
	{
		this->data = new int[this->width * this->height];
		this->type = "png";
	}

	virtual void Open();

	virtual int* GetData();

	virtual void PrintData();

	~PngFile() {}
};

#endif //PNGFILE_H_GUARD