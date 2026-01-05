/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip> // For std::quoted

/*****************************************************************************/
/* Unify some common functions and types between Unix and Windows            */
/*****************************************************************************/
#if (defined(_WIN32) || defined(WIN32))
#include <string>
#define RTI_SNPRINTF(src, srcSize, format, ...) \
	_snprintf_s(src, srcSize, _TRUNCATE, format, __VA_ARGS__)
#define RTI_STRCASECMP      _stricmp
#define RTI_STRNCASECMP     _strnicmp
#define RTI_STRTOULL        _strtoui64
#define RTI_STRTOUL         strtoul
#define RTI_STRNCMP         strncmp
#else
#include <strings.h>
#define RTI_SNPRINTF        snprintf
#define RTI_STRCASECMP      strcasecmp
#define RTI_STRNCASECMP     strncasecmp
#define RTI_STRTOULL        strtoull
#define RTI_STRTOUL         strtoul
#define RTI_STRNCMP         strncmp
#endif

/* Command processor in a chatApp prompt session */
void processCommand(const std::string& input) {
	std::stringstream ss(input);
	std::string cmd;
	ss >> cmd;

	if (cmd == "exit") {
		exit(0);
	}
	else if (cmd == "list") {
		std::cout << "[System] Listing items..." << std::endl;
		// Logic for list goes here
	}
	else if (cmd == "send") {
		std::string target, message;
		ss >> target;

		// std::quoted handles strings with spaces wrapped in " "
		ss >> std::quoted(message);

		if (target.empty() || message.empty()) {
			std::cout << "Usage: send <target> \"message\"" << std::endl;
		}
		else {
			std::cout << ">> Sending to [" << target << "]: " << message << std::endl;
		}
	}
	else if (!cmd.empty()) {
		std::cout << "Unknown command: " << cmd << std::endl;
	}
}

/* Main Function */
int main(int argc, char* argv[]) {
	// --- 1. Parsing Startup Arguments ---
	std::map<std::string, std::string> args;
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg[0] == '-') {
			if (i + 1 < argc) {
				args[arg] = argv[++i];
			}
			else if (arg[1] == 'd') {
				args[arg] = "debug";
			}
			else { continue; }
		}
	}

	//Validation of arguments
	if (args.count("-u") == 0 || args.count("-g") == 0 || args.count("-f") == 0 || args.count("-l") == 0) {
		std::cout << "Please input all mandatory arguments : -u <UserName> -g <GroupName> -f <FirstName> -l <LastName>" << std::endl;
		exit(1);
	}

	// Display parsed arguments
	std::cout << "--- Session Started ---" << std::endl;
	std::cout << "User: " << args["-u"] << std::endl;
	std::cout << "Group: " << args["-g"] << std::endl;
	std::cout << "FirstName: " << args["-f"] << std::endl;
	std::cout << "LastName: " << args["-l"] << std::endl;
	if (args.count("-d") > 0) {
		std::cout << "Debug Option ENABLED." << std::endl;
	}

	// --- 2. Interactive Loop ---
	std::string line;
	while (true) {
		std::cout << "chatApp> ";
		if (!std::getline(std::cin, line)) break; // Handle Ctrl+C or EOF

		if (!line.empty()) {
			processCommand(line);
		}
	}

	return 0;
}
