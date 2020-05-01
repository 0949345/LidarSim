#include "Header.h"

void Header::generateHeader(int size) { //biggest part of the header can be hardcoded
    header.datagram_marker = 1; //TO DO: Needs edeting
    header.protocol = 2; //TO DO: Needs edeting
    header.version = 1.0;
    header.length = size;
}
void Header::generateHeader(int size, int prevSize, int prevOffset) { //biggest part of the header can be hardcoded
    header.datagram_marker = 1; //TO DO: Needs edeting
    header.protocol = 2; //TO DO: Needs edeting
    header.version = 1.0;
    header.length = size;
    header.fragment_offset = prevSize + prevOffset;
}

//  Getters & Setters

headerStruct Header::getHeader(){
    return header;
}

void Header::setHeader(headerStruct value){
    header = value;
}