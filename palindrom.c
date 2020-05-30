/*Assighnment 3
    Campus:Beer Sheva
    Author:Eyal Bismuth ID:308200203
*/
#include <stdio.h>
int IsApalindrom(int arr[],int start,int end);
int PrintDivided (int arr[],int size,int value);
void PrintMaxPalindrom(int arr[],int size);
void ArrayInput(int arr[],int size);
#define ONE 1
#define ZERO 0
#define M 10
#define N 14
int main(){ /*this program checks mutual dividers for array numbers and also checks palindrom in arrays*/
    int One[N],Two[M],value;
    printf("enter a value to check if it is a divider\n");
    scanf("%d",&value);
    printf("array 1 :\n");
    ArrayInput(One,N);
    printf("array 2 :\n");
    ArrayInput(Two,M);
    printf("the amount of numbers from array One that can be divided by value are :%d\n",PrintDivided(One,N,value));
    printf("the amount of numbers from array Two that can be divided by value are :%d\n",PrintDivided(Two,M,value));
    PrintMaxPalindrom(One,N);
    PrintMaxPalindrom(Two,M);
return ZERO;
}
int PrintDivided (int arr[],int size,int value){ /*this function checks which array numbers divide fully by a value- 1.prints them 2.sending back there amount*/
    int i,count = ZERO;
    if(value == ZERO){
        return -1;
    }
    for(i = ZERO;i < size;i ++){
        if (arr[i] % value == ZERO){
            printf("%d ",arr[i]);
            count ++;
        }
    }
return count;
}
void PrintMaxPalindrom(int arr[],int size){ /* this function checks for the longest palindrom in array and prints it(also uses the function IsAPalindrom that check if array is a palindrom*/
    int i,j,start,end,max=ZERO;
    for(start=ZERO;start<size;start++){
        for(end=size-ONE; end > start ;end--){
            if(IsApalindrom(arr,start,end)&&(end-start)>max){
                i=start;
                j=end;
                max=end-start+ONE;
            }
        }
    
    
    }
    if(max==ZERO){
        printf("thers no palindrom in the array");
    }else{
    printf("the max palindrom is: ");
    for(;i<=j;i++){
        printf("%d",arr[i]);
    }
}

printf("\n");
}
int IsApalindrom(int arr[],int start,int end){/*with a given start and end index this function cheaks for palindrom in arrays*/
    int flag=ONE;
    for(;start < end ;end--,start++){
        if(arr[start] != arr[end]){
            flag=ZERO;
        }
        
    }
return flag;
}
void ArrayInput(int arr[],int size){/*this function filling an array with user input*/
    for(int i=ZERO;i<size;i++){
        printf("enter an integer for array\n");
        scanf("%d",&arr[i]);
    }
}