#include "../include/CommandQueue.hpp"
#include "../include/Command.hpp"

void ChatApp::Commands::queue::CommandQueue::push(ChatApp::Commands::Command c) {
	this->qCommand.push(c);
}
ChatApp::Commands::Command ChatApp::Commands::queue::CommandQueue::pop() {
	Command c = this->qCommand.front();
	this->qCommand.pop();
	return c;
}
