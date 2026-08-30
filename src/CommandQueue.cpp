#include "../include/CommandQueue.hpp"
#include "../include/Command.hpp"

void ChatApp::Commands::Queue::CommandQueue::push(
    ChatApp::Commands::Command c) {
  this->qCommand.push(c);
}
ChatApp::Commands::Command ChatApp::Commands::Queue::CommandQueue::pop() {
  //if(this->qCommand.empty())
	  //return nullptr;
  Command c = this->qCommand.front();
  this->qCommand.pop();
  return c;
}
