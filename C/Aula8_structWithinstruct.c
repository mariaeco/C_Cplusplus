/*==================================================================
 ====================================================================
                       C Course
                  C - Struct aninhadas
 ====================================================================
 ====================================================================*/
#include <stdio.h>
#include <stdlib.h>

struct address{
    char city[20];
    int pin;
    char phone[14];
};

struct employee{
    char name[20];
    struct address add;
};

void main(){
    struct employee emp;
   
    printf("Enter employee information:\n");
    scanf("%s %s %d %s", emp.name, emp.add.city, &emp.add.pin, &emp.add.phone);

    system("cls");// na biblioteca stdlib.h

    printf("Print employee information:\n");
    printf("Name: %s \nCity: %s\nPincode: %d\nPhone:%s\n", emp.name,
             emp.add.city, emp.add.pin, emp.add.phone);
}
