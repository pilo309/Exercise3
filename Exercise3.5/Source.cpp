#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <conio.h>

#define RED 6
#define YELLOW 5
#define GREEN 4

//Tilf�j et igen nyt RaspberryPi - projekt og kald det �Trafikstyring Iteration4�.Skriv nu
//et program, der opfylder punkt 4 ovenfor.Brugeren(ham / hende p� trafikcentralen)
//skal - ved tryk p� 3 forskellige taster p� tastaturet - kunne skifte mellem :
//1. dagstilstand(brug koden fra iteration 1)
//2. aften / weekendtilstand(brug koden fra iteration 3)
//3. afslutte programmet

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	// To do your code

	int waitredgreen = 3000;
	int waityellow = 1000;

	while (1)							// uendeligt loop iteration 3
	{
		char mode = 0;

		printf_s("Indtast n for nattilstand og d for dagstilstand, 0 for at afslutte\n");
		mode = _getch();

		switch (mode)
		{
		case 'd':
			do
			{
				printf_s("\nDu er nu i dagstilstand. Tryk p� vilk�rlig tast for at afbryde program.\n");
				ledOn(6);
				Wait(waitredgreen);					//t�nde r�d lys dern�st gul
				ledOn(5);
				Wait(waityellow);
				ledOff(6);
				ledOff(5);
				ledOn(4);
				Wait(waitredgreen);					//gr�n lys, og der t�ndes 
				ledOff(4);
			} while (!_kbhit());

			break;



		case 'n':

			printf_s("Du er nu i nattilstand. Tryk p� vilkaarlig tast for at afbryde program.\n");
			
			do
			{
				ledOn(GREEN);
				if (keyPressed(P1) == 1 || getIntensity() < 70)   //t�nde r�d lys s�fremt P1 trykkes eller lysintensitet
				{
					ledOff(GREEN);
					ledOn(YELLOW);
					Wait(waityellow);					//t�nde r�d lys dern�st gul
					ledOff(YELLOW);
					ledOn(RED);
					Wait(waitredgreen);					//gr�n lys, og der t�ndes 
					ledOff(RED);
				}
			} while (!_kbhit());
			break;

		case '0':
		{
			return 0;

			break;
		}

		}
	}

	return 0;
}