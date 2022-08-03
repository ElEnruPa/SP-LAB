#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Pokemon.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int ok;
	int cargaDatos;
	cargaDatos = 0;

    LinkedList* listaPokemones = ll_newLinkedList();

    do{
    	limpiar();
    	printf("Ingrese una opcion:\n"
    			"1_ Cargar archivo pokemones. \n"
    			"2_ Modificar valor ataque.\n"
    			"3_ Imprimir Pokemones. \n"
    			"4_ Filtrar tipo Fuego.\n"
    			"5_ Filtrar Extra Grandes de tipo Veneno.\n"
    			"6_ Salir.\n");
    	scanf("%d",&opcion);
    	validarEntero(&opcion, 1, 6);

    	switch(opcion)
    	{
    		case 1:
    			ok = montes_pokemon_loadFromText("Data_Pokemones.csv", listaPokemones);

    			if(ok == 1)
    			{
    				printf("\nDatos cargados correctamente.\n");
    				cargaDatos = 1;
    			}
    			else
    			{
    				printf("Hubo un error al intentar cargar los datos.\n");
    			}

    			system("pause");
    			break;

    		case 2:
    			limpiar();
    			if(cargaDatos == 1)
    			{
    				ok = montes_pokemon_modificaValorAtaque(listaPokemones);

					if(ok == 1)
					{
						printf("Se modifico el valor de ataque correctamente.\n");
					}
					else
					{
						printf("Hubo un error al modificar el valor.\n");
					}
    			}
    			else
    			{
    				printf("No se puede modificar ningun pokemon si todavia no se cargaron los datos.\n");
    			}

    			system("pause");
    			break;

    		case 3:
    			limpiar();
    			if(cargaDatos == 1)
    			{
    				ok = montes_pokemon_ListPokemones(listaPokemones);

    				if(ok == 0)
    				{
    					printf("Hubo un error al intentar mostrar la lista de los pokemones.\n");
    				}
    			}
    			else
    			{
    				printf("No se puede imprimir ningun pokemon si todavia no se cargaron los datos.\n");
    			}

    			system("pause");
    			break;

    		case 4:
    			limpiar();
    			if(cargaDatos == 1)
    			{
    				ok = montes_pokemon_filtroFuego("Lista_Filtrada_Tipo_Fuego.csv", listaPokemones);

    				if(ok == 1)
    				{
    					printf("Se guardaron los pokemones filtrados correctamente en el archivo.\n");
    				}
    				else
    				{
    					printf("Hubo un error al intentar guardar los pokemones filtrados en el archivo.\n");
    				}
    			}
    			else
				{
    				printf("No se puede guardar ningun pokemon filtrado si todavia no se cargaron los datos.\n");
				}

    			system("pause");
    			break;

    		case 5:
    			limpiar();
    			if(cargaDatos == 1)
    			{
        			ok = montes_pokemon_filtroXLyPoison(listaPokemones);

        			if(ok == 0)
        			{
    					printf("Hubo un error al intentar mostrar la lista de los pokemones filtrados.\n");
        			}
    			}
    			else
    			{
    				printf("No se puede imprimir ningun pokemon si todavia no se cargaron los datos.\n");
    			}

    			system("pause");
    			break;

    		case 6:
    			limpiar();
    			printf("---CONSOLA APAGADA---");
    			break;

    	}

    }while(opcion!=6);

	return 0;
}
