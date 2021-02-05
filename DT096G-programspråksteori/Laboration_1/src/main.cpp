#include <iostream>
#include <getopt.h>

#include "headers/tokens.h"
#include "headers/FileHandler.h"
#include "headers/parser.h"

int main(int argc, char *argv[]) {
	int inputArguments;
	static auto GETOPT_INPUTS ="i:r:";
	std::string filePayload;
	std::string regexArgument;

	while((inputArguments = getopt(argc, argv, GETOPT_INPUTS)) != -1) {
		switch(inputArguments) {
			// File reader
			case 'i': {
				FileHandler file(optarg);
				filePayload = file.readFile();
				break;
			}
			// Input arguments for reg.ex
			case 'r': {
				Parser parser(optarg);

				if(filePayload != "") {
					parser.setPayload(filePayload);
				}
				
				break;
			}

			default: {
				return EXIT_FAILURE;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
