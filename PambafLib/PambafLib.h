#ifndef PAMBAFLIB_H
#define PAMBAFLIB_H

class PambafLib
{

public:

    //Generate a key of a specific length
    static const char* generateKey(int length);

    //Encrypt a message with a key
    static const char* encrypt(const char* message, const char* withKey);

    //Decrypt an encrypted message with a key
    static const char* decrypt(const char* encryptedMessage, const char* withKey);

    //Get version of the library
    static const char* getVersion();

};

#endif // PAMBAFLIB_H
