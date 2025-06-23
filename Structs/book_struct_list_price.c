#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[100];
    char author[100];
    int years;
    float price; 

}
book;

int main ()
{
    int c;
    int n;
    float average = 0;

    printf("How many book? ");
    scanf("%d", &n);
    while (c = getchar() != '\n' && c != EOF);

    book* liste = malloc(sizeof(book) * n);
    if (liste == NULL)
    {
        printf("Allocation error");
        return (1);
    }

    for (int i = 0; i < n; i++)
    {

        printf("BOOK n° %d\n", i+1);

        printf("TITLE: ");
        fgets(liste[i].title, sizeof(liste[i].title), stdin);
        liste[i].title[strcspn(liste[i].title, "\n")] = 0;

        printf("AUTHOR: ");
        fgets(liste[i].author, sizeof(liste[i].author), stdin);
        liste[i].author[strcspn(liste[i].author, "\n")] = 0;

        printf("YEARS: ");
        scanf("%d", &liste[i].years);
        while (c = getchar() != '\n' && c != EOF);

        printf("PRICE: ");
        scanf("%f", &liste[i].price);
        while (c = getchar() != '\n' && c != EOF);
    }

    for (int i = 0; i < n; i++)
    {
        average += liste[i].price;
        printf("the title of the book is: %s | the autor is %s | published in: %d | price: %.2f\n", liste[i].title, liste[i].author, liste[i].years, liste[i].price);
        
    }
    average /= n;
    printf("The price average is: %.2f ", average);
    free (liste);
    return (0);
}