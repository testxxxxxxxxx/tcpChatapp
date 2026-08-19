#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP
namespace ChatApp::SocketServer {
class Server;
};
namespace ChatApp::Commands::Queue {
class CommandQueue;
};

namespace ChatApp::Multiplexing {
class MultiplexerI {
public:
  virtual void init() = 0;
  virtual void loopEvent(ChatApp::Commands::Queue::CommandQueue *cq) = 0;
  virtual void notifyWritable(int fd) = 0;
};
class Multiplexer : public MultiplexerI {
  ChatApp::SocketServer::Server *s;
  int efd, maxEvents;

public:
  Multiplexer(ChatApp::SocketServer::Server *s, int maxEvents)
      : s(s), maxEvents(maxEvents) {}
  ~Multiplexer() {}

  void init() override;
  void loopEvent(ChatApp::Commands::Queue::CommandQueue *cq) override;
  void notifyWritable(int fd) override;
};
}; // namespace ChatApp::Multiplexing
#endif
