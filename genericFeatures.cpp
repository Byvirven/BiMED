/*!
 * \project_name BiM Encoder/Decoder
 * \file genericFeatures.hpp
 * \brief the generic features
 * \details This class is used to define several generic functions useful to the application or any of projet classes without instantiate this class. Basically, all functions are declared here can be called from anywhere without instantiation
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 2 August 2013
 * \copyright This software is published in MPLv2.0
 *
 */


#include "genericFeatures.hpp"

std::string genericFeatures::removePrefix
(
	std::string filename, 
	std::string prefix
) 
{
	int firstindex = filename.find_first_of(prefix);
	// returns what comes after first string "prefix"	 
	return filename.substr (firstindex+prefix.size(),filename.size()-(firstindex+prefix.size()));
}

std::string genericFeatures::removeSuffix
(
	std::string filename, 
	std::string suffix
) 
{
	int lastindex = filename.find_last_of(suffix);
	// returns what comes after string "suffix"	 
	return filename.substr (lastindex+suffix.size(),filename.size()-(lastindex+suffix.size()));
}

std::string genericFeatures::int2str
(
	int futurestring
) 
{
	std::ostringstream oss;
	// write the output stream
	oss << futurestring;
	return oss.str();
}

bool genericFeatures::hasExtension
(
	std::string filename
) 
{
	// find last "."
	int lastindex = filename.find_last_of(".");
	// test if empty
	if (lastindex == -1) {
		return false;
	}
	// copy what comes after last dot
	std::string extension = filename.substr 
	(
		lastindex+1,
		filename.size()-(lastindex+1)
	);
	// if the length is superior to 1 character, true else false
	return (extension.size()>0) ? true : false ;
}

bool genericFeatures::isExtension
(
	std::string filename, 
	std::string extension
) 
{
	// find last "."
	int lastindex = filename.find_last_of(".");
	// copy what comes after last dot
	std::string str2 = filename.substr (lastindex+1,filename.size()-(lastindex+1));
	// loop through each character and makes it lower-case. 
	// stop at end of string (\0)
	for(int i = 0; str2[i] != '\0'; i++){
		str2[i] = tolower(str2[i]);
	}
	// return the result
	return (extension.compare(str2) == 0) ? true : false ;
}

bool genericFeatures::fileExists
(
	std::string filename
)
{
	std::ifstream f(filename.c_str());
	if (f.good()) {
		f.close(); return true;
	}
	f.close(); return false;
}

bool genericFeatures::isHexadecimal
(
	std::string data
)
{
	if (data.size() > 0) {
		bool hexPrefix = false;
		if (data.compare(0,2,"0x") == 0 or data.compare(0,2,"0X") == 0) {
			hexPrefix = !hexPrefix; 
		}
		
		if(data.find_first_not_of("0123456789abcdefABCDEF", ((hexPrefix)?2:0)) == std::string::npos) 
		{
			return true;
		} else {
			return false;
		} 
	}
	return false;
}

bool genericFeatures::hasHexadecimalPrefix
(
	std::string data
)
{
	bool hexPrefix = false;
	if (data.size() > 0) {
		if (data.compare(0,2,"0x") == 0 or data.compare(0,2,"0X") == 0) {
			hexPrefix = !hexPrefix; 
		}
	}
	return hexPrefix;
}

