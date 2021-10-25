#ifndef CRYSTALLINE_GLFW_WINDOW_HPP
#define CRYSTALLINE_GLFW_WINDOW_HPP

#include "AsyncLib/logger.hpp"
#include "GLFW/glfw3.h"
#include "window/window.hpp"

namespace crystalline {

// TODO: Implement ability to have mulitple windows
class GlfwWindow : public Window {
 public:
  GlfwWindow(const WindowProperties&);
  virtual ~GlfwWindow();

  virtual bool Active() override { return !glfwWindowShouldClose(window_); }

  virtual void Update() override;

  virtual std::pair<int, int> Size() override;

  virtual std::vector<std::string> GetVulkanExtensions() const override;

 private:
  std::shared_ptr<async_lib::Logger> logger_;
  GLFWwindow* window_;

  void SetCallbacks();
};

}  // namespace crystalline

#endif  // CRYSTALLINE_GLFW_WINDOW_HPP
