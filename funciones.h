#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>

using namespace std;

//DECLARACION DE FUNCIONES

void pedirNombre(string& nombre); //Asigna el nombre ingresado a una variable por referencia

void tirarDados(int vDados[], int tam); //Carga un vector de un tamaĂąo especificado con numeros aleatorios 1-6

void mostrarDados(int vDados[], int tam); //Muestra los valores obtenidos

void jugar(int puntajeObjetivo, int lanzamientosPorRonda, int cantidadDados); // Llama a las demas funciones hasta que la partida termina

void mostrarMaxPuntuacion(string usuarioMaxPuntuacion, int maxPuntuacion); // Muestra la puntuacion maxima lograda y el usuario correspondiente

void mostrarInterfazTurno(string usuario, int ronda, int puntajeTotal, int maxPuntajeRonda, int nroLanzamiento); // Muestra la interfaz de usuario durante los lanzamientos

void mostrarInterfazEntreTurno(string usuario, int ronda, int puntajeTotal); // Muestra la interfaz del o los usuarios entre los turnos

void copiarTirarDados(int vDados[], int vDados2[],int tam );//Copia la funcion tirar dados

//FUNCIONES DE CALCULO DE PUNTOS

int sumarDados(int vDados[]);
void ordenarDados(int vDados[], int tam);
bool escalera(int vDados[], int tam);
bool seisDeSeis(int vDados[]);
bool seisIguales(int vDados[]);

int calcularPuntos(int vDados[], int tam); // Devuelve los puntos segun las combinaciones de los dados


//IMPLEMENTACION DE FUNCIONES

void pedirNombre(string& nombre){
    system("cls");
    cout << "Ingresar nombre del jugador: ";
    cin >> nombre;
    system("cls");
}

void tirarDados(int vDados[], int tam){
    for(int i = 0; i < tam; i++){
        vDados[i] = (rand() % 6) + 1;
        //PRUEBA
        //cout << "Dado " << i+1 << " - " << vDados[i] << endl;
    }
}

void mostrarDados(int vDados[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << "Dado " << i+1 << " - " << vDados[i] << endl;
    }
}

void mostrarInterfazTurno(string usuario, int ronda, int puntajeTotal, int maxPuntajeRonda, int nroLanzamiento){
    system("cls");

    cout<<"TURNO DE " << usuario;
    cout<<"  |  ";
    cout<<"RONDA Nro " << ronda;
    cout<<"  |  ";
    cout<<"PUNTAJE TOTAL: "<< puntajeTotal <<" PUNTOS"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"MAXIMO PUNTAJE DE LA RONDA: "<< maxPuntajeRonda <<" PUNTOS"<<endl;
    cout<<"LANZAMIENTO Nro " << nroLanzamiento << endl;
    cout<<"-------------------------------------------------------------------"<<endl;
}

void mostrarInterfazEntreTurno(string usuario, int ronda, int puntajeTotal){
    system("cls");

    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<<"'                                                         '"<<endl;
    cout<<"'                     RONDA Nº                            '"<<endl;
    cout<<"'                PROXIMO TURNO: JAVIER                    '"<<endl;
    cout<<"'                                                         '"<<endl;
    cout<<"'               PUNTAJE MARTA: 70 PUNTOS                  '"<<endl;
    cout<<"'                                                         '"<<endl;
    cout<<"'               PUNTAJE JAVIER: 70 PUNTOS                 '"<<endl;
    cout<<"'                                                         '"<<endl;
    cout<<"'- - - - - - - - - - - - - - - - - - - - - - - - - - - - -'"<<endl;

    system("pause");
}

int sumarDados(int vDados[]) {
    int suma = 0;
    for (int i = 0; i < 6; i++) {
        suma += vDados[i];
    }
    return suma;
}

void ordenarDados(int vDados[], int tam) {
    int i, j, posmin, aux;
    for (i = 0; i < tam - 1; i++) {
        posmin = i;
        for (j = i + 1; j < tam; j++) {
            if (vDados[j] < vDados[posmin]) posmin = j;
        }
        aux = vDados[i];
        vDados[i] = vDados[posmin];
        vDados[posmin] = aux;
    }
}

bool escalera(int vDados[], int tam) {
    int vDadosCopia[tam];  //CREA UNA COPIA DEL VECTOR DADOS
    copiarTirarDados(vDados, vDadosCopia, tam);
    ordenarDados(vDadosCopia, tam); //ORDENA LA COPIA PARA VERIFICAR SI HAY ESCALERA, SIN AFECTAR EL VECTOR ORIGINAL
    int contador = 0;
    for (int i = 0; i < 6; i++){
        if (vDadosCopia[i] == i + 1) {
            contador++;
        }
    }

    if (contador == 6){
        //cout << "escalera" << endl; //PRUEBA
        return true;
    }
    else
    {
        return false;
    }
}

