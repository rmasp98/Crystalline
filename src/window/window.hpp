#ifndef CRYSTALLINE_WINDOW_HPP
#define CRYSTALLINE_WINDOW_HPP

#include <memory>
#include <string>
#include <vector>

#include "AsyncLib/observer.hpp"
#include "window/input_enums.hpp"

namespace crystalline {

struct WindowProperties {
  std::string title;
  int width;
  int height;
  // graphics API
  // vsync
  // resize
  // fullscreen
};

using ResizeObserverSharedPtr = std::shared_ptr<async_lib::Observer<int, int>>;
using CloseObserverSharedPtr = std::shared_ptr<async_lib::Observer<>>;
using KeyObserverSharedPtr =
    std::shared_ptr<async_lib::Observer<KeyCode, ButtonEvent>>;
using CharObserverSharedPtr =
    std::shared_ptr<async_lib::Observer<unsigned int>>;
using MouseButtonObserverSharedPtr =
    std::shared_ptr<async_lib::Observer<MouseCode, ButtonEvent>>;
using MousePosObserverSharedPtr =
    std::shared_ptr<async_lib::Observer<double, double>>;
using ScrollObserverSharedPtr =
    std::shared_ptr<async_lib::Observer<double, double>>;

struct CallbackData {
  async_lib::Subject<int, int> ResizeEvent;
  async_lib::Subject<> CloseEvent;
  async_lib::Subject<KeyCode, ButtonEvent> KeyEvent;
  async_lib::Subject<unsigned int> CharEvent;
  async_lib::Subject<MouseCode, ButtonEvent> MouseButtonEvent;
  async_lib::Subject<double, double> MousePositionEvent;
  async_lib::Subject<double, double> ScrollEvent;
};

class Window {
 public:
  virtual ~Window() = default;

  virtual bool Active() = 0;

  virtual void Update() = 0;

  virtual std::pair<int, int> Size() = 0;

  virtual std::vector<std::string> GetVulkanExtensions() const = 0;

  // TODO: Cursor enable/disable/invisible
  // TODO: Set cursor image

  // TODO: do I need vsync?

  // TODO: Subscribe joystick events
  // TODO: Subscribe clipboard events
  // TODO: Subscribe path drop events

  ResizeObserverSharedPtr SubscribeResizeEvents(
      std::function<void(int, int)> callback) {
    return callbackData_.ResizeEvent.Subscribe(callback);
  }

  CloseObserverSharedPtr SubscribeCloseEvents(std::function<void()> callback) {
    return callbackData_.CloseEvent.Subscribe(callback);
  }

  KeyObserverSharedPtr SubscribeKeyEvents(
      std::function<void(KeyCode, ButtonEvent)> callback) {
    return callbackData_.KeyEvent.Subscribe(callback);
  }

  CharObserverSharedPtr SubscribeCharEvents(
      std::function<void(unsigned int)> callback) {
    return callbackData_.CharEvent.Subscribe(callback);
  }

  MouseButtonObserverSharedPtr SubscribeMouseButtonEvents(
      std::function<void(MouseCode, ButtonEvent)> callback) {
    return callbackData_.MouseButtonEvent.Subscribe(callback);
  }

  MousePosObserverSharedPtr SubscribeMousePositionEvents(
      std::function<void(double, double)> callback) {
    return callbackData_.MousePositionEvent.Subscribe(callback);
  }

  ScrollObserverSharedPtr SubscribeScrollEvents(
      std::function<void(double, double)> callback) {
    return callbackData_.ScrollEvent.Subscribe(callback);
  }

 protected:
  CallbackData callbackData_;

  Window() = default;
};

}  // namespace crystalline

#endif  // CRYSTALLINE_WINDOW_HPP
