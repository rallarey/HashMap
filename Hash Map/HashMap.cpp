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
	oldMapSize = 11;
	map = new hashNode*[mapSize]();
	first = "";
	numKeys = 0;
	hashfn = hash1;
	collfn = coll1;
	hashcoll = 0;
	collisions = 0;

}

void hashMap::addKeyValue(string k, string v) {
	int index = getIndex(k);
	bool newIndex = true;
	int i = 1;

	if (map[index] == NULL){
		// add new hashnode with the strings

		hashNode *newNode = new hashNode(k,v);
		map[index] = newNode;
		numKeys++;

	} else if (map[index]->keyword == k){
		//call hashnode addvalue

		map[index]->addValue(v);

	} else if (map[index]->keyword != k){

		while (newIndex){ // if node has different keyword, keeps calculating new hash index

			hashcoll++;
			int collisionIndex;

			if(collfn){ // calculating new collision Index;
				collisionIndex = coll1(index, i, k);
				collisions++;
			} else {
				collisionIndex = coll2(index, i, k);
				collisions++;
			}

			if (map[collisionIndex] == NULL){  // checks if map at index is null, then adds node

				hashNode *newNode = new hashNode(k,v);
				map[collisionIndex] = newNode;
				numKeys++;
				newIndex = false;

			} else if (map[collisionIndex]->keyword == k){ // checks if keyword matches node index

				map[collisionIndex]->addValue(v);
				newIndex = false;
			}

			i++; // iteration

		}
	}

	if (numKeys *10 >= mapSize * 7){
		reHash();
	}
}

int hashMap::getIndex(string k) {
	int index;
	int collisionIndex;
	int i = 1;

	if (hashfn){ // uses hashfn (boolean) determining whether to use calc hash 1 or 2
		index = calcHash1(k);
		if (map[index] != NULL && map[index]->keyword != k){

			hashcoll++;

			if(collfn){ // uses collfn (boolean) determining whether to use coll 1 or 2
				collisionIndex = coll1(index, i, k);
				collisions++;
			} else {
				collisionIndex = coll2(index, i, k);
				collisions++;
			}

			if (map[collisionIndex] == NULL && map[collisionIndex]->keyword == k){
				return collisionIndex;
			}

			i++;

		} else if (map[index] == NULL && map[index]->keyword == k){
			return index;
		}
	} else {
		index = calcHash2(k);
		if (map[index] != NULL && map[index]->keyword != k){

			hashcoll++;

			if(collfn){
				collisionIndex = coll1(index, i, k);
				collisions++;
			} else {
				collisionIndex = coll2(index, i, k);
				collisions++;
			}

			if (map[collisionIndex] == NULL && map[collisionIndex]->keyword == k){
				return collisionIndex;
			}

			i++;

		} else if (map[index] == NULL && map[index]->keyword == k){
			return index;
		}
	}
}

int hashMap::calcHash2(string k){
	int key = 0;
	if (k.length() >= 3){
		key = (int(k[0]) + (27*int(k[1]))) + (pow(27,2)*int(k[2])); // pow(27,2) -> 27^2

	} else if (k.length() == 2){
		key = (int(k[0]) + (27*int(k[1])));

	} else if (k.length() == 1){
		key = int(k[0]);

	}
	return key % mapSize;

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
	int index;
	getClosestPrime();
	hashNode **newMap;
	newMap = new hashNode*[mapSize]();

	for (int i = 0; i < oldMapSize; i++){
		if(map[i] != NULL){
			index = getIndex(map[i]->keyword);
			newMap[index] = map[i];
		}
	}
}

int hashMap::coll1(int h, int i, string k) { // double hashing
	int key;
	if (hashfn){
		key = calcHash1(k);
	} else {
		key = calcHash2(k);
	}
	return (h + (i*(i+key))) % mapSize; // second hash
}

int hashMap::coll2(int h, int i, string k) { // linear probing
	int nextIndex = i+1;
	if (nextIndex >= mapSize){
		return 0;
	} else {
		return nextIndex;
	}
}

int hashMap::findKey(string k) {
	int index;
	index = getIndex(k);
	if(map[index]->keyword == k){
		return index;
	} else {
		return -1;
	}

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


