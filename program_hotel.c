#include<stdio.h>

typedef struct
{
    char specialCharacter;
    char separatorDash1;  
    char separatorDash2;
    char separatorColon;
    char separatorComma;

    int year;
    int month;
    int day;
    int hour;
    int minute;
    int price; 

    int totalMinutes; 

    // proměnné pro opraci $ 
    char separatorDash_1;
    char separatorDash_2; 
    char separatorColon2; 
    int year2;  
    int month2; 
    int day2; 
    int hour2; 
    int minute2;
    
}DataInput;

bool LeapYear(int *currentYear)
{
    if (*currentYear%4 == 0 && *currentYear%100 == 0 && *currentYear%400 == 0) return true;
    else if (*currentYear%4 == 0 && *currentYear%100 == 0) return false;
    else if (*currentYear%4 == 0) return true;
    else return false;
}

bool DateComparation(int i, DataInput *input, char v)  // kontroluje rostoucí posloupnost u '+' a aby byl druhý datum větší u '$'
{   
    long long a = 0; 
    long long b = 0; 

    if (v == '$') 
    { 
        // porovnavani dvou dat primo ze 1 struktury
        a += input[i].year * 100; 
        a += input[i].month;
        a = a * 100;   
        a += input[i].day; 
        a = a * 100; 
        a += input[i].hour; 
        a = a*100; 
        a += input[i].minute; 
        
        b += input[i].year2 * 100; 
        b += input[i].month2;
        b = b * 100;   
        b += input[i].day2; 
        b = b * 100; 
        b += input[i].hour2; 
        b = b*100; 
        b += input[i].minute2;  

        if (a >= b) return 0; 
    } 
    else 
    {   
        if (i > 0 && v != '$') 
        {
            // kontroluje jestli '+' tvoří rostroucí posloupnost 

            a += input[i].year * 100; 
            a += input[i].month;
            a = a * 100;   
            a += input[i].day; 
            a = a * 100; 
            a += input[i].hour; 
            a = a*100; 
            a += input[i].minute; 
        
            b += input[i-1].year * 100; 
            b += input[i-1].month;
            b = b * 100;   
            b += input[i-1].day; 
            b = b * 100; 
            b += input[i-1].hour; 
            b = b*100; 
            b += input[i-1].minute;   

            if (a <= b) return 0;
        }
    }  

    return 1;
}

bool DateCheck(int i, DataInput *input, char v) // kontroluje jestli je datum platný
{
    bool pR = LeapYear(&input[i].year);

    if (input[i].year < 2000 || input[i].year > 2999
        || input[i].month < 1 || input[i].month > 12
        || input[i].day < 1 || input[i].day > 31
        || (input[i].day > 30 && input[i].month == 4) || (input[i].day > 30 && input[i].month == 6) || (input[i].day > 30 && input[i].month == 9) || (input[i].day > 30 && input[i].month == 11)
        || (input[i].day > 29 && input[i].month == 2 && pR == true)
        || (input[i].day > 28 && input[i].month == 2 && pR == false)
        || input[i].hour < 0 || input[i].hour > 23
        || input[i].minute < 0 || input[i].minute > 59  
        || input[i].separatorDash1 != '-' || input[i].separatorDash2 != '-' 
        || input[i].separatorColon != ':' || input[i].separatorComma != ',') return 0; 
    
    
    if (v == '$') 
    {
          if (input[i].year2 < 2000 || input[i].year2 > 2999
        || input[i].month2 < 1 || input[i].month2 > 12
        || input[i].day2 < 1 || input[i].day2 > 31
        || (input[i].day2 > 30 && input[i].month2 == 4) || (input[i].day2 > 30 && input[i].month2 == 6) || (input[i].day2 > 30 && input[i].month2 == 9) || (input[i].day2 > 30 && input[i].month2 == 11)
        || (input[i].day2 > 29 && input[i].month2 == 2 && pR == true)
        || (input[i].day2 > 28 && input[i].month2 == 2 && pR == false)
        || input[i].hour2 < 0 || input[i].hour2 > 23
        || input[i].minute2 < 0 || input[i].minute2 > 59 
        || input[i].separatorDash_1 != '-' || input[i].separatorDash_2 != '-' 
        || input[i].separatorColon2 != ':') return 0; 
    } 

    if (DateComparation(i, input, v) == false) return 0;

    return 1;
}

