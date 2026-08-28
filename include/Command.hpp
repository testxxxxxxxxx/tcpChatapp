#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <string>
namespace ChatApp::Commands {
	enum class CommandType {
		LOGIN,
		MESSAGE,
		CALL
	};
	class Command {
		public:
			int fd;
			CommandType type;
			std::string query;

	};	
};
#endif
