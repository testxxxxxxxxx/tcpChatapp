#include "../include/Command.hpp"
#include "../include/CommandParser.hpp"
#include <string>
#include <string_view>
#include <vector>

ChatApp::Commands::Command ChatApp::Commands::Parser::CommandParser::parse(int cfd, std::string_view query) {
	std::vector<std::string> splited;
	std::string subQuery; 
	for(char c : query) {
		if(c == ' ') {
			splited.push_back(subQuery);
			subQuery = "";
		}
		else 
			subQuery += c;
	}
	Command c;
	c.fd = cfd;
	if(splited[0] == "LOGIN")
		c.type = ChatApp::Commands::CommandType::LOGIN;
	else if(splited[0] == "MESSAGE")
		c.type = ChatApp::Commands::CommandType::MESSAGE;
	else if(splited[0] == "CALL")
		c.type = ChatApp::Commands::CommandType::CALL;
	c.query = splited[1];
	return c;
}
