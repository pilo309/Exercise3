#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

#define RED 6
#define YELLOW 5
#define GREEN 4

//Exercise 3.3 Trafikstyring – iteration 2
//Tilføj et nyt RaspberryPi - projekt til din solution.Kald det ”Trafikstyring Iteration2”.
//Kopier din kode fra main() i iteration 1 til main() i iteration 2.
//Diskutér med dine medstuderende hvorfor du skal lave et nyt projekt i stedet for
//bare at fortsætte i samme projekt.
//Lav de nødvendige ændringer, så trafiklyset kun skifter til ”rødt lys”, hvis der
//kommer en fodgænger og trykker på fodgængerknappen) (hint 3B).
//Husk pseudokode først !
//Når programmet virker, har du opfyldt pkt. 2. Du kan derfor gå videre til iteration 3.

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

		if (keyPressed(P1) == 1)				//tænde rød lys såfremt P1 trykkes
		{
			ledOff(GREEN);
			ledOn(YELLOW);
			Wait(waityellow);					//tænde rød lys dernæst gul
			ledOff(YELLOW);
			ledOn(RED);
			Wait(waitredgreen);					//grøn lys, og der tændes 
			ledOff(RED);
		}
		
	}

	return 0;
}