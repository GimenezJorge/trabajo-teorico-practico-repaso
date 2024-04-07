#include <stdio.h>                                                           //incluyo las librerias necesarias
#include <string.h>
#include <stdlib.h>

typedef struct Producto                                                      //defino los elementos de la estructura del producto
{
  int id;
  char articulo[20];
  int cantidad;
  float precio;
  float precioFinal;
} Producto;

typedef struct Nodo                                                          //defino el nodo
{
  struct Producto datos;                                                     //vinculo el nodo con la estructura
  struct Nodo* sig;                                                          //vinculo el nodo con el siguiente
}Nodo;

int menu();                                                                  //prototipos de funciones
float TipoFactura();
Nodo* agregar(Nodo*, Producto);
Nodo* nuevoNodo();
void mostrarLista(Nodo*);
void hallarMayor(Nodo*);
void hallarProm(Nodo*, int);

int main(void) {
  int opcion,contID=1,cantProd;                                              //defino variables
  float iva=0.21,subtotal;
  Nodo *pIni;                                                                //define el nodo 
  pIni = NULL;
  Producto prod;                                                             //defino el producto
  do                                                                         //while del menu
  {    
    switch (opcion)                                                          //el usuario elige una opcion del menu
    {    
      case 1:
        iva=TipoFactura();                                                   //llamo a la funcion que elige el tipo de factura
        break;
      case 2:
        printf("\nCuantos productos se ingresaron en la factura?: ");        //pido la cantidad de productos
        scanf("%i",&cantProd);                                               //leo la cantidad de productos
        while(getchar()!='\n');                                              //limpio el buffer
        for (int i=0; i<cantProd; i++)                                       //ingreso los productos que el usuario me indicó
        {
          prod.id = contID++;                                                //le asigno un id secuencial
          printf("\nINGRESE NOMBRE DEL ARTICULO: ");                         //pido el nombre del articulo 
          fgets(prod.articulo ,sizeof(prod.articulo),stdin);                 //leo el nombre del producto
          prod.articulo[strcspn(prod.articulo, "\n")] = '\0';                //elimino el salto de linea
          
          printf("\nINGRESE EL PRECIO: ");                                   //pido el precio del producto
          scanf("%f",&prod.precio);                                          //leo el precio del producto
          while(getchar()!='\n');                                            //limpio el buffer
          
          printf("\nINGRESE CANTIDAD: ");                                    //pido la cantidad del producto
          scanf("%i",&prod.cantidad);                                        //leo la cantidad del producto
          while(getchar()!='\n');                                            //limpio el buffer

          subtotal=prod.precio*prod.cantidad;                                //calculo el subtotal
          prod.precioFinal = subtotal + (subtotal*iva);                      //calculo el precio final (sumando el iva)
          pIni=agregar(pIni, prod);                                          //llamo a la funcion que agrega el producto a la lista        
        }                        
        break;
      case 3:        
        hallarMayor(pIni);                                                   //llamo a la funcion que halla el mayor
        break;
      case 4:
        hallarProm(pIni, contID);                                            //llamo a la funcion que halla el promedio
        break;
    }    
    opcion=menu();                                                           //llamo a la funcion que muestra el menu
  }while (opcion !=0);                                                       
  return 0;
}
int menu()
{
  int opcion;                                                                //defino la variable para elegir la opcion del menu
  system ("clear");
  printf("\n\n=============================================\n");             //dibujo todo el menu
  printf("1) TIPO DE FACTURA: \n");
  printf("2) INGRESAR PRODUCTOS: \n");
  printf("3) HALLAR EL PRODUCTO DE MAYOR VALOR: \n");
  printf("4) HALLAR EL PROMEDIO: \n\n");
  printf("0) Salir\n");
  printf("=============================================\n");
  printf ("\nElija una opción del menu principal: ");
  scanf ("%i",&opcion);                                                       //leo la opcion elegida
  while(getchar()!='\n');                                                     //limpio el buffer
  return opcion;                                                              //retorno la opcion elegida
}

Nodo* nuevoNodo()                                                             //funcion que crea un nodo
{
  Nodo* p;                                                                    //defino el nodo
  p=(Nodo*)malloc(sizeof(Nodo));                                              //le asigno memoria
  p->sig=NULL;                                                                //indico que es el ultimo hasta ahora
  return p;                                                                   //retorno el nodo
}

