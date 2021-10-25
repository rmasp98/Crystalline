#ifndef CRYSTALLINE_RENDERER_API_HPP
#define CRYSTALLINE_RENDERER_API_HPP

namespace crystalline {

class RenderApi {
 public:
  virtual ~RenderApi() = default;

 protected:
  RenderApi() = default;
};

}  // namespace crystalline

#endif  // CRYSTALLINE_RENDERER_API_HPP