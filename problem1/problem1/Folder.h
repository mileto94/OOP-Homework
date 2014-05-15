#include<iostream>
#include<string>


class Folder
{
protected:
	std::string name;

public:
	Folder(std::string name) : name(name) {}

	std::string GetName() const
	{
		return this->name;
	}


};
