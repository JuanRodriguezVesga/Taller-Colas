#include <stdlib.h>
#include <stdio.h>

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

void encolar(Nodo *&, Nodo *&, int);
int desencolar(Nodo *&);
bool colaVacia(Nodo *&);
void mostrarCola(Nodo *&);
void vaciarCola(Nodo *&, Nodo *&);
void sumaPromedio();
void menu();

/*Varibles globales*/
int suma=0, contador=0;

int main()
{
    system("color 0a");
    int numero, opcion;
    Nodo *delante = NULL;
    Nodo *atras = NULL;

    do{
        menu(); scanf("%d",&opcion);
        switch(opcion){
            case 1:
                printf("\tIngrese un numero a encolar: ");
                scanf("%d",&numero);
                encolar(delante,atras,numero);
                printf("\tSe encolo correctamente el numero %d\n\n", numero);
                system("pause");
                system("cls");
                break;

            case 2:
                if(colaVacia(delante)==true){
                    printf("\tLa pila esta vacia...\n\n");
                }else{
                   numero = desencolar(delante);
                   printf("\tSe desencolo el numero: %d\n\n", numero);
                }
                system("pause");
                system("cls");
                break;

            case 3:
                if(colaVacia(delante)==true){
                    printf("\tLa cola esta vacia...\n\n");
                }else{
                      printf("\tMOSTRANDO COLA...\n\n");
                      mostrarCola(delante);
                }
                system("pause");
                system("cls");
                break;

            case 4:
                if(colaVacia(delante)==true){
                    printf("\tLa cola esta vacia...\n\n");
                }else{
                    printf("\tVaciando la cola...\n");
                    vaciarCola(delante , atras);
                }
                system("pause");
                system("cls");
                break;

            case 5:
                sumaPromedio();
                system("pause");
                system("cls");
                break;

            case 6:
                exit(0);

                default: printf("\tOpcion invalida...\n");
        }
    }while(opcion!=6);


    return 0;
}

void menu(){
    printf("\tMENU DE COLAS\n\n");
    printf("1. Encolar\n");
    printf("2. Desencolar\n");
    printf("3. Mostrar Cola\n");
    printf("4. Vaciar Cola\n");
    printf("5. Suma y Promedio\n");
    printf("6. Salir\n");
    printf("\n\n\tIngrese opcion: ");
}

bool colaVacia(Nodo*& delante){
    if(delante==NULL){
        return true;
    }else{
        return false;
    }
}

void encolar(Nodo*& delante, Nodo*& atras, int numero){
    Nodo *nueva_cola;
    nueva_cola = new(struct Nodo);
    nueva_cola->dato=numero;
    suma+=numero;
    nueva_cola->siguiente=NULL;
     contador++;

    if(delante==NULL){
        delante = nueva_cola;
    }else{
        atras->siguiente = nueva_cola;
    }
    atras = nueva_cola;
}

int desencolar(Nodo*& delante){
    int n;
    Nodo *p_aux;

    p_aux = delante;
    n = p_aux->dato;
    suma-=p_aux->dato;
    contador--;
    delante = (delante)->siguiente;
    delete(p_aux);
    return n;
}

void mostrarCola(Nodo *& delante){
    Nodo *p_aux;
    p_aux=delante;
    while(p_aux!=NULL){
        printf("\t %d \n", p_aux->dato);
        p_aux = p_aux->siguiente;
    }
}

void vaciarCola(Nodo *& delante, Nodo *& atras){
    Nodo *p_aux, *r_aux;
    p_aux=delante;
    while(p_aux!=NULL){
        r_aux = p_aux;
        p_aux=p_aux->siguiente;
        delete(r_aux);
    }
    suma=0;
    contador=0;
    delante = NULL;
    atras = NULL;
}

void sumaPromedio(){
    printf("\n");
    printf("\tLa suma total de los numeros en la cola es: %d\n", suma);
    printf("\tEl promedio total es: %d\n", suma/contador);
}
