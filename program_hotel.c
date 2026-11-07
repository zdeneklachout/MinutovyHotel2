#include<stdio.h>

typedef struct
{
    char specialCharacter;
    char separatorDash;
    char separatorColon;
    char separatorComma;

    int year;
    int month;
    int day;
    int hour;
    int minute;
    int price;
}DataInput;

bool leapYear(int *currentYear)
{
    if (*currentYear%4 == 0 && *currentYear%100 == 0 && *currentYear%400 == 0) return true;
    else if (*currentYear%4 == 0 && *currentYear%100 == 0) return false;
    else if (*currentYear%4 == 0) return true;
    else return false;
}

bool dateCheck(int i, DataInput *input)
{
    bool pR = leapYear(&input[i].year);

    if (input[i].year < 2000 || input[i].year > 2999
        || input[i].month < 1 || input[i].month > 12
        || input[i].day < 1 || input[i].day > 31
        || (input[i].day > 30 && input[i].month == 4) || (input[i].day > 30 && input[i].month == 6) || (input[i].day > 30 && input[i].month == 9) || (input[i].day > 30 && input[i].month == 11)
        || (input[i].day > 29 && input[i].month == 2 && pR == true)
        || (input[i].day > 28 && input[i].month == 2 && pR == false)
        || input[i].hour < 0 || input[i].hour > 23
        || input[i].minute < 0 || input[i].minute > 59) return 0;

    return 1;
}

void stayDuration()
{

}

void priceCalculation()
{

}

char InputStop(int i, DataInput *input)  // Dává vstup na kousky dokud nenarazí na $ nebo #
{   
    int pocet = 0;

    while(true)
    {
        pocet = 10;
        bool d = false;

        if (scanf(" %c", &input[i].specialCharacter) != 1)
        {
            printf("Nespravny vstup.\n");
            return 'N';
        }

        if (*(&input[i].specialCharacter) == '$')
        {
            pocet = 9;
            d = true;
        }

        for (int j = pocet; j <= 10; j++)
        {
            if (j == 10 && d == true) pocet = 8;

            if (scanf(" %d %c %d %c %d %d %c %d %c %d", &input[i].year, &input[i].separatorDash, &input[i].month, // !!
                &input[i].separatorDash, &input[i].day, &input[i].hour, &input[i].separatorColon, &input[i].minute, &input[i].separatorComma, &input[i].price ) != pocet)
            {
                printf("Nespravny vstup.\n");
                return 'N';
            }

        }

        /*
        printf("%c %d %c %d %c %d %d %c %d %c %d\n", input[i].specialCharacter, input[i].year, input[i].separatorDash, input[i].month,
               input[i].separatorDash, input[i].day, input[i].hour,input[i].separatorColon,
               input[i].minute, input[i].separatorComma, input[i].price);
        */

        if (d) return '$';
        else if (*(&input[i].specialCharacter) == '#') return '#';

        return '+';


    }

}


int main()
{
    printf("Operace:\n");
    DataInput Input[10000];

    for(int i = 0; i < 10000; i++)
    {
        char v = InputStop(i,Input);

        if (dateCheck(i,Input) == false) return 1;

        if (v == '$') priceCalculation();
        else if (v == '#') stayDuration();
        else if (v == 'N') return 1;


    }

    return 0;
}
