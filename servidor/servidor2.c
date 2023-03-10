/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "gestionBiblioteca.h"
#include <rpc/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

libro libros[4];
datos_persona persona[10];
datos_prestamo prestamo[10];
datos_credencial credencial[1];
datos_prestamo temp[10];
void llenarBiblioteca();
void vaciar(char temp[]);
void copiar(char temp[], int s);
int consultaVector(char *cod);
int consultaLibro(char *pNombre);
int consultarPrestamo(char *cod);
int consultaSesion(datos_credencial sesion);
int multa(char *multa);
int valid_date(int date, int mon, int year);
int cantidad =0;
int cantPres =0;
libro consLibros[10];
int cont =0;
int aleatorio_en_rango(int minimo, int maximo);

FILE *f;


bool_t *
registrarpersona_1_svc(datos_persona *argp, struct svc_req *rqstp)
{
	static bool_t  result;

	printf("\nInvocando a registrar persona\n");
	if(cantidad <10){
		persona[cantidad] = *argp;
		result = TRUE;
		cantidad++;
	}
	else
	{
		printf("\nCantidad de maxima de personas alcanzada\n");
		result = FALSE;
	}
	return &result;
}

datos_persona *
consultarpersona_1_svc(char *argp, struct svc_req *rqstp)
{
	static datos_persona  result;

	printf("\nInvocando a consultar Persona\n");
	int resul = consultaVector(argp);
	printf("\nBuscando\n");
	if(resul!=1){
		persona[resul].id = aleatorio_en_rango(1000, 9999);
		printf("\n%d",persona[resul].id);
		result = persona[resul];
	}
	else{
		result.id = -1;
	}

	return &result;
}

bool_t *
verificar_1_svc(int *argp, struct svc_req *rqstp)
{
	static bool_t  result;

	int val = *argp;
	for(int i =0; i<2;i++){
		if(persona[i].id == val){
			result = TRUE;
			break;
		}
		else{
			result = FALSE;
		}
	}
	return &result;
}

bool_t *
prestarlibro_1_svc(datos_prestamo *argp, struct svc_req *rqstp)
{
	static bool_t  result;
	printf("\nPrestando libro\n");
	if(cantPres <10){
				prestamo[cantPres] = *argp;
				result = TRUE;
				cantPres++;
			}
	else
	{
		printf("\nCantidad  maxima de prestamos alcanzada\n");
		result = FALSE;
	}
	return &result;
}

datos_prestamo *
devolverlibro_1_svc(char **argp, struct svc_req *rqstp)
{
	static datos_prestamo  result;

	printf("\nInvocando a consultar Devolver\n");
	int resul = consultarPrestamo(*argp);
	int mult = multa(*argp);
	printf("\nBuscando\n");
	if(resul!=-1){
		if(mult==0){
			result = prestamo[resul];
		}
		else if(mult >=1 && mult <=3){
			prestamo[resul].multa = 10000;
			result = prestamo[resul];
		}
		else if(mult >=4 && mult <=8){
			prestamo[resul].multa = 10000+(1000*(mult-3));
			result = prestamo[resul];
		}
		else if(mult >8){
			prestamo[resul].multa = 15000+(2000*(mult-8));
			result = prestamo[resul];
		}
	}
	else{
		result.multa = -1;
	}
	return &result;
}

datos_prestamo *
calcularmulta_1_svc(datos_prestamo *argp, struct svc_req *rqstp)
{
	static datos_prestamo  result;

	
	return &result;
}

libro *
consultarlibro_1_svc(char **argp, struct svc_req *rqst)
{
	static libro result;
	int res = consultaLibro(*argp);
	printf("\nConsultando libros\n");
	if (res != -1) {
    	result = libros[res];
  } else {
    result.error = -1;
  }
	return &result;
}

datos_credencial *
abrir_sesion_1_svc(datos_credencial *argp, struct svc_req *rqstp)
{
	static datos_credencial  result;
	llenarBiblioteca();
	int pos = consultaSesion(*argp);
  printf("\nInvocando abrir sesion");
  if (pos != -1) {
    credencial[pos].id=aleatorio_en_rango(1000, 9999);
	result = credencial[pos];
  } else {
    result.id = pos;
  }
	return &result;
}

