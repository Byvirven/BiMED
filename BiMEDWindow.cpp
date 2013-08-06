/*!
 * \project_name EBU Player
 * \file genericAlertWindow.cpp
 * \brief Generic alert window functions
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 4 march 2013
 *
 * This software is published in LGPLv3.0
 *
 */

#include "BiMEDWindow.hpp"

BiMEDWindow::BiMEDWindow
(
	void
) 
{

	// configure the window
	set_title("BiMED : The EBU BiM Encoder/Decoder");
	set_icon_from_file("img/BiMLogo.png");
	
	// instantiate the widgets
	Gtk::Box * vbox = manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,5));
	Gtk::ScrolledWindow * SWforTextEnc = manage(new Gtk::ScrolledWindow());
	Gtk::ScrolledWindow * SWforTextDec = manage(new Gtk::ScrolledWindow());
	Gtk::Separator * S1 = manage(new Gtk::Separator(Gtk::ORIENTATION_HORIZONTAL));
	Gtk::Separator * S2 = manage(new Gtk::Separator(Gtk::ORIENTATION_HORIZONTAL));
	Gtk::Separator * S3 = manage(new Gtk::Separator(Gtk::ORIENTATION_HORIZONTAL));
	Gtk::Button * DecEncButton = manage(new Gtk::Button("Encode/Decode"));
	Gtk::TextView * toEncode = manage (new Gtk::TextView());
	Gtk::TextView * toDecode = manage (new Gtk::TextView());
	
	
	// instantiate window menu
	m_refActionGroup = Gtk::ActionGroup::create();

	//File|New sub menu:
	m_refActionGroup->add(Gtk::Action::create("FileOpenToDecode",
		        Gtk::Stock::OPEN, "Open BiM", "Open a BiM file to decode"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_open_to_decode));

	m_refActionGroup->add(Gtk::Action::create("FileOpenToEncode",
		        Gtk::Stock::OPEN, "Open XML", "Open an XML file to encode"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_open_to_encode));

	m_refActionGroup->add(Gtk::Action::create("FileSaveDecoded",
		        Gtk::Stock::SAVE_AS, "Save XML", "Save the decoded result"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_save_decoded));
		    
	m_refActionGroup->add(Gtk::Action::create("FileSaveEncoded",
		        Gtk::Stock::SAVE_AS, "Save BiM", "Save the encoded result"),
		    sigc::mem_fun(*this, &BiMEDWindow::on_save_encoded));

	//File menu:
	m_refActionGroup->add(Gtk::Action::create("FileMenu", "File"));
	//Sub-menu.
	m_refActionGroup->add(Gtk::Action::create("FileOpen", Gtk::Stock::OPEN));
	m_refActionGroup->add(Gtk::Action::create("FileSave", Gtk::Stock::SAVE_AS));
	m_refActionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
			sigc::mem_fun(*this, &BiMEDWindow::on_leave)
	);

	//Edit menu:
	m_refActionGroup->add(Gtk::Action::create("ActionMenu", "Action"));
	m_refActionGroup->add(Gtk::Action::create("EncodeDecode", Gtk::Stock::EXECUTE),
		    sigc::mem_fun(*this, &BiMEDWindow::on_encode_decode));

	//Help menu:
	m_refActionGroup->add( Gtk::Action::create("HelpMenu", "Help") );
	m_refActionGroup->add( Gtk::Action::create("HelpAbout", Gtk::Stock::HELP),
		    sigc::mem_fun(*this, &BiMEDWindow::on_about) );

	m_refUIManager = Gtk::UIManager::create();
	m_refUIManager->insert_action_group(m_refActionGroup);

	add_accel_group(m_refUIManager->get_accel_group());

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
		  "      <menuitem action='EncodeDecode'/>"
		  "    </menu>"
		  "    <menu action='HelpMenu'>"
		  "      <menuitem action='HelpAbout'/>"
		  "    </menu>"
		  "  </menubar>"
		  "</ui>";

	try
	{
	 m_refUIManager->add_ui_from_string(ui_info);
	}
	catch(const Glib::Error& ex)
	{
	 std::cerr << "building menus failed: " <<  ex.what();
	}
	
	Gtk::Widget* pMenubar = m_refUIManager->get_widget("/MenuBar");
	
	// configure the widgets
	SWforTextEnc->set_size_request(100, 161);
	SWforTextDec->set_size_request(100, 161);
	
	toEncode->set_pixels_above_lines(2);
	toEncode->set_left_margin(2);
	toEncode->set_right_margin(2);
	toEncode->set_editable(true);
  	toEncode->set_cursor_visible(true);
	toEncode->set_wrap_mode(Gtk::WRAP_WORD);
	
	toEncodeTextBuffer = Gtk::TextBuffer::create();
 	toEncodeTextBuffer->set_text("Set the text to encode here");
	// signal
	/*toEncodeTextBuffer->signal_end_user_action().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this,
				&classEngine::on_textnode_changed
			),
			toEncodeTextBuffer->get_text()
		)
	);*/
	toEncode->set_buffer(toEncodeTextBuffer);

	
	toDecode->set_pixels_above_lines(2);
	toDecode->set_left_margin(2);
	toDecode->set_right_margin(2);
	toDecode->set_editable(true);
  	toDecode->set_cursor_visible(true);
	toDecode->set_wrap_mode(Gtk::WRAP_WORD);
	
	toDecodeTextBuffer = Gtk::TextBuffer::create();
 	toDecodeTextBuffer->set_text("Set the text to decode here");
	// signal
	/*toDecodeTextBuffer->signal_end_user_action().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this,
				&classEngine::on_textnode_changed
			),
			toDecodeTextBuffer->get_text()
		)
	);*/

	 toDecode->set_buffer(toDecodeTextBuffer);
	
	
	// set the widget in his relative
	vbox->add(*pMenubar);
	vbox->add(*S1);
	vbox->add(*SWforTextEnc);
	vbox->add(*S2);
	vbox->add(*SWforTextDec);
	vbox->add(*S3);
	vbox->add(*DecEncButton);
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
	DecEncButton->show();
	toEncode->show();
	toDecode->show();
	
	// show window's widgets
	show();
	//genericFeatures::writeFirstBinaryFile();
	//genericFeatures::readFirstBinaryFile();
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
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
			genericFeatures::readFile(FC->getPathToFile());
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
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{	
			toDecodeTextBuffer->set_text(genericFeatures::readBinaryFile(FC->getPathToFile()));
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
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
	
/*		gst->setFile
		(
			FC->getURIToFile(),
			Glib::filename_display_basename(FC->getPathToFile())
		);*/
	}
	delete FC;

}

void BiMEDWindow::on_save_encoded
(
	void
)
{
	// instanciate a new filechooser
	filechooserDialog * FC = new filechooserDialog
	(
		*this,
		"Save the encoded XML file into a BiM file",
		Gtk::FILE_CHOOSER_ACTION_OPEN,
		Glib::get_home_dir(),
		false,
		1
	);
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
	
/*		gst->setFile
		(
			FC->getURIToFile(),
			Glib::filename_display_basename(FC->getPathToFile())
		);*/
	}
	delete FC;

}

void BiMEDWindow::on_leave
(
	void
)
{
	hide();
}

void BiMEDWindow::on_encode_decode
(
	void
)
{

}

void BiMEDWindow::on_about
(
	void
)
{

}


