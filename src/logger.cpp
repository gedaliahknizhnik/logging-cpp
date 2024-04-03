#include "logger.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

namespace logging {

LogLevel StringToLogLevel(const std::string& log_level) {
  std::string level;
  std::transform(log_level.begin(), log_level.end(), level.begin(), ::toupper);

  if ("DEBUG" == level) {
    return LogLevel::DEBUG;
  } else if ("INFO" == level) {
    return LogLevel::INFO;
  } else if ("WARNING" == level) {
    return LogLevel::WARNING;
  } else if ("ERROR" == level) {
    return LogLevel::ERROR;
  } else if ("FATAL" == level) {
    return LogLevel::FATAL;
  } else {
    return LogLevel::NOT_A_LEVEL;
  }
}

const std::string LogLevelToString(const LogLevel log_level) {
  switch (log_level) {
    case LogLevel::DEBUG:
      return "DEBUG";
    case LogLevel::INFO:
      return "INFO";
    case LogLevel::WARNING:
      return "WARNING";
    case LogLevel::ERROR:
      return "ERROR";
    case LogLevel::FATAL:
      return "FATAL";
    case LogLevel::NOT_A_LEVEL:
    default:
      return "UNKNOWN";
  }
}

const std::string LogLevelColorString(const LogLevel log_level) {
  switch (log_level) {
    case LogLevel::DEBUG:
      return "\033[1;32m";
    case LogLevel::INFO:
      return "\033[0m";
    case LogLevel::WARNING:
      return "\033[1;33m";
    case LogLevel::ERROR:
      return "\033[1;31m";
    case LogLevel::FATAL:
      return "\033[1;35m";
    case LogLevel::NOT_A_LEVEL:
    default:
      return "\033[0m";
  }
}

Logger::Logger() : log_level_(LogLevel::INFO) {}
Logger::Logger(const LogLevel log_level) : log_level_(log_level) {}
void Logger::SetLogLevel(const LogLevel log_level) { log_level_ = log_level; }

void Logger::Log(const LogLevel log_level, const std::string& message) {
  if (log_level < log_level_) {
    return;
  }
  std::cout << LogLevelColorString(log_level) << "["
            << LogLevelToString(log_level) << "] " << message << "\033[0m"
            << "\n";
}

}  // namespace logging
