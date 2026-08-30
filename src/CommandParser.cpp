#include "../include/Command.hpp"
#include "../include/CommandParser.hpp"
#include <string>
#include <string_view>
#include <vector>

ChatApp::Commands::Command ChatApp::Commands::Parser::CommandParser::parse(int cfd, std::string_view query) {
	std::vector<std::string> splited;
	std::string subQuery;
	char prev;	
	for(char c : query) {
		if(c == ' ' || (prev == '\\' && c == '0')) {
			splited.push_back(subQuery);
			subQuery = "";
		}
		else 
			subQuery += c;
		prev = c;
	}
	Command c;
	c.fd = cfd;
	if(splited[0] == "LOGIN")
		c.type = ChatApp::Commands::CommandType::LOGIN;
	else if(splited[0] == "MESSAGE")
		c.type = ChatApp::Commands::CommandType::MESSAGE;
	else if(splited[0] == "CALL")
		c.type = ChatApp::Commands::CommandType::CALL;
	subQuery = "";
	for(char ch : query) {
		if(ch == ' ') {
			c.query.push_back(subQuery);
			subQuery = "";
		}
		else
			subQuery += ch;
	}
	c.query.push_back(subQuery);
	return c;
}
