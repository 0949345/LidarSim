#include "Header.h"

void Header::generateHeader(int size) { //biggest part of the header can be hardcoded
    header[0] = 'MS3';
}

//  Getters & Setters

char Header::getHeaderIndex(int i){
    return header[i];
}

void Header::setHeaderIndex(int i, char value){
    header[i] = value;
}