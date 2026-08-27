#ifndef COMMAND_PARSER
#define COMMAND_PARSER
namespace ChatApp::Commands {
	class Command;
};
namespace ChatApp::Commands::Parser {
	class CommandParserI {
		public:
			virtual ChatApp::Commands::Command parse(char* command) = 0;
	};
	class CommandParser : public CommandParserI {
		public:
			CommandParser() {};
			virtual ~CommandParser() = default;

			ChatApp::Commands::Command parse(char* command) override;	
	};
};
#endif
