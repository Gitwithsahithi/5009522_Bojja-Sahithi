#include <stdio.h>

int main()
{
    int day;

    do {
        printf("Enter a number to print the day: ");
        scanf("%d", &day);

        switch (day) {
            case 1: printf("Monday\n"); break;
            case 2: printf("Tuesday\n"); break;
            case 3: printf("Wednesday\n"); break;
            case 4: printf("Thursday\n"); break;
            case 5: printf("Friday\n"); break;
            case 6: printf("Saturday\n"); break;
            case 7: printf("Sunday\n"); break;
            default:
                printf("Invalid input - Please enter a number from 1 to 7.\n");
                continue;
        }
        break; // exits the loop if input is valid

    } while (1);

    return 0;
}
