#include <OGL.h>
#include <ResourceManager.h>
#include <ShadersProgram.h>
#include <Texture.h>
#include <memory>

ResourceManager::ResourceManager() {}

void ResourceManager::load_shaders(const std::string name,
                                   std::shared_ptr<ShadersProgram> &s) {
  auto path = m_Shaders + name;
  auto v_path = path + ".vs";
  auto f_path = path + ".fs";

  auto shader = std::make_shared<ShadersProgram>();

  shader->create(v_path.c_str(), f_path.c_str());

  s = shader;
}

void ResourceManager::load_textures(const std::string name, GLenum type,
                                    std::shared_ptr<Texture> &t) {
  auto path = m_Textures + name;

  auto texture = std::make_shared<Texture>(type, path.c_str());

  texture->load();

  t = texture;
}

std::shared_ptr<ShadersProgram>
ResourceManager::createShader(const std::string shader_name) {

  std::shared_ptr<ShadersProgram> s;

  load_shaders(shader_name, s);

  return s;
}

std::shared_ptr<Texture>
ResourceManager::getTexture(const std::string texture_name, GLenum type) {

  std::shared_ptr<Texture> t;

  load_textures(texture_name, type, t);

  return t;
}