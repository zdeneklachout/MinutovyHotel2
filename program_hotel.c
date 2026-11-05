#include<stdio.h>

typedef struct
{
    char specialCharacter;
    char separator;

    int year;
    int month;
    int day;
    int hour;
    int minute;
    int price;
}DataInput;

bool leapYear(int year)
{
    if (year%4 == 0 && year%100 == 0 && year%400 == 0) return true;
    else if (year%4 == 0 && year%100 == 0) return false;
    else if (year%4 == 0) return true;
    else return false;
}

void stayDuration()
{

}

void priceCalculation()
{

}

char InputStop(int i, DataInput *input)
{
    while(true)
    {
        if (scanf("%c %d %c %d %c %d %d %c %d %c %d", &input[i].specialCharacter, &input[i].year, &input[i].separator, &input[i].month, &input[i].separator, &input[i].day, &input[i].hour, &input[i].separator, &input[i].minute, &input[i].separator, &input[i].price ) != 11)
        {
            printf("Nespravny vstup.\n");
            return 'N';
        }
    }

    if (*(&input[i].specialCharacter) == '$') return '$';
    else if (*(&input[i].specialCharacter) == '#') return '#';
}


int main()
{
    DataInput Input[10000];

    for(int i = 0; i < 10000; i++)
    {
        if (InputStop(i, Input) == '$') priceCalculation();
        else if (InputStop(i, Input) == '#') stayDuration();
        else return 1;
    }

    return 0;
}