int MinutesYear(int r, int minutesYear, DataInput *input, int i, char v) // patří k nedokončená logice u $
{   
    if (v == '$') 
    {
        for (int l = input[i].year; l < input[0].year; l++) 
        {
            if (LeapYear(&l) == true) r = 527040;   
            else r = 525600;
            minutesYear += r;
        } 

        for (int m = input[i-1].year; m < input[i].year2; m++) 
        {
            if (LeapYear(&m) == true) r = 527040;   
            else r = 525600;
            minutesYear += r;
        }  

    }
    
    return minutesYear;
} 

int MinutesMonth(int m, DataInput *input, int minutesMonth, int i) // patří k nedokončený logice u $
{
    for (int k = 1; k < input[i].month; k++) 
    {
        // ruzne hodnoty pro ruzne mesice 
        if (k == 1 || k == 3 || k == 5 || k == 7 || k == 8 || k == 10) m = 31; 
        else if (k == 4 || k == 6 || k == 9 || k == 11) m = 30;
        else if (k == 2 && LeapYear(&input[i].year) == false) m = 28;
        else m = 29;

        minutesMonth += m;
    }

    return minutesMonth;
}

void StayDuration()
{

}

void PriceCalculation(int i, DataInput *input, char v) // absolutně nedokončená logika pro $
{   
    int r = 0; 
    long long minutesYear = 0; 

    minutesYear = MinutesYear(r, minutesYear, input, i, v); 

    int m = 0;  
    int minutesMonth = 0; 

    minutesMonth = MinutesMonth(m, input, minutesMonth, i); 

    int d = 1440; 
    int h = 60; 

    int minutesDay = (input[i].day - 1) * d; 
    int minutesHour = (input[i].hour -1) * h; 
    int minuty = (input[i].minute); 

    long long totalMinutes;

    totalMinutes = minutesYear + minutesMonth + minutesDay + minutesHour + minuty; 
    input[i].totalMinutes = totalMinutes;
}

char InputStop(int i, DataInput *input)  // Dává vstup na kousky dokud nenarazí na $ nebo #
{   

    while(true)
    {
        bool d = false;

        if (scanf(" %c", &input[i].specialCharacter) != 1)
        {
            printf("Nespravny vstup.\n");
            return 'N';
        }

        if (*(&input[i].specialCharacter) == '$') d = true;
        
        if (!d) 
        {
             if (scanf(" %d %c %d %c %d %d %c %d %c %d", &input[i].year, &input[i].separatorDash1, &input[i].month, 
                &input[i].separatorDash2, &input[i].day, &input[i].hour, &input[i].separatorColon, &input[i].minute, &input[i].separatorComma, &input[i].price ) != 10)
            {
                printf("Nespravny vstup.\n");
                return 'N';
            }
        } 
        else 
        {
            
            if (scanf(" %d %c %d %c %d %d %c %d %c %d %c %d %c %d %d %c %d", &input[i].year, &input[i].separatorDash1, &input[i].month, // !!
                &input[i].separatorDash2, &input[i].day, &input[i].hour, &input[i].separatorColon, &input[i].minute, &input[i].separatorComma, &input[i].year2,
                &input[i].separatorDash_1, &input[i].month2, &input[i].separatorDash_2,&input[i].day2, &input[i].hour2, &input[i].separatorColon2, &input[i].minute2) != 17)
            {   
                printf("Nespravny vstup.\n");
                return 'N';
            }
        }
       

        if (d) return '$';
        else if (*(&input[i].specialCharacter) == '#') return '#';

        return '+';

    }

}

int main()
{
    printf("Operace:\n");
    DataInput Input[10000]; // pole struktur 

    for (int i = 0; i < 10000; i++)
    {
        char v = InputStop(i,Input);


        if (DateCheck(i,Input,v) == false) return 1;

        if (v == '$') PriceCalculation(i,Input,v);
        if (v == '#') StayDuration();
        else if (v == 'N') return 1;


    }

    return 0;
}
