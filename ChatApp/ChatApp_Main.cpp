// ChatApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip> // For std::quoted

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

int main(int argc, char* argv[]) {
	// --- 1. Parsing Startup Arguments ---
	std::map<std::string, std::string> args;
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg[0] == '-' && i + 1 < argc) {
			args[arg] = argv[++i];
		}
	}

	// Display parsed arguments
	std::cout << "--- Session Started ---" << std::endl;
	std::cout << "User: " << args["-u"] << std::endl;
	std::cout << "Group: " << args["-g"] << std::endl;
	std::cout << "FirstName: " << args["-f"] << std::endl;
	std::cout << "LastName: " << args["-l"] << std::endl;

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

