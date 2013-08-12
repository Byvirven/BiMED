/*!
 * \project_name BiM Encoder/Decoder
 * \file BiMEDWindow.cpp
 * \brief Gtk:Window specifications of the BiM Encoder/Decoder
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 2 August 2013
 *
 * This software is published in MPLv2.0
 *
 */

//#include <glibmm/miscutils.h>
#include "BiMEDWindow.hpp"

BiMEDWindow::BiMEDWindow
(
	void
) 
{

	// configure the window
	set_title("BiMED : The EBU BiM Encoder/Decoder");
	#ifdef __unix__
		set_icon_from_file(Glib::get_current_dir()+"/img/BiMLogo.png");
	#endif
	#ifdef _WIN32
		set_icon_from_file(Glib::get_current_dir()+"\\img\\BiMLogo.png");
	#endif
	
	// instantiate the widgets
	Gtk::Box * vbox = manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,5));
	Gtk::ScrolledWindow * SWforTextEnc = manage(new Gtk::ScrolledWindow());
	Gtk::ScrolledWindow * SWforTextDec = manage(new Gtk::ScrolledWindow());
	Gtk::Separator * S1 = manage(new Gtk::Separator(Gtk::ORIENTATION_HORIZONTAL));
	Gtk::Separator * S2 = manage(new Gtk::Separator(Gtk::ORIENTATION_HORIZONTAL));
	Gtk::Separator * S3 = manage(new Gtk::Separator(Gtk::ORIENTATION_HORIZONTAL));
	Gtk::Button * encodeButton = manage(new Gtk::Button("Encode"));
	Gtk::Button * decodeButton = manage(new Gtk::Button("Decode"));
	Gtk::TextView * toEncode = manage (new Gtk::TextView());
	Gtk::TextView * toDecode = manage (new Gtk::TextView());
	
	
	// instantiate window menu
	refActionGroup = Gtk::ActionGroup::create();

	//File|New sub menu:
	refActionGroup->add(Gtk::Action::create("FileOpenToDecode",
		        Gtk::Stock::OPEN, "Open BiM", "Open a BiM file to decode"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_open_to_decode));

	refActionGroup->add(Gtk::Action::create("FileOpenToEncode",
		        Gtk::Stock::OPEN, "Open XML", "Open an XML file to encode"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_open_to_encode));

	refActionGroup->add(Gtk::Action::create("FileSaveDecoded",
		        Gtk::Stock::SAVE_AS, "Save XML", "Save the decoded result"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_save_decoded));
		    
	refActionGroup->add(Gtk::Action::create("FileSaveEncoded",
		        Gtk::Stock::SAVE_AS, "Save BiM", "Save the encoded result"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_save_encoded));

	//File menu:
	refActionGroup->add(Gtk::Action::create("FileMenu", "File"));
	//Sub-menu.
	refActionGroup->add(Gtk::Action::create("FileOpen", Gtk::Stock::OPEN));
	refActionGroup->add(Gtk::Action::create("FileSave", Gtk::Stock::SAVE_AS));
	refActionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
			sigc::mem_fun(*this, &BiMEDWindow::on_leave)
	);

	//Edit menu:
	refActionGroup->add(Gtk::Action::create("ActionMenu", "Action"));
	refActionGroup->add(Gtk::Action::create("Encode", 
					Gtk::Stock::EXECUTE, "Encode", "Encode the data text"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_encode_clicked));
	refActionGroup->add(Gtk::Action::create("Decode", 
					Gtk::Stock::EXECUTE, "Decode", "Decode the binary data"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_decode_clicked));

	//Help menu:
	refActionGroup->add( Gtk::Action::create("HelpMenu", "Help") );
	refActionGroup->add( Gtk::Action::create("HelpAbout", Gtk::Stock::HELP, "About BiMED", "Get more details about this application"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_about) );

	refUIManager = Gtk::UIManager::create();
	refUIManager->insert_action_group(refActionGroup);

	add_accel_group(refUIManager->get_accel_group());

	//Layout the actions in a menubar and toolbar:
	Glib::ustring ui_info = 
		  "<ui>"
		  "  <menubar name='MenuBar'>"
		  "    <menu action='FileMenu'>"
		  "      <menu action='FileOpen'>"
		  "        <menuitem action='FileOpenToDecode'/>"
		  "        <menuitem action='FileOpenToEncode'/>"
		  "      </menu>"
		  "      <separator/>"
		  "      <menu action='FileSave'>"
		  "        <menuitem action='FileSaveDecoded'/>"
		  "        <menuitem action='FileSaveEncoded'/>"
		  "      </menu>"
		  "      <separator/>"
		  "      <menuitem action='FileQuit'/>"
		  "    </menu>"
		  "    <menu action='ActionMenu'>"
		  "      <menuitem action='Encode'/>"
		  "      <menuitem action='Decode'/>"
		  "    </menu>"
		  "    <menu action='HelpMenu'>"
		  "      <menuitem action='HelpAbout'/>"
		  "    </menu>"
		  "  </menubar>"
		  "</ui>";

	try
	{
	 refUIManager->add_ui_from_string(ui_info);
	}
	catch(const Glib::Error& ex)
	{
	 std::cerr << "building menus failed: " <<  ex.what();
	}
	
	Gtk::Widget* pMenubar = refUIManager->get_widget("/MenuBar");
	
	// configure the widgets
	
	set_default_size(340, 550);
	set_has_resize_grip(true);
	vbox->set_spacing(5);
	vbox->set_homogeneous(false);
	vbox->set_border_width(8);
	
	SWforTextEnc->set_size_request(320, 198);
	SWforTextDec->set_size_request(320, 198);

	// configure the TextViews
	toEncode->set_pixels_above_lines(3);
	toEncode->set_left_margin(3);
	toEncode->set_right_margin(3);
	toEncode->set_editable(true);
  	toEncode->set_cursor_visible(true);
	toEncode->set_wrap_mode(Gtk::WRAP_WORD_CHAR);
	
	toEncodeTextBuffer = Gtk::TextBuffer::create();
 	toEncodeTextBuffer->set_text("Set the text to encode here");
	
	toEncode->set_buffer(toEncodeTextBuffer);
	//////////////////////////////////////////	
	toDecode->set_pixels_above_lines(2);
	toDecode->set_left_margin(2);
	toDecode->set_right_margin(2);
	toDecode->set_editable(true);
  	toDecode->set_cursor_visible(true);
	toDecode->set_wrap_mode(Gtk::WRAP_WORD_CHAR);

	toDecodeTextBuffer = Gtk::TextBuffer::create();
 	toDecodeTextBuffer->set_text("Set the text to decode here");

	toDecode->set_buffer(toDecodeTextBuffer);
	
	// configure the buttons
	encodeButton->signal_clicked().connect
	(
		sigc::mem_fun
		(
			*this,
			&BiMEDWindow::on_encode_clicked
		)
		
	);
	
	decodeButton->signal_clicked().connect
	(
		sigc::mem_fun
		(
			*this,
			&BiMEDWindow::on_decode_clicked
		)
		
	);
	
	// set the widget in his relative
	vbox->pack_start(*pMenubar, Gtk::PACK_SHRINK, 0);
	vbox->pack_start(*S1,Gtk::PACK_SHRINK, 0);
	vbox->pack_start(*SWforTextEnc,Gtk::PACK_EXPAND_WIDGET,0);
	vbox->pack_start(*encodeButton,Gtk::PACK_SHRINK,0);
	vbox->pack_start(*S2,Gtk::PACK_SHRINK,0);
	vbox->pack_start(*SWforTextDec,Gtk::PACK_EXPAND_WIDGET,0);
	vbox->pack_start(*decodeButton,Gtk::PACK_SHRINK,0);
	vbox->pack_start(*S3,Gtk::PACK_SHRINK,0);
	add(*vbox);
	SWforTextEnc->add(*toEncode);
	SWforTextDec->add(*toDecode);


		
	// show the widgets
	vbox->show();
	SWforTextEnc->show();
	SWforTextDec->show();
	S1->show();
	S2->show();
	S3->show();
	encodeButton->show();
	decodeButton->show();
	toEncode->show();
	toDecode->show();
	
	// show window's widgets
}

