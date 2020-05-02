#include "Header.h"

void Header::generateHeader(int size) { //Biggest part of the header can be hardcoded
    header.datagram_marker = "MS3"; //TO DO: Wordt niet goed overgedragen
    header.protocol = "MD"; //TO DO: Wordt niet goed overgedragen
    header.version = 1.0;
    header.length = size;
}
void Header::generateHeaderNonFirst(int size, int prevSize, int prevOffset) { //biggest part of the header can be hardcoded
    header.datagram_marker = 1; //TO DO: Wordt niet goed overgedragen
    header.protocol = 2; //TO DO: Wordt niet goed overgedragen
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