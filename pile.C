#include <stdio.h>

struct Elements
{
    int number;
    Elements *next;
} typedef Elements;

struct Piles
{
    Elements *first;
    Elements *last;
} typedef Piles;

void add_next_elements(Elements *first, Elements *next) {
    first->next = next;
    next->number = first->number + 1;
}
void count_pile_from_element(const Elements *element) {
    // For verify if is a new showing
    static int counter;
    // If counter if negative don't considerate as a new element
    if (counter == 0)
        printf("Cout pile form new element:\n\t%d", element->number);
    else
        printf("%d\n", element->number);

    if (element->next != NULL)
        count_pile_from_element(element->next);
}

int main(int argc, char const *argv[])
{
    Elements first = {0, NULL};
    Elements second = {0, NULL};
    add_next_elements(&first,&second);
    count_pile_from_element(&first);
    return 0;
}
