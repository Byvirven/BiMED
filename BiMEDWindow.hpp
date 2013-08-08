#ifndef CPP_BIMEDWINDOW_CLASS_H
#define CPP_BIMEDWINDOW_CLASS_H

/*!
 * project_name BiM Encoder/Decoder
 * \file BiMEDWindow.hpp
 * \brief Gtk:Window specifications of the BiM Encoder/Decoder
 * \details This class is used to launch a generic window to display the main window of the application
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 2 August 2013
 * \copyright This software is published in MPLv2.0
 *
 */

#include <iostream>

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/uimanager.h>
#include <gtkmm/stock.h>
#include <gtkmm/button.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/textbuffer.h>
#include <gtkmm/separator.h>

#include "filechooserDialog.hpp"
#include "genericAlertWindow.hpp"
#include "BiMEDEngine.hpp"
#include "AboutBiMED.hpp"


/*! \class BiMEDWindow
 * \brief This class is used to launch a generic window to display the main window of the application
 *
 * This class implements all generic functions which can be usefull to the BiM Encoder/Decoder or any of its components
 */

class BiMEDWindow : public Gtk::Window
{
public:

	/*!*
	* @fn BiMEDWindow(void)
	* @brief Class constructor
	* @brief The BiMEDWindow class constructor instantiates a new gtk window.
	* @param[in] void : none
	*/
	BiMEDWindow
	(
		void
	);
	
	/*!*
	* @fn ~BiMEDWindow(void)
	* @brief Class destructor
	* @brief The BiMEDWindow class will destroy this widget at the end of its life-cycle.
	* @param[in] void : none
	*/
	virtual ~BiMEDWindow
	(
		void
	);
	
protected:

	Glib::RefPtr<Gtk::UIManager> refUIManager; /*!< refUIManager Allow to build menus and toolbars from an XML description (not Glade) */
	Glib::RefPtr<Gtk::ActionGroup> refActionGroup; /*!< refActionGroup Allow to define menu items with action/events */
	Glib::RefPtr<Gtk::TextBuffer> toEncodeTextBuffer; /*!< toEncodeTextBuffer Define a multi-line buffer */
	Glib::RefPtr<Gtk::TextBuffer> toDecodeTextBuffer; /*!< toDecodeTextBuffer Define a multi-line buffer */
	
	

	/**
	* @fn void on_open_to_decode(void)
	* @brief This function will open a filechooser which will allow to the user to choose a file to open for decoding
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return nothing if all is right or an error at compilation time.
	*/
	void on_open_to_decode
	(
		void
	);

	/**
	* @fn void on_open_to_encode(void)
	* @brief This function will open a filechooser which will allow to the user to choose a file to open for encoding
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return nothing if all is right or an error at compilation time.
	*/
	void on_open_to_encode
	(
		void
	);

	/**
	* @fn void on_save_decoded(void)
	* @brief This function will open a filechooser which will allow to the user to save the decoded data as an xml file
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return nothing if all is right or an error at compilation time.
	*/
	void on_save_decoded
	(
		void
	);

	/**
	* @fn void on_save_encoded(void)
	* @brief This function will open a filechooser which will allow to the user to save the encoded data as an binary file
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return nothing if all is right or an error at compilation time.
	*/
	void on_save_encoded
	(
		void
	);

	/**
	* @fn void on_leave(void)
	* @brief This function will close and then destroy the application
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return nothing if all is right or an error at compilation time.
	*/
	void on_leave
	(
		void
	);

	/**
	* @fn void on_encode_clicked(void)
	* @brief This function will be called each time when the Encode button is clicked. Once released, the button will forward the data for encoding to the BiM Engine which will return the encoded data as an hexadecimal string. Finally, the string will be set into the encoded form.
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return nothing if all is right or an error at compilation time.
	*/
	void on_encode_clicked
	(
		void
	);

	/**
	* @fn void on_decode_clicked(void)
	* @brief This function will be called each time when the Decode button is clicked. Once released, the button will forward the data for decoding to the BiM Engine which will return the decoded data as a string. Finally, the string will be set into the decoded form.
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return nothing if all is right or an error at compilation time.
	*/
	void on_decode_clicked
	(
		void
	);

	/**
	* @fn void on_about(void)
	* @brief This function will display the about dialog window.
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return nothing if all is right or an error at compilation time.
	*/
	void on_about
	(
		void
	);
};

#endif /*CPP_BIMEDWINDOW_CLASS_H*/
