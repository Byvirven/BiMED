/*!
 * \project_name BiM Encoder/Decoder
 * \file CMDLine.cpp
 * \brief This is the class of the command line controller.
 * \details This class is used to parse properly a command line from terminal, offers a terminal menu, a man presentation and usefull stuff for terminal environment
 * \authors Marco Dos Santos Oliveira
 * \version 1.0.0
 * \date 9 August 2013
 * \copyright This software is published in MPLv2.0
 *
 */

#include "CMDLine.hpp"

CMDLine::CMDLine
(
	int argc, 
	char *argv[]
) 
{
	if (argc >= 2) 
	{
		for (int i=1;i<argc;i++) 
		{
			arguments.push_back((std::string)argv[i]);
		}
	}
}

CMDLine::~CMDLine
(
	void
)
{
}

void CMDLine::showArgument
(
	void
)
{
	for (unsigned int i=0;i<arguments.size())
}
