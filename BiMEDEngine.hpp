#ifndef CPP_BIMEDENGINE_CLASS_H
#define CPP_BIMEDENGINE_CLASS_H

/*!
 * \project_name BiM Encoder/Decoder
 * \file BiMEDEngine.hpp
 * \brief Engine specifications of the BiM Encoder/Decoder
 * \details This class is used to execute the generic features of the application
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 7 August 2013
 * \copyright This software is published in MPLv2.0
 *
 */

#include <fstream>

/*! \class BiMEDEngine
 * \brief this class is used to define the BiM functions for encoding and decoding. 
 *
 * This class implements all generic functions which can be usefull for the encoding and decoding of data following the ISO/IEC:23001 standard (MPEG-B Part I : Binary MPEG format for XML) 
 */

class BiMEDEngine
{
	public:


		/**
		 * @fn static std::string readFile(std::string file)
		 * @brief This function will read a file character per character and will return a string with the content of the reading.
		 * @brief
		 * @note needs more documentation
		 * @param[in] std::string file : The path to the file to read
		 * @return std::string if all is right or an error at compilation time.
		 */
		static std::string readFile
		(
			std::string file
		);
		
		/**
		 * @fn static void writeFile(std::string file, std::string data)
		 * @brief This function will create or overwrite a file and then it will write the data inside the file. 
		 * @brief
		 * @note needs more documentation
		 * @param[in] std::string file : The path to the file to write
		 * @param[in] std::string data : The data to write
		 * @return std::string if all is right or an error at compilation time.
		 */
		static void writeFile
		(
			std::string file,
			std::string data
		);
		
		/**
		 * @fn static std::string readBinaryFile(std::string file)
		 * @brief This function will read a file byte per byte and will return a string with the content of the reading as an hexadecimal string.
		 * @brief
		 * @note needs more documentation
		 * @param[in] std::string file : The path to the file to read
		 * @return std::string if all is right or an error at compilation time.
		 */
		static std::string readBinaryFile 
		(
				std::string file
		);
		
		/**
		 * @fn static void writeBinaryFile(std::string file, std::string data)
		 * @brief This function will create or overwrite a file and then it will write the data byte per byte inside the file. 
		 * @brief
		 * @note needs more documentation
		 * @param[in] std::string file : The path to the file to write
		 * @param[in] std::string data : The data to write
		 * @return std::string if all is right or an error at compilation time.
		 */
		static void writeBinaryFile 
		(
				std::string file,
				std::string data
		);
		
		/**
		 * @fn static std::string convertTxtToBinary (std::string data)
		 * @brief This function will convert a string called "data" into its equivalent hexadecimal string.
		 * @brief
		 * @note needs more documentation
		 * @param[in] std::string data : the string to convert into hexadecimal
		 * @return std::string if all is right or an error at compilation time.
		 */
		static std::string convertTxtToBinary 
		(
				std::string data
		);

		/**
		 * @fn static std::string convertBinaryToTxt (std::string data)
		 * @brief This function will convert an hexadecimal string called "data" into its utf8 equivalent.
		 * @brief
		 * @note needs more documentation
		 * @param[in] std::string data : the hexadecimal string to convert into utf8 string
		 * @return std::string if all is right or an error at compilation time.
		 */
		static std::string convertBinaryToTxt 
		(
				std::string data
		);
	
	protected:

		
		/**
		 * @fn static char convertToBinary (unsigned char HalfMSB, unsigned char HalfLSB)
		 * @brief This function will convert an utf8 character into its hexadecimal equivalent.
		 * @brief
		 * @note needs more documentation
		 * @param[in] unsigned char HalfMSB : 4 MSB of the char
		 * @param[in] unsigned char HalfLSB : 4 LSB of the char
		 * @return char if all is right or an error at compilation time.
		 */
		static char convertToBinary
		(
			unsigned char HalfMSB,
			unsigned char HalfLSB
		);

		/**
		 * @fn static std::string hexToStr (unsigned short hex)
		 * @brief This function will convert a byte into its string equivalent.
		 * @brief
		 * @note needs more documentation
		 * @param[in] std::string data : the byte to convert into hexadecimal
		 * @return std::string if all is right or an error at compilation time.
		 */
		static std::string hexToStr
		(
			unsigned short hex
		);

};

#endif /*CPP_BIMEDENGINE_CLASS_H*/
