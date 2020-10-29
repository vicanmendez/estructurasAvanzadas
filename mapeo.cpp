#include <stdio.h>




// Tamaño del mapeo
const int TAM = 10;


// Cada item del mapeo contendrá el elemento a guardar y un booleano que indica si existe o no
typedef struct {
    bool existe;
    char * info;
} item;

//Cada posición del mapeo contendrá un item. Por lo que a cada item le corresponderá una posición
typedef item Mapeo[TAM];

void Crear (Mapeo &m)
{
    int i;
    for(i=0; i<TAM; i++)
    m[i].existe = false;
}


bool Pertenece (Mapeo m, int pos)
{
    return (m[pos].existe);
}

void Insertar (Mapeo &m, char * e, int pos)
{
    m[pos].existe = true;
    m[pos].info = e;
}

//Precondición: Pertenece(m,pos)
char * Obtener (Mapeo m, int pos)
{
return m[pos].info;
}

//Precondición: Pertenece(m,pos)
void Eliminar (Mapeo &m, int pos)
{
    m[pos].existe = false;
}

int main() {
    Mapeo m;
    int opc, pos;
    char * dato;
    do {
        printf("\t \t MAPEO \n \n 1-Crear \n 2-Ingresar dato \n 3-Obtener dato \n 4-Eliminar dato \n 0-Salir");
        scanf("%d", &opc);
        switch(opc) {
            case 1: Crear(m);
            break;

            case 2:
                printf("Ingresa el dato \n");
                scanf("%s", &dato);
                //printf("Has ingresado %s", &dato);
                printf("Ingresa la posición \n");
                scanf("%d", &pos);
                if(!Pertenece(m, pos)) {
                    Insertar(m, dato, pos);
                    printf("Dato guardado \n");
                } else {
                    printf("Ya existe un elemento en esa posición \n");
                }
                break;

            case 3:
                printf("Ingresa la posición a buscar \n");
                scanf("%d", &pos);
                if(!Pertenece(m, pos)) {
                    printf("No pertenece ningún dato a esa posición \n");
                } else {
                    char * palabra = Obtener(m, pos);
                    printf("El dato contenido en esa posición es %s \n", &palabra);
                }
                break;

            case 4:
                printf("Ingresa la posición a eliminar \n");
                scanf("%d", &pos);
                if(!Pertenece(m, pos)) {
                    printf("No pertenece ningún dato a esa posición \n");
                } else {
                    Eliminar(m, pos);
                    printf("Dato eliminado \n");
                }
                break;

            default:
                break;

        }
    }while(opc != 0);
}
