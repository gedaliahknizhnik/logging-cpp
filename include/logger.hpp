#ifndef LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_HPP

#include <string>

namespace logging {

enum class LogLevel : unsigned int {
  DEBUG = 0U,
  INFO = 1U,
  WARNING = 2U,
  ERROR = 3U,
  FATAL = 4U,
  NOT_A_LEVEL = 5U,
};

LogLevel StringToLogLevel(const std::string& log_level);
const std::string LogLevelToString(const LogLevel log_level);
const std::string LogLevelColorString(const LogLevel log_level);

class Logger {
 public:
  Logger();
  Logger(const LogLevel log_level);

  void SetLogLevel(const LogLevel log_level);
  void Log(const LogLevel log_level, const std::string& message);

 private:
  LogLevel log_level_;
};

}  // namespace logging
#endif
