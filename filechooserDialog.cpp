/*!
 * \project_name BiM Encoder/Decoder
 * \file filechooserDialog.cpp
 * \brief Generic filechooser window functions
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 2013 August 2
 *
 * This software is published in LGPLv3.0
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
	} else {
		if (response == Gtk::RESPONSE_OK) {
			output_filename = ( (mimeType == 0)
					? 
						((genericFeatures::isExtension(get_filename(),"xml"))
						? get_filename()
						: get_filename()+".xml")
					: 
						((genericFeatures::isExtension(get_filename(),"bim"))
						? get_filename()
						: get_filename()+".bim")
					);
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

Glib::ustring filechooserDialog::getURIToFile
(
	void
)
{
	return get_uri();
}

std::vector<Glib::ustring> filechooserDialog::getURIToFiles
(
	void
)
{
	return get_uris();
}

Glib::ustring filechooserDialog::getURIToFolder
(
	void
)
{
	return get_current_folder_uri();
}
	
std::string filechooserDialog::getPathToFile
(
	void
)
{
	return get_filename();
}
	
std::vector<std::string> filechooserDialog::getPathToFiles
(
	void
)
{
	return (get_action() != Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER)
		? get_filenames()
		: genericFeatures::listFiles(get_filenames().at(0));
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
	// filter for any ebucore files
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
	// filter for any ebucore files
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	filter->set_name("Any BiM source");
	filter->add_mime_type("text/bim");//xml mime type
	filter->add_pattern("*.bim");
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
		case 1 : // BiM filter
		{
			setBiMFilter();
		} break;
		default : {} break;
	}
	setAllFilesFilter();
}
