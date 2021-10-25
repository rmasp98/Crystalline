#ifndef CRYSTALLINE_RENDERER_HPP
#define CRYSTALLINE_RENDERER_HPP

#include <memory>

#include "renderer/render_api.hpp"

namespace crystalline {

struct Layout {};

class Renderer {
 public:
  Renderer() = default;
  ~Renderer() = default;

  std::shared_ptr<RenderApi> GetRenderApi() const { return renderApi_; }

  // Adds vertex buffer to a queue to be loaded to GPU
  // And returns std::function to remove from GPU
  int LoadVertexData(float* vertexBuffer, int* indexBuffer, Layout layout);

  int LoadImage();

  // Add render info to a queue for later rendering (index, config)
  void AddToRenderQueue();

  void Render();

 protected:
  std::shared_ptr<RenderApi> renderApi_;
};

}  // namespace crystalline

#endif  // CRYSTALLINE_RENDERER_HPP