#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};
struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
};

float costoTotal(struct Producto Producto);

int main(){
    //declaracion de variables
    int cantClientes;
    struct Cliente *arregloClientes;
    float costoTotalCliente=0;


    printf("\nIngrese la cantidad de clientes"); //? Solicita la cantidad de clientes
    scanf("%d", &cantClientes);

//Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.

    if (cantClientes>0 && cantClientes<6)//! controlamos que cada preventista puede visitar hasta 5 clientes
    {
        arregloClientes = (struct Cliente *)malloc(cantClientes*sizeof(struct Cliente)); //memoria dinamicamente

        for (int i = 0; i < cantClientes; i++)
        {
            // cargamos los datos de cada cliente
            printf("\n----------------Cliente[%i]-------------", i+1);
            arregloClientes[i].ClienteID = i+1;
            printf("\nIngrese el Nombre del cliente: ");
            fflush(stdin);
            arregloClientes[i].NombreCliente = (char *)malloc(sizeof(char)*100);
            gets(arregloClientes[i].NombreCliente);
            fflush(stdin);
            srand(time(NULL));

            //A medida que se dé de alta cada cliente, Generar aleatoriamente la cantidad de productos asociados al cliente y sus características.

            arregloClientes[i].CantidadProductosAPedir = rand() % 5 + 1; //cantidad de productos aleatoriamente
            // Reservamos memoria dinamicamente para Productos, dependiendo de la cantidad de productos aleatoriamente
            arregloClientes[i].Productos = (struct Producto *)malloc(arregloClientes[i].CantidadProductosAPedir * sizeof(struct Producto));
            for (int j = 0; j < arregloClientes[i].CantidadProductosAPedir; j++) //usamos otra variable "j" 
            {
               arregloClientes[i].Productos[j].ProductoID = j + 1;
               arregloClientes[i].Productos[j].Cantidad = rand() % 10 + 1;
               arregloClientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5]; 
               arregloClientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
            }
            
        }
        
    }else
    {
        printf("Cantidad de clientes, no admitida");
    }
    

    /*v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar por cliente 
    (sumatoria del costo de todos los productos)*/
    for (int i = 0; i < cantClientes; i++)
    {
        printf("\n-----------Datos Cliente %d----------\n", i+1);
        printf("\nClienteID: %d", arregloClientes[i].ClienteID);
        printf("\nNombre Cliente: %s", arregloClientes[i].NombreCliente);
        printf("\nCantidad de Productos: %d", arregloClientes[i].CantidadProductosAPedir);
        for (int j = 0; j < arregloClientes[i].CantidadProductosAPedir; j++)
        {
            printf("\nProductoID: %d\n", arregloClientes[i].Productos[j].ProductoID);
            printf("\nCantidad: %d",  arregloClientes[i].Productos[j].Cantidad);
            printf("\nTipo de Producto: %s", arregloClientes[i].Productos[j].TipoProducto);
            printf("\nPrecio unitario: %.2f",arregloClientes[i].Productos[j].PrecioUnitario);
            costoTotalCliente = costoTotalCliente + costoTotal(arregloClientes[i].Productos[j]);
            
        }
        printf("\nTotal a Pagar: %.2f\n", costoTotalCliente);
        costoTotalCliente = 0;
    }

    for (int i = 0; i < cantClientes; i++)
    {
        free(arregloClientes[i].NombreCliente);
    }
    
    free(arregloClientes);
    
    
    return 0;
}
/*iv) Implemente una función que calcule el costo total de un producto. Esta función debe
recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por
el PrecioUnitario.
*/
float costoTotal(struct Producto Producto){
    float costo;
    costo = Producto.Cantidad * Producto.PrecioUnitario;
    return costo;
}