BiMEDWindow::~BiMEDWindow
(
	void
)
{
}

void BiMEDWindow::on_open_to_encode
(
	void
)
{
	// instanciate a new filechooser
	filechooserDialog * FC = new filechooserDialog
	(
		*this,
		"Select an XML file to encode",
		Gtk::FILE_CHOOSER_ACTION_OPEN,
		Glib::get_home_dir(),
		false,
		0
	);
	// get back the response
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
			toEncodeTextBuffer->set_text(BiMEDEngine::readFile(FC->getPathToFile()));
	}
	delete FC;

}

void BiMEDWindow::on_open_to_decode
(
	void
)
{
		// instanciate a new filechooser
	filechooserDialog * FC = new filechooserDialog
	(
		*this,
		"Select a BiM file to decode",
		Gtk::FILE_CHOOSER_ACTION_OPEN,
		Glib::get_home_dir(),
		false,
		1
	);
	// get back the response
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{	
			toDecodeTextBuffer->set_text(BiMEDEngine::readBinaryFile(FC->getPathToFile()));
	}
	delete FC;
}

void BiMEDWindow::on_save_decoded
(
	void
)
{
		// instanciate a new filechooser
	filechooserDialog * FC = new filechooserDialog
	(
		*this,
		"Save the decoded BiM file into an XML file",
		Gtk::FILE_CHOOSER_ACTION_SAVE,
		Glib::get_home_dir(),
		false,
		0
	);
	// get back the response
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
		BiMEDEngine::writeFile
		(
			(
				(genericFeatures::isExtension(FC->getPathToFile(),"xml"))
				? FC->getPathToFile()
				: FC->getPathToFile()+".xml"
			)
			, toEncodeTextBuffer->get_text()
		);
	}
	delete FC;

}

