#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

//Exercise 3.2 Trafikstyring – iteration 1
//Opret et nyt RaspberryPi - projekt og kald det ”Trafikstyring Iteration1”.Skriv her i et
//program, der får trafiklyset til at skifte på korrekt måde mellem ”rødt lys” og ”grønt
//lys” med passende tidsintervaller(hint 3A).
//Husk at skrive pseudokode før du gør i gang !
//Når dette virker, har du et program, der opfylder pkt. 1 ovenfor 
//Du kan derfor gå videre til iteration 2.

//lave program der skifter med passende intervaller mellem rød og grøn lys

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

		ledOn(6);
		Wait(waitredgreen);					//tænde rød lys dernæst gul
		ledOn(5);
		Wait(waityellow);
		ledOff(6);
		ledOff(5);
		ledOn(4);
		Wait(waitredgreen);					//grøn lys, og der tændes 
		ledOff(4);


	}

	return 0;
}