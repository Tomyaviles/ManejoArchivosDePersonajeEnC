#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const MAX_PLAYER = 3;
typedef struct
{

    int ataque;
    int agilidad;
    int voluntad;
    int vida;
    char nombre[60];


} player;
////IMPORTANTE PROTOTIPAR ESTAS DOS FUNCIONES:
player ModificarNombre(player j1);
player ModificarAtributos(player j1);
player eliminar(char archivo[], player j1);


int main()
{
    int atak, agil , volunt;
    int opcionMenu;
    int pos = 0;
    int cont = 0;
    player jugadorestemp[40] = {"temparchi.bin"};
    player jugadores[40] = {"jugadores.bin"};
    srand(time(NULL));

  do{
    printf("\nIngrese la opcion que desea utilizar\n");
    printf("\n1.Nuevo Player(si utiliza esta opcion, se borraran todos los que tenia ya cargados!!!)");
    printf("\n2.Agregar Nuevo Player");
    printf("\n3.Muestra todos los Players");
    printf("\n4.Busca un archivo del player por su posicion");
    printf("\n5.Modifica un player");
    printf("\n6.Eliminar player por posicion");
    printf("\n7.Eliminar todo");
    printf("\nPresione 0 para salir\n");
    printf("\nIngrese la opcion a elegir: ");
    fflush(stdin);
    scanf("%i", &opcionMenu);
     Atributos(&atak, &agil, &volunt);

    switch(opcionMenu)
    {
    case 1:
           CargaPlayer("jugadores.bin", &atak, &agil, &volunt);
        break;
    case 2:
        ContadoradeArchvios("jugadores.bin", &cont);
        printf("Hay %i archivos\n", cont);
        if(cont < 3)
        {
            AgregarPlayer("jugadores.bin", &atak, &agil, &volunt);
        }
        else{
            printf("\nYA HAY 3 PERSONAJES, NO SE PUEDE CARGAR MAS\n");
        }
        break;
    case 3:
         Muestra("jugadores.bin");
         break;
    case 4:
        printf("Ingrese la posicion que desea buscar: ");
        fflush(stdin);
        scanf("%i", &pos);
        BuscarJugador("jugadores.bin", &pos);
        break;
    case 5:
        printf("Ingrese la posicion que desea modificar: ");
        fflush(stdin);
        scanf("%i", &pos);
        ModificarPlayer("jugadores.bin", &pos);
        break;
    case 6:
        Buscareliminar("jugadores.bin", "temparchi.bin");
        break;
    case 7:
        EliminarTodo("jugadores.bin");
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("\nEsa opcion no esta disponible...\n");
        break;


    }
    system("pause");
  }while(opcionMenu != 0);

}





int ContadoradeArchvios(char jugadores[], int *cont)
  {
      FILE* archi;
      player j1;
      *cont = 0;
      archi = fopen(jugadores, "rb");

      if(archi!=NULL)
      {
          while(!feof(archi))
          {
              fread(&j1, sizeof(player), 1, archi);
              if(!feof(archi))
              {
                  *cont = *cont + 1;
              }
          }
          fclose(archi);
      }
  }


//Esta funcion devuelve los atributos random para la creacion del personae//
void Atributos(int *atak, int *agil, int *volunt)
{

    *atak = 0;
    *agil = 0;
    *volunt = 0;
    *atak = Dado8();
    *agil = Dado8();
    *volunt = Dado8();
}





////Esta es una funcion random para los dados/////////////////////////////////////
int Dado8()
{
    int dado = 0;
    dado = (rand()%7)+1;

return dado;
}




