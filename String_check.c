/*Assighnment 3
    Campus:Beer Sheva
    Author:Eyal Bismuth ID:308200203
*/
#include <stdio.h>
#define END '\0'
#define ZERO 0
#define ONE 1
#define N 6
#define MAXWORD 15
#define CHARD 32
#define MAXSTRING 100
int StringChecker(char str[]);
void FgetsCorrect(char str[]);
int FindSimilarWords(char str[]);
int StringBracketCheck(char str[]);
int StringSize(char str[]);
int BracketEven(char str[]);
int StringWordCheck(char str[],char str2[]);
int main(){/* this program has 2 purpses :1.check if a string is a valid bracket string 2.check if a string have similar words*/
    char bracket [MAXSTRING]; 
    char words [MAXSTRING];
    printf("enter a string for ""valid brackets"" check\n");
    fgets(bracket,MAXSTRING,stdin);
    FgetsCorrect(bracket);
    if(StringChecker(bracket)){
        printf("valid string brackets\n");
    }
    else{
        printf("invalid string brackets\n");
    }
    printf("enter a string for ""similar word"" check\n");
    fgets(words,MAXSTRING,stdin);
    FgetsCorrect(words);
    if(FindSimilarWords(words) == ZERO){
        printf("there are no similar words in the string\n");
    }
return ZERO;
}
int StringSize(char str[]){/* this function counting how many index a string have(without '\0')*/
    int i,count = ZERO;
    for(i = ZERO;str[i] != END;i ++){
        count++;
    }
return count;
}
int StringBracketCheck(char str[]){/*this function checks if a string have only brackets */
    int i,flag = ONE;
    for(i = ZERO;str[i] != END;i ++){
        if((str[i] != ')') && (str[i] != '('))
        flag = ZERO; 
    }
return flag;
}
int StringChecker(char str[]){ /*this function checks if a string is a valid or invalid bracket string*/
    int i,j,count = ZERO,size = StringSize(str);
    if(StringBracketCheck(str) && BracketEven(str) && str[ZERO] == '(' && str[StringSize(str)-1] == ')'){
        for(i = ZERO;i < size;i ++){
            if(str[i] == '('){
                for(j = i + ONE;j < size;j ++){
                    if(str[j] == ')'){
                        count ++;
                        str [j] = '*';
                        break;
                    }
                }
            }
        }   
    }
    if(count == size/2){
        return ONE;
    }else{
        return ZERO;
    }
}
int BracketEven (char str []){/* this function check if theres an even number of '(' and ')' in a string*/
    int i,open_bracket = ZERO,close_bracket = ZERO;
    for(i = ZERO;str[i] != END;i ++){
            if(str[i] == '('){
                open_bracket ++;
            }else{
                close_bracket ++;
            }
    }
if((open_bracket != ZERO) && (open_bracket == close_bracket)){
    return ONE;
}
else{
    return ZERO;
}  
}
int FindSimilarWords(char str[]){/*this function checks for similar words in a given string if they exist the function print them and returning the number of couples she found*/
    int i = ZERO,j,c,x,count = ZERO;
    char temp[MAXWORD],temp2[MAXWORD];
    while(str[i] != END){
        for(x = ZERO;str[i] != ' ' && str[i] != END;i ++,x ++){
            temp[x] = str[i];
            }
            temp[x] = END;
        j = i + ONE;
        while(str[j] != END){
            for(c = ZERO;str[j] != ' ' && str[j] != END;c ++,j ++){
                temp2[c] = str[j];
            }
            temp2[c] = END;
            if(str[j] != END){
            j ++;
            }
            if(StringWordCheck(temp,temp2)){
            printf("%s\n%s\n",temp,temp2);
            count ++;
            }
        }
    if(str[i] != END){
    i ++;
    }
    }
return count;
}
int StringWordCheck(char str[],char str2[]){/*this function checks if two strings have the same letters*/
    int i,j,flag = ZERO;
    for(i = ZERO;str[i] != END;i ++){
        for(j = ZERO;str2[j] != END;j ++){
            if((str[i] == str2[j]) || (str[i] == (str2[j] - CHARD)) || (str[i] == (str2[j] + CHARD))){
                flag = ONE;
                break;
            }else{
                flag = ZERO;
            }
        }
         if(flag == ZERO){
            return ZERO;
        }
        
    }
    for(i = ZERO;str2[i] != END;i ++){
        for(j = ZERO;str[j] != END;j ++){
            if((str2[i] == str[j] )|| (str2[i] == (str[j] - CHARD)) || (str2[i] == (str[j] + CHARD))){
                flag = ONE;
                break;
            }else{
                flag = ZERO;
            }
        }
        if(flag == ZERO){
            return ZERO;
        }
    }   
return flag;      
}
void FgetsCorrect(char str[]){ /*this function making sure that in the end of the users input the 'enter' key will be replaced by '\0'*/
    int i;
    for(i = ZERO; i < MAXSTRING; i++){
        if(str[i] == '\n'){
            str[i] = END;
            break;
        }
    }
}



              