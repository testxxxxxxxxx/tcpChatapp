#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <string>
namespace ChatApp::Commands {
	class Command {
		int fd, type;
		std::string query;
	};
	enum class CommandType {
		AUTH,
		MESSAGE,
		CALL
	};
};
#endif
