#include <iostream>
#include <cctype>
#include "Cipher.h"
#include <locale>
#include <codecvt>

using namespace std;

void check( wstring text, wstring key,  bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        Cipher cipher(key);
        cipherText = cipher.encrypt(text);
        decryptedText = cipher.decrypt(cipherText);
        wcout<<L"Ключ: "<<key<<endl;
        wcout<<L"Начальный текст: "<<text<<endl;
        wcout<<L"Закодированный текст: "<<cipherText<<endl;
        wcout<<L"Декодированный текст: "<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        wcerr<<"Error: "<<e.what()<<endl;
    }
}

int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;

    check(L"СИМПЛ",L"");
    wcout<<endl;
    wcout<<endl;
    check(L"СИМПЛ",L"!!!");
    wcout<<endl;
    wcout<<endl;
    check(L"СИМПЛ1",L"5");
    wcout<<endl;
    wcout<<endl;
    check(L"симпл",L"5");
    wcout<<endl;
    wcout<<endl;
    check(L"СИМПЛ",L"0");
    wcout<<endl;
    wcout<<endl;
    return 0;

}
