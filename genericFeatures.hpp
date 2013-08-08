#ifndef CPP_GENERICFEATURES_CLASS_H
#define CPP_GENERICFEATURES_CLASS_H

/*!
 * \project_name BiM Encoder/Decoder
 * \file genericFeatures.hpp
 * \brief the generic features specifications
 * \details This class is used to define several generic functions useful to the application or any of projet classes without instantiate this class. Basically, all public functions are declared as static to avoid the class instanciation
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 2 August 2013
 * \copyright This software is published in MPLv2.0
 *
 */

#include <sstream>



/*! \class genericFeatures
 * \brief this class is used to define generic functions
 *
 * This class implements all generic functions which can be usefull to the application
 */

class genericFeatures {
public:

	/**
	 * @fn static std::string removePrefix(std::string str, std::string prefix)
	 * @brief Returns the portion of the string after the first string prefix
	 * @brief
	 * @note needs more documentation
	 * @param[in] std::string filename : The filename to modify
	 * @param[in] std::string prefix   : a prefix to remove
	 * @return std::string if all is right or an error at compilation time.
	 */
	static std::string removePrefix
	(
		std::string filename, 
		std::string prefix
	);

	/**
	 * @fn static std::string removeSuffix(std::string str, std::string suffix)
	 * @brief Returns the portion of the string after the first string suffix
	 * @brief
	 * @note needs more documentation
	 * @param[in] std::string filename : The filename to modify
	 * @param[in] std::string suffix   : a suffix to remove
	 * @return std::string if all is right or an error at compilation time.
	 */
	static std::string removeSuffix
	(
		std::string filename, 
		std::string suffix
	);
	
	/**
	 * @fn static std::string int2str(int futurestring)
	 * @brief Convert an int to a std::string
	 * @brief
	 * @note needs more documentation
	 * @param[in] int futurestring   : int to convert
	 * @return std::string if all is right or an error at compilation time.
	 */
	static std::string int2str
	(
		int futurestring
	);
	
	/**
	 * @fn static bool hasExtension(std::string filename)
	 * @brief This function will test if the input file has an extension.
	 * @brief
	 * @note needs more documentation
	 * @param[in] std::string filename : The filename to test
	 * @return std::string if all is right or an error at compilation time.
	 */
	static bool hasExtension
	(
		std::string filename
	);

	/**
	 * @fn static bool isExtension(std::string filename, std::string extension)
	 * @brief This function will test if the input string ends by the extension. The extension should come after a dot.
	 * @brief
	 * @note needs more documentation
	 * @param[in] std::string filename  : The filename to test
	 * @param[in] std::string extension : Extension file to test
	 * @return std::string if all is right or an error at compilation time.
	 */
	static bool isExtension
	(
		std::string filename, 
		std::string extension
	);

	/**
	 * @fn static bool fileExists(std::string filename)
	 * @brief This function will test if the input file exists.
	 * @brief
	 * @note needs more documentation
	 * @param[in] std::string filename : Path to the file to test
	 * @return std::string if all is right or an error at compilation time.
	 */
	static bool fileExists
	(
		std::string filename
	);

	/**
	 * @fn static bool isHexadecimal(std::string data)
	 * @brief This function will test if the string - data - is an hexadecimal string or not
	 * @brief
	 * @note needs more documentation
	 * @param[in] std::string data : String to check
	 * @return std::string if all is right or an error at compilation time.
	 */
	static bool isHexadecimal
	(
		std::string data
	);

	/**
	 * @fn static bool hasHexadecimalPrefix(std::string data)
	 * @brief This function will test if the string - data - has the hexadecimal prefix (0x or 0X) or not
	 * @brief
	 * @note needs more documentation
	 * @param[in] std::string data : String to check
	 * @return std::string if all is right or an error at compilation time.
	 */
	static bool hasHexadecimalPrefix
	(
		std::string data
	);
	
protected:
	
};
#endif
