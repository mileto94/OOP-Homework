#ifndef PDFFILE_H_GUARD
#define PDFFILE_H_GUARD

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

#endif //PDFFILE_H_GUARD