bool seisDeSeis(int vDados[]) {
    int contador = 0;
    for (int i = 0; i < 6; i++)
    {
        if (vDados[i] == 6) {
            contador++;
        }
    }
    if (contador == 6)
    {
    //cout << "Seis dados 6" << endl; //PRUEBA
        return true;
    }
    else
    {
        return false;
    }
}

bool seisIguales(int vDados[]) {
    int repetidos = 0;
    for (int i = 1; i < 6; i++)
    {
        if (vDados[i] == vDados[i - 1])
        {
            repetidos++;
            //cout << "Una repeticion entre indices " << i << " y " << i-1 << endl; //PRUEBA
        }
    }
    if (repetidos == 5)
    {
    //cout << "Seis dados iguales" << endl; //PRUEBA
        return true;
    }
    else
    {
        return false;
    }
}

int calcularPuntos(int vDados[], int tam, int puntajeObjetivo) {
    int calculo = -1;

    if(escalera(vDados, tam)){
        calculo = puntajeObjetivo;
    }
    else if (seisDeSeis(vDados)){
        //Seis dados SEIS, devuelve 0
        calculo = 0;
    }
    else if (seisIguales(vDados)){
        //Seis dados IGUALES, devuelve valor repetido * 10
        calculo = vDados[0] * 10;
    }
    else{
        //Sumar todos los dados
        calculo = sumarDados(vDados);
    }

    return calculo;
}

void jugar(int puntajeObjetivo, int lanzamientosPorRonda, int cantidadDados, int vDados[]){
    string nombreJugador;
    pedirNombre(nombreJugador);

    int puntajeTotal = 0, ronda = 1; //Inicialización de variables
    int puntajeLanzamiento;

    //CICLO DE RONDAS
    while(puntajeTotal < puntajeObjetivo){
        int maxPuntajeRonda = 0;
        system("cls");
        //CICLO DE LANZAMIENTOS DE DADOS
        for(int i = 0; i < lanzamientosPorRonda; i++){
            tirarDados(vDados, cantidadDados);
            puntajeLanzamiento = calcularPuntos(vDados, cantidadDados, puntajeObjetivo);

            if(puntajeLanzamiento == puntajeObjetivo){ //Si hay escalera, gana la partida
                maxPuntajeRonda = puntajeLanzamiento;
                mostrarInterfazTurno(nombreJugador, ronda, puntajeTotal, maxPuntajeRonda, i+1);
                mostrarDados(vDados, cantidadDados);
                cout << "\nESCALERA!" << endl;
                break; //Sale del ciclo for
            }
            else if(puntajeLanzamiento == 0){ //Si hay seis 6, resetea el puntaje a 0
                maxPuntajeRonda = puntajeLanzamiento;
                puntajeTotal = 0;
                mostrarInterfazTurno(nombreJugador, ronda, puntajeTotal, maxPuntajeRonda, i+1);
                mostrarDados(vDados, cantidadDados);
                cout << "\nSEIS DE SEIS! TU PUNTAJE TOTAL FUE REINICIADO A CERO!\n" << endl;
                system("pause");
                continue; //Pasa a la siguiente iteración
            }
            else if(puntajeLanzamiento > maxPuntajeRonda)
                maxPuntajeRonda = puntajeLanzamiento;

            mostrarInterfazTurno(nombreJugador, ronda, puntajeTotal, maxPuntajeRonda, i+1);
            mostrarDados(vDados, cantidadDados);

            system("pause");
        }
        puntajeTotal += maxPuntajeRonda;
        cout << "\nFIN DE LA RONDA NRO. " << ronda << "  |  PUNTAJE SUMADO: " << maxPuntajeRonda << endl;
        ronda++;
        system("pause");
    }

    cout << "\nFELICIDADES " << nombreJugador << "! GANASTE LA PARTIDA!" << endl;
    cout << "PUNTAJE FINAL: " << puntajeTotal << endl;
}

void copiarTirarDados(int vDados[], int vDados2[],int tam )
{
    //cout<<"La copia del los dados es: ";
    int i;
    for(i=0; i<tam; i++)
    {
        vDados2[i]=vDados[i];
        //cout<<vDados2[i]<<"\t";
    }
}

void mostrarMaxPuntuacion(string usuarioMaxPuntuacion, int maxPuntuacion) {
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "                                                           " << endl;
    cout << "                   MAXIMA PUNTUACION                       " << endl;
    cout << "                                                           " << endl;
    cout << "              JUGADOR: "<< usuarioMaxPuntuacion<< endl;
    cout << "                                                           " << endl;
    cout << "              PUNTOS: " << maxPuntuacion << " PUNTOS" << endl;
    cout << "                                                           " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

#endif // FUNCIONES_H_INCLUDED
