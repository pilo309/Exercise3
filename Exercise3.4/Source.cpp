#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

#define RED 6
#define YELLOW 5
#define GREEN 4

//Exercise 3.4 Trafikstyring – iteration 3
//Tilføj igen et nyt RaspberryPi - projekt og kald det ”Trafikstyring Iteration3”.Kopier
//din kode fra main() i iteration 2 til main() i iteration 3.
//Tilføj så følgende til dit program : Trafiklyset skal også skifte til ”rødt lys”, hvis der
//detekteres et køretøj på sidevejen.Du kan simulere trafiksensoren ved at lyse på
//fotoresitoren med din mobiltelefon.Når du så sætter en hånd ind mellem mobilen
//og resistoren, svarer det til at der kommer en bil og ”bryder lysstrålen”(hint 3C).
//Begynd med at rette din pseudokode.
//Når dette virker, har du et program, der opfylder pkt. 3 ovenfor  Du kan derfor gå
//videre til iteration 4.

//pseudokode, lave trafiklys der skifter til rød ved tryk på knap eller brud af lys

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

		if (keyPressed(P1) == 1 || getIntensity() < 70)   //tænde rød lys såfremt P1 trykkes eller lysintensitet
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