#include<iostream>
#include "PngFile.h"
using namespace std;


void PngFile::Open()
{
	cout<<"Opening a "<<this->type<<endl;
}

int* PngFile::GetData()
{
	int size = this->width * this->height;
	for(int i = 0; i < size; i++)
		this->data[i] = 0;
	return this->data;
}

void PngFile::PrintData()
{
	int* data = GetData();
	int size = this->width * this->height;
	for(int i = 0; i < size; i++)
	{
		cout<<this->data[i]<<" ";
	}
	cout<<endl;
}