#include <stdio.h>
#include <stdbool.h>

bool isItLeap(int number) {
    if ((number % 4 == 0 && number % 100 != 0) || (number % 400 == 0)) {
        return true;
    } else {
        return false;
    };
};

int days_in_month[] ={0, 31,28,31,30,31, 30,31,31,30,31, 30, 31};
char* month_names[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
    int days_left_in_month;

    while (days_left_to_add > 0) {
        days_left_in_month = days_in_month[*mm] - *dd + 1;

        // Adjusting days_left_in_month for February in leap years
        if (*mm == 2 && isItLeap(*yy)) {
            days_left_in_month++;
        }

        if (days_left_to_add >= days_left_in_month) {
            // Advance to the next month
            days_left_to_add -= days_left_in_month;
            *dd = 1;
            if (*mm == 12) {
                *mm = 1;
                (*yy)++;
            } else {
                (*mm)++;
            }
        } else {
            // Add remaining days
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}


int main() {
  int mm, dd, yy, days_left_to_add;
  
  printf("Please enter a date between the years 1800 and 10000: ");
  scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);

  add_days_to_date(&mm,&dd,&yy, days_left_to_add);

  printf("New date: %s %d, %d\n", month_names[mm], dd, yy);

    /*int year;
     printf("Enter a number between 1800 and 10000: ");scanf("%d", &year);
  

    if (isItLeap(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    };

    return 0;*/
};

