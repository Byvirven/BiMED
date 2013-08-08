#ifndef CPP_GENERICALERTWINDOW_CLASS_H
#define CPP_GENERICALERTWINDOW_CLASS_H

/*!
 * \project_name BiM Encoder/Decoder
 * \file genericAlertWindow.hpp
 * \brief Generic alert window specifications
 * \details This class is used to launch a generic dialog box where will be displayed the alert messages.
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 7 August 2013
 * \copyright This software is published in MPLv2.0
 *
 */

#include <gtkmm/messagedialog.h>


/*! \class genericAlertWindow
 * \brief This class is used to launch a simple alert message window
 *
 * This class implements all generic functions which can be usefull for a simple alert message window. To use it, the user shall define the parent of the alert window, the title of the alert window and its message
 */

class genericAlertWindow : public Gtk::MessageDialog
{
public:

	/*!*
	* @brief Class constructor
	* @brief The genericAlertWindow class constructor instantiates a new dialog message.\n\n
	* @param[in] Gtk::Window& alertParent : The window which instantiates the dialog message
	* @param[in] const Glib::ustring alertTitle : The title of the dialog message window
	* @param[in] std::string alertMessage : The message to write into the dialog box
	*/
	genericAlertWindow
	(
		Gtk::Window& alertParent,
	 	const Glib::ustring & alertTitle,
	 	std::string alertMessage
	);
	
	/*!*
	* @fn ~genericAlertWindow(void)
	* @brief Class destructor
	* @brief The genericAlertWindow class will destroy this widget at the end of its life-cycle.
	* @param[in] void : none
	*/
	virtual ~genericAlertWindow
	(
		void
	);
	
protected:

};

#endif /*CPP_GENERICALERTWINDOW_CLASS_H*/
