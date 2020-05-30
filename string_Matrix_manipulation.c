//this program builds a 2 dimension "matrix" of words and doing some operations on it//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZERO 0
#define ONE 1
#define MAX_LEN 10
#define CHARD 'a'-'A'
void WordFrequency(char ** words,int countWords);
void BuildStringMatrix(char*** words,int Rsize);
void TextPreProcessing(char*** text,int* countWords,char** stopWords,int countStopWords);
void ClettersToS(char** str,int size);
int SimilarWords(char* words1,char** words2 ,int sword2);
int main(){
    int i,Wsize,SWsize;
    char ** words =NULL, ** stopWords = NULL;
    printf("enter the amount of words you desire in the array\n");
    scanf("%d",&Wsize);
    getchar();
    BuildStringMatrix(&words,Wsize);
    printf("enter the amount of words for the ""stop word"" array\n");
    scanf("%d",&SWsize);
    getchar();
    BuildStringMatrix(&stopWords,SWsize);
    TextPreProcessing(&words,&Wsize,stopWords,SWsize);
    
return ZERO;
}
void BuildStringMatrix(char*** words,int Rsize){//this function allocating "heap" memory to a double pointer from the main and fills the memory with words//
    int i,j,len;
    char str[MAX_LEN];
    *words = (char**)malloc(Rsize* sizeof(char*));
    if(*words == NULL){
        printf("there is not enough space goodbye\n");
        exit(1);
    }
    for(i = ZERO;i < Rsize;i ++){
        printf("enter a word for str place %d\n",i + ONE);
        scanf("%s",str);
        len = strlen(str) + ONE;
        (*words)[i] = (char*)malloc(len);
        if((*words)[i] == NULL){
            free(*words);
            printf("there is not enough space goodbye\n");
            exit(1);
        }
        strcpy((*words)[i],str);
    }
}
void WordFrequency(char ** words,int countWords){//this function checking how many words are in the "matrix" and prints them with the amount of times they appear//
    int i,j,count = ZERO;
    char **str = words; 
    for(i = ZERO;i < countWords;i ++,count = ZERO){
        for(j = i;j < countWords && str[i][ZERO] != '\0';j ++){
                if(strcmp(str[i],str[j]) == ZERO){
                    count ++;
                    if(i != j){
                        str[j][ZERO] = '\0';
                    }
                } 
        }
            if(str[i][ZERO]!= '\0'){
                printf("%s : %d\n",words[i],count);
            }
    }
    for(i = ZERO;i < countWords;i ++){
        free(str[i]);
    }
free(str);
str = NULL;
}
void TextPreProcessing(char*** text,int* countWords,char** stopWords,int countStopWords){//this function receivs a matrix of words and a "stopword" matrix deleting the words that appear in the "stopword" and pints the words an the amount of them using WordFrequency functio // 
    int i,c = ZERO,j,Tsize = *countWords,flag = ONE;
    char** str = NULL;
    ClettersToS(*text,*countWords);
    str = (*text);
    *text = NULL;
    for((*countWords) = ZERO, i = ZERO;i < Tsize;i ++){
        if(str[i][ZERO] != '\0'){
            (*countWords) += ONE; 
        }
    }
    *text = (char**)malloc((*countWords) * sizeof(char*));
    if(*text == NULL){
        printf("there is not enough memory\n");
        exit(ONE);
    }
    for(i = ZERO;i < *countWords; i ++){
        (*text)[i] = (char*)malloc(MAX_LEN * sizeof(char));
         if((*text)[i] == NULL){
            free(*text);
            printf("there is not enough memory\n");
            exit(ONE);
        }
    }
    for(i = ZERO;i < Tsize;i ++){
        if(SimilarWords(str[i],stopWords,countStopWords)){
            strcpy((*text)[c],str[i]);
            c ++;
        }
    }
    WordFrequency(*text,*countWords);
    for(i = ZERO;i < Tsize;i ++){
        free(str[i]);
    }
free(str);
}
void ClettersToS(char** str,int size){//this function recevis a matrix of word and replacing the uppercase letters to smallercase and also turning "numbers words to '\0'// 
    int i,j;
    for(i = ZERO;i < size;i ++){
       for(j = ZERO;str[i][j] != '\0';j ++){
           if(str[i][j] >= 'A' && str[i][j] <= 'Z'){
               str[i][j] += CHARD;
            }
            if((str[i][j] < 'A') || (str[i][j] > 'Z' && str[i][j] < 'a') || (str[i][j] > 'z')){
                str[i][ZERO] = '\0';
            }
        } 
    }
}
int SimilarWords(char* words1,char** words2 ,int sword2){//this function checks if a word(string) is appearing in another matrix of words//
    int i,j,flag = ONE;
    for(i = ZERO;i < sword2;i ++){
        if(strcmp(words1,words2[i]) == ZERO || words1[ZERO] == '\0'){   
            flag = ZERO;
            break;
        }
    }
return flag;
}
