#pragma once
#include <string.h>

typedef struct DictionaryElement
{
	int hash;
	unsigned int memorySizeInInt;
	void *memoryPointer;
	int memory[1000];

} DictionaryElement;

typedef struct Key {

	long long value;
	size_t lenght;

}Key;

typedef struct Dictionary {

	unsigned long long numOfElements;
	Key key[10000];
	DictionaryElement elements[10000];

}Dictionary10000;


typedef struct Obj
{
	int hash;
	unsigned int memorySize;
	void *memoryPointer;
	int val;
	int memory[999];
} Obj;

Dictionary10000* AllocDictionary10000(unsigned int type);


int InitDictionary10000(Dictionary10000* dict);

int KeyExist(Dictionary10000* dict, Key k);


void InsertElement10000(Dictionary10000* dictionary, void* element, Key k);

DictionaryElement* GetElement(Dictionary10000* dict, Key k);

void RemoveElement(Dictionary10000* dict, Key k);

void RemoveElementFromHash(Dictionary10000* dict, DictionaryElement* element);