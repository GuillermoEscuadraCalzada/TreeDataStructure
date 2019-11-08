#pragma once
#include <iostream>
#include "Nodo.h"
using std::cout;
template<class T>
class Tree
{
public:
	Nodo<T>* root;
	Nodo<T>* last;
	int size;
	Tree();
	~Tree();

	void insert(T val);
	bool find(T val);
	Nodo<T>* delete_Node(T val);
	void printTree(Nodo<T>* arbol);
	void printTree(Nodo<T>* arbol, int contador);
	void printTree();
};

template<class T>
inline Tree<T>::Tree()
{
	root = last = nullptr;
	size = 0;
}

template<class T>
inline Tree<T>::~Tree()
{
}

template<class T>
inline void Tree<T>::insert(T val)
{

	if(root == nullptr) //La ra�z est� vac�a, por lo que se crea un nodo aqu�
	{
		root = new Nodo<T>(val); //Se crea un nuevo valor
		last = root;
		size++;
	}
	else
	{
		Nodo<T>* temp = root;
		while(root != nullptr)
		{
			if(root->value > val) //El valor de root actual es mayor al valor introducido
			{
				if(root->left == nullptr) //Left es nulo
				{
					root->left = new Nodo<T>(val); //Crea nodo aqu�
					root->left->parent = root; //Su padre es el root actual
					last = root->left; //Last se crea
					size++;
					break;
				}
				else //En caso de no ser nulo, avanza a esa posici�n y repite el ciclo
					root = root->left;
				//else if(root->left->value > val) //El valor de left es mayor al introducido
				//{
				//	root = root->left; //Avanza a left
				//}
				//else if(root->left->value < val) //El valor de left es menor
				//{
				//	root = root->left;
				//	//if(root->left->right == nullptr) //Si el que se encuentra a la derecha de left es nulo, pon un nodo ah�
				//	//{
				//	//	root->left->right = new Nodo<T>(val); //Crea un nodo aqu�
				//	//	root->left->right->parent = root->left; //El padre de este nodo es el a
				//	//	last = root->left->right; //Es el �ltimo en ser a�adido
				//	//	break;
				//	//}
				//	//else
				//	//{
				//	//	root = root->left->right; //root avanza a la derecha de su rama izquierda
				//	//}
				//}
			}
			else if(root->value < val) //El valor de la ra�z es menor al valor introducido
			{
				if(root->right == nullptr) //Si la rama de la derecha es nula
				{
					root->right = new Nodo<T>(val); //Crea el nodo aqu� 
					root->right->parent = root; //El padre de esta rama es 
					last = root->right; //se vuelve en la �ltima entrada
					size++;
					break;
				}
				else //En caso de no ser nulo, avanza a esa posici�n y repite el ciclo
					root = root->right;
				//else if(root->right->value > val)
				//{
				//	root = root->left;
				//}
				//else if(root->right->value < val)
				//{
				//	root = root->right;
				//	//if(root->right->right == nullptr)
				//	//{
				//	//	root->right->right = new Nodo<T>(val);
				//	//	root->right->right->parent = root->right;
				//	//}
				//}
			}
		}
		root = temp; //Root retoma el valor de temp


	}
}

template<class T>
inline bool Tree<T>::find(T val)
{
	if(root == nullptr) //Si es nulo, regresa falso
		return false;
	else if(root->value == val) //Si contiene el mismo valor, regresa verdadero
	{
		return true;
	}
	else //En caso de no estar en la ra�z, busca en las dem�s ramas
	{
		Nodo<T>* temp = root; //Guarda el valor de la ra�z
		while(root != nullptr)  //Avanza hasta ser nulo
		{
			if(root->value == val) //Si el valor de la ra�z es igual al introducido
			{
				root = temp;		//Root recupera su valor principal
				return true;		 //Regresa verdadero
			}
			else if(root->value > val&& root->left != nullptr) //Si el valor de root es mayor al introducido,
			{

				root = root->left; //Avanza a la izquierda
			}
			else if(root->value < val && root->right != nullptr) //Si el valor de root es menor al introducido
			{
				root = root->right; //Avanza a la derecha
			}
			else
			{
				root = temp; //Si es falso, recupera el valor original
				return false;
			}
		}
	}
}

