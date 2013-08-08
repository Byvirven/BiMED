/*!
 * \project_name BiM Encoder/Decoder
 * \file BiMEDEngine.cpp
 * \brief Engine of the BiM Encoder/Decoder
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 7 August 2013
 *
 * This software is published in MPLv2.0
 *
 */

#include "BiMEDEngine.hpp"


std::string BiMEDEngine::readFile
(
	std::string file
)
{

	std::ifstream f(file);
	std::string str((std::istreambuf_iterator<char>(f)),
		              std::istreambuf_iterator<char>());
	return str;
}

void BiMEDEngine::writeFile
(
	std::string file,
	std::string data
)
{
	std::ofstream f(file);
	f << data;
}

std::string BiMEDEngine::readBinaryFile 
(
		std::string file
)
{
	// open a binary file for reading and set the cursor position at the end of file
	std::ifstream f(file, std::ios::in | std::ios::binary | std::ios::ate);
	size_t sizeOfBinary = f.tellg(); // get the length
	f.seekg(0, std::ios::beg); // set the pointer to the beginning
	std::string binaryXML("");
	f >> std::noskipws; // don't omit the "white spaces" c.f. ios_base -> isspace
	for (unsigned short i=0; i<sizeOfBinary; i++) {
		char byte; 
		f.seekg(i); // move the cursor at position i
		f >> byte; // get back the byte at position i
		binaryXML += hexToStr((unsigned short)(byte>>4))+hexToStr((unsigned short)(byte&0x0F));
	}
	f.close();
	return binaryXML;
}

std::string BiMEDEngine::convertTxtToBinary 
(
		std::string data
)
{
	unsigned int sizeOfData = data.size(); // get the length
	std::string binaryData("");
	for (unsigned int i=0; i<sizeOfData; i++) {
		binaryData += hexToStr((unsigned short)(data.at(i)>>4))+hexToStr((unsigned short)(data.at(i)&0x0F));
	}
	return binaryData;
}

std::string BiMEDEngine::convertBinaryToTxt 
(
		std::string data
)
{
	unsigned int size = data.size();
	std::string txtData("");
	for (unsigned int i = 0; i<(size/2);i++) {
		char byte = convertToBinary((unsigned char)data.at(2*i) ,(unsigned char)data.at((2*i)+1));
		txtData += byte;
	}
	return txtData;
}

void BiMEDEngine::writeBinaryFile 
(
		std::string file,
		std::string data
)
{
	std::ofstream f(file, std::ios::out | std::ios::binary);
	unsigned int size = data.size();
	for (unsigned int i = 0; i<(size/2);i++) {
		char byte = convertToBinary((unsigned char)data.at(2*i) ,(unsigned char)data.at((2*i)+1));
		f.write((char *)(&byte), sizeof(char));
	}
	f.close();
}

char BiMEDEngine::convertToBinary
(
	unsigned char HalfMSB,
	unsigned char HalfLSB
)
{
	unsigned char byte[] = {HalfMSB, HalfLSB};
	unsigned short converted = 0;
	unsigned int fullbytesize = 1;
	for (unsigned int i=0;i<=fullbytesize;i++) {
		switch(byte[i]) {
			case 49: converted += ((i==0) ? 16: 1); break;
			case 50: converted += ((i==0) ? 32: 2); break;
			case 51: converted += ((i==0) ? 48: 3); break;
			case 52: converted += ((i==0) ? 64: 4); break;
			case 53: converted += ((i==0) ? 80: 5); break;
			case 54: converted += ((i==0) ? 96: 6); break;
			case 55: converted += ((i==0) ? 112: 7); break;
			case 56: converted += ((i==0) ? 128: 8); break;
			case 57: converted += ((i==0) ? 144: 9); break;
			case 65: converted += ((i==0) ? 160: 10); break;
			case 66: converted += ((i==0) ? 176: 11); break;
			case 67: converted += ((i==0) ? 192: 12); break;
			case 68: converted += ((i==0) ? 208: 13); break;
			case 69: converted += ((i==0) ? 224: 14); break;
			case 70: converted += ((i==0) ? 240: 15); break;
			default: ;
		}
	}
	return (char)converted;
}

std::string BiMEDEngine::hexToStr
(
	unsigned short hex
)
{
	std::string converted;
	switch(hex) {
		case 1: converted = "1"; break;
		case 2: converted = "2"; break;
		case 3: converted = "3"; break;
		case 4: converted = "4"; break;
		case 5: converted = "5"; break;
		case 6: converted = "6"; break;
		case 7: converted = "7"; break;
		case 8: converted = "8"; break;
		case 9: converted = "9"; break;
		case 10: converted = "A"; break;
		case 11: converted = "B"; break;
		case 12: converted = "C"; break;
		case 13: converted = "D"; break;
		case 14: converted = "E"; break;
		case 15: converted = "F"; break;
		default: converted = "0" ;
	}
	return converted;
}
