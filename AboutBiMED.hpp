#ifndef CPP_ABOUTBIMED_CLASS_H
#define CPP_ABOUTBIMED_CLASS_H

/*!
 * \project_name BiM Encoder/Decoder
 * \file AboutBiMED.hpp
 * \brief Gtk::AboutDialog specifications of the BiM Encoder/Decoder
 * \details This class is used to launch a generic window to display information about the program like its logo, name, copyright, website and license
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 8 August 2013
 * \copyright This software is published in MPLv2.0
 *
 */

#include <gtkmm/aboutdialog.h>

#include "AboutBiMED.hpp"


/*! \class AboutBiMED
 * \brief This class is used to launch an about dialog window
 *
 * This class implements all generic functions which can be usefull for an about dialog window. Call it will launch an about dialog which will display the license, credits, copyright, version number, etc...)
 */

class AboutBiMED : public Gtk::AboutDialog
{
public:

	/*!*
	* @fn AboutBiMED(void)
	* @brief Class constructor
	* @brief The AboutBiMED class constructor instantiates a new Gtk::AboutDialog window.
	* @param[in] void : none
	*/
	AboutBiMED
	(
	);
	/*!*
	* @fn ~AboutBiMED(void)
	* @brief Class destructor
	* @brief The AboutBiMED class will destroy this widget at the end of its life-cycle.
	* @param[in] void : none
	*/
	virtual ~AboutBiMED
	(
		void
	);
	
protected:


};

#endif /*CPP_ABOUTBIMED_CLASS_H*/
