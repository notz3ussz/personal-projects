#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void display_file(ifstream &infile)
{
	string buffer;
	
	cout << "----------------------------------" << endl;
	cout << "File start" << endl;
	cout << "----------------------------------" << endl << endl;
	
	for (int i = 0; i < 10; i++)
	{	
		getline(infile, buffer);
		cout << buffer << endl;
		
		if (infile.eof())
		{
			cout << endl;
			cout << "----------------------------------" << endl;
			cout << "ALL CONTENTS PRINTED" << endl;
			cout << "----------------------------------" << endl << endl;
			return;
		}
	}
	
	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "ONLY FIRST 10 LINES SHOWN" << endl;
	cout << "----------------------------------" << endl << endl;
}

void search_string(ifstream &infile)
{
	string target, buffer;
	
	cout << "Enter the string you want to search: ";
	getline(cin, target);
	
	cout << "String \"" << target << "\" found at the following lines: " << endl;
	for (int i = 1; !infile.eof(); i++)
	{
		getline(infile, buffer);
		
		if (buffer.find(target) != string::npos) 
			cout << i << endl;
	}
	cout << endl;
	
}

int main()
{
	ifstream inputFile;
	string fileName;
	
	do
	{
		cout << "Enter name of file: ";
		getline(cin, fileName);
		
		inputFile.open(fileName);
		
		if (!inputFile)
		{
			cout << "No such file exists. Try again." << endl;
		}
	} while (!inputFile);
	
	search_string(inputFile);
	
	inputFile.close();
	
	return 0;
}
