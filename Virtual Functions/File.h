#ifndef FILE_H_GUARD
#define FILE_H_GUARD

#include<iostream>
#include<string>


class File
{
protected:
	std::string name;

public:
	File(std::string name) : name(name) {}

	std::string GetName() const
	{
		return this->name;
	}

	virtual void Open() {}

	virtual ~File() {}
};

#endif // FILE_H_GUARD