template<class T>
inline Nodo<T>* Tree<T>::delete_Node(T val)
{
	if(root == nullptr)			//root es nula, no se puede borrar nada, no hay �rbol
		return root;			//Termina la funci�n
	else						//El �rbol tiene contenido,
	{
		Nodo<T>* temp = root;
		while(root != nullptr) //Avanza hasta chocar con nulo
		{

			if(root->value > val) //Si el valor de root es mayor al introducido, avanza a la izquierda
				root = root->left;
			else if(root->value < val)  //Si el valor de root es menor, avanza a la derecha
				root = root->right;

			else if(root->value == val && root->left == nullptr && root->right == nullptr) //La ra�z no tiene hijos
			{
				if(root->parent != nullptr)							//Si el padre es diferente de null, significa que el valor no se encuentra en la ra�z original
				{
					if(root->parent->right == root)					//Si el valor de la derecha del padre es esta ra�z, 
						root->parent->right = nullptr;				// la derecha del padre se vuelve nula

					else if(root->parent->left == root)				 //Si el valor de la izquierda del padre es esta ra�z, 
						root->parent->left = nullptr;				// la izquierda del padre se vuelve nula

					delete root; //Borra esta ra�z
					root = nullptr;
				}
				else //Si es la ra�z, s�lo borrala
				{
					delete root;			//Borra la ra�z
					root = nullptr;
				}
				size--; //Reduce el tama�o
				break;
			}
			else if(root->left == nullptr && root->value == val) //La ra�z s�lo tiene hijos a la izquierda
			{
				root->right->parent = root->parent;			 //El padre de la ra�z derecha de la ra�z actual, ser� el padre  de esta
				root->parent->right = root->right;			//La ra�z derecha del padre, se vuelve la ra�z derecha de la ra�z actual
				Nodo<T>* temp = root;						//Crea un nodo temporal
				root = root->right;							//La ra�z avanza a la derecha
				delete temp;								//Borrala 
				size--;									    //Reduce el tama�o
				break;
			}
			else if(root->right == nullptr && root->value == val) //La ra�z no tiene hijos a la derecha
			{
				root->left->parent = root->parent;  //El padre de la ra�z a la izquierda, es el padre de la actual
				root->parent->left = root->left;	//La ra�z izquierda del padre, se vuelve la ra�z izquierda de la ra�z actual
				Nodo<T>* temporal = root;			//Guarda el valor de esta ra�z
				root = root->left;					//Avanza a la izquierda
				delete temporal;				    //Borra temp
				size--;								//Reduce el tama�o
				break;
			}
		}
		root = temp;
	}
	return root;

}

template<class T>
inline void Tree<T>::printTree(Nodo<T>* arbol)
{
	if(arbol == nullptr)
		return;
	else
	{
		printTree(arbol->left);
		std::cout << arbol->value << " | ";
		printTree(arbol->right);
	}
}

template<class T>
inline void Tree<T>::printTree(Nodo<T>* arbol, int contador)
{
	if(arbol == nullptr)
		return;
	else
	{
		printTree(arbol->right, contador + 1);

		cout << "\n";
		for(int i = 0; i < contador; i++)
		{
			cout << "     ";
		}
		cout << arbol->value << "\n";

		printTree(arbol->left, contador + 1);
	}
}

template<class T>
inline void Tree<T>::printTree()
{
	if(root == nullptr)
		return;
	else
	{
		Nodo<T>* temp = root;
		while(root != nullptr)
		{
			if(root->left == nullptr && root->right == nullptr)
				cout << root->value << "\n";

			//else if(root)
		}
	}
}

