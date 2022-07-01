#pragma once

#ifndef SGX_CRYPTO_H
#define SGX_CRYPTO_H

#include "sgx_tseal.h"
#include "enclave_u.h"
#include "sgx_urts.h"
#include <string>
#include "sgx_tcrypto.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <tchar.h>

#include <windows.h>
#include <algorithm>
#include <cctype>
#include <conio.h>

#ifdef DEBUG
	#define ENCLAVE_FILE _T("../x64/Simulation/enclave.signed.dll") //full path if debug
#else
	#define ENCLAVE_FILE _T("enclave.signed.dll")
#endif //DEBUG

#include <stdlib.h>
#include <wincrypt.h>


#define DEBUG_LEVEL 1

using namespace std;

namespace SGX_Crypto {
	size_t getLen(size_t textLength);
	size_t getEncrypt(char* plainText, size_t plainTextLength, sgx_sealed_data_t* outSealBuffer, char* outTextBuffer);
	size_t getDecrypt(char* encText, size_t encTextLength, sgx_sealed_data_t* sealData, char* outTextBuffer);
	sgx_enclave_id_t initEnclave();
}

#endif //SGX_CRYPTO_H
