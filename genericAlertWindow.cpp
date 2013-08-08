/*!
 * \project_name BiM Encoder/Decoder
 * \file genericAlertWindow.cpp
 * \brief Generic alert window functions
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 7 August 2013
 * \copyright This software is published in MPLv2.0
 *
 */

#include "genericAlertWindow.hpp"

genericAlertWindow::genericAlertWindow
(
		Gtk::Window& alertParent,
	 	const Glib::ustring & alertTitle,
	 	std::string alertMessage
) 
: 
	 Gtk::MessageDialog (alertParent, alertTitle)
{
	set_secondary_text(alertMessage);
	run();
}

genericAlertWindow::~genericAlertWindow
(
	void
)
{
}
