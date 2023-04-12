/*Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados los liste por pantalla*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *nombres[5];
    //cargamos los nombres
    for (int i = 0; i < 5; i++)
    {
        nombres[i] = malloc(5*sizeof(char)); // Reserva dinamica de memoria
        printf("\nIngrese el Nombre: ");
        gets(nombres[i]); // guardamos los nombres        
    }
    //mostramos los nombres
    for (int i = 0; i < 5; i++)
    {
        printf("\nNombre[%i]: %s",i,  nombres[i]);
    }
}