void BiMEDWindow::on_save_encoded
(
	void
)
{
	if (!toDecodeTextBuffer->get_text().empty() and genericFeatures::isHexadecimal(toDecodeTextBuffer->get_text())) {
		// instanciate a new filechooser
		filechooserDialog * FC = new filechooserDialog
		(
			*this,
			"Save the encoded XML file into a BiM file",
			Gtk::FILE_CHOOSER_ACTION_SAVE,
			Glib::get_home_dir(),
			false,
			1
		);
		// get back the response
		if (FC->getResponse() == Gtk::RESPONSE_OK) 
		{
			BiMEDEngine::writeBinaryFile
			(
				(
					(genericFeatures::isExtension(FC->getPathToFile(),"bin"))
					? FC->getPathToFile()
					: FC->getPathToFile()+".bin"
				)
				,
				(
					(genericFeatures::hasHexadecimalPrefix(toDecodeTextBuffer->get_text()))
					? toDecodeTextBuffer->get_text().substr(2, toDecodeTextBuffer->get_text().size()-2)
					: toDecodeTextBuffer->get_text()
				)
			);
		}
		delete FC;
	} else {
		genericAlertWindow * AC = new genericAlertWindow
		(
			*this, 
			"Error : Unable to save the binary file" , 
			"Please, check the hexadecimal text to save. Maybe, the text area is empty or contains some non hexadecimal characters."
		);
		delete AC;
	}
}

void BiMEDWindow::on_leave
(
	void
)
{
	hide();
}

void BiMEDWindow::on_encode_clicked
(
	void
)
{
	if (toEncodeTextBuffer->size() > 0) {
		toDecodeTextBuffer->set_text(BiMEDEngine::convertTxtToBinary(toEncodeTextBuffer->get_text()));
	} else {
		genericAlertWindow * AC = new genericAlertWindow
		(
			*this, 
			"Error : Unable to encode the text data" , 
			"Please, type something in the text area to encode. It cannot stay empty."
		);
		delete AC;
	}
}

void BiMEDWindow::on_decode_clicked
(
	void
)
{
	if (genericFeatures::isHexadecimal(toDecodeTextBuffer->get_text())) {
		toEncodeTextBuffer->set_text(BiMEDEngine::convertBinaryToTxt(toDecodeTextBuffer->get_text()));
	} else {
		genericAlertWindow * AC = new genericAlertWindow
		(
			*this, 
			"Error : Unable to decode the binary data" , 
			"Please, check the hexadecimal text. Maybe, the text area is empty or contains non hexadecimal characters."
		);
		delete AC;
	}
}

void BiMEDWindow::on_about
(
	void
)
{
	AboutBiMED * AB = new AboutBiMED();
	delete AB;
}


