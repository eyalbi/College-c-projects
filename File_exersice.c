#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZERO 0
#define ONE 1
#define THREE 3
#define FIVE 5
#define TEN 10
typedef enum{false,true}Bool;
typedef struct{
char hours[THREE],minutes[THREE],sec[THREE];
}TaskTime;
typedef struct{
    char name[TEN + ONE];
    char id[TEN];
    TaskTime RunTime;
}Marthon;
void RunnersToStruct(FILE * inf,Marthon** runners,int size);
int RunnersAmount(FILE* inf);
void FastestRunners(Marthon** runners,int size);
void PrintToOutFile(FILE * Outf,Marthon* runners,int size);
int main(){//this program searching for the fastest marthon runners in an input file that given by the user and write output file with the fastest runners data//
    FILE* inf, *Outf;
    Marthon* runners;
    int size;
    char file[40];
    printf("enter ""marthon runners"" input file name\n");
    scanf("%s",file);
    inf = fopen(file,"r");
    if(!inf){
        printf("input file error\n");
        exit(ONE);
    }
    printf("enter output file name that you want\n");
    scanf("%s",file);
    Outf = fopen(file,"w");
    if(!Outf){
        printf("output file error\n");
        fclose(inf);
        exit(ONE);
    }
    size = RunnersAmount(inf);
    RunnersToStruct(inf,&runners,size);
    fclose(inf);
    FastestRunners(&runners,size);
    PrintToOutFile(Outf,runners,size);
    printf("your output file has been updated with the fastest marthon runners\n");
    free(runners);
    fclose(Outf);
    return ZERO;    
}
int RunnersAmount(FILE* inf){//this function checks how many runners an input file has//
    int i,count = ZERO;
    char input;
    for(i = ZERO;!(feof(inf));i ++){
        fseek(inf,1L,SEEK_CUR);
        fscanf(inf,"%c",&input);
        if(input == '\n'){
            count ++;
        }
    }
    rewind(inf);
    return count;
}
void RunnersToStruct(FILE * inf,Marthon** runners,int size){//this function builds a struct array with the runners data//
    int i;
    *runners = (Marthon*)malloc(size * sizeof(Marthon));
    if(*runners == NULL){
        printf("there is not enough space\n");
        fclose(inf);
        exit(ONE);
    }
    for(i = ZERO;i < size;i ++){
        if(fscanf(inf,"%s%s%s%s%s",(*runners)[i].name,(*runners)[i].id,(*runners)[i].RunTime.hours,(*runners)[i].RunTime.minutes,(*runners)[i].RunTime.sec) != FIVE){
            printf("input error\n");
            break;    
        }
    }
rewind(inf);
}
void FastestRunners(Marthon** runners,int size){//this function searching for the fastest runners and updating the names of the slower ones to \0//
    int i,j;
    for(i = ZERO;i < size;i ++){
        for(j = i + ONE;j < size;j ++){
            if(strcmp((*runners)[i].RunTime.hours,(*runners)[j].RunTime.hours) > ZERO){
               ((*runners)[i].name)[ZERO] = '\0';
            }
            else if(strcmp((*runners)[i].RunTime.hours,(*runners)[j].RunTime.hours) < ZERO){
                ((*runners)[j].name)[ZERO] = '\0';
            }
            else if(strcmp((*runners)[i].RunTime.hours,(*runners)[j].RunTime.hours) == ZERO){
                if(strcmp((*runners)[i].RunTime.minutes,(*runners)[j].RunTime.minutes) > ZERO){
                    ((*runners)[i].name)[ZERO] = '\0';
                }
                else if(strcmp((*runners)[i].RunTime.minutes,(*runners)[j].RunTime.minutes) < ZERO){
                    ((*runners)[j].name)[ZERO] = '\0';
                }
                else if(strcmp((*runners)[i].RunTime.minutes,(*runners)[j].RunTime.minutes) == ZERO){
                    if(strcmp((*runners)[i].RunTime.sec,(*runners)[j].RunTime.sec) > ZERO){
                        ((*runners)[i].name)[ZERO] = '\0';
                    }
                    else if(strcmp((*runners)[i].RunTime.sec,(*runners)[j].RunTime.sec) < ZERO){
                        ((*runners)[j].name)[ZERO] = '\0';
                    }
                }
            }
        }
    }
}
void PrintToOutFile(FILE * Outf,Marthon* runners,int size){//this function prints the data of the fastest runners to the output file that the user chose earlyer//
    int i;
    for(i = ZERO;i < size;i ++){
        if((runners[i].name)[ZERO] != '\0'){
            fprintf(Outf,"%s %s %s %s %s\n",runners[i].name,runners[i].id,runners[i].RunTime.hours,runners[i].RunTime.minutes,runners[i].RunTime.sec);
        }
    }
}