int consultaVector(char *cod){
	int resultado=-1;
	int i ;
	for (i=0 ;  i<11 ; i++){
		if (strcmp(persona[i].codigo, cod)!=0){
			resultado=i;
			break;
		}	
	}
	return resultado;
}

int consultarPrestamo(char *cod){
	int resultado=-1;
	int i ;
	for (i=0 ;  i<11 ; i++){
		if (strcmp(prestamo[i].codigo, cod)){
			printf("\n%s", prestamo[i].nom_libro);
			resultado=i;
			return resultado;
		}	
	}
	return resultado;
}

int  consultaLibro(char *pNombre){
	for (int i = 0; i < 4; i++) {
		if (strcmp(libros[i].area_conocimiento,pNombre)==0){
			return i;
		}
		if (strcmp(libros[i].autor, pNombre) == 0){
			return i;
			break;
		}
		if (strcmp(libros[i].editorial, pNombre) == 0){
			return i;
			break;
		}
  }
  return -1;
}

int consultaSesion(datos_credencial sesion) {
    if (strcmp(sesion.usuario, credencial[0].usuario) == 0 &&
        strcmp(sesion.clave, credencial[0].clave) == 0){
			return 0;
		}
  return -1;
}

void llenarBiblioteca(){
	char nombre[4][20] = {"Calculo", "Requisitos", "Mecanica", "Estadistica"};
	char isbn[4][10] = {"dsfw12121", "dwd122112", "33efdffe", "d112sswd"};
	char editorial[4][20] = {"Palmas", "Mundo", "Space", "Palmas"};
	char categoria[4][20] = {"Matematicas", "Sistemas", "Fisica", "Matematicas"};
	char autor[4][20] = {"Andres", "Marta", "Valentina", "Jhonfer"};

	for(int i=0; i<4;i++){
		strcpy(libros[i].nombre,nombre[i]);
		strcpy(libros[i].autor,autor[i]);
		strcpy(libros[i].isbn,isbn[i]);
		strcpy(libros[i].editorial,editorial[i]);
		strcpy(libros[i].area_conocimiento,categoria[i]);

	}

}

int multa(char *multa){
	int day1, day2,mon1, mon2,year1,year2;
	int day_diff, mon_diff, year_diff;      
	for(int i =0;i<10;i++){
		if(strcmp(prestamo[i].codigo, multa)){
			day1 = prestamo[i].dia_2;
			day2 = prestamo[i].dia_3;
			mon1 = prestamo[i].mes_2;
			mon2 = prestamo[i].mes_3;
			year1 = prestamo[i].anio2;
			year2 = prestamo[i].anio3;
			if(day2 < day1)
			{      
				// borrow days from february
				if (mon2 == 3)
				{
					//  check whether year is a leap year
					if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) 
					{
						day2 += 29;
					}

					else
					{
						day2 += 28;
					}                        
				}

				// borrow days from April or June or September or November
				else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) 
				{
				day2 += 30; 
				}

				// borrow days from Jan or Mar or May or July or Aug or Oct or Dec
				else
				{
				day2 += 31;
				}

				mon2 = mon2 - 1;
			}

			if (mon2 < mon1)
			{
				mon2 += 12;
				year2 -= 1;
			}       

			day_diff = day2 - day1;
			mon_diff = mon2 - mon1;
			year_diff = year2 - year1;
		}
	}
 return day_diff;
}

int valid_date(int day, int mon, int year)    
{
    int is_valid = 1, is_leap = 0;

    if (year >= 1800 && year <= 9999) 
    {

        //  check whether year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
        {
            is_leap = 1;
        }

        // check whether mon is between 1 and 12
        if(mon >= 1 && mon <= 12)
        {
            // check for days in feb
            if (mon == 2)
            {
                if (is_leap && day == 29) 
                {
                    is_valid = 1;
                }
                else if(day > 28) 
                {
                    is_valid = 0;
                }
            }

            // check for days in April, June, September and November
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) 
            {
                if (day > 30)
                {
                    is_valid = 0;
                }
            }

            // check for days in rest of the months 
            // i.e Jan, Mar, May, July, Aug, Oct, Dec
            else if(day > 31)
            {            
                is_valid = 0;
            }        
        }

        else
        {
            is_valid = 0;
        }

    }
    else
    {
        is_valid = 0;
    }

    return is_valid;

}

int aleatorio_en_rango(int minimo, int maximo){
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}