//Includes
#include "PambafLib.h"
#include <string>
#include <cstring>
#include <stdlib.h>
#include <ctime>

using namespace std;

const char* PambafLib::generateKey(int length)
{
    //Initalize variable for the key
    static string key;
    key = "";

    //Initalize randomizer
    srand((unsigned int)time(NULL));

    //Check if length is >= 0
    if (length <= 0)
    {
        throw "Length must be higher than 0";
        return "";
    }

    //Initalize variable for the number of necessary characters
    int necessary = length;

    //Limit number of necessary characters to 255 (number of used characters)
    if (necessary > 255)
    {
        necessary = 255;
    }

    //Initalize variable for characters
    string chars = "";

    //Fill 'chars' with necessary characters
    for (int i = 0; i < necessary; i++)
    {
        chars += i + 1;
    }

    //Fill 'chars' with random characters
    for (int i = necessary; i < length; i++)
    {
        chars += (rand() % 255) + 1;
    }

    //Initalize temporary variables for shuffling the key
    string tempChars = "";
    char tempChar = 0;

    //Shuffle and encode the key
    for (int i = 0; i < length; i++)
    {
        //Choose random character from 'chars' and add the code to the key followed by a point
        tempChar = chars[rand() % chars.length()];
        key += to_string((unsigned char)tempChar);
        key += ".";

        //Remove this character from 'chars'
        for (unsigned int j = 0; j < chars.length(); j++)
        {
            if (chars[j] != tempChar || tempChar == '\0')
            {
                tempChars += chars[j];
            }
            else
            {
                tempChar = '\0';
            }
        }
        chars = tempChars;
        tempChars = "";
    }

    //Remove the last character (a point) from the key
    key = key.substr(0, key.length() - 1);

    //Return the key
    return key.c_str();
}

const char* PambafLib::encrypt(const char* message, const char* withKey)
{
    //Initalize variable for the encrypted message
    static string encryptedMessage;
    encryptedMessage = "";

    //Initalize randomizer
    srand((unsigned int)time(NULL));

    //Initalize temporary variables for decoding the key
    string key = "";
    string tempCode = "";

    //Decode the key
    for (unsigned int i = 0; i < strlen(withKey); i++)
    {
        switch (withKey[i])
        {
        case '.':
            key += atoi(tempCode.c_str());
            tempCode = "";
            break;
        default:
            tempCode += withKey[i];
            break;
        }
    }
    key += atoi(tempCode.c_str());

    //Initalize variables for finding possibilities and encrypting the message
    int* possibilities = (int*)malloc((key.length()) * sizeof(int));
    int possibilitiesIndex = 0;

    //Find possibilities and encrypt the message
    for (unsigned int i = 0; i < strlen(message); i++)
    {
        //Check if the key doesnt contain the character
        if ((unsigned)message[i] > key.length())
        {
            //Encrypt character with the key length and add it to the encrypted message followed by a point
            encryptedMessage += to_string(key.length() + message[i]);
            encryptedMessage += ".";
        }
        else
        {
            //Reset possiblities
            possibilitiesIndex = 0;

            //Find possible indices in the key
            for (unsigned int j = 0; j < key.length(); j++)
            {
                if (message[i] == key[j])
                {
                    possibilities[possibilitiesIndex] = j;
                    possibilitiesIndex++;
                }
            }

            //Choose random index from 'possibilities' and add the index to the encrypted message followed by a point
            encryptedMessage += to_string(possibilities[rand() % possibilitiesIndex]);
            encryptedMessage += ".";
        }
    }

    //Remove the last character (a point) from the encrypted message
    encryptedMessage = encryptedMessage.substr(0, encryptedMessage.length() - 1);

    //Return the encrypted message
    return encryptedMessage.c_str();
}

const char* PambafLib::decrypt(const char* encryptedMessage, const char* withKey)
{
    //Initalize variable for the decrypted message
    static string decryptedMessage;
    decryptedMessage = "";

    //Initalize randomizer
    srand((unsigned int)time(NULL));

    //Initalize temporary variables for decoding the key
    string key = "";
    string tempCode = "";

    //Decode the key
    for (unsigned int i = 0; i < strlen(withKey); i++)
    {
        switch (withKey[i])
        {
        case '.':
            key += atoi(tempCode.c_str());
            tempCode = "";
            break;
        default:
            tempCode += withKey[i];
            break;
        }
    }
    key += atoi(tempCode.c_str());

    //Initalize variables for decrypting the encrypted message
    tempCode = "";

    //Decrypting the encrypted message
    for (unsigned int i = 0; i < strlen(encryptedMessage); i++)
    {
        switch (encryptedMessage[i])
        {
        case '.':
            //Check if the key doesnt contain the character
            if ((unsigned)atoi(tempCode.c_str()) > key.length())
            {
                //Get character add it to the decrypted message
                decryptedMessage += atoi(tempCode.c_str()) - (int)key.length();
            }
            else
            {
                //Get character from key by index and add it to the decrypted message
                decryptedMessage += key[atoi(tempCode.c_str())];
            }
            tempCode = "";
            break;
        default:
            tempCode += encryptedMessage[i];
            break;
        }
    }
    if ((unsigned)atoi(tempCode.c_str()) > (unsigned)key.length())
    {
        decryptedMessage += atoi(tempCode.c_str()) - (int)key.length();
    }
    else
    {
        decryptedMessage += key[atoi(tempCode.c_str())];
    }

    //Return the decrypted message
    return decryptedMessage.c_str();
}

const char* PambafLib::getVersion()
{
    return "1.0.0";
}