///Esta funcion crea un nuevo personaje, borrando todos los que ya habia//////////////////////////
void CargaPlayer(char jugador[], int *n1, int *n2, int *n3)
{
    player j1;
    FILE *archi;
    int opcion = 0;

    archi = fopen(jugador, "wb");
    if(archi!= NULL)
    {
      do{
        printf("Ingrese el nombre del personaje: ");
        fflush(stdin);
        scanf("%s", &j1.nombre);

        printf("ELIJA SUS ESTADISTICAS DE ATAQUE: \n");
        printf("\n1.ataque: %i", *n1);
        printf("\n2.ataque: %i", *n2);
        printf("\n3.ataque: %i\n", *n3);

        printf("\nIngrese la opcion a elegir: ");
        fflush(stdin);
        scanf("%i", &opcion);

        switch(opcion)
        {
          case 1:
             j1.ataque = *n1;
             break;
         case 2:
            j1.ataque = *n2;
            break;
         case 3:
            j1.ataque = *n3;
            break;
         default:
             printf("\nUSTED A ELEGIDO LA OPCION INCORRECTA, VUELVA A SELECCIONAR\n");
             break;
        }
        }while(opcion!=1 && opcion!=2 && opcion!=3);




            printf("\n");
            printf("\nELIJA SUS ESTADISTICAS DE AGILIDAD\n");
            if(opcion == 1)
            {
               do{
                printf("\n1.agilidad: %i", *n2);
                printf("\n2.agilidad: %i\n", *n3);
                printf("\nElija su estadistica: ");
                fflush(stdin);
                scanf("%i", &opcion);
                switch(opcion)
                {
                case 1:
                    j1.agilidad = *n2;
                    printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n3);
                    j1.voluntad = *n3;
                    break;
                case 2:
                    j1.agilidad = *n3;
                     printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n2);
                     j1.voluntad = *n2;
                     break;
                default:
                    printf("\nUSTED A ELEGIDO LA OPCION INCORRECTA, VUELVA A ELEGIR\n");

                 }
               }while(opcion != 1 && opcion != 2);


            }
            else{
                if(opcion == 2)
                {
                   do{
                    printf("\n1.agilidad: %i", *n1);
                    printf("\n2.agilidad: %i\n", *n3);
                    printf("\nElija su estadistica: ");
                    fflush(stdin);
                    scanf("%i", &opcion);

                    switch(opcion)
                    {
                    case 1:
                        j1.agilidad = *n1;
                        printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n3);
                        j1.voluntad = *n3;
                        break;
                    case 2:
                        j1.agilidad = *n3;
                        printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n1);
                        j1.voluntad = *n1;
                        break;
                    default:
                        printf("\nUSTED AH ELEGIDO LA OPCION INCORRECTA, VUELVA A ELEGIR\n");
                    }
                   }while(opcion != 1 && opcion != 2);
                }
                else{
                    do{
                    printf("\n1.agilidad: %i", *n1);
                    printf("\n2.agilidad: %i\n", *n2);
                    printf("\nElija su estadistica: ");
                    fflush(stdin);
                    scanf("%i", &opcion);

                    switch(opcion)
                    {
                    case 1:
                        j1.agilidad = *n1;
                        printf("\nUSTED RECIBE %i PUNTOS DE VOLNTAD\n", *n2);
                        j1.voluntad = *n2;
                        break;

                    case 2:
                        j1.agilidad = *n2;
                        printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n1);
                        j1.voluntad = *n1;
                        break;
                    default:
                        printf("\nUSTED AH ELEGIDO LA OPCION INCORRECTA, VUELVA A ELEGIR\n");
                    }
                    }while(opcion != 1 && opcion != 2);
                }
            }


     fwrite(&j1, sizeof(player), 1, archi);
    }
    fclose(archi);
}







///////////////////////////////////////////////////////////////////////////////////////////////
//Esta funcion, agrega un nuevo personaje al archivo, falta poner un limite para 3 personajes
////////////////////////////////////////////
void AgregarPlayer(char jugador[], int *n1, int *n2, int *n3)
{
    player j1;
    FILE *archi;
    int opcion = 0;

    archi = fopen(jugador, "ab");
    if(archi!= NULL)
    {
      do{
        printf("Ingrese el nombre del personaje: ");
        fflush(stdin);
        scanf("%s", &j1.nombre);

        printf("ELIJA SUS ESTADISTICAS DE ATAQUE: \n");
        printf("\n1.ataque: %i", *n1);
        printf("\n2.ataque: %i", *n2);
        printf("\n3.ataque: %i\n", *n3);

        printf("\nIngrese la opcion a elegir: ");
        fflush(stdin);
        scanf("%i", &opcion);

        switch(opcion)
        {
          case 1:
             j1.ataque = *n1;
             break;
         case 2:
            j1.ataque = *n2;
            break;
         case 3:
            j1.ataque = *n3;
            break;
         default:
             printf("\nUSTED A ELEGIDO LA OPCION INCORRECTA, VUELVA A SELECCIONAR\n");
             break;
        }
        }while(opcion!=1 && opcion!=2 && opcion!=3);




            printf("\n");
            printf("\nELIJA SUS ESTADISTICAS DE AGILIDAD\n");
            if(opcion == 1)
            {
               do{
                printf("\n1.agilidad: %i", *n2);
                printf("\n2.agilidad: %i\n", *n3);
                printf("\nElija su estadistica: ");
                fflush(stdin);
                scanf("%i", &opcion);
                switch(opcion)
                {
                case 1:
                    j1.agilidad = *n2;
                    printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n3);
                    j1.voluntad = *n3;
                    break;
                case 2:
                    j1.agilidad = *n3;
                     printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n2);
                     j1.voluntad = *n2;
                     break;
                default:
                    printf("\nUSTED A ELEGIDO LA OPCION INCORRECTA, VUELVA A ELEGIR\n");

                 }
               }while(opcion != 1 && opcion != 2);


            }
            else{
                if(opcion == 2)
                {
                   do{
                    printf("\n1.agilidad: %i", *n1);
                    printf("\n2.agilidad: %i\n", *n3);
                    printf("\nElija su estadistica: ");
                    fflush(stdin);
                    scanf("%i", &opcion);

                    switch(opcion)
                    {
                    case 1:
                        j1.agilidad = *n1;
                        printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n3);
                        j1.voluntad = *n3;
                        break;
                    case 2:
                        j1.agilidad = *n3;
                        printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n1);
                        j1.voluntad = *n1;
                        break;
                    default:
                        printf("\nUSTED AH ELEGIDO LA OPCION INCORRECTA, VUELVA A ELEGIR\n");
                    }
                   }while(opcion != 1 && opcion != 2);
                }
                else{
                    do{
                    printf("\n1.agilidad: %i", *n1);
                    printf("\n2.agilidad: %i\n", *n2);
                    printf("\nElija su estadistica: ");
                    fflush(stdin);
                    scanf("%i", &opcion);

                    switch(opcion)
                    {
                    case 1:
                        j1.agilidad = *n1;
                        printf("\nUSTED RECIBE %i PUNTOS DE VOLNTAD\n", *n2);
                        j1.voluntad = *n2;
                        break;

                    case 2:
                        j1.agilidad = *n2;
                        printf("\nUSTED RECIBE %i PUNTOS DE VOLUNTAD\n", *n1);
                        j1.voluntad = *n1;
                        break;
                    default:
                        printf("\nUSTED AH ELEGIDO LA OPCION INCORRECTA, VUELVA A ELEGIR\n");
                    }
                    }while(opcion != 1 && opcion != 2);
                }
            }


     fwrite(&j1, sizeof(player), 1, archi);
    }
    fclose(archi);
}













