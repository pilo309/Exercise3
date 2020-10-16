#include <stdio.h>


//Exercise 3.1 For - løkke
//Opret et nyt Visual Studio projekt(Solution Name : ”Exercise3” – Project Name :
//”For - loop”).Skriv heri et lille program der udskriver alle lige tal fra 50 til 2 i faldende
//rækkefølge – altså 50 48 46 ……6 4 2. Du skal(selvfølgelig) bruge en for - løkke.

//lave en forløkke der printer alle tal fra 50 til 2 i 2-tals interval

int main(void)
{

	int i;

	for (i = 50; i >= 2; i-=2)
	{
		printf_s("%d\n", i);
	}

	return 0;
}