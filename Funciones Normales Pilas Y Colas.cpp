//EJERCICIO DE MENU PILAS Y COLAS
#include <stdlib.h>
#include <stdio.h>


struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

//FUNCIONES PILA
void apilar(Nodo*&, int);
int desapilar(Nodo*&);
void cima(Nodo*&);
bool pilaVacia(Nodo *&);
void mostrarPila(Nodo*&);
void destruirPila(Nodo*&);
void menuPila();


void Menu();

//FUNCIONES COLA
void encolar(Nodo *&, Nodo *&, int);
int desencolar(Nodo *&);
bool colaVacia(Nodo *&);
void mostrarCola(Nodo *&);
void vaciarCola(Nodo *&, Nodo *&);
void menuCola();


int main(){
    
    Menu();

    return 0;
}


void Menu(){
    int opcion;
    do{
    printf("\tMENU DE GESTIONES\n\n");
    printf("\t1. Pilas\n");
    printf("\t2. Colas\n");
    printf("\t3. Salir\n");
    printf("\tIngrese una opcion: ");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            system("cls");
            menuPila();
            break;

        case 2:
            system("cls");
            menuCola();
            break;

        case 3:
            exit(0);
            break;

            default: printf("\tOpcion Invalida...\n");
          }
    }while(opcion!=3);
}

void menuPila(){
    Nodo *Cima = NULL;
    int x, opcion;
    do{
    printf("\tIMPLEMENTACION DE UNA PILA\n\n");
    printf("\t1. Apilar\n");
    printf("\t2. Desapilar\n");
    printf("\t3. Mostrar Pila\n");
    printf("\t4. Destruir Pila\n");
    printf("\t5. Mostrar Cima\n");
    printf("\t6. Salir\n");
    printf("\t Ingrese opcion: ");
    scanf("%d",&opcion);
        switch(opcion){
        case 1:
            printf("\n\n\t\tINGRESE UN NUMERO A APILAR: ");
            scanf("%d",&x);
            apilar(Cima, x);
            system("pause");
            system("cls");
            break;

        case 2:
            if(pilaVacia(Cima)!=true){
                x=desapilar(Cima);
                printf("\n\n\t\tNumero %d desapilado\n\n", x);
            }else{
                printf("\n\n\t\tLa pila esta vacia...\n\n");
            }
            system("pause");
            system("cls");
            break;

        case 3:
            printf("\n\n\t\tMOSTRANDO PILA\n\n");
            if(pilaVacia(Cima)!=true){
                mostrarPila(Cima);
            }else{
                printf("\n\n\t\tLa pila esta vacia...\n\n");
            }
            system("pause");
            system("cls");
            break;

        case 4:
            destruirPila(Cima);
            printf("\n\n\t\tLa pila esta destruida...\n\n");
            system("pause");
            system("cls");
            break;

        case 5:
            printf("\n\n\t\tMOSTRANDO CIMA\n\n");
            cima(Cima);
            system("pause");
            system("cls");
            break;

        case 6:
            system("cls");
            Menu();
            break;
        }
    }while(opcion!=6);

}

void apilar(Nodo *&Cima, int x){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato=x;
    nuevo_nodo->siguiente=Cima;
    Cima=nuevo_nodo;
    printf("\n\n\t\tEl dato %d se agrego correctamente a la pila\n", x);
}

bool pilaVacia(Nodo *&Cima){
    if(Cima==NULL){
        return true;
    }else{
        return false;
    }
}

void mostrarPila(Nodo *&Cima){
    Nodo *aux;
    aux=Cima;

    while(aux!=NULL){
        printf("\t\t %d\n", aux->dato);
        aux=aux->siguiente;
    }
}

void cima(Nodo*&Cima){
    int x;
    if(Cima==NULL){
        printf("\n\n\t\tLa pila esta vacia...\n\n");
    }else{
        x = Cima->dato;
        printf("\t %d\n", x);
    }
}

int desapilar(Nodo*&Cima){
    int x;
    Nodo *aux;
    if(Cima==NULL){
        printf("\n\n\t\tLa pila esta vacia...\n\n");
    }else{
        aux=Cima;
        x=aux->dato;
        Cima=Cima->siguiente;
        delete(aux);
    }
    return x;
}

void destruirPila(Nodo *&Cima){
    Nodo *aux;
    if(Cima==NULL){
        printf("\n\n\t\tLa pila esta vacia...\n\n");
    }else{
        while(Cima!=NULL){
            aux=Cima;
            Cima=Cima->siguiente;
            delete(aux);
        }
    }
}

void menuCola(){
    int numero, opcion;
    Nodo *delante = NULL;
    Nodo *atras = NULL;

    do{
    printf("\tMENU DE COLAS\n\n");
    printf("\t1. Encolar\n");
    printf("\t2. Desencolar\n");
    printf("\t3. Mostrar Cola\n");
    printf("\t4. Vaciar Cola\n");
    printf("\t5. Salir\n");
    printf("\n\n\tIngrese opcion: ");
    scanf("%d",&opcion);
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
                system("cls");
                Menu();
                break;

                default: printf("\tOpcion invalida...\n");
        }
    }while(opcion!=5);
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
    n = p_aux->dato;
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
    delante = NULL;
    atras = NULL;
}
