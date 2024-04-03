#include "logger.hpp"

int main() {
  logging::Logger l{};
  l.SetLogLevel(logging::LogLevel::DEBUG);
  l.Log(logging::LogLevel::DEBUG, "Hello, World!");
  l.Log(logging::LogLevel::INFO, "Hello, World!");
  l.Log(logging::LogLevel::WARNING, "Hello, World!");
  l.Log(logging::LogLevel::ERROR, "Hello, World!");
  l.Log(logging::LogLevel::FATAL, "Hello, World!");
  return 0;
}
