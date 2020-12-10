#include <iostream>
#include <conio.h>
#include <stdlib.h>



using namespace std;

struct Nodo{
	int dato; // se declara los tipos de variables que se van a utilizar
	Nodo *der; // este funcion va a almacenar los dastos que se van a insertar
	Nodo *izq;	
};


// se crea un menu para poder realizar la operacion 
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int); // este metodo sirve para crear los nodos
void mostrarArbol(Nodo *,int);// esta metodo va tener dos parametros uno para el arbol y otro para el contador para que muestre los datos ingresados
bool busqueda(Nodo *,int); // se crea un metodo para la busqueda de los datos introducidos
void preOrden(Nodo *); // se crea un metodo para mostrar la lista de datos ingresados 

Nodo *arbol = NULL;

int main() { // se crea el metodo principal para la ejecucion del programa 
	menu(); // se imprime el menu
	
	getch(); // nos permitira guardar un valor en una variable que se vaya introducir
	return 0;// se retorna el valor de tipo 0
}

//se define una funcion de menu
void menu(){
	int dato,opcion,contador=0;
	// se inserta una setencia de control para la iteracion de nuestro metodo
	do{
	    cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostar el arbol completo"<<endl;
		cout<<"3. Buscar un elemento en el arbol"<<endl;
		cout<<"4. Recorrer el arbol en preorden"<<endl;
		cout<<"5. Salir"<<endl;
		cout <<"opcion: ";
		
		cin>>opcion;
		
	    switch(opcion){
			case 1: cout<<"\nDigite un numero: ";// se imprime el mensaje que desea el usurio realizar
			        cin>>dato;
			        insertarNodo(arbol,dato);// insertamos un nuevo nodo para agragarlo a nuestro codigo 
			        cout<<"\n"; // se inserta un salto de linea
			        system("pause");
			        break;
			case 2: cout<<"\nMostrando el arbol completo:\n\n";// se imprime un mensaje en pantalla que indica la accion que realiza nuestro metodo
			        mostrarArbol(arbol,contador);
			        cout<<"\n"; // se inserta un salto de linea
			        system ("pause");// el pause sirve para que nos permita ver el arbol plasmado
			        break;
			case 3: cout<<"\nDijite el elemento a busacar en el arbol: "; 
			        cin>>dato;
			        if(busqueda(arbol,dato) == true){// se utilizan una condicion para indicar si el valor esta dentro de los datos introducidos.
			        	cout<<"\nElemento "<<dato<<" a sido encontrado en el arbol\n";
					}
					else{
						cout<<"\nElemento no encontrado\n";// se imprime el mensaje para indicar que el elemento no esta dentro de los numeros introducidos
							
					}
					cout<<"\n";
					system ("pause");
					break;
			case 4:	cout<<"\nRecorrido en preorden: ";	
			        preOrden(arbol);
			        cout<<"\n\n";
			        system("pause");
			        break;
		}
		system("cls");
	}while(opcion != 5);
}

//se crea una funcion para crear un nuevo nodo
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}
// se crea un metodo con la funcion para insertar elemntos en el arbol
void insertarNodo(Nodo *&arbol,int n){
	if(arbol == NULL){ // se indica que si el arbol esta vacio
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;	
	}
	else{// se indica que si el arbol tiene un nodo o mas nodos
	    int valorRaiz = arbol->dato;// se  obtiene  el valor de la raiz que se va introduciendo
	    if(n < valorRaiz){// si el elemento es menor a la raiz, los valores se insertan en la izquierda
		    insertarNodo(arbol->izq,n);    
		}
		else{//si el elemento es mayor a la raiz,los valores se insertan en derecha
		    insertarNodo(arbol->der,n);
		}
	}

}
//se define una funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){//se indica  si el arbol esta vacio
		return;
	}  
	else{// si no se cumple la condicion , nos immprimira los datos que contiene el arbol
	    mostrarArbol(arbol->der,cont+1); // esta funcion nos sirve para imprimir todos los datos del arbol 
	    for(int i=0;i<cont;i++){// utilizamos un bucle desde  cero hasta que sea menor a contador 
		    cout<<"   " ;// se inserta un espacio para separar los datos del arbol
	   }
	   cout<<arbol->dato<<endl;// se imprime todo los datos del lado izquierdo
    	mostrarArbol(arbol->izq,cont+1);// se muestra los datos que contiene el arbol 
   }

}
//se crea una Funcion pra buscar un elemento en el arbol
bool busqueda (Nodo *arbol,int n){
	if(arbol == NULL){// se indica si el arbol esta vacio
	   return false;	
	}
	else if(arbol->dato == n){// se indica si no encuentra el elemento en el arbol entonces accedera a otro suceso
	    return true;
	}
	else if(n < arbol->dato){ // otro evento que se puede presentar al buscar los nodos
	    return busqueda(arbol->izq,n);	
	}  
	   
    else{
	    return busqueda(arbol->der,n);
	   	
	} 
 }
//se inserta el metodo con la  funcion para recorrido en modo preorden
void preOrden(Nodo *arbol){
	if(arbol == NULL){ // indica si la lista esta vacia 
		return;
	}
	else{// en el caso contrario de que no se cumpla la condicion 
		cout<<arbol->dato<<" - "; // se imprime la raiz del numero del inicio 
		preOrden(arbol->izq); // se llama de nuevo la funcion del metodo  preorden para recorrer el lado izquierdo del arbol 
		preOrden(arbol->der);
	}
}	         
	   


