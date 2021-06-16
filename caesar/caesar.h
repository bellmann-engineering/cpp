#include <string>

using namespace std;


class CaesarExtended 
{
	private:
		string alphabet; 
		string key;
		
			
	public:
	
		CaesarExtended(string word, int shift)
		{
			for(char a='a'; a<='z';a++)
				alphabet += a;		
			
			for(char a='A'; a<='Z';a++)
				alphabet += a;	
			
			string alpha = alphabet;
			int alphaLen = alphabet.size();
				
			int n = word.size();

			for (int i = 0; i < n; i++) 
			{
				char c = word[i];
				int z = alpha.find(c);
				alpha = alpha.substr(0,z) + alpha.substr(z+1,alphaLen-i);
			}
			
			int na = alpha.size();
			key = alpha.substr(na-shift,na) + word + alpha.substr(0,alphaLen-n-shift);			
		}
		 

		string encrypt(string input)
		{
			char c;
			int z;

			string output="";

			for (int i = 0; i < input.size(); i++) 
			{
				c = input[i];
				z = alphabet.find(c);
				char x = key[z];
				output = output + x;
			}

			return output;
		}

		string decrypt(string input)
		{
			char c;
			int z;
			
			string output = "";

			for(int i = 0; i < input.size(); i++) 
			{
				c = input[i];
				z = key.find(c);
				output = output + alphabet[z];
			}

			return output;
		}

};

