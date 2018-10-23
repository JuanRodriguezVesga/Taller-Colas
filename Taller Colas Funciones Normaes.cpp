#include <stdlib.h>
#include <stdio.h>


struct Nodo{
    int Nro;
    struct Nodo *siguiente;
};

void encolar(Nodo *&, Nodo *&, int);
int desencolar(Nodo *&);
bool colaVacia(Nodo *&);
void mostrarCola(Nodo *&);
void vaciarCola(Nodo *&, Nodo *&);
void menu();

int main()
{
    
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

                default: printf("\tOpcion invalida...\n");
        }
    }while(opcion!=5);


    return 0;
}

void menu(){
    printf("Menu De Colas\n\n");
    printf("1. Encolar\n");
    printf("2. Desencolar\n");
    printf("3. Mostrar Cola\n");
    printf("4. Vaciar Cola\n");
    printf("5. Salir\n");
    printf("Ingrese opcion: ");
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
    nueva_cola->Nro=numero;
    nueva_cola->siguiente=NULL;

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
    n = p_aux->Nro;
    delante = (delante)->siguiente;
    delete(p_aux);
    return n;
}

void mostrarCola(Nodo *& delante){
    Nodo *p_aux;
    p_aux=delante;
    while(p_aux!=NULL){
        printf("\t %d \n", p_aux->Nro);
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
    delante = NULL;
    atras = NULL;
}
