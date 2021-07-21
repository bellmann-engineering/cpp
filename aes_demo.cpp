// sudo apt-get install libcrypto++-dev libcrypto++-doc libcrypto++-utils
// g++ aes_demo.cpp -o aes -lcryptopp
// https://cryptopp.com/wiki/Advanced_Encryption_Standard

#include <iostream>
#include <iomanip>

#include <crypto++/modes.h>
#include <crypto++/aes.h>
#include <crypto++/filters.h>
#include <crypto++/osrng.h>

using namespace std;
using namespace CryptoPP;


int main(int argc, char* argv[]) {

	//AutoSeededRandomPool prng; 
	
    byte key[CryptoPP::AES::DEFAULT_KEYLENGTH];
	byte iv[CryptoPP::AES::BLOCKSIZE];
    
	memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);
	
	
	//prng.GenerateBlock(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    //prng.GenerateBlock(iv, CryptoPP::AES::BLOCKSIZE);


    string plaintext = "Dies ist ein Testtext, der verschlüsselt werden soll.";
    string ciphertext = "";
    string decryptedtext = "";


    cout << "Plain Text (" << plaintext.size() << " bytes)" << endl;
    cout << plaintext << endl << endl;

    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink( ciphertext ) );
    stfEncryptor.Put( reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length() );
    stfEncryptor.MessageEnd();

    cout << "Cipher Text (" << ciphertext.size() << " bytes)" << endl;

    for( int i = 0; i < ciphertext.size(); i++ ) 
	{
        cout << "0x" << hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
    }

    cout << endl << endl;

    // Decrypt
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(ciphertext.c_str()), ciphertext.size());
    stfDecryptor.MessageEnd();


    cout << "Decrypted Text: " << endl;
    cout << decryptedtext;
    cout << endl << endl;

    return 0;
}