#include "../include/ResponseProvider.hpp"
#include "../include/Command.hpp"
#include <string>

std::string ChatApp::ResponseManagement::ResponseProvider::getText(ChatApp::Commands::Command* c) {
	std::string response = "";
	switch(c->type) {
		case ChatApp::Commands::CommandType::LOGIN:
		{
			std::string login = c->query[0];
			std::string password = c->query[1];
			//TODO: mysql connection
		} break;
		case ChatApp::Commands::CommandType::MESSAGE:
		{
			
		} break;
		case ChatApp::Commands::CommandType::CALL:
		{

		} break;
		default:
			break;
	}
	return response;
}
