#define SDL_MAIN_HANDLED
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <SDL.h>
#include <SDL_render.h>


static const int value = 100;


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

	unsigned int KindOfDictionry;
	unsigned long long numOfElement;
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

int InitDictionary10000(Dictionary10000* dict, unsigned int type) {

	unsigned long long size = 10000;
	dict->numOfElement = size;
	dict->KindOfDictionry = type;
	return 0;
}

int KeyExist(Dictionary10000* dict, Key k) {
	int i = 0;
	for (i = 0; i < dict->numOfElement; i++)
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

	if(KeyExist(dictionary,k) == 1)
	{
		printf("key already exist \n\n");
		return;
	}
	Dictionary10000* dict = dictionary;
	int i = 0;
	for (int i = 0; i < dict->numOfElement; i++)
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
	for ( i = 0; i < dict->numOfElement ; i++)
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
	for (i = 0; i < dict->numOfElement; i++)
	{
		if (dict->key[i].lenght == k.lenght) {
			void* pointer0 = &dict->key[i].value;
			void* pointer1 = &k.value;
			int ret = memcmp(pointer0, pointer1, k.lenght);
			if (ret == 0) {
				memset(&dict->elements[i], 0, sizeof(DictionaryElement));
				memset(&dict->key[i],0,sizeof(Key));
			}
		}
	}
}

int main(int argc, const char **argv) {

	//////////////////////////////
	Dictionary10000* dict = AllocDictionary10000(5);

	Obj newObj;
	newObj.val = 10;

	Key key;
	key.lenght = 4;
	key.value = 50;

	//insert element in dictionary
	InsertElement10000(dict, &newObj, key);
	//////////////////////////////

	//////////////////////////////
	//see if there is element in dictionary
	Obj* ll = (Obj*)&dict->elements[0];
	printf("First test:\n");
	printf("	Key value: %llu  ", dict->key[0].value);
	printf("	Value: %llu\n\n", ll->val);
	//////////////////////////////

	//////////////////////////////
	//see if there is element in dictionary form function
	Obj* element = (Obj*)GetElement(dict, key);
	printf("Second test:\n");
	printf("	Value from function: %llu  \n\n", element->val);
	//////////////////////////////

	//////////////////////////////
	//remove element
	RemoveElement(dict, key);

	printf("Third test:\n");

	Obj* elementDelated = (Obj*)GetElement(dict, key);
	if (elementDelated == NULL) {
		printf("	return null because there isn't that value\n\n");
	}
	//////////////////////////////

	//////////////////////////////
	//insert element in dictionary another time
	InsertElement10000(dict, &newObj, key);

	Obj* object = (Obj*)&dict->elements[0];
	printf("Forth test:\n");
	printf("	Key value after remove: %llu  ", dict->key[0].value);
	printf("	Value after remove: %llu\n\n", object->val);

	Obj* elementAfterRemove = (Obj*)GetElement(dict, key);
	printf("Fifth test:\n");
	printf("	Value from function: %llu  \n\n", elementAfterRemove->val);
	//////////////////////////////

	//////////////////////////////
	//insert the same hey
	InsertElement10000(dict, &newObj, key);
	//////////////////////////////

	//////////////////////////////
	//insert another value with another key
	Obj newObjToInset;
	newObjToInset.val = 5;

	Key keyToInsert;
	keyToInsert.lenght = 4;
	keyToInsert.value = 25;

	InsertElement10000(dict, &newObjToInset, keyToInsert);

	Obj* elementAnother = (Obj*)GetElement(dict, keyToInsert);

	printf("Sixth test:\n");
	printf("	Value from function: %llu  \n\n", elementAnother->val);
	//////////////////////////////
	scanf_s("Press enter");

	return 0;
}