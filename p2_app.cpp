 /* Author:           Youssef Almkari                                                   */
/* Creation Date:     September 12th, 2014                                              */
/* Due Date:          September 23th, 2014                                              */
/* Course:            CSC237                                                            */
/* Professor Name:    Dr. Schaper                                                       */
/* Assignment:        #2                                                                */
/* File Name:         p2_app.cpp                                                        */
/* Purpose:           Application to test class 'linklist' and apply all of its methods */

#include "linklist.h"
#include "rational.h"
#include<iostream>


int main() {
	linklist<int> myList;                                            // Create linklist Object
	myList.insertFront(5);                                           // h -> 5 -> NULL
	myList.insertEnd(10);                                            // h -> 5 -> 10 -> NULL
	std::cout << myList;
}
