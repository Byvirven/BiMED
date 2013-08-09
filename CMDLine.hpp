#ifndef CPP_CMDLINE_CLASS_H
#define CPP_CMDLINE_CLASS_H

/*!
 * \project_name BiM Encoder/Decoder
 * \file CMDLine.hpp
 * \brief This is the class specification of the command line controller
 * \details This class is used to parse properly a command line from terminal
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 9 August 2013
 * \copyright This software is published in MPLv2.0
 *
 */

/*! \class CMDLine
 * \brief This class is used to parse properly a command line from terminal
 *
 * This class will parse a command line typed by the user. 
 */

class CMDLine 
{
public:

	/*!*
	* @fn CMDLine(int argc,	char *argv[])
	* @brief Class constructor
	* @brief The CMDLine class constructor instantiates a new Gtk::AboutDialog window.
	* @param[in] void : none
	*/
	CMDLine
	(
		int argc, 
		char *argv[]
	);
	/*!*
	* @fn ~CMDLine(void)
	* @brief Class destructor
	* @brief The CMDLine class will destroy this widget at the end of its life-cycle.
	* @param[in] void : none
	*/
	virtual ~CMDLine
	(
		void
	);
	
protected:
	std::vector<std::string> arguments;/*!< arguments vector in which will be stored the initial arguments typed into the terminal */
	

};

#endif /*CPP_CMDLINE_CLASS_H*/