///////ESTA MUESTRA LOS ARCHIVOS///////////////////////////////////////
void Muestra(char jugador[])
{
    FILE* archi;
    player j1;
    archi = fopen(jugador, "rb");
    int i = 1;

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&j1, sizeof(player), 1, archi);
            if(!feof(archi))
            {
               Mostrar(j1);
            }
        }
        fclose(archi);
    }
}

void Mostrar(player j1)
{

    puts("\n------------------\n");
    printf("\NOMBRE: %s ", j1.nombre);
    printf("\nATAQUE: %d", j1.ataque);
    printf("\nAGILIDAD: %d", j1.agilidad);
    printf("\nVOLUNTAD: %d", j1.voluntad);
    puts("\n------------------\n");
}




///////////////////////////////////////////////////////////////
/////////ESTA FUNCION BUSCA A UN JUGADOR Y LO MUESTRA//////////7
/////////////////////////////////////////////////////////////////
void BuscarJugador(char jugador[], int *pos)
{
    FILE* archi;
    archi = fopen(jugador, "rb");
    player j1;
    if(archi != NULL)
    {
        fseek(archi, sizeof(player)*(*pos-1), 0);
        fread(&j1, sizeof(player), 1, archi);
        Mostrar(j1);
        fclose(archi);
    }
}



//////////////////////////////////////////////////////
///////////Modificar un archivos//////////////////////
///////////////////////////////////////////////////////

void ModificarPlayer(char jugador[], int *pos)
{
    int n1 = Dado8(n1);
    int n2 = Dado8(n2);
    int n3 = Dado8(n3);
    int opcion = 0;
    FILE *archi = fopen(jugador, "r+b");
    player j1;
    printf("1.Modidicar Nombre: \n");
    printf("2.Modificar atributos: \n");
    printf("\nIngrese la opcion a elegir: ");
    fflush(stdin);
    scanf("%i", &opcion);


    if(archi != NULL)
    {
        switch(opcion)
        {
        case 1:
            fseek(archi, sizeof(player)*(*pos-1), 0);
            fread(&j1, sizeof(player), 1, archi);
            j1 = ModificarNombre(j1);///Recibe el nombre modificado y los cambia por los que tenia
            fseek(archi, sizeof(player)*(*pos-1), 0);
            fwrite(&j1, sizeof(player), 1, archi);
            Mostrar(j1);
            fclose(archi);
            break;
        case 2:
            fseek(archi, sizeof(player)*(*pos-1),0);
            fread(&j1, sizeof(player), 1, archi);
            j1 = ModificarAtributos(j1);///Recibe los atributos modificados y los cambia por los que tenia
            fseek(archi, sizeof(player)*(*pos-1), 0);
            fwrite(&j1,sizeof(player), 1, archi);
            Mostrar(j1);
            fclose(archi);
            break;
        }

    }

}

/////MODIFICA LOS NOMBRES/////
player ModificarNombre(player j1)
{
    printf("Ingrese el nuevo nombre: ");
    fflush(stdin);
    scanf("%s", &j1.nombre);

    return j1;
}



