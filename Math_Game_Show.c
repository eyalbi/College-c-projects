/*assignment :2
campus: beer sheva
author:bismuth eyal,ID:308200203*/
#define ZERO 0
#define ONE 1
#define TEN 10
#define HUNDREAD 100
#define THOUSAND 1000
#define OTHOUSAND 10000
void CountIntersectDigts();
int DigitsCounter(int a);
int ZeroCheck(int a,int b);
int DividersSum (int a);
void PrintFriends();
long int ReverseDigits(long int a);
void ReverseAndAdd5 ();
long int MaxDigit(long int num);
long int RemoveMaxDigit();
int PrintSpecialNumbers();
int MakeNewNumber();
void PrintPattern();
#include <stdio.h>
int main(){       /*this program is a mathematical "gameshow" the user choose options and the program do as he chose*/
    int Operate;
    do{  /*this is an option menu for the users that repeats itself until users choosing exit*/
       printf("1-same digts\n2-friend numbers\n3-reverse the digits and add 5\n4-remove all max digit\n5-print the special numbers\n6-make a new number\n7-print numbers in pattern\n8-exit\n");
       scanf("%d",&Operate);
       switch(Operate){
            case 1:
            CountIntersectDigts();
            break;
            case 2:
            PrintFriends();
            break;
            case 3:
            ReverseAndAdd5 ();
            break;
            case 4:
            printf("%ld\n",RemoveMaxDigit());
            break;
            case 5:
            printf("the amount of special numbers is : %d\n",PrintSpecialNumbers());
            break;
            case 6:
            printf("the new number is : %d\n",MakeNewNumber());
            break;
            case 7:
            PrintPattern();
            break;
            case 8:
            printf("have a nice day!\n");
            break;
            default :
            printf("invalid input please try again\n");
            break;


    
        }  
    }
    while(Operate !=8);/*a loop that check if the users want to exit*/
return ZERO;
}
void CountIntersectDigts(){   /*this function checking for 2 integers how many times the first number digits apereaing in the second digits*/
    int i,j,num1=ONE,temp1,num2=ONE,temp2,c=ZERO;
    while(ZeroCheck(num1,num2)!=ZERO){    /*zero cheack is a function that checks if 2 number equal to zero at the same time*/
    printf("enter 2 integers\n");
    scanf("%d%d",&num1,&num2);
    if(ZeroCheck(num1,num2)==ZERO){
        break;
    }
    temp1=num1;
    for(i=ZERO;i<DigitsCounter(num1);i++){ /*digits counter is a function thats check how many digits a number have */
        temp2=num2;
        for(j=ZERO;j<DigitsCounter(num2);j++){
            if(temp1%TEN==temp2%TEN){
            c++;
            }
            temp2=temp2/TEN;
        }
       temp1=temp1/TEN;
    }
    printf("%d\n",c);
    c=ZERO;
    }
    
}    
int DigitsCounter(int a){/*this function checking how many digits a intger has.*/
    int counter=ZERO;
    if (a==ZERO){
        return ONE;
    }
    while (a!=ZERO){
        a=a/TEN;
        counter++;
    }
    
return counter;
}
int ZeroCheck(int a,int b){/*this funcyion checks if two integers are equal to zero at the same time*/
    if (a==ZERO&&b==ZERO){
       return ZERO;
    }
    else{
        return ONE;
    }
}
int DividersSum(int a){/*this function checks the sum of the dividers of an integer (not including the number itself)*/
     int i,j,sum=ZERO;
     for(i=1;i<a;i++){
        if(a%i==ZERO)
        sum+=i;
        }    
return sum;
}
void PrintFriends(){/*this function print the numbers between 1-1000 that the some of their dividers equals to one another(including perfect number)*/
    int i,j;
    for(i=ONE;i<=THOUSAND;i++){
        for(j=ONE;j<=THOUSAND;j++){
            if (DividersSum(i)==j&&DividersSum(j)==i){
                printf("%d %d\n",i,j);
            }
        }
    }
}
long int ReverseDigits(long int a){/*this function reverse the number digits*/
    long int rev_num=ZERO;
    while (a>ZERO){
      rev_num=rev_num*TEN+a%TEN; 
      a=a/TEN;   
    }
return rev_num;    
}
void ReverseAndAdd5 (){/*this function reverse the digits of a number and add five to the result*/
    long int num;
    printf("enter a long positive integer\n");
    scanf("%ld",&num);
    printf("%ld\n",ReverseDigits(num)+5);
}
long int MaxDigit(long int num){/*this function checks what is the max digit of a number*/
     int max=ZERO;
     max=num%TEN;
     while(num>ZERO&&num!=ZERO){
     num=num/TEN;
     if(num%TEN>max)
     max=num%TEN;
    } 
return max;
}
long int RemoveMaxDigit(){      /*this functio removes the max digit of a number and return a new number without the max digit */
    long int i,num,temp,rem_num=ZERO;
    printf("enter a long and positive integer\n");
    scanf("%ld",&num);
    temp=ReverseDigits(num); /*reverss digits is a functio that reversing a number digits(help function)*/
    for(i=ZERO;i<DigitsCounter(num);i++){
        if(temp%TEN<MaxDigit(num)){ /*max digit is a functio that check the max digit of an integer*/
            rem_num=rem_num*TEN+temp%TEN;
        }
    temp=temp/TEN;    
    }
return rem_num;
}
int PrintSpecialNumbers(){ /*this function prints all positive 5 digits number that all of ther digits are different and return the amount of them*/
    int counter = ZERO,n1,n2,n3,n4,n5;
    long int i;
    for(i=OTHOUSAND;i<(OTHOUSAND*TEN);i++){
        n1=i%TEN;
        n2=(i/TEN)%TEN;
        n3=(i/HUNDREAD)%TEN;
        n4=(i/THOUSAND)%TEN;
        n5=(i/OTHOUSAND)%TEN;
        if(((n1 != n2)&& (n1!=n3) && (n1!= n4) && (n1!=n5))&&((n2 != n3) && (n2 !=n4) && (n2 !=n5)) &&((n3 != n4) &&(n3 != n5))&&((n4 != n5))){
            printf("%ld:is a special number\n",i);
            counter ++;
        }     

    }
return counter;
}
int MakeNewNumber(){ /*this function gets an input of 2 integers and making a new number with the max digit from every number */
int num1,num2,new_number=ZERO,temp1,temp2;
do{
    printf("enter 2 positive integers\n");
    scanf("%d%d",&num1,&num2);
    }
    while(num1 <= ZERO && num2 <= ZERO);
    temp1 = ReverseDigits (num1);
    temp2 = ReverseDigits (num2);
    while(temp1 > ZERO||temp2 > ZERO){
        while(DigitsCounter(temp1) > DigitsCounter(temp2)){ /*first case: num 1 has more digits than num2 */
            new_number = new_number * TEN + temp1 % TEN;
            temp1 = temp1 / TEN;
        }
        while(DigitsCounter(temp2) > DigitsCounter(temp1)){ /*second case:  num 2 has more digits than num 1 */
            new_number = new_number * TEN + temp2 % TEN;
            temp2 = temp2 / TEN;
        }
    if(temp1 % TEN >= temp2 % TEN){
        new_number = new_number * TEN + temp1 % TEN;
    }else{
      new_number = new_number * TEN + temp2 % TEN;   
    }
    temp1 = temp1 / TEN;
    temp2 = temp2 / TEN;
    }
return new_number;
}
void PrintPattern(){ /*this function prints a triangle (and is reflaction) of following numbers according to user input*/
    int temp,num,i,j,SpaceCount ;
    printf("enter a positive integer between 2-9\n") ;
    scanf("%d",&num) ;
    temp=num;
    if(num <= 9 && num > ZERO){
    for(i=1;i<=num;i++){
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        for(SpaceCount=(temp*2)-2;SpaceCount>=1;SpaceCount--){
            printf(" ");
        }
        for(--j;j>0;j--){
            printf("%d",j);
        }
        temp=temp-1;
    printf("\n");
    }
    }else{
        printf("you have entered a wrong input\n");
    }
  
}

    









