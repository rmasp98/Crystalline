#ifndef CRYSTALLINE_APPLICATION_HPP
#define CRYSTALLINE_APPLICATION_HPP

#include "AsyncLib/logger.hpp"
#include "window/window.hpp"

namespace crystalline {

class Application {
 public:
  Application();
  virtual ~Application();

  virtual void Run();

 protected:
  std::shared_ptr<async_lib::Logger> logger_;
  std::unique_ptr<Window> window_;
  CloseObserverSharedPtr observer_;
};

}  // namespace crystalline

#endif  // CRYSTALLINE_APPLICATION_HPP
