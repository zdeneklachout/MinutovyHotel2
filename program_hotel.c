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

bool leapYear(int *currentYear)
{
    if (*currentYear%4 == 0 && *currentYear%100 == 0 && *currentYear%400 == 0) return true;
    else if (*currentYear%4 == 0 && *currentYear%100 == 0) return false;
    else if (*currentYear%4 == 0) return true;
    else return false;
}

bool dateComparation(int i, DataInput *input, char v) 
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
        if (i > 0) 
        {
            // porovnani dvou dat ze dvou struktur 
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

bool dateCheck(int i, DataInput *input, char v)
{
    bool pR = leapYear(&input[i].year);

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

    if (dateComparation(i, input, v) == false) return 0;

    return 1;
}

void stayDuration()
{

}

void priceCalculation(int i, DataInput *input)
{   
    int r = 0; 
    long long minutyRok = 0; 

    for (int l = &input[i].year; l < &input[i+1].year; l++) // jenom pro '+'
    {
        if (leapYear(&l) == true) r = 527040;   
        else r = 525600;
        minutyRok += r;
    } 

    int m = 0;  
    int minutyMesic = 0; 

    for (int k = 1; k < &input[i].month; k++) 
    {
        // ruzne hodnoty pro ruzne mesice
    }




    int d = 1440; 
    int h = 60; 

    int minutyDen = (input[i].day - 1) * d; 
    int minutyHodina = (input[i].hour -1) * h; 
    int minuty = (input[i].minute); 

    long long celkemMinut;

    celkemMinut = minutyRok + minutyMesic + minutyDen + minutyHodina + minuty;
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
             if (scanf(" %d %c %d %c %d %d %c %d %c %d", &input[i].year, &input[i].separatorDash1, &input[i].month, // !!
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
    DataInput Input[10000];

    for(int i = 0; i < 10000; i++)
    {
        char v = InputStop(i,Input);

        if (dateCheck(i,Input,v) == false) return 1;

        priceCalculation(i,Input);
        if (v == '#') stayDuration();
        else if (v == 'N') return 1;


    }

    return 0;
}
