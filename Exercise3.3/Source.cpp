#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

#define RED 6
#define YELLOW 5
#define GREEN 4

//Exercise 3.3 Trafikstyring � iteration 2
//Tilf�j et nyt RaspberryPi - projekt til din solution.Kald det �Trafikstyring Iteration2�.
//Kopier din kode fra main() i iteration 1 til main() i iteration 2.
//Diskut�r med dine medstuderende hvorfor du skal lave et nyt projekt i stedet for
//bare at forts�tte i samme projekt.
//Lav de n�dvendige �ndringer, s� trafiklyset kun skifter til �r�dt lys�, hvis der
//kommer en fodg�nger og trykker p� fodg�ngerknappen) (hint 3B).
//Husk pseudokode f�rst !
//N�r programmet virker, har du opfyldt pkt. 2. Du kan derfor g� videre til iteration 3.

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

	while (1)							// uendeligt loop
	{
		ledOn(GREEN);

		if (keyPressed(P1) == 1)				//t�nde r�d lys s�fremt P1 trykkes
		{
			ledOff(GREEN);
			ledOn(YELLOW);
			Wait(waityellow);					//t�nde r�d lys dern�st gul
			ledOff(YELLOW);
			ledOn(RED);
			Wait(waitredgreen);					//gr�n lys, og der t�ndes 
			ledOff(RED);
		}
		
	}

	return 0;
}