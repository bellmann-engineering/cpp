#include "huffman.h"

#include <cstring>
#include <fstream>


using namespace std;

#define DEBUG 0

int main()
{
	string text = "Der Sommer im Norden ist wie der Winter im Süden.";
	
	Huffman huff;

	string enc = huff.encodeText(text);
	cout << "Encoded: " << enc << endl;
	
#if DEBUG
	for (pair<char, string> pair : huff.getHuffmanTable()) 
	{
		cout << pair.first << " " << pair.second << endl;
	}
#endif

	cout << "Decoded: " << huff.decodeText(enc) << endl;
	
	
	/*ofstream savefile("encodedText.dat", ios_base::binary);
	if(savefile.good())
	{		
		savefile.write(enc.c_str(),enc.size()); 
		savefile.close();
	}
	
	ofstream out("decodeText.dat");
    out << text;
    out.close();*/

	return 0;
}