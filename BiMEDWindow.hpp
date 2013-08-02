#ifndef CPP_BIMEDWINDOW_CLASS_H
#define CPP_BIMEDWINDOW_CLASS_H

/*!
 * project_name BiM Encoder/Decoder
 * \file BiMEDWindow.hpp
 * \brief Gtk:Window specifications of the BiM Encoder/Decoder
 * \details This class is used to launch a generic window to display the main window of the application
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 2 August 2013
 * \copyright GNU GPLv3
 *
 */

#include <gtkmm.h>
#include <gdkmm.h>
#include <iostream>
#include <string>
#include <fstream>

#include "filechooserDialog.hpp"

class BiMEDWindow : public Gtk::Window
{
public:

	/*!*
	* @brief Class constructor
	* @brief The genericAlertWindow class constructor instantiates a new dialog message.\n\n
	* @param[in] Gtk::Window& alertParent : The window which instantiates the dialog message
	* @param[in] const Glib::ustring alertTitle : The title of the dialog message window
	* @param[in] std::string alertMessage : The message to write into the dialog box
	*/
	BiMEDWindow
	(
	);
	
	virtual ~BiMEDWindow
	(
		void
	);
	
protected:

	Glib::RefPtr<Gtk::UIManager> m_refUIManager;
	Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
	Glib::RefPtr<Gtk::TextBuffer> toEncodeTextBuffer;
	Glib::RefPtr<Gtk::TextBuffer> toDecodeTextBuffer;
	
	void on_open_to_decode
	(
		void
	);

	void on_open_to_encode
	(
		void
	);

	void on_save_decoded
	(
		void
	);

	void on_save_encoded
	(
		void
	);

	void on_leave
	(
		void
	);

	void on_encode_decode
	(
		void
	);

	void on_about
	(
		void
	);
};

#endif /*CPP_BIMEDWINDOW_CLASS_H*/
