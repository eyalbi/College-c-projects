/*Assighnment 3
    Campus:Beer Sheva
    Author:Eyal Bismuth ID:308200203
*/
#include <stdio.h>
#define ZERO 0
#define N 4
int Ring(int Matrix [][N],int id);
int MatrixSum(int Matrix [][N]);
void MatrixInput(int Matrix[][N]);
int AllRings(int matrix[][N]);
int RingCheck(int size);
int AllRings(int matrix[][N]);
int main(){                     /*this program checks matrix rings and there sum*/
    int matrix [N][N],ring;
    MatrixInput(matrix);
    printf("enter ring number\n");
    scanf("%d",&ring);
    printf("the sum of ring %d: %d\n",ring,Ring(matrix,ring));
    printf("the sum of the matrix:%d\n",AllRings(matrix));
return ZERO;
}
int Ring(int Matrix[][N],int id){ /*this function recives a matrix and a ring number and returning the ring's sum if the ring number is invalid the fuction prints a fault massege*/
    int row,culom,sum = ZERO;
    if(id < ZERO || RingCheck(N) <= id){
        printf("number is illegal\n");
        return ZERO; 
    }
    for(row = id;row < N-id;row++){
        for(culom = id;culom < N-id;culom ++){
            if((row == id) || (row == (N-1)-id)||(culom == id) || (culom == (N-1)-id)){
                sum += Matrix[row][culom];
            }
        }
    }
return sum;
}
int MatrixSum(int Matrix [][N]){ /* this function calculate matrix sum*/
    int row,culom,sum = ZERO;
    for(row = ZERO;row < N;row ++){
        for(culom = ZERO;culom < N;culom ++){
            sum += Matrix[row][culom];

        }
    }
return sum;
}
void MatrixInput(int Matrix[][N]){ /*this function filling a matrix with user input*/
    int row,culom;
    for(row = ZERO;row < N;row ++){
        for(culom = ZERO;culom < N;culom ++){
            printf("enter a value for place [%d] [%d]\n",row,culom);
            scanf("%d",&Matrix[row][culom]);
        }
    }
}
int RingCheck(int size){/* this function checks the amount of rings a matrix have*/
    int ring = ZERO,temp = size;
    while(temp>=1){
        if(temp == 2){
            ring ++ ;
            break;
        }
        ring++;
        temp-=2;
    }
return ring;
}
int AllRings(int matrix[][N]){/*this function prints ring number and its sum and sending back the matrix total sum*/
    int i;
    for(i = ZERO;i < RingCheck(N);i++){
        printf("ring %d: %d\n",i,Ring(matrix,i));
    }
return MatrixSum(matrix);
}
