#ifndef LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_HPP

#include <chrono>
#include <string>

namespace logging {

constexpr int TIMESTAMP_WIDTH{16};  // Width of the timestamp field
constexpr int TIMESTAMP_PRECS{5};   // Precision of the timestamp field

/**
 * @brief Get the current timestamp in milliseconds.
 *
 * @return [std::chrono::milliseconds] The current timestamp in milliseconds
 */
inline double timestamp_ms() {
  return std::chrono::time_point_cast<std::chrono::microseconds>(
             std::chrono::system_clock::now())
             .time_since_epoch()
             .count() /
         10e6;
}

/**
 * @brief Possible logging levels
 */
enum class LogLevel : unsigned int {
  DEBUG = 0U,
  INFO = 1U,
  WARNING = 2U,
  ERROR = 3U,
  FATAL = 4U,
  NOT_A_LEVEL = 5U,
};

/**
 * @brief Convert a string to a LogLevel, useful for setting parameters from
 * the command line.
 *
 * @param log_level - [std::string&]T he string to convert
 * @return [LogLevel] The converted LogLevel
 */
LogLevel StringToLogLevel(const std::string& log_level);
/**
 * @brief Convert a LogLevel to a string, useful for printing the LogLevel.
 *
 * @param log_level - [LogLevel] The LogLevel to convert
 * @return [std::string] The converted string
 */
const std::string LogLevelToString(const LogLevel log_level);

// LOGGER CLASS
// ****************************************************************

/**
 * @brief Logger class for printing standard log messages to the console.
 *
 * Supports standard behavior for logging messages at different levels. Levels
 * at or above the set level are printed to the console.
 *
 * Messages are printed as [LEVEL][TIME] MESSAGE
 */
class Logger {
 public:
  /**
   * @brief Construct a new Logger object with the default log level.
   */
  Logger();
  /**
   * @brief Construct a new Logger object with a specific log level.
   */
  Logger(const LogLevel log_level);

  /**
   * @brief Set the log level for the logger.
   *
   * @param log_level - [LogLevel] The new log level
   */
  void SetLogLevel(const LogLevel log_level);
  /**
   * @brief Log a message at the specified log level.
   */
  void Log(const LogLevel log_level, const std::string& message);

 private:
  LogLevel log_level_;
};

}  // namespace logging
#endif
