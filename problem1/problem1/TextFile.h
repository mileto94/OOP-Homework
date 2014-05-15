#ifndef TEXTFILE_H_GUARD
#define TEXTFILE_H_GUARD

#include<iostream>
#include<string>
#include "File.h"


class TextFile : public File
{
protected:

private:
	std::string fileContent;
public:
	TextFile(std::string name) : File(name) 
	{
		this->fileContent = "";
	}

	void SetContent(std::string& content);

	void PrintContent() const;

	virtual void Open() = 0;
};

#endif //TEXTFILE_H_GUARD