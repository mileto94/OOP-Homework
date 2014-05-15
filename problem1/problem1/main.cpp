#include<iostream>
#include "Folder.h"
#include "PngFile.h"
#include "JpgFile.h"
#include "BmpFile.h"

//#include "TextFile.h"
#include "ChildrenOfImageFile.h"
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

	PdfFile t("PDF");
	t.PrintContent();
	string c = "pdf";
	t.SetContent(c);
	t.PrintContent();
	
	DocFile d("DOC");
	c = "doc";
	d.SetContent(c);
	d.PrintContent();
	d.Open();

	TxtFile txt("TXT");
	c = "txt";
	txt.SetContent(c);
	txt.PrintContent();
	txt.Open();
}