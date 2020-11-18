#include <cs50.h>
#include <stdio.h>


long get_card_number(void);

bool is_valid_card(long card);

int main(void)
{
    long card_number = 0;
    do
    {
        card_number = get_card_number();
    }
    while ( card_number <= 0 || is_valid_card(card_number) == false);
}

long get_card_number(void)
{

    return get_long("card :\n");
}

bool is_valid_card(long in)
{
    int card_size = 0 ,x = 0	,	highest_digit	=	0	, sec_highest_digit	=	0	,	card_digit_verifier = 0 , counter = 0 , digits_sum = 0 , luhns_check_sum = 0, remainder = 0 ;
    long card = 0;
    bool luhns_check_sum_valid = false;
    for(long i = in ; i	>	0 ;	i/=10 )
    {
    remainder = (i % 10) ;
    x =remainder * 2 ;
    if(counter % 2 == 1){

    if(x > 9){
        luhns_check_sum += (x % 10) + (x / 10);

    }else{
        luhns_check_sum += x;
    }
    }else{
    luhns_check_sum += remainder;
    }
    card = i/10;

    if(card > 0 && card < 10)
    {
    highest_digit = (i/10) ;
    sec_highest_digit = remainder;
    }
    card_size++;
    counter++;
    remainder = 0;


    }
    //luhns check sum%19 == 0? valid card
    luhns_check_sum_valid = (luhns_check_sum % 10) == 0?true:false;

    //prelim check if card is amex , visa or mastercard
    card_digit_verifier =	(highest_digit	*	10)	+	sec_highest_digit;
    if(luhns_check_sum_valid == true)
    {
    if(highest_digit == 4 && ( card_size == 13 || card_size == 16)  ){
    printf("VISA\n");
    }
    else if(card_size == 16 && card_digit_verifier >  50 && card_digit_verifier <= 55 ){
    printf("MASTERCARD\n");
    }
    else if(card_size == 15 && ( card_digit_verifier ==  34 || card_digit_verifier == 37) ){
    printf("AMEX\n");
    }
    else
    {
    printf("INVALID\n");
    }

    }
    else
    {
    printf("INVALID\n");

    }
    return true;

}
