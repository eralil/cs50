#include <cs50.h>
#include <stdio.h>


int main(void)
{

    int size = get_int("Enter size\n");
    int  arr[size]  ;

   
    for(int i = 0 ;i < size ;i++)
    {
        printf("%i of arr[%i]\n",i,arr[i]);
    }



}


