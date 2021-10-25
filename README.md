# Crystalline

This is the central library for the game engine that will be the only part of the engine bundled with the game.

It will be broken down into the following systems:
* Renderer
* Resource Manager
* Physics Engine
* UI
* Sound 
* Animation
* Scripting

Things to think about:
  - Event system
  - Layer stack
  - Precompiled headers


Current plans:
- Window will be interface for window, input and Renderer
  - CreateRenderer adding to a vector of renderers
    - take struct/class of renderer configuration
  - AddToRenderQueue will be how client draws
    - takes renderer index and struct of render settings
  - UploadToRenderer will be how client loads data to graphics
    - Probably need to populate an unload function


Systems:
* Renderer - wrapper around various rendering APIs (e.g. Vulkan, opengl and DirectX)
* Resource Manager - lifetime management of all game object resources (e.g. meshes, textures, fonts, etc.)
* Physics Engine - wrapper around physics engine (likely bullet)
* UI - standard user interface elements like buttons, textbox (may just be wrapper around ImGui)
* Sound - loading and playing of sound objects
* Animation - loading and processing of animations
* Scripting - scripting interface into engine (likely python)
* Scene? - management of scene including potentially LOD, occlusion, etc.
* Visual effects? - e.g. particle systems, HDR, etc.
* Networking? - required for MMO, online scoreboards etc.
* AI? - some basic built in AI types
* ECS? - entity component system interface for game objects
* Platform? - a platform indpendence layer (e.g. windows, filesystem)
