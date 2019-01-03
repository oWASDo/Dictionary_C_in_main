#define SDL_MAIN_HANDLED
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <SDL.h>
#include <SDL_render.h>
#include "MainH.h"

static const int value = 100;


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

	Obj* elementDeleted = (Obj*)GetElement(dict, key);
	if (elementDeleted == NULL) {
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
	free(dict);

	
	//////////////////////////////
	Dictionary10000* dictionary = AllocDictionary10000(5);

	Obj o;
	o.val = 50;

	Key chiave;
	chiave.lenght = 4;
	chiave.value = 11;

	//insert element in dictionary
	InsertElement10000(dictionary, &o, chiave);


	Obj* element0 = (Obj*)GetElement(dictionary, chiave);

	RemoveElementFromHash(dictionary, element0);


	printf("Senventh test:\n");
	printf("	Value from function: %llu  \n\n", element0->val);
	//////////////////////////////


	scanf_s("Press enter");

	return 0;
}