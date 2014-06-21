#ifndef TXTFILE_H_GUARD
#define TXTFILE_H_GUARD

#include<iostream>
#include<string>
#include "TextFile.h"

class TxtFile : public TextFile
{
public:
	TxtFile(std::string name) : TextFile(name) {}

	virtual void Open()
	{
		std::cout<<"Opening a txt\n";
	}
};

#endif //TXTFILE_H_GUARD