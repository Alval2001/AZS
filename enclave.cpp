#include "enclave_t.h"
#include <string>
#include "sgx_tcrypto.h"
#include "sgx_trts.h"
#include "sgx_utils.h"
#include "sgx_tseal.h"

void decryptText(char* encMsg, size_t len, char* plainText, size_t lenOut, sgx_sealed_data_t* sealedData, uint32_t sealed_Size, char* debug, uint8_t debug_size)
{
	sgx_status_t seal_status = SGX_SUCCESS;//Переменная состояния для вывода
	sgx_status_t decrypt_status = SGX_SUCCESS;//Переменная состояния для расшифровки
	uint8_t* encMessage = (uint8_t*)encMsg;
	uint8_t* p_dst = (uint8_t*)malloc(lenOut * sizeof(char));
	uint8_t key[SGX_AESGCM_KEY_SIZE];
	uint32_t key_size = SGX_AESGCM_KEY_SIZE;
	seal_status = sgx_unseal_data(sealedData, NULL, NULL, key, &key_size);

	if (seal_status != SGX_SUCCESS) {
		memcpy(debug, "Cannot Unseal the key", strlen("Cannot Unseal the key"));
		free(p_dst);
		return;
	}

	decrypt_status = sgx_rijndael128GCM_decrypt( // ф-я шифрования
		&key,// Указатель на ключ, который будет использоваться в операции дешифрования AES - GCM.Размер должен быть 128 бит.
		encMessage + SGX_AESGCM_MAC_SIZE + SGX_AESGCM_IV_SIZE, //Указатель на входной поток данных, подлежащий расшифровке. Буфер может быть нулевым, если есть текст.
		(uint32_t)lenOut, //Задает длину входного потока данных, подлежащего расшифровке. Это может быть равно нулю, но p_src и p_dst должны быть равны нулю, а and_len должно быть больше нуля.
		p_dst,//Задает длину входного потока данных, подлежащего расшифровке. Это может быть равно нулю, но p_src и p_dst должны быть равны нулю, а and_len должно быть больше нуля.
		encMessage + SGX_AESGCM_MAC_SIZE, //Базовый указатель + IV
		SGX_AESGCM_IV_SIZE,//Размер IV
		NULL, //Указатель на необязательный дополнительный буфер данных аутентификации, который предоставляется для вычисления MAC-адреса GCM при шифровании. Данные в этом буфере не были зашифрованы. Это поле является необязательным и может быть нулевым.
		0,//Задает длину дополнительного буфера данных аутентификации. Этот буфер является необязательным, и поэтому его размер может быть равен нулю.
		(sgx_aes_gcm_128bit_tag_t*)encMsg);//Указатель на  MAC

	if (decrypt_status != SGX_SUCCESS) {
		memcpy(debug, "Problem with data decryption", strlen("Problem with data decryption"));
		free(p_dst);
		return;
	}
	memcpy(plainText, p_dst, lenOut);
	free(p_dst);// функция Delete, но для  языка C (Очистка памяти, удалили поинтер p_dest)
	return;
}

void encryptText(char* plainText, size_t length, char* cipher, size_t len_cipher, sgx_sealed_data_t* sealed, uint32_t sealed_Size, char* debug, uint8_t debug_size)
{
	uint32_t key_size = SGX_AESGCM_KEY_SIZE;
	sgx_status_t seal_status;//Переменная состояния для распечатывания ключа
	sgx_status_t encrypt_status;//Переменная состояния для шифрования данных
	sgx_sealed_data_t* sealedData = sealed;
	uint8_t* plain = (uint8_t*)plainText;
	uint8_t* iv;
	size_t cipherTextSize = SGX_AESGCM_KEY_SIZE + SGX_AESGCM_MAC_SIZE + length;
	uint8_t* cipherText = (uint8_t*)malloc(cipherTextSize * sizeof(char));
	//	uint8_t cipherText[4098] = {0};
	uint8_t key[16];
	sgx_status_t ret;
	seal_status = sgx_unseal_data(sealedData, NULL, NULL, key, &key_size);
	if (seal_status != SGX_SUCCESS) {
		memcpy(debug, "Cannot Unseal the key", strlen("Cannot Unseal the key"));
		free(cipherText);
		return;
	}
	sgx_read_rand(cipherText + SGX_AESGCM_MAC_SIZE, SGX_AESGCM_IV_SIZE);//Заполнение анклава случайными числами
	encrypt_status = sgx_rijndael128GCM_encrypt(// rijndael-анклавовкая фу-я шифрования AES
		&key,//Key
		plain,//Указатель на открытый текст
		length,//Длина открытого текста
		cipherText + SGX_AESGCM_IV_SIZE + SGX_AESGCM_MAC_SIZE,//Базовый указатель плюс размер IV + размер Mac = место назначения
		cipherText + SGX_AESGCM_MAC_SIZE,//IV... базовый указатель плюс MAC
		SGX_AESGCM_IV_SIZE,//Размер IV
		NULL,
		0,
		(sgx_aes_gcm_128bit_tag_t*)(cipherText));
	if (encrypt_status != SGX_SUCCESS) {
		memcpy(debug, "Problem with data encryption", strlen("Problem with data encryption"));
		free(cipherText);
		return;
	}
	memcpy(cipher, cipherText, len_cipher);//Копирование cipherText в выходной буфер
	free(cipherText);
	return;
}

/*Функция, которая генерирует случайный ключ и запечатывает его*/
void seal(sgx_sealed_data_t* sealedData, uint32_t seal_data_size, char* debug, uint8_t debug_size) {
	sgx_status_t ret = SGX_SUCCESS;
	uint8_t key[16];
	sgx_read_rand(key, SGX_AESGCM_KEY_SIZE); // рандомный ключ
	sgx_sealed_data_t* internal_buffer = (sgx_sealed_data_t*)malloc(seal_data_size);
	ret = sgx_seal_data(
		0,//Дополнительный Mac Text len
		NULL,//Дополнительный MAC text
		SGX_AESGCM_KEY_SIZE,//Длина ключа для шифрования
		key,//Указатель на ключ (сгенерирован выше)
		seal_data_size,//Sealed рамер данных
		internal_buffer);//Указатель на запечатанные данные
	if (ret != SGX_SUCCESS) {
		memcpy(debug, "Data Sealing Error", strlen("Data Sealing Error"));
		free(internal_buffer);
		return;
	}
	memcpy(sealedData, internal_buffer, seal_data_size);
	free(internal_buffer);
	return;
}// Seal-Возможность герметизации данных позволяет анклаву надежно хранить ключи, получать доступ к сохраненным
  //ключам в разных версиях программного обеспечения и избегать накладных расходов на проверку и подготовку
  //во время обычного выполнения

/*Функция для получения размера запечатанных данных*/
uint32_t sizeOfSealData() {
	uint32_t size_data = sgx_calc_sealed_data_size(0, SGX_AESGCM_KEY_SIZE);
	return size_data;
}