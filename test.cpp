#include <stdio.h>
#include <string>
#include "sgx_crypto.h"

using namespace std;

int main() {
	cout<<"========================== SGX TEXT Encryption =========================="<<endl<<endl;

	string plainText = "Good afternoon, Anton Alexandrovich. It wasn't easy, but we tried. In programming, we are not very strong, but we squeezed the maximum out of ourselves, because we donТt want to write an exam, so we present to your attention the task for the machine - Sincerely, Alizade Ulyana Vitalievna and Valyavsky Alexey Alexandrovich. PS: 3 for our eyes, this item is the only one we have not yet handed over, the rest have already been closed, and we would like to close this one too. Cheer up joke: Developers accused of writing unreadable code declined to comment.";
	  
	sgx_sealed_data_t* sealBuffer = new sgx_sealed_data_t();
	auto plainTextLength = plainText.length(); 
	
	cout << "PLAIN TEXT : " << plainText << endl;
	cout << "PLAIN TEXT LENGTH : " << plainTextLength << endl; 
	cout << endl;

	char* encText = new char[SGX_Crypto::getLen(plainTextLength)];
	auto encTextLength = SGX_Crypto::getEncrypt(&*plainText.begin(), plainTextLength, sealBuffer, encText); // plaintext-строка, а нам надо передеать указательн на char , дл€ этого мы используем begin, он возвращает итерратор начала , потом *(указатель на начало и ссылка на пам€ть- из String  получаем указатель на Char

	cout << "Encrypted : " << encText << endl;
	cout << "Encrypted Length : " << encTextLength << endl;
	cout << endl;

	char* decText = new char[encTextLength];
	auto decTextLength = SGX_Crypto::getDecrypt(encText, encTextLength, sealBuffer, decText);
	
	cout<< "Decrypted : " << decText <<endl;
	cout << "Decrypted Length : " << decTextLength << endl;
	cout << endl;
	
	return 0;
}

