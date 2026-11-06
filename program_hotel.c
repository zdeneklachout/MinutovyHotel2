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

bool leapYear(int year)
{
    if (year%4 == 0 && year%100 == 0 && year%400 == 0) return true;
    else if (year%4 == 0 && year%100 == 0) return false;
    else if (year%4 == 0) return true;
    else return false;
}

void dateCheck(DataInput *input)
{
    if (year < 2000
        || month < 1 || month > 12
        || day < 1 || day > 31
        || (day > 30 && month == 4) || (day > 30 && month == 6) || (day > 30 && month == 9) || (day > 30 && month == 11)
        || (day > 29 && month == 2 && pR == true)
        || (day > 28 && month == 2 && pR == false)) return 0;
}

void stayDuration()
{

}

void priceCalculation()
{

}

char InputStop(int i, DataInput *input)  // Dává vstup na kousky dokud nenarazí na $ nebo #
{   

    while(true)
    {
        if (scanf(" %c %d %c %d %c %d %d %c %d %c %d", &input[i].specialCharacter, &input[i].year, &input[i].separatorDash, &input[i].month,
            &input[i].separatorDash, &input[i].day, &input[i].hour, &input[i].separatorColon, &input[i].minute, &input[i].separatorComma, &input[i].price ) != 11)
        {
            printf("Nespravny vstup.\n");
            return 'N';
        }

        printf("%c %d %c %d %c %d %d %c %d %c %d\n",*(&input[i].specialCharacter), *(&input[i].year), *(&input[i].separatorDash), *(&input[i].month), 
        *(&input[i].separatorDash), *(&input[i].day), *(&input[i].hour), *(&input[i].separatorColon), 
        *(&input[i].minute), *(&input[i].separatorComma), *(&input[i].price)); 

        if (*(&input[i].specialCharacter) == '$') return '$';
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

        if (v == '$') priceCalculation();
        else if (v == '#') stayDuration();
        else if (v == 'N') return 1;

        dateCheck(Input);

    }

    return 0;
}
