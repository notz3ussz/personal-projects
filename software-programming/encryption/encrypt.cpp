#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encrypt_string(string s)
{
	string encrypted;
	
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		int v = c;
		
		if (isalpha(c))
			encrypted += static_cast<char>(c + 10);
		else
			encrypted += c;
	}
	
	return encrypted;
}

int main()
{
	fstream infile;
	fstream outfile;
	string filename, buffer;
	
	do
	{
		cout << "Enter name of file to encrypt: ";
		getline(cin, filename);
		
		infile.open(filename, ios::in);
		
		if (!infile)
			cout << "Invalid file, try again!" << endl;
	} while (!infile);
	
	outfile.open(filename.substr(0, filename.find_last_of(".")) + "_ENCRYPTED.txt", ios::out);
	
	while (getline(infile, buffer))
	{
		outfile << encrypt_string(buffer);
		outfile << endl;
	}
	
	cout << "Encrypted." << endl;
		
	infile.close();
	outfile.close();
	
	return 0;
}