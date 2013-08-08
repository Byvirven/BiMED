/*!
 * \project_name BiM Encoder/Decoder
 * \file filechooserDialog.cpp
 * \brief Generic filechooser window functions
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 2013 August 2
 * \copyright This software is published in MPLv2.0
 *
 */

#include "filechooserDialog.hpp"

filechooserDialog::filechooserDialog
(
	Gtk::Window& parent, 
	const Glib::ustring& title, 
	Gtk::FileChooserAction action, 
	Glib::ustring currentFolder,
	bool multipleSelection,
	unsigned int mimeType
) 
: 
	 Gtk::FileChooserDialog (parent, title, action)
{
	// append filechooser buttons and linked events
	add_button
	(
		Gtk::Stock::CANCEL, 
		Gtk::RESPONSE_CANCEL
	);
	add_button
	(
		Gtk::Stock::OK, 
		Gtk::RESPONSE_OK
	);
	// set the path to folder of the application as current folder
	set_current_folder(currentFolder);
	// Allow the selection of several files
	set_select_multiple(multipleSelection);
	// ask confirmation before overwrite an existing file
	if (action == Gtk::FILE_CHOOSER_ACTION_SAVE)
		set_do_overwrite_confirmation(true);
	// mime type file filter
	setFilters(mimeType);
	// run the filechooser and grab the result
	response = run();
	// alert dialog
	if (action != Gtk::FILE_CHOOSER_ACTION_SAVE) {
		if (response == Gtk::RESPONSE_OK and 
		!genericFeatures::fileExists(get_filename()))
		{
			genericAlertWindow * AC = new genericAlertWindow
			(
				*this, 
				"File error" , 
				"The file you are trying to open does not exist"
			);
			delete AC;
		}
	}
}

filechooserDialog::~filechooserDialog
(
	void
)
{
}

int filechooserDialog::getResponse
(
	void
)
{
	return response;
}
	
std::string filechooserDialog::getPathToFile
(
	void
)
{
	return get_filename();
}

std::string filechooserDialog::getPathToFolder
(
	void
)
{
	return get_current_folder();
}

void filechooserDialog::setXMLFilter
(
	void
) 
{
	// filter for any xml files
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	filter->set_name("Any XML source");
	filter->add_mime_type("text/xml");//xml mime type
	filter->add_pattern("*.xml");
	// add the filters to the filechooser
	add_filter(filter);
}

void filechooserDialog::setBiMFilter
(
	void
) 
{
	// filter for any bin files
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	filter->set_name("Any BiM source");
	filter->add_mime_type("application/octet-stream");// RFC2046
	filter->add_pattern("*.bin");
	filter->add_pattern("*.txt");
	// add the filters to the filechooser
	add_filter(filter);
}


void filechooserDialog::setAllFilesFilter
(
	void
) 
{
	// no filter -> all files
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	filter->set_name("All files");
	filter->add_pattern("*");
	// add the filters to the filechooser
	add_filter(filter);
}

void filechooserDialog::setFilters
(
	unsigned int mimeType
)
{	
	switch (mimeType)
	{
		case 0 : // XML filter
		{
			setXMLFilter();
		} break;
		case 1 : // Octet-stream filter
		{
			setBiMFilter();
		} break;
		default : {} break;
	}
	setAllFilesFilter();
}
