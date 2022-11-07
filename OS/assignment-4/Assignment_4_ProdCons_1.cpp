#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;
void producer()
{
    mutex--;
    full++;
    empty--;
    x++;
    printf("producer producing item %d\n", x);
    mutex++;
}
void consumer()
{
    mutex--;
    full--;
    empty++;
    printf("consumer consuming item %d\n", x);
    x--;
    mutex++;
}
int main()
{
    int ch;
    for (int i = 1; i > 0; i++)
    {
        printf("Enter 1 for producer\nEnter 2 fr consumer\nEnter 3 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (mutex == 1 && empty != 0)
            {
                producer();
            }
            else
            {
                printf("buffer is full\n");
            }
            break;
        case 2:
            if (mutex == 1 && full != 0)
            {
                consumer();
            }
            else
            {
                printf("buffer is empty\n");
            }
            break;
        case 3:
            exit(0);
            break;
        }
    }
}