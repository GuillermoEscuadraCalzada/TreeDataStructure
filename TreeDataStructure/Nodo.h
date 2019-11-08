#pragma once

template<class T>
class Nodo
{
public:
	Nodo<T>* parent;
	Nodo<T>* left;
	Nodo<T>* right;

	T value;
	Nodo(T vañ);
	~Nodo();
};

template<class T>
inline Nodo<T>::Nodo(T val)
{
	value = val;
	parent = left = right = nullptr;
}

template<class T>
inline Nodo<T>::~Nodo()
{
}
