#include "lab3_enc_t.h"
#include "sgx_trts.h"
#include <string.h>

const char table[6][41] = {
    "7eb5ecd8ce73ae063e7ae783c54eac15748667a7",
    "1c25628f790fd2258821bfe33d6284e8cacf445e",
    "f4bace63c61af4dc9e1e3c1b6a4271f3bf2c7b25",
    "ff018ffa70d2deccc38483d5cacc41d7321088f6",
    "318e469cfb3582c4f6d280ff09654201bd218e85"
};

void foo(char* buf, size_t len, size_t idx) {
    if (idx < 5) {  //проверка индекса строки- меньше 5
        const char* data_ptr = data_ptr = table[idx];
        memcpy(buf, data_ptr, strlen(data_ptr)); //  1                           
    }
    else { // вывод 0строки
        memset(buf, 0, strlen(table[0])); //         2                        
    }
    return;
}