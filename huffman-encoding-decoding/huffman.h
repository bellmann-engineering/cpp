#ifndef _HUFFMAN_H__
#define _HUFFMAN_H__

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

// Vergleich um Sortierung der Nodes zu ermöglichen: Die Items bei denen Freq. am niedrigsten ist
// die Buchstaben, die am seltensten vorkommen sollen nach ganz oben sortiert werden, 
// da sie die unterste Ebene des Baums bilden
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		return l->freq > r->freq;
	}
};

class Huffman 
{
	private:
		priority_queue<Node*, vector<Node*>, comp> m_queue;
		unordered_map<char, string> m_huffmanTable;
		unordered_map<char, int> m_freq;
		
		Node* createNode(char, int, Node* = NULL, Node* = NULL); 		
		void encode(Node*, string); 
		void decode(Node*, int&, string);
		string m_encodedText;
		string m_decodedText;
		Node* m_root;
		vector<Node*> m_nodesList;

	public:
		Huffman();
		~Huffman();
		string encodeText(string);
		string decodeText(string);
		
		unordered_map<char, string> getHuffmanTable() { return m_huffmanTable; };
};

#endif 
