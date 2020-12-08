/*
 * HashMap.cpp
 *
 *  Created on: May 4, 2020
 *      Author: 13027
 */


#include "hashMap.hpp"
#include "hashNode.hpp"
#include <iostream>
#include <math.h>
using namespace std;

hashMap::hashMap(bool hash1, bool coll1) {

}

void hashMap::addKeyValue(string k, string v) {

}

int hashMap::getIndex(string k) {

}

int hashMap::calcHash2(string k){

}

int hashMap::calcHash1(string k){

}

void hashMap::getClosestPrime() {
	int doubleMap = mapSize * 2;
	int nextPrime = doubleMap;
	bool found = false;
	while (!found){
		// updates nextPrime and calls isPrime to see if the value is a prime number
		nextPrime++;
		if (isPrime(nextPrime)){
			found = true;
		}
	}
}

bool hashMap::isPrime(int x){
	// helper function to determine if the number is prime
	for (int i = 2; i <= x/2; i++){
		if (x % 1 == 0){
			return false;
		}
	}
	return true;
}

void hashMap::reHash() {

}

int hashMap::coll1(int h, int i, string k) {

}

int hashMap::coll2(int h, int i, string k) {

}

int hashMap::findKey(string k) {

//NOTE: THIS METHOD CANNOT LOOP from index 0 to end of hash array looking for the key.  That destroys any efficiency in run-time. 
}


void hashMap::printMap() {
	cout << "In printMap()" << endl;
	for (int i = 0; i < mapSize; i++) {
		//cout << "In loop" << endl;
		if (map[i] != NULL) {
			cout << map[i]->keyword << ": ";
			for (int j = 0; j < map[i]->currSize;j++) {
				cout << map[i]->values[j] << ", ";
			}
			cout << endl;
		}
	}
}


