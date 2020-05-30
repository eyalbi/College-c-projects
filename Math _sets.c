/*Assignmmet 4 :
    Campus : Beer Sheva
    Author : Eyal Bismuth, ID: 308200203
*/
//this program bulding integer groups and calculate diffrent groups operators such as union,intersection,and differance//
#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
#define ONE 1
void BuildGroup (int** Group,int* pCount);
int Inputcheck (int* p,int num,int size);
int ReturningValues (int* g1,int size1,int* g2,int size2);
int* UNION (int* group1,int size1,int* group2,int size2,int* psizeUnion);
int* Intersection (int* group1,int size1,int* group2,int size2,int* pSizeInter);
int* DIFF (int* group1,int size1,int* group2,int size2,int* pSizeDiff);
void PrintGroup (int* group,int size);
int main(){
    int *Group1 = NULL,*Group2 = NULL,Size1,Size2,*Union = NULL,Usize,*Inter = NULL,Isize,*Diff = NULL,Dsize;
    printf ("enter size for group 1\n");
    scanf ("%d",&Size1);
    BuildGroup (&Group1,&Size1);
    printf ("enter size for group 2\n");
    scanf ("%d",&Size2);
    BuildGroup (&Group2,&Size2);
    printf("group 1:");
    PrintGroup (Group1,Size1);
    printf("group 2:");
    PrintGroup (Group2,Size2);
    Union = UNION (Group1,Size1,Group2,Size2,&Usize);
    Inter = Intersection(Group1,Size1,Group2,Size2,&Isize);
    Diff = DIFF(Group1,Size1,Group2,Size2,&Dsize);
    printf("the union group is:");
    PrintGroup(Union,Usize);
    printf("the intersection group is:");
    PrintGroup(Inter,Isize);
    printf("the differance group is(group1-group2):");
    PrintGroup(Diff,Dsize);
    free(Union);
    free(Inter);
    free(Diff);
    free(Group1);
    free(Group2);
 return ZERO;
}
void BuildGroup (int** Group,int* pCount){  //this function receives an adress of a pointer from the main and adress of int variable(size) from the main and bulding a group//
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
int Inputcheck (int* p,int num,int size){//this function check if an number is allready in array for preventing retunrning values//
    int i,flag = ONE;
    for(i = ZERO;i < size;i++){
        if(p[i] == num){
            flag = ZERO;
            break;
        }
    }
return flag;
}
int* UNION(int* group1,int size1,int* group2,int size2,int* psizeUnion){//this function receving 2 groups and there size from the main and returning there union group by return and the sizr of the union by pointer//
    int* Union,i,j;
    *psizeUnion = (size1 + size2) - ReturningValues(group1,size1,group2,size2);
    Union = (int*)malloc(*psizeUnion * sizeof(int));
    if(Union == NULL){
        printf("there is not enough memory in the heap.\n");
        exit(ONE);
    }
    else{
        for(i = ZERO;i < size1;i ++){
            Union[i] = group1[i];
        }
        for(j = ZERO;j < size2 ;j++,i++){
            if(Inputcheck(Union,group2[j],i)){
                Union[i] = group2[j];
            }else{
                i--;
            }
        }
    }
return Union;
}
int ReturningValues (int* g1,int size1,int* g2,int size2){//this function receving 2 groups and there sizes and returning the amount of the returning values they share//
    int i,j,count = ZERO;
    for(i = ZERO;i < size1;i ++){
        for(j = ZERO;j < size2; j++){
            if(g1[i] == g2[j]){
                count ++;
            }
        }
    }
return count;
}
int* Intersection (int* group1,int size1,int* group2,int size2,int* pSizeInter){//this function receving 2 groups building and returning there intersection group by return and the intersection size by a pointer//
    int* Intersection,i,j,c = ZERO;
    *pSizeInter = ReturningValues(group1,size1,group2,size2);
    if(*pSizeInter == ZERO){
        printf("theres no intersection group.\n");
    }
    Intersection = (int*)malloc(*pSizeInter * sizeof(int));
    if(Intersection == NULL){
        printf("there is not enough memory in the heap.\n");
        exit(ONE);
    }
    for(i = ZERO;i < size1;i ++){
        for(j = ZERO;j < size2;j ++){
            if(group1[i] == group2[j]){
                Intersection[c] = group1[i];
                c ++;
            }
        }
    }
return Intersection;
}
int* DIFF (int* group1,int size1,int* group2,int size2,int* pSizeDiff){//this function receving 2 groups building and returning there differance group(group1 - group2) by return and the differance size by a pointer//
    int* Diff,i,j = ZERO;
    *pSizeDiff = size1 - ReturningValues(group1,size1,group2,size2);
    Diff = (int*)malloc(*pSizeDiff * sizeof(int));
    if(Diff == NULL){
        printf("there is not enough memory in the heap.\n");
        exit(ONE);
    }
    for(i = ZERO;i < size1;i ++){
        if(Inputcheck(group2,group1[i],size2)){
            Diff[j] = group1[i];
            j ++;
        }
    }
return Diff;
}
void PrintGroup (int* group,int size){//this function recevie a group and prints it//
    int i;
    if(size == ZERO){
        printf("{ }\n");
    }
    else{
        printf("{");
        for(i = ZERO;i < size;i ++){
            if(i == size - ONE){
            printf("%d}\n",group[i]);
            }
            else{
                printf("%d,",group[i]);
            }
        }
    }
}
   
