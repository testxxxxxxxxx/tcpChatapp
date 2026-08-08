#ifndef COMMAND_QUEUE_HPP
#define COMMAND_QUEUE_HPP
#include <queue>
namespace ChatApp::Commands {
	class Command;
};
namespace ChatApp::Commands::queue {
	class CommandQueueI {
		public:
			virtual void push(ChatApp::Commands::Command c) = 0;
			virtual ChatApp::Commands::Command pop() = 0;
	};
	class CommandQueue : public CommandQueueI {
		std::queue<ChatApp::Commands::Command> qCommand;
		public:
			CommandQueue() {}
			virtual ~CommandQueue() = default;

			void push(ChatApp::Commands::Command c) override;
			ChatApp::Commands::Command pop() override;
	};
};
#endif
