#include <cs50.h>
#include <stdio.h>

//get height
int get_wall_height(void);

void print_wall(int height);

int main(void)
{

    int height = 0;
    do
    {
        height = get_wall_height();
    }
    while(height == 0);

    print_wall(height);
}

int get_wall_height()
{


    int input = get_int("Height :");
    if(input >0 && input < 9)
    {
        return input;
    }else
    {
        return 0;
    }
}

void print_wall(int height){

    for(int i=1 ; i <= height ; i++)
    {


        //left space
        for(int k = height; k > i;  k--)
        {

            printf(" ");

        }

        //left wall
        for(int j = 0; j < i; j++)
        {

            printf("#");
        }
        //mid space
        printf("  ");
        //right wall
        for(int j = 0; j < i; j++)
        {

            printf("#");
        }

        printf("\n");
    }
}