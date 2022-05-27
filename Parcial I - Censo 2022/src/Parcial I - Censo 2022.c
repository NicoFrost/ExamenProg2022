/*
 ============================================================================
 Name        : Parcial I
 Author      : Nicolas Gorza
 ============================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "libreriaP.h"
#include "FuncionesV.h"
#include "FuncionesC.h"
#include "Estructuras.h"

#define TAM 2000

int main(void) {

	setbuf(stdout,NULL);
	int option;
	int id = 20000;
	int fLegajo,sid,flagViviendas = 0;

	eVivienda viviendas[TAM];
	eVivienda ingresoViv;
	eCensista censistas[3] = {{100, "Ana", 34, "1203-2345"}, {101, "Juan", 24, "4301-54678"}, {102, "Sol", 47, "5902-37487"}};
	char respuesta[5];
	int contadorA = 0,contadorJ = 0,contadorS = 0 ;
	initVivienda(viviendas, TAM);

	do{
		option = MenuGeneral(0, "1.Alta Vivienda\n", "2.Modificar Vivienda\n", "3.Baja Vivienda\n", "4.Listar Viviendas\n", "5.Listar Censistas\n", "6.Informes Censistas\n");
		switch (option) {
			case 1:
				if(!(setVivData(&ingresoViv,censistas))){
					if(addVivienda(viviendas, TAM, id, ingresoViv.calle, ingresoViv.cantidadPersonas, ingresoViv.cantidadHabitaciones, ingresoViv.tipoVivienda, ingresoViv.legajoCensista)){
						switch(ingresoViv.legajoCensista){
							case 100:
								contadorA++;
								break;
							case 101:
								contadorJ++;
								break;
							case 102:
								contadorS++;
								break;
						}
						id++;
						ClearViv(&ingresoViv);
						flagViviendas = 1;
						printf("\n¡VIVIENDA AÑADIDA!\n");
					}
				}
				break;
			case 2:
				if(flagViviendas){
					printVivienda(viviendas, TAM);
					do{
						printf("INGRESE ID DE VIVIENDA A MODIFICAR: ");
						setbuf(stdin,NULL);
						scanf("%d",&fLegajo);
						sid = findViviendaByLegajo(viviendas, TAM, fLegajo);
						if(sid != -1){
							ClearViv(&ingresoViv);
							if(modVivienda(&ingresoViv)){
								modVivData(sid, ingresoViv, viviendas, TAM);
							}
						} else {
							printf("ERROR, ID no encontrado\n");
						}
					}while(sid == -1);
				} else {
					printf("DEBE INGRESAR AL MENOS UNA VIVIENDA\n");
				}
				break;
			case 3:
				if(flagViviendas){
					printVivienda(viviendas, TAM);
					do{
						printf("INGRESE ID DE VIVIENDA A BORRAR: ");
						setbuf(stdin,NULL);
						scanf("%d",&fLegajo);
						sid = findViviendaByLegajo(viviendas, TAM, fLegajo);
						if(sid != -1){
							switch(viviendas[sid].legajoCensista){
								case 100:
									contadorA--;
									break;
								case 101:
									contadorJ--;
									break;
								case 102:
									contadorS--;
									break;
							}
							removeVivienda(viviendas, TAM, sid);
							verifRemovedAll(&flagViviendas, TAM,viviendas);
						} else {
							printf("ERROR, ID no encontrado\n");
						}
					}while(sid == -1);
				} else {
					printf("DEBE INGRESAR AL MENOS UNA VIVIENDA\n");
				}
				break;
			case 4:
				if(flagViviendas){
					sortViviendasByCalle(viviendas, TAM);
					printVivienda(viviendas, TAM);
					printf("Escriba cualquier tecla para contiuar...");
					fflush(stdin);
					gets(respuesta);
				} else {
					printf("DEBE INGRESAR AL MENOS UNA VIVIENDA\n");
				}
				break;
			case 5:
				printCensistas(censistas, 3);
				printf("Escriba cualquier tecla para contiuar...");
				fflush(stdin);
				gets(respuesta);
				break;
			case 6:
				if(flagViviendas){
					mostrarInforme(censistas, 3, viviendas, TAM);
						if(contadorA >= contadorJ && contadorJ >= contadorS){
							printf("Ana hizo mas censos: %d",contadorA);

						} else {
							if(contadorJ >= contadorA && contadorA >= contadorS){
								printf("Juan hizo mas censos: %d",contadorJ);

							} else {
								if(contadorS >= contadorJ && contadorS >= contadorA){
									printf("Sol hizo mas censos: %d",contadorS);

								}

						}
					}
				} else {
					printf("DEBE INGRESAR AL MENOS UNA VIVIENDA\n");
				}
				break;
			default:
				if(option != -1 && option != 0){
					printf("ERROR, numero fuera de rango de menu\n");
				}
		}
	}while(option != 0);

	return EXIT_SUCCESS;
}
