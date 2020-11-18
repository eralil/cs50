#include <math.h>
#include <cs50.h>
#include <stdio.h>

float get_balance(void);

int get_total_due_in_cents(float in);

void print_denominations(int due);

int main(void)
{
    float balance ;
    do
    {
        balance = get_balance();
    }
    while (balance < 0);

    int due = get_total_due_in_cents(balance);

    print_denominations(due);


}

float get_balance(void)
{
   return get_float("Balance :?\n");
}

int get_total_due_in_cents(float in)
{
    return in > 0 ? round(in * 100) : 0  ;
}

void print_denominations(int balance)
{
    int quarter = 0, dime = 0, nickel = 0, pennies = 0, due = balance;
    if (due % 25 != due)
    {
        quarter = due / 25;
        due -= quarter * 25;
    }
    if (due % 10 != due)
    {
        dime = due /10;
        due -= dime * 10;
    }
    if (due % 5 != due)
    {
        nickel = due / 5;
        due -= nickel * 5;
    }

    pennies = due;

    int total_paid_out = quarter + nickel + dime +pennies;
    printf("total paid out %i\n",total_paid_out);

}