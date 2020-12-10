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
#include <string>
using namespace std;

hashMap::hashMap(bool hash1, bool coll1) {
	mapSize = 11;
	map = new hashNode*[mapSize]();
	first = "";
	numKeys = 0;
	hashfn = hash1;
	collfn = coll1;
	hashcoll = 0;
	collisions = 0;

}

void hashMap::addKeyValue(string k, string v) {

}

int hashMap::getIndex(string k) {

}

int hashMap::calcHash2(string k){
	int nextPrime = getClosestPrime();
	int key = 0;
	key = (k[0] + (27*k[1])) + (pow(27,2)*k[2]); // pow(27,2) -> 27^2
	return key;

	// treat first 3 characters of string as base-27 integer;

}

int hashMap::calcHash1(string k){
	int asciiSum = 0;
	int length = k.length(); // length of string

	for (int i = 0; i <= length; i++){
		asciiSum += int(k[i]); // casting a string to an int gets the ascii value
	}
	return asciiSum % mapSize; // mapSize gets changed to closest prime

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
	mapSize = nextPrime;
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


