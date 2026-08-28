#ifndef COMMAND_PARSER
#define COMMAND_PARSER
#include <string_view>
namespace ChatApp::Commands {
	class Command;
};
namespace ChatApp::Commands::Parser {
	class CommandParserI {
		public:
			virtual ChatApp::Commands::Command parse(int fd, std::string_view command) = 0;
	};
	class CommandParser : public CommandParserI {
		public:
			CommandParser() {};
			virtual ~CommandParser() = default;

			ChatApp::Commands::Command parse(int fd, std::string_view command) override;	
	};
};
#endif
