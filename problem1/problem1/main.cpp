#include<iostream>
#include "Folder.h"
#include "PngFile.h"
#include "JpgFile.h"
#include "BmpFile.h"
using namespace std;


void main()
{
	Folder f("folder");
	cout<<f.GetName()<<endl;

	PngFile p("Png", 1, 2);
	p.PrintData();
	p.Open();
	p.GetData();

	JpgFile j("Jpg", 2, 3);
	j.PrintData();
	j.Open();


	BmpFile b("Bmp", 3, 4);
	b.PrintData();
	b.Open();

}