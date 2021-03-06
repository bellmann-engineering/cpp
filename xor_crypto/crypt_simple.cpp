#include <iostream>

using namespace std;

string encryptDecrypt(string toEncrypt) 
{
    char key[3] = {'K', 'C', 'Q'}; //Any chars will work, in an array of any size
    string output = toEncrypt;
    
    for (int i = 0; i < toEncrypt.size(); i++)
    {
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
    }
    
    return output;
}

int main(int argc, const char * argv[])
{
    string encrypted = encryptDecrypt("Great Britain will Junkfood-Werbung im TV vor 21 Uhr verbieten.");
    cout << "Encrypted:" << encrypted << "\n";
    
    string decrypted = encryptDecrypt(encrypted);
    cout << "Decrypted:" << decrypted << "\n";
    
    return 0;
}
