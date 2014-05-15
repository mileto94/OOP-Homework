#ifndef TEXTFILE_H_GUARD
#define TEXTFILE_H_GUARD

#include<iostream>
#include "File.h"


class TextFile : public File
{
protected:

public:
	TextFile(std::string name) : File(name) {};

	void PrintContent() const;

};

#endif //TEXTFILE_H_GUARD