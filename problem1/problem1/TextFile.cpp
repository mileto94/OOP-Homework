#include<iostream>
#include<string>
#include "TextFile.h"

using namespace std;

void TextFile::PrintContent() const
{
	cout<<this->fileContent<<endl;
}

void TextFile::SetContent(string &content)
{
	for(int i = 0; i < content.length(); i++)
	{
		this->fileContent += content[i];
	}
}