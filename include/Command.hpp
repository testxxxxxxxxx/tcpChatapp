#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <vector>
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
			std::vector<std::string> query;

	};	
};
#endif
