#ifndef CHILDRENOFIMAGEFILE_H_GUARD
#define CHILDRENOFIMAGEFILE_H_GUARD

#include<iostream>
#include<string>
#include "TextFile.h"

class PdfFile : public TextFile
{
public:
	PdfFile(std::string name) : TextFile(name) {}

	virtual void Open()
	{
		std::cout<<"Opening a pdf\n";
	}
};


class DocFile : public TextFile
{
public:
	DocFile(std::string name) : TextFile(name) {}

	virtual void Open()
	{
		std::cout<<"Opening a doc\n";
	}
};


class TxtFile : public TextFile
{
public:
	TxtFile(std::string name) : TextFile(name) {}

	virtual void Open()
	{
		std::cout<<"Opening a txt\n";
	}
};


#endif //CHILDRENOFIMAGEFILE_H_GUARD