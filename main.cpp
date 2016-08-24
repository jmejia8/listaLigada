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

		Nodo* aux = primero;

		while (aux != NULL){
			if (aux->dato > dato){

				if (aux->anterior == NULL){
					el_nuevo->siguiente = aux;
					aux->anterior = el_nuevo;
					primero = el_nuevo;
				}else{
					el_nuevo->siguiente = aux;
					el_nuevo->anterior = aux->anterior;
					// linea conflictiva
					aux->anterior->siguiente = el_nuevo;
				}


				// cout << "Dato: " <<  dato <<  "  agredado satisfactoriamente :D \n";
				return true;
			}

			aux = aux->siguiente;
		}

		ultimo->siguiente = el_nuevo;
		
		el_nuevo->anterior = ultimo;

		ultimo = el_nuevo;

		return true;
	}

	bool eliminar(int posicion){
		Nodo* aux = primero;

		if (posicion == 0) {
			primero = primero->siguiente;
			delete aux;

			if (primero == NULL)
				ultimo = NULL;

			return true;
		}



		for (int i = 0; aux != NULL; i++){
			if (posicion == i){

				if (aux->anterior == NULL)
					primero = aux->siguiente;

				if (aux->siguiente == NULL)
					ultimo = aux->anterior;


				aux->anterior->siguiente = aux->siguiente;
				aux->siguiente->anterior = aux->anterior;

				delete aux;
				return true;
			}

			aux = aux->siguiente;
		}

		return false;
	}

	void mostrar(){
		Nodo* aux = primero;

		while (aux != NULL){
			cout << aux->dato << ", ";
			aux = aux->siguiente;
		}

		cout << endl;
	}

	bool vaciarLista(){
		Nodo* actual = primero;
		Nodo* aux = primero;

		while (aux != NULL){
			actual = aux;
			aux = aux->siguiente;
			delete actual;
		}

		primero = NULL;
		ultimo =  NULL;

		cout << "La lista se borró satisfactoriamente." << endl;
		return true;
	}


};

void menu(){
	cout << "--------------------" << endl;
	cout << "\nElija una opción"   << endl;
	cout << "--------------------" << endl;
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
				cout << "Escribe un entero: ";
				cin >> opcion;
				elementos.insertar(opcion);
				break;
			case 2:
				elementos.mostrar();
				break;
			case 3:
				cout << "Escribe un entero: ";
				cin >> opcion;
				elementos.eliminar(opcion);
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

