#include "enclave_t.h"
#include <string>
#include "sgx_tcrypto.h"
#include "sgx_trts.h"
#include "sgx_utils.h"
#include "sgx_tseal.h"

void decryptText(char* encMsg, size_t len, char* plainText, size_t lenOut, sgx_sealed_data_t* sealedData, uint32_t sealed_Size, char* debug, uint8_t debug_size)
{
	sgx_status_t seal_status = SGX_SUCCESS;//���������� ��������� ��� ������
	sgx_status_t decrypt_status = SGX_SUCCESS;//���������� ��������� ��� �����������
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

	decrypt_status = sgx_rijndael128GCM_decrypt( // �-� ����������
		&key,// ��������� �� ����, ������� ����� �������������� � �������� ������������ AES - GCM.������ ������ ���� 128 ���.
		encMessage + SGX_AESGCM_MAC_SIZE + SGX_AESGCM_IV_SIZE, //��������� �� ������� ����� ������, ���������� �����������. ����� ����� ���� �������, ���� ���� �����.
		(uint32_t)lenOut, //������ ����� �������� ������ ������, ����������� �����������. ��� ����� ���� ����� ����, �� p_src � p_dst ������ ���� ����� ����, � and_len ������ ���� ������ ����.
		p_dst,//������ ����� �������� ������ ������, ����������� �����������. ��� ����� ���� ����� ����, �� p_src � p_dst ������ ���� ����� ����, � and_len ������ ���� ������ ����.
		encMessage + SGX_AESGCM_MAC_SIZE, //������� ��������� + IV
		SGX_AESGCM_IV_SIZE,//������ IV
		NULL, //��������� �� �������������� �������������� ����� ������ ��������������, ������� ��������������� ��� ���������� MAC-������ GCM ��� ����������. ������ � ���� ������ �� ���� �����������. ��� ���� �������� �������������� � ����� ���� �������.
		0,//������ ����� ��������������� ������ ������ ��������������. ���� ����� �������� ��������������, � ������� ��� ������ ����� ���� ����� ����.
		(sgx_aes_gcm_128bit_tag_t*)encMsg);//��������� ��  MAC

	if (decrypt_status != SGX_SUCCESS) {
		memcpy(debug, "Problem with data decryption", strlen("Problem with data decryption"));
		free(p_dst);
		return;
	}
	memcpy(plainText, p_dst, lenOut);
	free(p_dst);// ������� Delete, �� ���  ����� C (������� ������, ������� ������� p_dest)
	return;
}

void encryptText(char* plainText, size_t length, char* cipher, size_t len_cipher, sgx_sealed_data_t* sealed, uint32_t sealed_Size, char* debug, uint8_t debug_size)
{
	uint32_t key_size = SGX_AESGCM_KEY_SIZE;
	sgx_status_t seal_status;//���������� ��������� ��� �������������� �����
	sgx_status_t encrypt_status;//���������� ��������� ��� ���������� ������
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
	sgx_read_rand(cipherText + SGX_AESGCM_MAC_SIZE, SGX_AESGCM_IV_SIZE);//���������� ������� ���������� �������
	encrypt_status = sgx_rijndael128GCM_encrypt(// rijndael-����������� ��-� ���������� AES
		&key,//Key
		plain,//��������� �� �������� �����
		length,//����� ��������� ������
		cipherText + SGX_AESGCM_IV_SIZE + SGX_AESGCM_MAC_SIZE,//������� ��������� ���� ������ IV + ������ Mac = ����� ����������
		cipherText + SGX_AESGCM_MAC_SIZE,//IV... ������� ��������� ���� MAC
		SGX_AESGCM_IV_SIZE,//������ IV
		NULL,
		0,
		(sgx_aes_gcm_128bit_tag_t*)(cipherText));
	if (encrypt_status != SGX_SUCCESS) {
		memcpy(debug, "Problem with data encryption", strlen("Problem with data encryption"));
		free(cipherText);
		return;
	}
	memcpy(cipher, cipherText, len_cipher);//����������� cipherText � �������� �����
	free(cipherText);
	return;
}

/*�������, ������� ���������� ��������� ���� � ������������ ���*/
void seal(sgx_sealed_data_t* sealedData, uint32_t seal_data_size, char* debug, uint8_t debug_size) {
	sgx_status_t ret = SGX_SUCCESS;
	uint8_t key[16];
	sgx_read_rand(key, SGX_AESGCM_KEY_SIZE); // ��������� ����
	sgx_sealed_data_t* internal_buffer = (sgx_sealed_data_t*)malloc(seal_data_size);
	ret = sgx_seal_data(
		0,//�������������� Mac Text len
		NULL,//�������������� MAC text
		SGX_AESGCM_KEY_SIZE,//����� ����� ��� ����������
		key,//��������� �� ���� (������������ ����)
		seal_data_size,//Sealed ����� ������
		internal_buffer);//��������� �� ������������ ������
	if (ret != SGX_SUCCESS) {
		memcpy(debug, "Data Sealing Error", strlen("Data Sealing Error"));
		free(internal_buffer);
		return;
	}
	memcpy(sealedData, internal_buffer, seal_data_size);
	free(internal_buffer);
	return;
}// Seal-����������� ������������ ������ ��������� ������� ������� ������� �����, �������� ������ � �����������
  //������ � ������ ������� ������������ ����������� � �������� ��������� �������� �� �������� � ����������
  //�� ����� �������� ����������

/*������� ��� ��������� ������� ������������ ������*/
uint32_t sizeOfSealData() {
	uint32_t size_data = sgx_calc_sealed_data_size(0, SGX_AESGCM_KEY_SIZE);
	return size_data;
}