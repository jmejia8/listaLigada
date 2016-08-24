#include <iostream>

using namespace std;


class Nodo
{
public:
	int dato;

	Nodo* anterior = NULL;
	Nodo* siguiente = NULL;

};

class Lista
{
public:
	
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;

	bool insertar(int dato){
		Nodo* el_nuevo = new Nodo;

		el_nuevo->dato  = dato;

		if (primero == NULL){
			primero = el_nuevo;
			ultimo = el_nuevo;

			return true;
		}

		Nodo* actual = primero;

		while (actual != NULL){
			if (actual->dato > dato){

				if (actual->anterior == NULL){
					el_nuevo->siguiente = actual;
					actual->anterior = el_nuevo;
					primero = el_nuevo;
				}else{
					el_nuevo->siguiente = actual;
					el_nuevo->anterior = actual->anterior;
					// linea conflictiva
					actual->anterior->siguiente = el_nuevo;
				}


				// cout << "Dato: " <<  dato <<  "  agredado satisfactoriamente :D \n";
				return true;
			}

			actual = actual->siguiente;
		}

		ultimo->siguiente = el_nuevo;
		
		el_nuevo->anterior = ultimo;

		ultimo = el_nuevo;

		return true;
	}

	bool eliminar(int dato){
		Nodo* actual = primero;


		while (actual != NULL){
			if (actual->dato == dato){

				if (actual->anterior == NULL and actual->siguiente == NULL) {
					primero = NULL;
					ultimo = NULL;
					delete actual;
					return true;
				}

				// si el actual es el primero, cambiamos apuntador primero
				if (actual->anterior == NULL){
					primero = actual->siguiente;
					primero->anterior = NULL;
				}
				else
					actual->anterior->siguiente = actual->siguiente;

				// si el actual es el ultimo, cambiamos apuntador ultimo
				if (actual->siguiente == NULL){
					ultimo = actual->anterior;
					ultimo->siguiente = NULL;
				}
				else
					actual->siguiente->anterior = actual->anterior;

				delete actual;
				return true;
			}

			actual = actual->siguiente;
		}

		return false;
	}

	void mostrar(){
		cout << "-=====- L I S T A -=====-\n";
		Nodo* actual = primero;

		while (actual != NULL){
			cout << actual->dato << ", ";
			actual = actual->siguiente;
		}

		cout << "\n=========================\n\n";

	}

	bool vaciarLista(){
		Nodo* aux = primero;
		Nodo* actual = primero;

		while (actual != NULL){
			aux = actual;
			actual = actual->siguiente;
			delete aux;
		}

		primero = NULL;
		ultimo =  NULL;

		cout << "La lista se borró satisfactoriamente." << endl;
		return true;
	}


};

void menu(){
	cout << "\n\n===========================" << endl;
	cout << "\tElija una opción"   << endl;
	cout << "===========================" << endl;
	cout << "1. agregar" << endl;
	cout << "2. mostrar" << endl;
	cout << "3. eliminar elemento" << endl;
	cout << "4. eliminar todo\n" << endl;
	cout << "Elige: ";
}


int main(int argc, char const *argv[])
{

	Lista elementos;

	// muestra el menu

	int opcion;
	
	while(1){
		menu();
		cin >> opcion;
		
		switch(opcion){
			case 1:
				cout << "Escribe un entero para agregar: ";
				cin >> opcion;
				elementos.insertar(opcion)?
					cout << "Elemento agredado.\n" :
					cout << "Intente más tarde.\n";
				break;
			case 2:
				elementos.mostrar();
				break;
			case 3:
				elementos.mostrar();
				cout << "Escribe el elemento a eliminar: ";
				cin >> opcion;
				elementos.eliminar(opcion)?
					cout << "Lo eliminé correctamente.\n":
					cout << "Dato no existe.\n";
				break;
			case 4:
				elementos.vaciarLista();
				break;
			default:
				return 0;
		}	
	}

	cout << "\n\nsaliendo..." << endl;

	return 0;
}

