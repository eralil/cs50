#include <cs50.h>
#include <stdio.h>

string name(string input);
//main method
int main(void){
    
    string name  = get_string("What is your name?\n");
    printf("Hello, %s\n",name);
    
}
