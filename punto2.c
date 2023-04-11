/*2) Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes. Ud. debe realizar las siguientes tareas:
a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
b. Muestre por pantalla los valores cargados
c. Saque el promedio de ganancia por año y muestrelos por pantalla
d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
cuándo ocurrió.
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int matriz[5][12], suma, minimo, maximo, anio, mes, mayor=0, menor=1000001, mes1, anio1;
    float promedio;

    srand(time(NULL));
    //todo  a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {

            matriz[i][j]= rand() % 50000 + 10000 ;
            //! b. Muestre por pantalla los valores cargados
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    //todo c. Saque el promedio de ganancia por año y muestrelos por pantalla
    for (int i = 0; i < 5; i++)
    {
        suma = 0;
        for (int j = 0; j < 12; j++)
        {
           suma = suma + matriz[i][j];
        }
        promedio = suma/12;
        printf("\nEl Promedio del año %d es: %.2f", i+1, promedio);
    }

    //todo d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (matriz[i][j]>mayor)
            {
                mayor = matriz[i][j];
                mes = j+1;
                anio = i+1;
            }
            if (matriz[i][j]<menor)
            {
                menor = matriz[i][j];
                mes1=j+1;
                anio1=i+1;
            }
        }
    }
    printf("\nEl valor maximo es %d, ocurrio en el mes %d, anio %d", mayor, mes, anio);
    printf("\nEl valor minimo es %d, ocurrio en el mes %d, anio %d", menor, mes1, anio1);


    
    return 0;
}