float TipoFactura()                                                           //eligir el tipo de factura (si no se llama, por defecto es el 21%)
{
  int opcion;                                                                 //defino la variable para elegir la opcion del menu
  float iva;                                                                  //defino la variable para el iva
  printf("\n==========================\n");                                   //dibujo el menu
  printf("1) Responsable Inscripto: \n");
  printf("2) Consumidor Final: \n");
  printf("3) Bienes y Servicios: \n");
  printf("==========================\n");
  printf("\nELEGIR EL TIPO DE FACTURA: ");
  scanf("%i",&opcion);                                                        //leo la opcion elegida
  switch (opcion)                                                             //el usuario elige una opcion del menu
  {
    case 1:                                                                   //si elige la opcion 1
      printf("RESPONSABLE INSCRIPTO - SE APLICA EL 10,5%% DE IVA");           //se muestra el tipo de factura
      iva=0.105;                                                              //se le asigna el iva
      break;
    case 2:
      printf("CONSUMIDOR FINAL - SE APLICA EL 21%% DE IVA");                  //se muestra el tipo de factura
      iva=0.21;                                                               //se le asigna el iva
      break;
    case 3:
      printf("BIENES Y SERVICIOS - SE APLICA EL 27%% DE IVA");                //se muestra el tipo de factura
      iva=0.27;                                                               //se le asigna el iva
      break;
  }
  return iva;                                                                 //retorno el iva
}

Nodo* agregar(Nodo *pIni,Producto prod)                                       //funcion que agrega un nodo a la lista
{
  Nodo* p=pIni;                                                               //defino el nodo
  if (p==NULL)                                                                //si la lista esta vacia
  {
    p=nuevoNodo();                                                            //creo un nodo
    p->datos=prod;                                                            //le asigno los datos del producto
    return p;                                                                 //retorno el nodo
  }
  while (p->sig!=NULL)                                                        //si la lista no esta vacia
  {
    p=p->sig;                                                                 //avanzo al siguiente nodo
  }
  Nodo* nuevo=nuevoNodo();                                                    //llamo a la funcion que crea un nodo
  p->sig=nuevo;                                                               //indico que el nuevo pasa a ser el siguiente
  nuevo->datos=prod;                                                          //le asigno los datos del producto
  return pIni;                                                                //retorno la lista
}

void hallarMayor(Nodo* lista)                                                 //funcion que halla el mayor
{
  Nodo* p;                                                                    //defino otro nodo
  p=lista;                                                                    //le asigno la lista (para no perder la original)

  int tempID,tempCantidad;                                                    //defino variables temporales
  char tempArticulo[20];
  float tempPrecio;
  float tempPrecioFinal;
  
  float mayor;                                                                 //defino la variable para el mayor
  mayor=p->datos.precioFinal;                                                  //inicializo las variables temporales
  tempID=p->datos.id;
  strcpy(tempArticulo,p->datos.articulo);
  tempCantidad=p->datos.cantidad;
  tempPrecio=p->datos.precio;
  tempPrecioFinal=p->datos.precioFinal;
  
  while (p!=NULL)                                                              //recorro la lista
  {
    if (p->datos.precioFinal>mayor)                                            //si encuentra un precio final mayor
    { 
      mayor=p->datos.precioFinal;                                              //los datos de ese producto se guardan en las variables temporales
      tempID=p->datos.id;
      strcpy(tempArticulo,p->datos.articulo);
      tempCantidad=p->datos.cantidad;
      tempPrecio=p->datos.precio;
      tempPrecioFinal=p->datos.precioFinal;
    }
    p=p->sig;                                                                  //avanzo al siguiente nodo
  }    
  printf("\n\nEL PRODUCTO DE MAYOR VALOR ES: \n");                             //muestro los datos del producto de mayor valor
  printf("\nID: %i | ARTICULO: %s | PRECIO: %.2f: | CANTIDAD: %i: | PRECIO FINAL $%.2f: ",tempID, tempArticulo,tempPrecio,tempCantidad,tempPrecioFinal);
  getchar();                                                                   //espero que el usuario presione enter
}

void hallarProm(Nodo* lista, int contID)                                       //funcion que halla el promedio
{
  Nodo* p;                                                                     //defino otro nodo
  p=lista;                                                                     //le asigno la lista (para no perder la original)

  float suma=0,prom=0;                                                         //defino variables para la suma y el promedio
  
  while (p!=NULL)                                                              //recorro la lista
  {
    suma+=p->datos.precioFinal;                                                //voy sumando los precios finales
    p=p->sig;                                                                  //avanzo al siguiente nodo  
  }  
  contID--;                                                                    //le resto 1 a la cantidad de productos, ya que siempre tengo 1 de más
  prom=suma/contID;                                                            //calculo el promedio
  printf("\nEL PROMEDIO DE LOS PRECIOS FINALES DE LOS %i PRODUCTOS ES: $%.2f ",contID,prom);  //muestro el promedio
}