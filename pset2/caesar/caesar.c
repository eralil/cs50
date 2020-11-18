#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

bool validate_input(string text);
void cipher_text(int key, string text);

int ASCII_Z = 90;
int ASCII_A = 65;
int ASCII_a = 97;
int ASCII_z = 122;
int ALPHABET_COUNT = 26;

int main(int argc, string argv[])
{


    long shifter = 1;
    if (argc == 2)
    {


        if (validate_input(argv[1]))
        {
            shifter = atoi(argv[1]);
            //PLAIN Text to CIPHER TEXT Converter
            cipher_text((shifter % ALPHABET_COUNT), get_string("plaintext: \n"));

        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Error , cannot proceed\n");
        return 1;
    }


    printf("\n");
    return 0;
}

//validate input key
bool validate_input(string text)
{

    //check if all char ar digits
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if (isdigit(text[i]) == false)
        {
            return false;
        }
    }

    int shifter = atoi(text);
    //only positive integers are allowed
    if ((shifter > 0) && (shifter < (long)(pow(2, 31) - 26)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//char shifting algorithm
void cipher_text(int key, string plain_text)
{

    int valid_in = 0, n = strlen(plain_text) ;
    char cipher_text[n];
    for (int j = 0, char_value = 0 ; j < n ; j++, valid_in++)
    {
        char_value = plain_text[j];


        if (plain_text[j]  >= ASCII_A && plain_text[j]  <= ASCII_Z)
        {

            cipher_text[valid_in] = (char)(char_value + key > ASCII_Z ? char_value + (-ALPHABET_COUNT) + key  : char_value + key);

        }
        else  if (plain_text[j]  >= ASCII_a && plain_text[j]  <= ASCII_z)
        {
            cipher_text[valid_in] = (char)(char_value + key > ASCII_z ? char_value + (-ALPHABET_COUNT) + key  : char_value + key);



        }
        else
        {
            cipher_text[valid_in] = plain_text[j];
        }

    }
    printf("ciphertext: ");
    for (int i = 0 ; i < valid_in ; i++)
    {
        printf("%c", cipher_text[i]);
    }

}