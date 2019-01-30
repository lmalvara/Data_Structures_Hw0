#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;
bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

int main(int argc, char* argv[])
{
	int word = 0;
	int num = 0;
	int size1 = 0;
	if (argc < 2) {
		std::cerr << "Usage: count filename=input1.txt\n";
	}
	ArgumentManager am(argc, argv);
	std::string filename = am.get("filename");
	std::ifstream ifs(filename.c_str());
	std::string line;
	while (getline(ifs, line)) {
		size1 = line.size(); 
		for (int i = 0; i < size1; i++) {
			if (ispunct(line[i])) {
				line[i] = ' ';
			}
		}
		// replace symbols by space for line.
		// ... 
		
		std::stringstream ss(line.c_str());
		std::string str;
		while (ss >> str) {
			if (is_number(str)) {
				num++; // ...
			}
			else {
				word++; // ...
			}
		}
	}
	cout << "words=" << word << " numbers=" << num << endl;
	return 0;
}
/*
int main(int argc, char* argv[2]) {

	string word;
	int length;
	int wordcount = 0;
	int numcount = 0;

	ifstream file;                //open file


	while (file >> word) {
		length = word.size();            //get the size of next string 

		int i = 0;                        //use to make sure index resets back to 0 after every while loop

		while (i < length) {                //keep going through each individual index of the string until it reaches max
			if (isalpha(word.at(i))) {        //if index is A-Z
				while (i < length && isalpha(word.at(i))) {       //ensure it doesnt go past the length
					i++;
				}
				wordcount++;                        //word count increase after word ends
				i++;                                //move to next index after fail
			}
			else if (isdigit(word.at(i))) {        //if index is 0-9
				while (i < length && isdigit(word.at(i))) {			//ensure it doesnt go past the length
					i++;
				}
				numcount++;                        //number count increase after word ends
				i++;                            //move to next index after fail
			}
			else {                                //if index isnt 0-9 || A-Z 
				i++;                    //its not a number or letter so ignore and move on
			}
		}
	}
	cout << "words=" << wordcount << " " << "numbers=" << numcount << endl;        //results
	system("pause");
	return 0;
}*/