#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef struct
 {
    char name[100];
    int age;
    float height;
 }
 user;

 int main()
 {

    int c;
    user* user1 = malloc(sizeof(user));

    printf("NAME: ");
    fgets(user1 ->name, sizeof(user1 ->name), stdin); 
    user1 ->name[strcspn(user1 ->name, "\n")] = 0;

    printf("AGE: ");
    scanf("%d", &user1 ->age);
    while ((c = getchar()) != '\n' && c != EOF);


    printf("HEIGHT: ");
    scanf("%f", &user1 ->height);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("The user name is %s, he's %d ans his height is: %.2f", user1 ->name, user1->age, user1->height);
    free (user1);
    return (0);
 }
