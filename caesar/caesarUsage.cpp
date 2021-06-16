#include <iostream>
#include "caesar.h"

using namespace std;

class MeineMeldeException
{
public: 
	MeineMeldeException(int a) { m_nr = a;}
	void MeldeException() { cout << "Led leutet rot" << endl; }
private:
	int m_nr;
};

struct MeineSpezialException : public exception
{
	const char* what() const throw()
	{
		return "meine Exception ist geflogen";
	}
};

void execute(int auswahl)
{
	if(auswahl == 1)
		throw (char*)"auswahl war 1";
	if(auswahl == 2)
		throw 5;
	if(auswahl == 3)
		throw MeineSpezialException();
	if(auswahl == 4)
		throw MeineMeldeException(auswahl);
}



int main()
{
	try
	{
		execute(4);
		
	}
	catch(int number)
	{
		cout << "gefangen: " << number << endl;
		return 0;
	}
	catch(char* text)
	{
		cout << "gefangen: " << text << endl;
		return 0;
	}
	catch(MeineSpezialException& ex)
	{
		cout << ex.what() << endl;
		return 0;
	}
	catch(MeineMeldeException& m)
	{
		m.MeldeException();
		return 0;
	}
	catch(...)
	{
		
		
	}
	
	int shift;
	
	cin.exceptions(ios_base::failbit);
	
	cout << "Zahl fuer Shifting eingeben: ";
	
	try
	{
		cin >> shift;
	}
	catch(ios_base::failure&)
	{
		cout << "war wohl keine zahl" << endl;
		return 0;
	}
	// catch(exception&)
	// {
		// cout << "Laufzeitfehler passiert" << endl;
		// return 0;
	// }
	// catch(...)
	// {
		// cout << "Genereller Laufzeitfehler passiert" << endl;
		// return 0;	
	// }
	
	// if(cin.fail())
	// {
		// cout << "das war wohl keine Zahl" << endl;
		// cin.clear(); 
		// cin.ignore();
		
		// return 0;
	// }
	
	CaesarExtended c("montag", shift);
	string sentence = "Kindergeburtstag";
	string encryptedSentence = c.encrypt(sentence);
	cout << "Verschuesselt: " << encryptedSentence << endl;
	cout << "Entschuesselt: " << c.decrypt(encryptedSentence) << endl;
	
	return 0;
}

