#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZERO 0
#define ONE 1
#define FOUR 4
#define FIVE 5
#define MAX_NAME 20
typedef enum {FALSE,TRUE} Bool;
typedef struct{
    char* name;
    int class;
    double salary;
}Employee;
Bool InitEmployee(Employee *employee);
void FgetsCorrect(char name []);
void CalcAverage(Employee *data,int size,float *result);
double ClassSalarySum(Employee * data,int size,int class,int *count);
int BuildFactory(Employee ** pdata);
void PrintFactory(Employee * Factory,int Wamount);
int main(){//this function builds a factory of worker at users demandm divding the workers to departments and calculating the salary average of every department//
    Employee *Factory;
    float result[FIVE];
    int FactorySize,i;
    FactorySize = BuildFactory(&Factory);
    PrintFactory(Factory,FactorySize);
    CalcAverage(Factory,FactorySize,result);
    for(i = ZERO;i < FIVE;i ++){
        if(result[i] != - ONE){
            printf("the salary's average of class number %d is : %.1lf\n",i + ONE,result[i]);
        }
        else{
            printf("there is no workers in class number %d\n",i + ONE);
        }
    }
    for(i = ZERO;i < FactorySize;i ++){
        free(Factory[i].name);
    }
    free(Factory);


return ZERO;
}
Bool InitEmployee(Employee *employee){//this function update an employee struct with user data including name,salary,class(between 1-5)//
    char name[MAX_NAME];
    printf("enter Employee's name\n");
    fgets(name,MAX_NAME,stdin);
    FgetsCorrect(name);
    employee->name = (char*)malloc(strlen(name) + ONE);
    if(employee->name == NULL){
        printf("there is not enough space\n");
        return FALSE;
    }
    strcpy(employee->name,name);
    do{
        printf("enter the employee class number(between 1-5) please\n");
        scanf("%d",&(*employee).class);
        
        if (employee->class < ONE || employee->class > FIVE) {
            printf("wrong input!\n");
        }
        
    }
    while(employee->class < ONE || employee->class > FIVE);
    printf("enter the worker salary\n");
    scanf("%lf",&employee->salary);
getchar();
return TRUE;    
}
void FgetsCorrect(char name []){//this function changing '\n' to'\0'//
    for(int i = ZERO;name[i] != '\0';i ++){
        if(name[i] == '\n'){
            name[i] = '\0';
        }
    }
}
void CalcAverage(Employee *data,int size,float *result){//this function calculating the average salary of each department and updating an array called result withe the answers//
    int i,count = ZERO;
    for(i = ZERO;i < FIVE;i ++,count = ZERO){
        double temp = ClassSalarySum(data,size,i + ONE,&count);
        if(temp == ZERO){
            result[i] = -ONE;
        }
        else{
            result[i] = temp / count;    
        }
    }
      
}    
double ClassSalarySum(Employee * data,int size,int class,int *count){//this function calculate department total salary sum and also return by pointer the amount of workers in the desire department//
    int i;
    double sum = ZERO;
    for(i = ZERO;i < size;i ++){
        if(data[i].class == class){
            sum += data[i].salary;
            (*count) ++;
        }
    }
    return sum;
}
int BuildFactory(Employee ** pdata){//this function build a factory and initalaizing it with user input by using "InitEmployee" function//
    int i,employeesAmount;
    printf("how many Employee's do you want in your Factory?\n");
    scanf("%d",&employeesAmount);
    getchar();
    *pdata = (Employee*)malloc(employeesAmount * sizeof(Employee));
    if(*pdata == NULL){
        printf("there is not enough space have a good day\n");
        exit(ONE);
    }
    for(i = ZERO;i < employeesAmount;i ++){
        InitEmployee(&(*pdata)[i]);
    }
return employeesAmount;
}
void PrintFactory(Employee * Factory,int Wamount){//this function prints the data of every worker in the factory//
    int i;
    for(i = ZERO;i < Wamount;i ++){
       printf("worker name is: %s\nclass number: %d\nworker salary: %.1lf\n",Factory[i].name,Factory[i].class,Factory[i].salary);
    }
}