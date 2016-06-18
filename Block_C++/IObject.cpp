#include <string.h>
#include <stdio.h>
#include "IObject.h"
#include "ScreenFunc.h"

IObject::IObject(int x, int y, char * shape){
	this->x = x;
	this->y = y;
	this->shape = new char[strlen(shape) + 1];
	strcpy(this->shape, shape);
}

IObject::~IObject(){
	delete[] shape;
}

void IObject::Render(){
	for (int i = 0; i < strlen(shape) / 2; i++){
		gotoxy((x + i * 2), y);
		printf("%.2s", shape);
	}
}
void IObject::Clear(){
	for (int i = 0; i < strlen(shape) / 2; i++){
		gotoxy((x + i * 2), y);
		printf("  ");
	}
}