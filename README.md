# Logging Library

**Maintainer:** Gedaliah Knizhnik <gedaliah.knizhnik@gmail.com> 

This is  basic logging library to support my other projects, although it is - of course- available for others to use. 

---

The library supports the basic function of loggers - namely logging at various levels, with logs at or above the current level being printed. Currently only console logging is supported, although file logging _may_ be added in the future. 

Usage:
```cpp

namespace logging {
  Logger l{LogLevel::INFO};

  l.Log(LogLevel::INFO, "This is a test message"); // Will be printed

  l.SetLogLevel(LogLevel::WARN);

  l.Log(LogLevel::INFO, "This is also a test message"); // Will not be printed

}
```

The output is currently a fixed format, and can be expected to look like:

```cpp
[LEVEL][TIMESTAMP] MESSAGE
```
