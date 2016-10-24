#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BYTE unsigned char

void warten(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

void Bit_Set(BYTE *B_Wert, int iN)
{
    BYTE B_Temp = 1;
    B_Temp = (B_Temp << iN);
    *B_Wert = (*B_Wert | B_Temp);
}

void Bit_Clear(BYTE *B_Wert, int iN)
{
    BYTE B_Temp = 1;
    B_Temp = (B_Temp << iN);
    B_Temp = ~B_Temp;
    *B_Wert = (*B_Wert & B_Temp);
}

void Bit_Test(BYTE *B_Wert, int iN)
{
    int iTest;
    int B_Test;
    BYTE B_Temp = 1;
    B_Test=*B_Wert;
    B_Temp = (B_Temp << iN);
    B_Test = (B_Test | B_Temp);

    printf("%d\n%d",*B_Wert, B_Test );
    if(B_Test==*B_Wert)
    {
        printf("Dieses Bit war gesetz!");
    }
    else
    {
        printf("Dieses Bit war nicht gesetz!");
    }

}

void Bit_Print(BYTE B_Wert)
{
    int iC;
    int iTemp;
    int aiByte[8];

    for(iC=0; iC<=7; iC++)
    {
        iTemp=B_Wert%2;
        if(iTemp==0)
        {
            // 0
            aiByte[iC]=0;
        }
        else
        {
            // 1
            aiByte[iC]=1;
        }
        B_Wert=B_Wert/2;
    }
    for(iC=7; iC>=0; iC--)
    {
        printf("%d", aiByte[iC]);   //Ausgabe vom Byte
    }
}

void Bit_Count(BYTE B_Wert)
{
    int iC;
    int iTemp;
    int iAmount=0;

    for(iC=0; iC<=7; iC++)
    {
        iTemp=B_Wert%2;
        if(iTemp!=0)
        {
            iAmount=iAmount+1;
        }
        B_Wert=B_Wert/2;
    }
    printf("%d", iAmount);
}

void Int_to_4BYTE(int iZ) //TODO: größte bit wird bleibt 0
{
    int iC;
    int iTemp;
    int aiByte[31];

    for(iC=0; iC<=31; iC++) {
        iTemp=iZ%2;
        if(iTemp==0) {
            // 0
            aiByte[iC]=0;
        }
        else{
            // 1
            aiByte[iC]=1;
        }
        iZ=iZ/2;
    }
    for(iC=31; iC>=0; iC--) {
        printf("%d", aiByte[iC]);   //Ausgabe der Bytes
    }
}

void bit_clearlowest(BYTE *B_Wert)
{
    int iTest;
    int iC=0;
    int B_Test;
    BYTE B_Temp = 1;
    B_Test=*B_Wert;
    do
    {
        B_Temp = (B_Temp << 1);
        B_Test = (B_Test | B_Temp);

        printf("%d\n%d",*B_Wert, B_Test );
        if(B_Test==*B_Wert)
        {
            printf("reset\n");
            //Bit gesetzt
            BYTE B_Temp = 1;
            B_Temp = (B_Temp << iC);
            B_Temp = ~B_Temp;
            *B_Wert = (*B_Wert & B_Temp);
            iC=9;
        }
        printf("%d",*B_Wert);
        iC++;
    }
    while(iC<8);



}

void bit_reverse(BYTE B_Wert)
{
    int iC;
    int iTemp;
    int aiByte[8];

    for(iC=0; iC<=7; iC++)
    {
        iTemp=B_Wert%2;
        if(iTemp==0)
        {
            // 0
            aiByte[iC]=0;
        }
        else
        {
            // 1
            aiByte[iC]=1;
        }
        B_Wert=B_Wert/2;
    }
    for(iC=0; iC<=7; iC++)
    {
        printf("%d", aiByte[iC]);   //Ausgabe vom Byte
    }
}


int main()
{
    int iAusw;
    int iC;
    int iN;
    int iAusg;  //Ausgabe
    BYTE B_Wert;

    printf("Welche Funktion möchten Sie öffnen?\n");
    printf("Bit_Set: 1\nBit_Clear: 2\nBit_Test: 3\nBit_Print: 4\nBit_Count: 5\nInt_to_4BYTE: 6\nbit_clearlowest: 7\nbit_reverse: 8\n");
    scanf("%i", &iAusw);
    fflush(stdin);
    printf("\n");
    switch(iAusw)
    {
    case 1:
        printf("Bitte geben Sie einen Wert (max. 255) ein: ");
        scanf("%d", &B_Wert);
        fflush(stdin);
        printf("Bitte geben Sie eine Position an: ");
        scanf("%d", &iN);
        fflush(stdin);
        printf("\n");
        Bit_Set(&B_Wert, iN);
        iAusg=B_Wert;
        printf("%d", B_Wert);
        break;

    case 2:
        printf("Bitte geben Sie einen Wert (max. 255) ein: ");
        scanf("%d", &B_Wert);
        fflush(stdin);
        printf("Bitte geben Sie eine Position an: ");
        scanf("%i", &iN);
        fflush(stdin);
        printf("\n");
        Bit_Clear(&B_Wert, iN);
        printf("%d", B_Wert);
        break;

    case 3:
        printf("Bitte geben Sie einen Wert (max. 255) ein: ");
        scanf("%d", &B_Wert);
        fflush(stdin);
        printf("Bitte geben Sie eine Position an: ");
        scanf("%i", &iN);
        fflush(stdin);
        printf("\n");
        Bit_Test(&B_Wert, iN);
        break;

    case 4:
        printf("Bitte geben Sie einen Wert (max. 255) ein: ");
        scanf("%d", &B_Wert);
        fflush(stdin);
        Bit_Print(B_Wert);
        break;

    case 5:
        printf("Bitte geben Sie einen Wert (max. 255) ein: ");
        scanf("%d", &B_Wert);
        fflush(stdin);
        Bit_Count(B_Wert);
        break;

    case 6:
        printf("Bitte geben Sie einen Wert (4 Byte) ein: ");
        scanf("%d", &B_Wert);
        fflush(stdin);
        Int_to_4BYTE(B_Wert);
        break;

    case 7:
        printf("Bitte geben Sie einen Wert (max. 255) ein: ");
        scanf("%d", &B_Wert);
        fflush(stdin);
        bit_clearlowest(&B_Wert);
        break;

    case 8:
        printf("Bitte geben Sie einen Wert (max. 255) ein: ");
        scanf("%d", &B_Wert);
        fflush(stdin);
        bit_reverse(B_Wert);
        break;

    }
	
	warten(10000);
    return 0;
}
