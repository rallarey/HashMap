/*
 * HashNode.cpp
 *
 *  Created on: May 4, 2020
 *      Author: 13027
 */




#include "hashMap.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



hashNode::hashNode(string s){
	keyword = s;
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(){
	keyword = "";
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(string s, string v){
	keyword = s;
	values = new string[100];
	values[0] = v;
	valuesSize = 100;
	currSize = 1;
}
void hashNode::addValue(string v) {
	// adding a value to the end of the value array associated
	// with a key

	if (currSize >= valuesSize) {
	       dblArray();
	}
	values[currSize] = v;
	currSize++;

}
void hashNode::dblArray() {
	// when the value array gets full, you need to make a new 
	// array twice the size of the old one (just double, no 
	//going to next prime) and then copy over the old values 
	//to the new values, then de-allocate the old array.  
	//Again, just copying over, no hash functions involved
	//here.

	string *doubleArray = new string[valuesSize * 2];
	for (int i = 0; i < valuesSize; i++){
		doubleArray[i] = values[i];
	}

	delete values;
	values = doubleArray;
	valuesSize = valuesSize * 2;

}

string hashNode::getRandValue() {
	//Every key has a values array - an array of words that 
	// follow that key in the text document.  You're going to 
	//randomly select one of those words and return it.  That 
	//will be the word that follows your key in your output 
	//function, and it will also be the next key.

	int i = rand() % currSize;
	return values[i];

}
