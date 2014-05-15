#include<iostream>
#include "JpgFile.h"
using namespace std;


void JpgFile::Open()
{
	cout<<"Opening a "<<this->GetType()<<endl;
}

int* JpgFile::GetData()
{
	int size = this->width * this->height;
	for(int i = 0; i < size; i++)
		this->data[i] = 1;
	return this->data;
}

void JpgFile::PrintData()
{
	int* data = GetData();
	int size = this->width * this->height;
	for(int i = 0; i < size; i++)
	{
		cout<<data[i]<<" ";
	}
	cout<<endl;
}