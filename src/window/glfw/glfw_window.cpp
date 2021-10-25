#include "window/glfw/glfw_window.hpp"

#include "GLFW/glfw3.h"

namespace crystalline {

GlfwWindow::GlfwWindow(const WindowProperties& props)
    : logger_(async_lib::GetLogger("Window")) {
  static bool glfwInitialised = false;
  if (!glfwInitialised) {
    logger_->Info("Initialising GLFW");
    glfwInitialised = glfwInit();
    assert(glfwInitialised);
  }

  logger_->Info("Creating GLFW window: \"{}\" - {}x{}", props.title,
                props.width, props.height);
  window_ = glfwCreateWindow(props.width, props.height, props.title.c_str(),
                             nullptr, nullptr);
  SetCallbacks();
}

GlfwWindow::~GlfwWindow() { glfwDestroyWindow(window_); }

void GlfwWindow::Update() {
  glfwSwapBuffers(window_);
  glfwPollEvents();
}

std::pair<int, int> GlfwWindow::Size() {
  int width, height;
  glfwGetWindowSize(window_, &width, &height);
  return {width, height};
}

std::vector<std::string> GlfwWindow::GetVulkanExtensions() const {
  uint32_t count;
  const char** arrayExtensions = glfwGetRequiredInstanceExtensions(&count);
  std::vector<std::string> vectorExtensions(count);
  for (size_t i = 0; i < count; ++i) {
    vectorExtensions.push_back(arrayExtensions[i]);
  }
  return vectorExtensions;
}

CallbackData* GetCallbackData(GLFWwindow* window) {
  return reinterpret_cast<CallbackData*>(glfwGetWindowUserPointer(window));
}

void GlfwWindow::SetCallbacks() {
  glfwSetWindowUserPointer(window_, reinterpret_cast<void*>(&callbackData_));

  glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {
    GetCallbackData(window)->CloseEvent.Notify();
  });

  glfwSetWindowSizeCallback(
      window_, [](GLFWwindow* window, int width, int height) {
        GetCallbackData(window)->ResizeEvent.Notify(width, height);
      });

  // TODO: Find if I need to use scancode or mods
  glfwSetKeyCallback(window_, [](GLFWwindow* window, int key, int /*scancode*/,
                                 int action, int /*mods*/) {
    GetCallbackData(window)->KeyEvent.Notify(static_cast<KeyCode>(key),
                                             static_cast<ButtonEvent>(action));
  });

  glfwSetCharCallback(window_, [](GLFWwindow* window, unsigned int character) {
    GetCallbackData(window)->CharEvent.Notify(character);
  });

  // TODO: Find if I need to use mods
  glfwSetMouseButtonCallback(
      window_, [](GLFWwindow* window, int button, int action, int /*mods*/) {
        GetCallbackData(window)->MouseButtonEvent.Notify(
            static_cast<MouseCode>(button), static_cast<ButtonEvent>(action));
      });

  glfwSetCursorPosCallback(
      window_, [](GLFWwindow* window, double xPos, double yPos) {
        GetCallbackData(window)->MousePositionEvent.Notify(xPos, yPos);
      });

  glfwSetScrollCallback(
      window_, [](GLFWwindow* window, double xOffset, double yOffset) {
        GetCallbackData(window)->ScrollEvent.Notify(xOffset, yOffset);
      });
}

}  // namespace crystalline
