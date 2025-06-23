#include<stdio.h>
#include<stdlib.h>

 typedef struct
 {
    char name[100];
    int age;
    float height;
 }
 user;

 int main()
 {
    user* user1 = malloc(sizeof(user));
    printf("NAME: ");
    scanf("%s", user1 ->name);

    printf("AGE: ");
    scanf("%d", &user1 ->age);

    printf("HEIGHT: ");
    scanf("%f", &user1 ->height);

    printf("The user name is %s, he's %d ans his height is: %.2f", user1 ->name, user1->age, user1->height);
    free (user1);
    return (0);
 }