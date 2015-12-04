/*Funzionante: sì. Svolto: sì. Approfondimenti: sì.
##################PROGRAMMA LAB08 - 12BHDLZ - Esercizio 1####################
#                                                                           #
#Copyright © 2015 Corrado Mulas.                                            #
#                                                                           #
#Rilasciato dietro licenza GNU GENERAL PUBLIC LICENSE VERSION 3             #
#                                                                           #
#    This program is free software: you can redistribute it and/or modify   #
#    it under the terms of the GNU General Public License as published by   #
#    the Free Software Foundation, either version 3 of the License, or      #
#    (at your option) any later version.                                    #
#                                                                           #
#    This program is distributed in the hope that it will be useful,        #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of         #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          #
#    GNU General Public License for more details.                           #
#                                                                           #
#    You should have received a copy of the GNU General Public License      #
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.  #
#                                                                           #
#############################################################################
*/
//##############################DA PULIRE###############################
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 30

int main(int argc, char **argv)
{
	char str[N];
	int i = 0;
	int alpha = 0;
	int num = 0;
	int e = 0; //flag per numero errori di inserimento.
	char str1[N];
	int f = 0;
	int cnd1 = 0;
	int j = 0;
	
	printf("Inserire una stringa di max %d caratteri: ", N);

	while(fgets(str, N, stdin) != NULL && e == 0)
	{
		//printf("%s\n", str);
		e++;
		
	//Verifica per stringhe nulle.
		if(strlen(str)-1 == 0)
		{
			printf("\nStringa vuota. Ripetere l'input. %d tentativi rimasti.\n", 2-e);
			//e++;
		}
		else
		{
			//e = 0;
			printf("\nLunghezza della stringa: %d", (int)strlen(str)-1);
		
			for(i = 0; i < strlen(str); i++)
			{
				//printf("\n%c",str[i]);
				if(isalpha(str[i]))
				{
					alpha++;
				}
				else
				{
					if(isdigit(str[i]))
					{
						num++;
					}
				}
			}
		}
		
		printf("\nNumero di caratteri alfabetici: %d.\nNumero di caratteri numerici: %d", alpha, num);
		
		alpha = 0;
		num = 0;
		
		printf("\nInserire una seconda stringa di max %d caratteri: ", N);
		while(fgets(str1, N, stdin) != NULL && f == 0)
		{
			f++;
			
			for(i = 0; i < strlen(str); i++)
			{
				if(str1[0] == str[i])
				{
					for(j = 0; j < strlen(str1); j++)
					{
						if(str1[j] == str[i+j])
						{
							cnd1++;
							if(strlen(str1) == cnd1+1)
							{
								j = N;
								i = N;
								printf("La seconda stringa è contenuta nella prima.");
								cnd1 = 0;
							}
						}
						else
						{
							if(strlen(str1) != cnd1+1)
							{
								j = N;
								i = N;
								printf("La seconda stringa non è contenuta nella prima.");
								cnd1 = 0;
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}

