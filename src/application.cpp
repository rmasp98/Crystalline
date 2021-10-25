#include "application.hpp"

#include "window/glfw/glfw_window.hpp"

namespace crystalline {

Application::Application() : logger_(async_lib::GetLogger()) {
  // set up game engine
  logger_->Info("Initialising Crytalline engine");

  // This should call a helper function that decides which interface to use
  WindowProperties props{"Test", 800, 600};
  window_ = std::make_unique<GlfwWindow>(props);
  observer_ = window_->SubscribeCloseEvents(
      []() { std::cout << "Closing" << std::endl; });
}

Application::~Application() {
  // shut down game engine
  observer_->Unsubscribe();
}

void Application::Run() {
  while (window_->Active()) {
    window_->Update();
  }
}

}  // namespace crystalline
