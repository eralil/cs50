#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

bool validate_input(string text);
void cipher_text(string key, string text);

int ASCII_Z = 90;
int ASCII_A = 65;
int ASCII_a = 97;
int ASCII_z = 122;
int ALPHABET_COUNT = 26;

int main(int argc, string argv[])
{


    if (argc == 2 && validate_input(argv[1]))
    {
        //PLAIN Text to CIPHER TEXT Converter
        cipher_text((argv[1]), get_string("plaintext: \n"));

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;

    }


    printf("\n");
    return 0;
}

//validate input key
bool validate_input(string text)
{

    //length check
    int n = strlen(text);
    if (n != 26){
        printf("Key must contain 26 characters.\n");
        return false;
    }
    //check if all char ar digits
    for (int i = 0 ; i < n ; i++)
    {
        if (isalpha(text[i]) == false)
        {
            return false;
        }
    }


    return true;

}
//char shifting algorithm
void cipher_text(string strkey, string plain_text)
{
    int x = 0;
    char j[] = {'J','R','S','S','B'};
    for(int i = 0 ,n = strlen(plain_text) ; i < n ; i++  )
    {
        x  = strkey[i];
        printf("hardcoded %c %i %i %i\n",j[i],j[i],x%26,x%26 - j[i]);
        printf("PT %c %i %c %i\n",plain_text[i],plain_text[i],plain_text[i]+x,plain_text[i]+x );
        printf("CI %c %i %i\n",strkey[i],strkey[i],x);

    }



    /*int valid_in = 0, n = strlen(plain_text) ;
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
    }*/

}