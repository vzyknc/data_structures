#include <stdio.h>

void printDigit(int N)
{
    printf("%d", N);
}

void PrintOut (unsigned int N)
{
    if(N >= 10)
    {
        PrintOut(N/10);
    }
    printDigit(N%10);
}

int IntPart(double N)
{
    return (int)N;
}

double DecPart(double N)
{
    return N - (double)IntPart(N);
}

double RoundUp(double N, int DecPlace)
{
    double AmountToAdd = 0.5;

    for (int i=0; i<DecPlace; i++)
    {
        AmountToAdd /= 10;
    }

    return N += AmountToAdd;
}

void PrintFractionPart(double FractionPart, int DecPlaces)
{
    int i, Adigit;

    for(i=0; i<DecPlaces; i++)
    {
        FractionPart *= 10;
        Adigit = IntPart(FractionPart);
        printDigit(Adigit);
        FractionPart = DecPart(FractionPart);
    }
}

void PrintReal (double N, int DecPlaces)
{
    int IntegerPart;
    double FracPart;

    if (N < 0)
    {
        putchar('-');
        N = -N;
    }
    N = RoundUp(N, DecPlaces);

    IntegerPart = IntPart(N);
    FracPart = DecPart(N);
    PrintOut(IntegerPart);
    if(DecPlaces > 0)
    {
        putchar('.');
        PrintFractionPart(FracPart, DecPlaces);
    }


}

void main()
{
    double N = 5.6377;
    int DecPlaces = 2;
    PrintReal(N, DecPlaces);
}