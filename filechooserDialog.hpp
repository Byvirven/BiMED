#ifndef CPP_FILECHOOSERDIALOG_CLASS_H
#define CPP_FILECHOOSERDIALOG_CLASS_H

/*!
 * \project_name BiM Encoder/Decoder
 * \file filechooserDialog.hpp
 * \brief Generic filechooser window specification
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 2013 August 2
 * \copyright This software is published in MPLv2.0
 *
 */

#include <gtkmm/filechooserdialog.h>
#include <gtkmm/stock.h>
#include <glibmm/miscutils.h>

#include "genericFeatures.hpp"
#include "genericAlertWindow.hpp"

/*! \class filechooserDialog
 * \brief This class is used to launch a generic filechooser
 *
 * This class implements all generic functions which can be usefull for a generic filechooser. It allows us to define the title of the filechooser, the kind of action (open or save), the behavior of the filechooser and even the mime type which will constrain the filechooser itself.
 */

class filechooserDialog : public Gtk::FileChooserDialog
{
public:

	/*!*
	* @brief Class constructor
	* @brief The genericFilechooserWindow class constructor instantiates a new filechooser with alert messages required.\n\n
	* @param[in] Gtk::Window& parent : The parent window which instantiates the filechooser
	* @param[in] const Glib::ustring& title : The title of the filechooser message window
	* @param[in] Gtk::FileChooserAction action : The type of action supported by the FileChooser
	* @param[in] Glib::ustring currentFolder : Set the directory of entry of the filechooser
	* @param[in] bool multipleSelection : Allow the selection of several files
	* @param[in] int mimeType : Set the mime type filter \n\n
		0 : XML files\n\n 
		1 : BiM Files\n\n 
		Others: any file\n\n
	*/	
	filechooserDialog
	(
		Gtk::Window& parent, 
		const Glib::ustring& title, 
		Gtk::FileChooserAction action, 
		Glib::ustring currentFolder,
		bool multipleSelection,
		unsigned int mimeType = 0
	);
	
	/*!*
	* @fn ~filechooserDialog(void)
	* @brief Class destructor
	* @brief The filechooserDialog class will destroy this widget at the end of its life-cycle.
	* @param[in] void : none
	*/
	virtual ~filechooserDialog
	(
		void
	);

	/**
	* @fn int getResponse(void)
	* @brief This function will return the Gtk::ResponType of the filechooser
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return int if all is right or an error at compilation time.
	*/
	int getResponse
	(
		void
	);

	/**
	* @fn std::string getPathToFile(void)
	* @brief This function will return the path to the selected file
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return std::string if all is right or an error at compilation time.
	*/
	std::string getPathToFile
	(
		void
	);

	/**
	* @fn std::string getPathToFolder(void)
	* @brief This function will return the path to the selected folder
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return std::string if all is right or an error at compilation time.
	*/
	std::string getPathToFolder
	(
		void
	);
	
protected:

	int response; /*!< response the Gtk::ResponType selected by the user into the filechooser */
	
	/**
	* @fn void setXMLFilter(void)
	* @brief This function filters files whose mime type corresponds to XML files. All others mime types are excluded
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return void if all is right or an error at compilation time.
	*/
	void setXMLFilter
	(
		void
	);
	/**
	* @fn void setBiMFilter(void)
	* @brief This function filters files whose mime type corresponds to BiM files. All others mime types are excluded
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return void if all is right or an error at compilation time.
	*/
	void setBiMFilter
	(
		void
	);

	/**
	* @fn void setAllFilesFilter(void)
	* @brief This functions defines the filter "All Files" ; this means all files are visible and accessible.
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return void if all is right or an error at compilation time.
	*/
	void setAllFilesFilter
	(
		void
	);
	
	/**
	* @fn void setFilters(int mimeType)
	* @brief This function allows you to set the appropriate mime types
	* @brief
	* @note needs more documentation
	* @param[in] int mimeType : this int defines the appropriate mime types
	* @note Values for mime types are : \n
	* \li \c \b 0 : Mimetypes for XML files
	* \li \c \b 1 : Mimetypes for BiM files
	* \li \c \b Others : By default, do nothing. 
	* @return nothning if all is right or an error at compilation time.
	*/
	void setFilters
	(
		unsigned int mimeType
	);

};

#endif /*CPP_FILECHOOSERWINDOW_CLASS_H*/
