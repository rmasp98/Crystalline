#include "renderer/vulkan/vulkan_render_api.hpp"

namespace crystalline {

auto CreateInstance(std::shared_ptr<Window>& window) {
  vk::ApplicationInfo appInfo("Test", 1, "Crystalline", VK_API_VERSION_1_1);
  vk::InstanceCreateInfo createInfo({}, &appInfo);
  (void)window;
  return vk::createInstanceUnique(createInfo);
}

VulkanRenderApi::VulkanRenderApi(std::shared_ptr<Window> window) {
  if (!instance_) {
    instance_ = CreateInstance(window);
  }
}

}  // namespace crystalline