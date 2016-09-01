/* Author:            Youssef Almkari                                                */
/* Creation Date:     September 12th, 2014                                           */
/* Due Date:          September 18th, 2014                                           */
/* Course:            CSC237                                                         */
/* Professor Name:    Dr. Schaper                                                    */
/* Assignment:        #2                                                             */
/* File Name:         linklist.cxx                                                   */
/* Purpose:           The implementation of Dr.Schaper's linklist                    */

#include<iostream>


/** linklist Implementation **/

template<class T>linklist<T>::linklist() : headPointer(NULL) {}

template<class T>linklist<T>::linklist(const linklist<T>& original) {
	headPointer = NULL;
	node* otherPTR = original.headPointer;
	while(otherPTR != NULL) {
		insertEnd(otherPTR->dataItem);
		otherPTR = otherPTR->linkPointer;
	}
}

template<class T>linklist<T>linklist<T>::operator =(linklist<T> rhs) {
	headPointer = NULL;
	node* otherPTR = rhs.headPointer;
	while(otherPTR != NULL) {
		insertEnd(otherPTR->dataItem);
		otherPTR = otherPTR->linkPointer;
	}
	return *this;
}

template<class T>linklist<T>::~linklist() {
	removeAll();
}

template<class T>bool linklist<T>::isEmpty() const {
	return (headPointer == NULL);
}

template<class T>size_t linklist<T>::NumberOfItems() const {
	size_t count = 0;
	node* p = headPointer;
	while(p != NULL) {
		count++;
		p = p->linkPointer;
	}
	return count;
}

template<class T>void linklist<T>::insertFront(T anItem) {
	if(isEmpty())
		headPointer = new node(anItem, NULL);
	else {
		node* p = headPointer;
		headPointer = new node(anItem, p);
	}
}

template<class T>void linklist<T>::insertEnd(T anItem) {
	if(isEmpty()) 
		headPointer = new node(anItem, NULL);
	else {
		node* p = headPointer;
		while(p->linkPointer != NULL) {
			p = p->linkPointer;
		}
		p->linkPointer = new node(anItem, NULL);
	}
}

template<class T>void linklist<T>::insertByPosition(size_t index, T anItem) {
	if(isEmpty())
		insertFront(anItem);
	else if(index > NumberOfItems())
		insertEnd(anItem);
	else {
		size_t count = 1;
		node* p = headPointer;
		node* trailp = NULL;
		while(count != index) {
			trailp = p;
			p = p->linkPointer;
			count++;
		}
		trailp->linkPointer = new node(anItem,p);
	}
}

template<class T>void linklist<T>::swapDataItem(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template<class T>void linklist<T>::insertByValue(T anItem) {
	if(isEmpty() || anItem < headPointer->dataItem)
		headPointer = new node(anItem, headPointer);
	else {
		node* p = headPointer->linkPointer;
		node* trailp = headPointer;
		while(p != NULL && p->dataItem < anItem) {
			trailp = p;
			p = p->linkPointer;
		}
		trailp->linkPointer = new node(anItem, p);
	}
}

template<class T>T linklist<T>::peekFront() const {
	return (headPointer->dataItem);
}

template<class T>T linklist<T>::peekEnd() const {
	node* p = headPointer;
	while(p->linkPointer != NULL)
		p = p->linkPointer;
	return (p->dataItem);
}

template<class T>T linklist<T>::peekByPosition(size_t index) const {
	if(index > NumberOfItems())
		return peekEnd();
	else {
		size_t count = 1;
		node* p = headPointer;
		while(count != index) {
			p = p->linkPointer;
			count++;
		}
		return (p->dataItem);
	}
}

template<class T>size_t linklist<T>::peekByValue(T anItem) const {
	size_t index = 0;
	node* p = headPointer;
	while(p != NULL && p->dataItem != anItem) {
		index++;
		p = p->linkPointer;
	}
	if(p == NULL)
		return 0;
	else
		return ++index;
}

template<class T>void linklist<T>::removeFront() {
	node* p = headPointer;
	headPointer = headPointer->linkPointer;
	delete p;
}

template<class T>void linklist<T>::removeEnd() {
	if(NumberOfItems() == 1) {
		node* p = headPointer;
		headPointer = p->linkPointer;
		delete p;
	}
	else {
		node* p = headPointer;
		node* trailp = NULL;
		while(p->linkPointer != NULL) {
			trailp = p;
			p = p->linkPointer;
		}
		trailp->linkPointer = p->linkPointer;
		delete p;
	}
}

template<class T>void linklist<T>::removeByPosition(size_t index) {
	if(index > NumberOfItems())
		removeEnd();
	else {
		size_t count = 1;
		node* p = headPointer;
		node* trailp = NULL;
		while(count != index) {
			trailp = p;
			p = p->linkPointer;
			count++;
		}
		if(count == 1) {
			headPointer = p->linkPointer;
			delete p;
		}
		else {
		trailp->linkPointer = p->linkPointer;
		delete p;
		}
	}
}

template<class T>void linklist<T>::removeByValue(T anItem) {
if(headPointer->dataItem == anItem) {
		node* p = headPointer;
		headPointer = headPointer->linkPointer;
		delete p;
	}
	else {
		node* p = headPointer->linkPointer;
		node* trailp = p;
		while(p != NULL && p->dataItem != anItem) {
			trailp = p;
			p = p->linkPointer;
		}
		trailp->linkPointer = p->linkPointer;
		delete p;
	}
}

template<class T>void linklist<T>::removeAll() {
	while(headPointer != NULL) {
		node* doomed = headPointer;
		headPointer = headPointer->linkPointer;
		delete doomed;
	}
}

template<class T>void linklist<T>::print(std::ostream& outStream, char separator = '\n') const {
	size_t count = 0;
	while(count != NumberOfItems()) {
		count++;
		outStream << this->peekByPosition(count) << separator;
	}
}

template<class T>T const& linklist<T>::operator[](size_t position) const {
	size_t count = 1;
	node* p = headPointer;
	while(count != position) {
		p = p->linkPointer;
		count++;
	}
	return (p->dataItem);
}

template<class T>T& linklist<T>::operator[](size_t position) {
	size_t count = 1;
	node* p = headPointer;
	while(count != position) {
		p = p->linkPointer;
		count++;
	}
	return (p->dataItem);
}

template<class T>std::ostream& operator <<(std::ostream& outStream, linklist<T> list) {
	list.print(outStream, ' ');
	return outStream;
}
