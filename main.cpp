/*!
 * \project_name BiM Encoder/Decoder
 * \file main.cpp
 * \brief BiM Encoder/Decoder main file
 * \details In this file, we instanciate all required class 
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 20 august 2012
 * \copyright This software is published in MPLv2.0
 *
 */

/*!
 *
 * \mainpage BiM Encoder/Decoder documentation

This is the documentation of the BiM Encoder/Decoder
 *
 */

#ifdef __unix__
	#include "BiMEDWindow.hpp"
#endif

#ifdef _WIN32
	#include "stdafx.h"
	#include <windows.h>
	
	int main (int argc, char **argv);
	int WINAPI WinMain
	(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow
	)
	{
		return main (__argc, __argv);
	}
#endif
/**
* @fn int main (int argc, char *argv[])
* @brief This function loads the player design (all windows design).
* @brief \n \n
* @param[in] argc : Optional.
* @param[in] argv : Optional.
* @return nothing if all is right or gtkmm-critical error/segmentation fault
* @note This function and his documentation must be completed
*/
int main (int argc, char *argv[]) {
	Gtk::Main app(argc, argv);
	BiMEDWindow * BiMEncDec = new BiMEDWindow();
	Gtk::Main::run( *BiMEncDec );
	delete BiMEncDec;
	return 0;
}
