#include "../include/ResponseProvider.hpp"
#include "../include/Command.hpp"
#include <string>

std::string ChatApp::ResponseManagement::ResponseProvider::getText(ChatApp::Commands::Command* c) {
	std::string response = "";
	switch(c->type) {
		case ChatApp::Commands::CommandType::LOGIN:
		{
			std::string login = c->query[0], password = c->query[1];
			//TODO: mysql connection
		} break;
		case ChatApp::Commands::CommandType::MESSAGE:
		{
			std::string from = c->query[0], to = c->query[1], content = c->query[2], token = c->query[3];
			//TODO: if to number is in session map send and save message to database with column delivered = 1 else save message to database with column delivered = 0
			//TODO: mysql connection   			
		} break;
		case ChatApp::Commands::CommandType::CALL:
		{

		} break;
		default:
			break;
	}
	return response;
}
