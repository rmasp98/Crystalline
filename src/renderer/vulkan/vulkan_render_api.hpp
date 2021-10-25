#ifndef CRYSTALLINE_VULKAN_RENDERER_API_HPP
#define CRYSTALLINE_VULKAN_RENDERER_API_HPP

#include <memory>

#include "renderer/render_api.hpp"
#include "vulkan/vulkan.hpp"
#include "window/window.hpp"

namespace crystalline {

class VulkanRenderApi : public RenderApi {
 public:
  VulkanRenderApi(std::shared_ptr<Window>);
  ~VulkanRenderApi() = default;

 private:
  inline static vk::UniqueInstance instance_;
};

}  // namespace crystalline

#endif  // CRYSTALLINE_VULKAN_RENDERER_API_HPP