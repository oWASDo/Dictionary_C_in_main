#pragma once
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "MainH.h"


Dictionary10000* AllocDictionary10000(unsigned int type) {

	//Allocation of one dictionary
	void* p = malloc(sizeof(Dictionary10000));
	//Clear allocation
	memset(p, 0, sizeof(Dictionary10000));
	//init dictionary
	InitDictionary10000((Dictionary10000*)p, type);
	//return pointer
	return p;

}

int InitDictionary10000(Dictionary10000* dict) {

	unsigned long long size = 10000;
	dict->numOfElements = size;
	return 0;
}

int KeyExist(Dictionary10000* dict, Key k) {
	int i = 0;
	for (i = 0; i < dict->numOfElements; i++)
	{
		if (dict->key[i].lenght == k.lenght) {
			void* pointer0 = &dict->key[i].value;
			void* pointer1 = &k.value;
			int ret = memcmp(pointer0, pointer1, k.lenght);
			if (ret == 0) {
				return 1;
			}
		}
	}
	return 0;
}

void InsertElement10000(Dictionary10000* dictionary, void* element, Key k) {

	if (KeyExist(dictionary, k) == 1)
	{
		printf("key already exist \n\n");
		return;
	}
	Dictionary10000* dict = dictionary;
	int i = 0;
	for (int i = 0; i < dict->numOfElements; i++)
	{
		if (dict->elements[i].hash == 0) {

			//initialize hash element
			dict->elements[i].hash = &dict->elements[i];

			//inizialize memory pointer
			dict->elements[i].memoryPointer = &dict->elements[i].memory;

			//inizialize memeory size
			dict->elements[i].memorySizeInInt = ((sizeof(DictionaryElement) - ((sizeof(int) * 2) + sizeof(long long))) / sizeof(int));



			DictionaryElement* el = (DictionaryElement*)element;
			int e = 0;
			//copy memory of element
			for (e = 0; e < dict->elements[i].memorySizeInInt; e++)
			{
				dict->elements[i].memory[e] = el->memory[e];
			}

			////////////////////////////
			//inizialize key
			dict->key[i].lenght = 4;
			dict->key[i].value = k.value;
			////////////////////////////
			break;
		}
	}
}

DictionaryElement* GetElement(Dictionary10000* dict, Key k) {

	int i = 0;
	for (i = 0; i < dict->numOfElements; i++)
	{
		if (dict->key[i].lenght == k.lenght) {
			void* pointer0 = &dict->key[i].value;
			void* pointer1 = &k.value;
			int ret = memcmp(pointer0, pointer1, k.lenght);
			if (ret == 0) {
				return &dict->elements[i];
			}
		}
	}
	return NULL;
}

void RemoveElement(Dictionary10000* dict, Key k) {

	int i = 0;
	for (i = 0; i < dict->numOfElements; i++)
	{
		void* pointer0 = &dict->key[i].value;
		void* pointer1 = &k.value;
		if (dict->key[i].lenght == k.lenght && memcmp(pointer0, pointer1, k.lenght) == 0) {

			memset(&dict->elements[i], 0, sizeof(DictionaryElement));
			memset(&dict->key[i], 0, sizeof(Key));

		}
	}
}

void RemoveElementFromHash(Dictionary10000* dict, DictionaryElement* element) {

	int i = 0;
	for (i = 0; i < dict->numOfElements; i++)
	{
		if (dict->elements[i].hash == element->hash) {
			memset(&dict->elements[i], 0, sizeof(DictionaryElement));
			memset(&dict->key[i], 0, sizeof(Key));
			break;
		}
	}
}