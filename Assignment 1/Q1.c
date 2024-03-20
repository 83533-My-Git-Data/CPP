#include<stdio.h>

struct Date{
    int day;
    int month;
    int year;  
};

void initDate (struct Date *ptrDate){
    ptrDate->day = 1;
    ptrDate->month=1;
    ptrDate->year = 1970;    
}
void acceptDateFromConsole(struct Date *ptrDate){
    printf("Enter day, month and year :");
    scanf("%d%d%d",&(ptrDate->day),&(ptrDate->month),&(ptrDate->year));
}
void printDateOnConsole(struct Date *ptrDate){
    printf("Date :%d:%d:%d\n",ptrDate->day,ptrDate->month,ptrDate->year);

}

int main(){
    struct Date d;
    int choice;
    initDate(&d);
    do{
        printf("1. Accept date\n");
        printf("2. Print Date\n");
        printf("3. Exit\n");
        printf("Enter your Choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                acceptDateFromConsole(&d);
                break;
            case 2:
                printDateOnConsole(&d);
                break;
            case 3:
                printf("Exit");
                break;
            default:
                printf("wrong choice");        
        }
    }while(choice!=3);
    return 0;
 }