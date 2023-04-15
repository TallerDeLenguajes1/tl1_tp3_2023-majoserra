/*5) Modifique el ejercicio nro 3 para que, en lugar de ingresar un número fijo de nombres, el
usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int cantNombres;
    char **nombres, *buff;

    printf("\nIngrese La cantidad de nombres: ");
    scanf("%d", &cantNombres);
    nombres = (char **)malloc(sizeof(char *)*cantNombres); //! Reservamos memoria dinamica para el puntero doble

    buff = (char *)malloc(sizeof(char)*100); //! Reservamos memoria dinamicamente para Buff

    for (int i = 0; i < cantNombres; i++)
    {
        fflush(stdin);
        printf("\nIngrese el Nombre: ");
        gets(buff);
        nombres[i] = (char *)malloc(sizeof(char)*strlen(buff)+ 1);
        strcpy(nombres[i], buff);
        
    }
    for (int i = 0; i < cantNombres; i++)
    {
        printf("\nNombre [%d]: %s", i+1, nombres[i]);
        free(nombres[i]);
    }
    
    free(buff);
    free(nombres);

    return 0;
}
