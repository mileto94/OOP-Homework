#include<iostream>
#include "BmpFile.h"
using namespace std;


void BmpFile::Open()
{
	cout<<"Opening a "<<this->GetType()<<endl;
}

int* BmpFile::GetData()
{
	int size = this->width * this->height;
	for(int i = 0; i < size; i++)
		this->data[i] = 2;
	return this->data;
}

void BmpFile::PrintData()
{
	int* data = GetData();
	int size = this->width * this->height;
	for(int i = 0; i < size; i++)
	{
		cout<<data[i]<<" ";
	}
	cout<<endl;
}