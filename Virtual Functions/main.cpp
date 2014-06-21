#include<iostream>
#include "Folder.h"
#include "PngFile.h"
#include "JpgFile.h"
#include "BmpFile.h"

#include "TxtFile.h"
#include "PdfFile.h"
#include "DocFile.h"
using namespace std;


void main()
{
	ImageFile* car = new PngFile("lamborgini.png", 200, 300);
	cout << car->GetData()[0] << endl; // 0
	ImageFile* windowsXp = new JpgFile("green_hill.jpg", 100, 200);
	cout << windowsXp->GetData()[1] << endl; // 1
	TextFile* favoriteSites = new DocFile("bookmarks.doc");
	string sites = "reddit.com, omgbasinerda.bg, neshtodrugokoetonqmadaprochete.net, penisland.net";
	favoriteSites->SetContent(sites);
	favoriteSites->PrintContent(); // reddit.com, omgbasinerda.org, neshtodrugokoetonqmadaprochetete.net, penisland.net
	
	Folder* documents = new Folder("C:\\Documents");
	documents->AddFile(favoriteSites);
	Folder* images = new Folder("C:\\Documents\\Images");
	documents->AddFolder(images);
	images->AddFile(car);
	images->AddFile(windowsXp);
	
	cout << documents->GetFiles()[0]->GetName() << endl; // bookmarks.doc
	cout << documents->GetFolders()[0]->GetName() << endl; // C:\Documents\Images
	cout << documents->GetFolders()[0]->GetFiles()[0]->GetName() << endl; // lamborgini.png
	
	documents->MoveFileTo(favoriteSites, images);
	File* pointerToSites = documents->GetFolders()[0]->GetFiles()[2];
	TextFile* textPointerToSites = static_cast<TextFile*>(pointerToSites);
	textPointerToSites->PrintContent(); //reddit.com, omgbasinerda.org, neshtodrugokoetonqmadaprochete.net, penisland.net
}