//this program builds an integer matrix and doing some operation on it//
#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
#define ONE 1
void BuildMatrix(int*** matrix,int row,int culom);
void FreeMatrix(int*** matrix,int row);
void PrintMatrix(int** matrix,int row,int culom);
void GetMinMax(int** matrix,int row,int culom,int* pMin,int* pMax);
void AddRow(int*** matrix,int* prow,int culom,int* NewRow,int culoms);
void RemoveCulom(int*** matrix,int row,int* pculom,int CulomNumber);
void BuildGroup (int** Group,int* pCount);
int Inputcheck (int* p,int num,int size);
int main(){
    int **matrix = NULL,*NewRow = NULL,row,culom,min,max,culoms,CulomN;
    printf("enter row's amount\n");
    scanf("%d",&row);
    printf("enter culom's amount\n");
    scanf("%d",&culom);
    BuildMatrix(&matrix,row,culom);
    PrintMatrix(matrix,row,culom);
    printf("enter new row size\n");
    scanf("%d",&culoms);
    if(culoms != culom){
        printf("dimension error\n");
    }
    else{
        BuildGroup(&NewRow,&culoms);
        AddRow(&matrix,&row,culom,NewRow,culoms);
        PrintMatrix(matrix,row,culom);
    }
printf("enter culom number that you want to erase\n");
scanf("%d",&CulomN);
RemoveCulom(&matrix,row,&culom,CulomN);
PrintMatrix(matrix,row,culom);
GetMinMax(matrix,row,culom,&min,&max);
printf("the min value in the matrix is :%d\nthe max value in the matrix is :%d\n",min,max);
FreeMatrix(&matrix,row);
return ZERO;
}
void BuildMatrix(int*** matrix,int row,int culom){//this functio receives a double pointer adrees for the main alllocating a dynamical space and create the matrix//
    int i,j;
    *matrix = (int**)malloc(row * sizeof(int*));
    if(*matrix == NULL){
        printf("theres not enough memory.\n");
        exit(ONE);
    }
    for(i = ZERO;i < row;i ++){
        (*matrix)[i] = (int*)malloc(culom * sizeof(int));
        if((*matrix)[i] == NULL){
            printf("theres not enough memory.\n");
            exit(ONE);
        }
        for(j = ZERO;j < culom;j ++){
        printf("enter value for place [%d] [%d]\n",i,j);
        scanf("%d",&(*matrix)[i][j]);
        }
    }
}
void FreeMatrix(int*** matrix,int row){//this function free a dynamical memory of a matrix//
    int i;
    for(i = ZERO;i < row;i ++){
        free((*matrix)[i]);
    }
free(*matrix);
}
void PrintMatrix(int** matrix,int row,int culom){//this function prints a matrix//
    int i,j;
    for(i = ZERO;i < row;i ++){
        for(j = ZERO;j < culom;j ++){
            printf("%d",matrix[i][j]);
        }
     printf("\n");
    }
}
void GetMinMax(int** matrix,int row,int culom,int* pMin,int* pMax){//this funcion receivs a matrix and returning by pointers to the main the min and max values of the matrix//
    int i,j;
    *pMax = *pMin = matrix[ZERO][ZERO];
    for(i = ZERO;i < row;i ++){
        for(j = ZERO;j < culom;j ++){
            if(matrix[i][j] > *pMax){
                *pMax = matrix[i][j];
            }
            if(matrix[i][j] < *pMin){
                *pMin = matrix[i][j];
            }
        }
    }
}
void AddRow(int*** matrix,int* prow,int culom,int* NewRow,int culoms){//this function add another row to a matrix//
    int i,j;
    if(culoms != culom){
        printf("dimension error new row size doesn't right\n");
        exit(1);
    }    
    (*matrix)[*prow] = (int*)malloc(sizeof(int));
    (*matrix)[*prow] = NewRow;
    *prow += ONE;
}
void RemoveCulom(int*** matrix,int row,int* pculom,int CulomNumber){//this function remove a culomn from the matrix by user choise//
    int** tempM = *matrix,j,i,c;
    if(CulomNumber < ZERO || CulomNumber >= *pculom){
        printf("invalid culom number\n");
        exit(1);
    }
    int temp = *pculom;
    *pculom -= ONE;
    *matrix = (int**)malloc(row * sizeof(int*));
    if(*matrix == NULL){
        printf("theres not enough memory.\n");
        exit(ONE);
    }
    for( i = ZERO;i < row;i ++){
        (*matrix)[i] = (int*)malloc((*pculom) * sizeof(int));
        if((*matrix)[i] == NULL){
            printf("theres not enough memory.\n");
            exit(ONE);
        }
    } 
    for(i = ZERO;i < row;i ++){
        for(c = ZERO,j = ZERO;j < temp;j ++){
            if(j != CulomNumber){
                (*matrix)[i][c] = tempM[i][j];
                c++;
            }
        }       
    }      
}
void BuildGroup (int** Group,int* pCount){ //this function build a one dimension group to be used in the "addrow" function(func from part1)//
    int i , num;
    *Group = (int*)malloc(*pCount * sizeof(int));
    if(*Group == NULL){
        printf("there is not enough memory in the heap.\n");
        exit (ONE);
    }else{
        for(i = ZERO;i < *pCount;i++){
            printf("enter a number for group place %d\n",i);
            scanf("%d",&num);
            if(Inputcheck((*Group),num,i)){
                (*Group)[i] = num;
            }
            else{
                printf("already enterd that number try again\n");
                i --;
            }
        }
    }   
}
int Inputcheck (int* p,int num,int size){//also a function from part 1 to be used in "buildgroup" as requasted//
    int i,flag = ONE;
    for(i = ZERO;i < size;i++){
        if(p[i] == num){
            flag = ZERO;
            break;
        }
    }
return flag;
}
