#ifndef DOCFILE_H_GUARD
#define DOCFILE_H_GUARD

#include<iostream>
#include<string>
#include "TextFile.h"


class DocFile : public TextFile
{
public:
	DocFile(std::string name) : TextFile(name) {}

	virtual void Open()
	{
		std::cout<<"Opening a doc\n";
	}
};

#endif //DOCFILE_H_GUARD