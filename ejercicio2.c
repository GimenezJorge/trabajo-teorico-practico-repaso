#include <stdio.h>
int LeerNum();                        //prototipo de la funcion          

int main(void) {                          
  printf ("ingresar 10 numeros\n");   //mensaje para el usuario   
  LeerNum();                          //llamo a la funcion  

  return 0;
}

int LeerNum()                        //funcion para leer los numeros
{
  int num,mayor,cont=1;              //defino las variables necesarias
  scanf("%i",&num);                  //hago una primer lectura para inicializar "mayor"
  mayor=num;                         //inicializo "mayor" con el primer numero ingresado

  
  for (int i=0;i<9;i++)              //leo los numeros restantes   
  {
    scanf("%i",&num);                //se ingresan los numeros
    
    if (num>mayor)                   //me fijo si hay un nuevo numero mayor                   
    {
      mayor=num;                     //actualizo el "mayor"
      cont=0;
    }
    if (num==mayor)                  //me fijo si se repite el numero mayor 
    {
      cont++;                        //aumento el contador para saber la cantidad de veces que se ingreso el mayor
    }


  }
  printf("el numero mayor es %i y fue ingresado %i veces",mayor,cont); //imprimo en pantalla los resultados
  return 0;
}