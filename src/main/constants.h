#pragma once

#include <filesystem>

namespace ad::constants {

namespace fs = std::filesystem;

const fs::path RESOURCES_PATH = "resources";
const fs::path IMAGES_PATH    = RESOURCES_PATH / "images";

const fs::path FILESAVEAS_PATH = IMAGES_PATH / "filesaveas.png";

}; // namespace ad::constants