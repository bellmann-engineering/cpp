#include <iostream>
#include <vector>

using namespace std;

vector<char> encryptDecrypt(vector<char> toEncrypt)
{
    vector<char> key = {'K', 'C', 'Q'}; // Any chars will work, in a vector of any size
    vector<char> output(toEncrypt.size());
    
    for (int i = 0; i < toEncrypt.size(); i++)
    {
        // Use a temporary variable for the key calculation
        int tempKeyIndex = i % key.size();
        output[i] = toEncrypt[i] ^ key[tempKeyIndex];
    }
    
    return output;
}

string vectorToString(const vector<char>& vec)
{
    string result;
    for (char c : vec)
    {
        result += c;
    }
    return result;
}

int main(int argc, const char * argv[])
{
    string input = "Great Britain will Junkfood-Werbung im TV vor 21 Uhr verbieten.";
    vector<char> toEncrypt(input.begin(), input.end());
    
    vector<char> encryptedVec = encryptDecrypt(toEncrypt);
    string encrypted = vectorToString(encryptedVec);
    cout << "Encrypted: " << encrypted << "\n";
    
    vector<char> decryptedVec = encryptDecrypt(encryptedVec);
    string decrypted = vectorToString(decryptedVec);
    cout << "Decrypted: " << decrypted << "\n";
    
    return 0;
}
