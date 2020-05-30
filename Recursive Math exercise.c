/*Assignment 5
      campus: Beer Sheva
      Author: Eyal Bismuth,ID: 308200203
*/
#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
#define ONE 1
#define TWO 2
#define TEN 10
#define MAX_LEN 80
typedef enum{FALSE,TRUE} Bool;
int MinDigit(long int num);
int DToBinary(int num);
Bool Arrayods(int arr[],int size);
int SumEven(int arr[],int size);
void FibonachiArray(int* arr,int size);
int StrLenth(char str[]);
int StrCompare(char str1 [],char str2 []);
void LongestStr(char* text[],int size,int * Lsize,int *count);
int main(){//this program operates a couple of recursive function//
    int binary,ArraySize,i,*array,Lsize = ZERO,AmountOfLsize = ONE;
    long int smalldigitcheck;
    char str1[MAX_LEN],str2[MAX_LEN],*text[]={"test","correct","data","one","replace"};
    printf("enter an integer to get the smallest digit in it\n");
    scanf("%li",&smalldigitcheck);
    printf("the smallest digit is %d\n",MinDigit(smalldigitcheck));
    printf("enter an integer for binary conversion\n");
    scanf("%d",&binary);
    printf("the number in binary is %d\n",DToBinary(binary));
    printf("enter a size for array\n");
    scanf("%d",&ArraySize);
    array = (int*)malloc(ArraySize * sizeof(int));
    if(array == NULL){
        printf("there is not enough memory have a good day\n");
        exit(1);
    }
    for(i = ZERO;i < ArraySize;i ++){
        printf("enter a value for array place %d\n",i + ONE);
        scanf("%d",&(array[i]));
    }
    if(Arrayods(array,ArraySize)){
        printf("all the array numbers are odd\n");
    }else{
        printf("not all the array numbers are odd\n");
    }
    free(array);
    printf("enter a size for array\n");
    scanf("%d",&ArraySize);
    array = (int*)malloc(ArraySize * sizeof(int));
    if(array == NULL){
        printf("there is not enough memory have a good day\n");
        exit(1);
    }
    for(i = ZERO;i < ArraySize;i ++){
        printf("enter a value for array place %d\n",i + ONE);
        scanf("%d",&(array[i]));
    }
    printf("the sum of the array's even number's is: %d\n",SumEven(array,ArraySize));
    free(array);
    printf("enter size for array (to create is ""values sum"" array)\n");
    scanf("%d",&ArraySize);
    array = (int*)malloc(ArraySize * sizeof(int));
    if(array == NULL){
        printf("there is not enough memory have a good day\n");
        exit(1);
    }
    for(i = ZERO;i < ArraySize;i ++){
        printf("enter a value for array place %d\n",i + ONE);
        scanf("%d",&(array[i]));
    }
    FibonachiArray(array,ArraySize);
    for(i = ZERO;i < ArraySize;i ++){
        printf("%d ",array[i]);
    }
    printf("\n");
    free(array);
    printf("enter a string for length check\n");    
    getchar();
    fgets(str1,MAX_LEN,stdin);
    for(i = ZERO;str1[i] != '\0';i ++){
        if(str1[i] == '\n'){
            str1[i] = '\0';
            break;
        }
    }
    printf("the string length is : %d\n",StrLenth(str1));
    printf("enter a string number 1 for compare check\n");    
    fgets(str1,MAX_LEN,stdin);
    for(i = ZERO;str1[i] != '\0';i ++){
        if(str1[i] == '\n'){
            str1[i] = '\0';
            break;
        }
    }
    printf("enter a string number 2 for compare check\n");    
    fgets(str2,MAX_LEN,stdin);
    for(i = ZERO;str2[i] != '\0';i ++){
        if(str2[i] == '\n'){
            str2[i] = '\0';
            break;
        }
    }
    if(StrCompare(str1,str2) == ZERO){
        printf("the strings are equal!\n");
    }
    else if(StrCompare(str1,str2) > ZERO){
        printf("string 1 is bigger!\n");
    }
    else{
        printf("string 2 is bigger!\n");
    }
    LongestStr(text,TEN/TWO,&Lsize,&AmountOfLsize);
    printf("the longest string in the strings array(test,correct,data,one,replace) is: %d\n",Lsize);
    printf("the amount of strings in the longest size is: %d\n",AmountOfLsize);
return ZERO;
}
int MinDigit(long int num){//this function gets integer and returning the min digit in recursvie aproach//
    int min ; 
    if (num > ZERO){
        min = num % TEN;
        if(MinDigit(num / TEN) < min){
            min = MinDigit(num / TEN);
        } 
    }
    if(num < ZERO){
        num *= -ONE;
         min = num % TEN;
        if(MinDigit(num / TEN) < min){
            min = MinDigit(num / TEN);
        } 
    }
    return min ;
}
int DToBinary(int num){//this function gets a decimal integer and returning its binary value in recursvie aproach//
    int bin = num % TWO;
    if (num > ZERO){
      return  bin + (TEN * DToBinary(num / TWO));
    
    }
return ZERO;
}
Bool Arrayods(int arr [],int size){//this function checks if integer array values are all odds in recursvie aproach if so returns true else return false//
    if(size > ZERO){
        if(arr[size - ONE] % TWO == ONE){
        return TRUE * Arrayods (arr,size - ONE);
        }else{
            return FALSE;
        }
    }
    return TRUE;
}
int SumEven(int arr[],int size){//this function calculate an array even numbers sum in recursvie aproach//
    
    if(size > ZERO){
        if(arr[size - ONE] % TWO == ZERO){
            return arr [size - ONE] + SumEven(arr,size - ONE);
        }else{
            return ZERO + SumEven(arr,size - ONE);
        }
    }
return ZERO ;
}
void FibonachiArray(int* arr,int size){//this function updating an array to is sum values array by index in recursvie aproach// 
    if(size > ZERO){
        int sum = ZERO;
        for(int i = ZERO;i < size;i ++){
            sum += arr[i]; 
        }
    arr[size - ONE] = sum;
    FibonachiArray(arr,size - ONE);
    }
}
int StrLenth(char str[]){//this function checks a string lentgh in recursvie aproach//
    if(str[ZERO] != '\0'){
        return ONE + StrLenth(++ str);
    }else{
        return ZERO;
    }
}
int StrCompare(char* str1,char* str2){//this function checks if strings are equal or not int recursvie aproach//
    if(str1[ZERO] != '\0' && str2[ZERO] != '\0'){
        if(str1[ZERO] > str2[ZERO]){
            return ONE + StrCompare(str1 + ONE,str2 + ONE);
        }
        if(str1[ZERO] == str2[ZERO]){
            return ZERO + StrCompare(str1 + ONE,str2 + ONE);
        }else{
            return -ONE + StrCompare(str1 + ONE,str2 + ONE);
        }
    }
    if(str1[ZERO] == '\0' && str2[ZERO] != '\0'){
        return -ONE;
    }
    if(str1[ZERO] != '\0' && str2[ZERO] == '\0'){
        return ONE;
    }
    if(str1[ZERO] == '\0' && str2[ZERO] == '\0'){
        return ZERO;
    }
}
void LongestStr(char* text[],int size,int * Lsize ,int * count){//this function checks in array of string who is the longest string and return its size and the amount of time this size apeears in the array in recursvie aproach//
    if(size >= ONE){
        int size1 = StrLenth(text[size - ONE]);
        if(size1 > *Lsize){
            *Lsize = size1;
            *count = ONE;
        }
        else if(size1 == *Lsize){
            *Lsize = size1;
            (*count) ++;
        }
    LongestStr(text,size - ONE,Lsize,count);
    }
}