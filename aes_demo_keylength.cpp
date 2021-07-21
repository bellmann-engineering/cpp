// sudo apt-get install libcrypto++-dev libcrypto++-doc libcrypto++-utils
// g++ aes_demo_keylength.cpp -o aes2 -lcryptopp
// https://cryptopp.com/wiki/Advanced_Encryption_Standard

#include <iostream>
#include <iomanip>

#include <crypto++/modes.h>
#include <crypto++/aes.h>
#include <crypto++/filters.h>
#include <crypto++/osrng.h>

using namespace std;
using namespace CryptoPP;

// CryptoPP::AES::DEFAULT_KEYLENGTH -> KEY_LENGTH_BYTES
#define KEY_LENGTH_BYTES 32

int main(int argc, char* argv[]) {

    // key length: 128-bit, 196-bit, 256-bit
    // DEFAULT_KEYLENGTH = 16 bytes -> 128-bit
	
	AutoSeededRandomPool prng; 
	
    byte key[KEY_LENGTH_BYTES];
	byte iv[CryptoPP::AES::BLOCKSIZE];
    
	memset(key, 0x00, KEY_LENGTH_BYTES);
    memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);
	
	//prng.GenerateBlock(key, KEY_LENGTH_BYTES);
    //prng.GenerateBlock(iv, CryptoPP::AES::BLOCKSIZE);
	
	cout << "Key (" << KEY_LENGTH_BYTES << ") bytes: ";
	for(int i = 0; i < KEY_LENGTH_BYTES; i++) 
	{
        cout << "0x" << hex << (0xFF & static_cast<byte>(key[i])) << " ";
    }
	
	cout << endl << endl;
	



    string plaintext = "Dies ist ein Testtext, der verschlüsselt werden soll.";
    string ciphertext = "";
    string decryptedtext = "";


    cout << "Plain Text (" << plaintext.size() << " bytes)" << endl;
    cout << plaintext << endl << endl;

    CryptoPP::AES::Encryption aesEncryption(key, KEY_LENGTH_BYTES);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext ));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length());
    stfEncryptor.MessageEnd();

    cout << "Cipher Text (" << ciphertext.size() << " bytes)" << endl;

    for(int i = 0; i < ciphertext.size(); i++) 
	{
        cout << "0x" << hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
    }

    cout << endl << endl;

    // Decrypt
    CryptoPP::AES::Decryption aesDecryption(key, KEY_LENGTH_BYTES);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink( decryptedtext ) );
    stfDecryptor.Put( reinterpret_cast<const unsigned char*>(ciphertext.c_str()), ciphertext.size());
    stfDecryptor.MessageEnd();

    cout << "Decrypted Text: " << endl;
    cout << decryptedtext;
    cout << endl << endl;

    return 0;
}