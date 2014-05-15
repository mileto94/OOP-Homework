#ifndef JPGFILE_H_GUARD
#define JPGFILE_H_GUARD

#include<iostream>
#include "ImageFile.h"


class JpgFile : public ImageFile
{
public:
	JpgFile(std::string name, int width, int height) : ImageFile(name, width, height) 
	{
		this->type = "jpg";
		this->data = new int[this->width * this->height];
	}

	virtual void Open();

	virtual int* GetData();

	virtual void PrintData();
	
	~JpgFile() {}
};

#endif // JPGFILE_H_GUARD