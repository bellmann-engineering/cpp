#include "huffman.h"

Huffman::Huffman()
{
	m_encodedText = "";
	m_decodedText = "";
}

// Erstelle einen Knoten mit Buchstabe, Vorkommen (Frequenz) und seinen Kindern (rechts + links)
Node* Huffman::createNode(char ch, int freq, Node* left /* = NULL*/, Node* right /* = NULL*/)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Rekursiv den Baum aufbauen, Rekursion terminiert wenn Root erreicht ist.
void Huffman::encode(Node* root, string str)
{
	if (root == NULL)
		return;

	// unten angekommen
	if (!root->left && !root->right) {
		m_huffmanTable[root->ch] = str;
	}

	encode(root->left, str + "0");
	encode(root->right, str + "1");
}

// Rekursion um zu dekodieren
void Huffman::decode(Node* root, int& index, string str)
{
	if (root == NULL)
		return;

	// unten angekommen
	if (!root->left && !root->right)
	{
		m_decodedText += root->ch;
		return;
	}

	index++;

	if (str[index] == '0') // bei 0 gehen wir links, bei 1 rechts
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

string Huffman::decodeText(string encodedText) 
{
	int index = -1;
	while (index < (int)encodedText.size() - 2) 
	{
		decode(m_root, index, encodedText);
	}
	
	return m_decodedText;
}

string Huffman::encodeText(string text)
{
	// zähle Buchstabenvorkommen 
	for (char ch: text) {
		m_freq[ch]++;
	}

	for (std::pair<char, int> pair : m_freq) 
	{
		m_queue.push(createNode(pair.first, pair.second));
	}

	//solange wie in der queue mind. 2 einträge sind
	while (m_queue.size() != 1)
	{
		// ermittle zwei Nodes mit dem Buchstaben der das niedrigste Vorkommen hat
		Node* left = m_queue.top(); //oberster aus der queue
		m_queue.pop(); //rausnehmen
		Node* right = m_queue.top();	
		m_queue.pop();

		// summe davon ergibt die neue node.
		int sum = left->freq + right->freq;
		m_queue.push(createNode('#', sum, left, right));
	}

	// root pointer in member merken
	m_root = m_queue.top();
	
	encode(m_root, "");

	for (char ch: text) 
	{
		m_encodedText += m_huffmanTable[ch];
	}
	
	return m_encodedText;
}