/////////MODIFICA LOS ATRIBUTOS//////
player ModificarAtributos(player j1)
{
    int n1 = Dado8(n1);
    int n2 = Dado8(n2);
    int n3 = Dado8(n3);
    int opcion = 0;
    do{
        int opcion = 0;
        printf("\nELIJA SUS ESTADISTICAS DE ATAQUE\n");
        printf("\n1.ataque: %i", n1);
        printf("\n2.ataque: %i", n2);
        printf("\n3.ataque: %i", n3);
        printf("\nIngrese la opcion a elegir: ");
        fflush(stdin);
        scanf("%i", &opcion);
        switch(opcion)
        {
        case 1:
                j1.ataque = n1;
                do{
                    printf("\nELIJA SUS ESTADISTICAS DE AGILIDAD: \n");
                    printf("\n1.agilidad: %i", n2);
                    printf("\n2.agilidad: %i", n3);
                    printf("\nIngrese la opcion a elegir: ");
                    fflush(stdin);
                    scanf("%i", &opcion);
                    switch(opcion)
                    {
                    case 1:
                        j1.agilidad = n2;
                        j1.voluntad = n3;
                        printf("\nSU PERSONAJE RECIBIO %i PUNTOS DE VOLUNTAD\n", n3);
                        break;
                    case 2:
                        j1.agilidad = n3;
                        j1.voluntad = n2;
                        printf("\nSU PERSONAJE RECIBIO %i PUNTOS DE VOLUNTAD\n", n2);
                        break;
                    }

                }while(opcion > 2 && opcion > 0);
                break;
        case 2:
            j1.ataque = n2;
            do{
                printf("\nELIJA SUS ESTADISTICAS DE AGILIDAD: \n");
                printf("\n1.agilidad: %i", n1);
                printf("\n2.agilidad: %i", n3);
                printf("\nIngrese la opcion a elegir: ");
                fflush(stdin);
                scanf("%i", &opcion);
                switch(opcion)
                {
                case 1:
                    j1.agilidad = n1;
                    j1.voluntad = n3;
                    printf("SU PERSONAJE RECIBIO %i PUNTOS DE VOLUNTAD", n3);
                    printf("\nataque: %i", j1.ataque);
                    printf("\nagilidad: %i", j1.agilidad);
                    printf("\nvoluntad: %i", j1.voluntad);
                    break;
                case 2:
                    j1.agilidad = n3;
                    j1.voluntad = n1;
                    printf("SU PERSONAJE RECIBIO %i PUNTOS DE VOLUNTAD", n1);
                    break;
                }
            }while(opcion > 2 && opcion < 0);
            break;
        case 3:
            j1.ataque = n3;
            do{
                printf("\nEELIJA SUS ESTADISTICAS DE AGILIDAD: \n");
                printf("\n1.agilidad: %i", n1);
                printf("\n2.agilidad: %i", n2);
                printf("\nIngrese la opcion a elegir: ");
                fflush(stdin);
                scanf("%i", &opcion);
                switch(opcion)
                {

                    case 1:
                        j1.agilidad = n1;
                        j1.voluntad = n2;
                        printf("\nSU PERSONAJE RECIBIO %i PUNTOS DE VOLUNTAD\n", n2);
                        break;
                    case 2:
                        j1.voluntad = n2;
                        j1.voluntad = n1;
                        printf("\nSU PERSONAJE RECIBIO %i PUNTOS DE VOLUNTAD\n", n1);
                        break;
                }
            }while(opcion > 2 && opcion < 0);
            break;
        default:
               printf("\nA ELEGIDO LA OPCION INCORRECTA\n");
               break;





        }
    }while(opcion > 3 && opcion < 0);
    return j1;
}


///ELIMINAR UN ARCHIVO//////////////////////////////
void Buscareliminar(char archivo[], char temparchivo[])
{
    FILE *archi, *Temparchi;
    player j1[MAX_PLAYER];
    char playerNombre[30];
    int cont = 0;
    printf("Ingrese el nombre del player a eliminar: ");
    fflush(stdin);
    gets(playerNombre);
    archi = fopen(archivo, "rb");
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&j1, sizeof(player), 1, archi);
            if(!feof(archi))
            {
                cont++;
            }
        }
        fclose(archi);
    }
    printf("%i\n", cont);

    Temparchi= fopen(temparchivo, "wb");

    for(int i = 0; i < cont; i++)
    {
        if(strcmp(j1[i].nombre, playerNombre) != 0)
        {
            fwrite(&j1[i], sizeof(player), 1, Temparchi);
        }
    }
    Muestra(temparchivo);
    fclose(Temparchi);

    /*remove(archivo);
    rename(temparchivo, archivo);*/


}

void EliminarTodo(char archivo[])
{
    FILE* archi;
    archi = fopen(archivo, "wb");
    fclose(archi);
}



