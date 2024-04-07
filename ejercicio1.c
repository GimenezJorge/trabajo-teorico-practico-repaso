#include <stdio.h>
int NumMayor(int*);                      //prototipo de la funcion

int main(void) {
  int vec[10];                           //defino el vector
  printf ("ingresar 10 numeros\n");      //mensaje para el usuario
  for (int i=0;i<10;i++)                 //ingreso de 10 numeros
  {
    scanf ("%i",&vec[i]);                //leo los numeros y los guardo en el vector
  }
  NumMayor(vec);                         //llamo a la funcion y le envio el vector



  return 0;
}
  
int NumMayor(int* vec)                   //funcion que averigua el numero mayor y la cantidad de veces ingresada (recibe el vector)
{
  int mayor=vec[0],cont=0;               //defino las variables (mayor y contador)
  for (int i=0;i<10;i++)                 //recorro el vector
  {
    if (vec[i]>mayor)                    //averiguo si el numero de la posicion actual es mayor que la variable "mayor"
    {
      mayor=vec[i];                      //si es mayor, modifico la variable
    }
  }
  for (int i=0;i<10;i++)                 //vuelvo a recorrer el vector desde el principio
  {
    if (mayor==vec[i])                   //si se repitio el mayor, aumento el contador
    {
      cont++;                            //aumento
    }
  }
  printf("el numero mayor es %i y fue ingresado %i veces",mayor,cont); //imprimo el resultado en pantalla
  return 0;
}