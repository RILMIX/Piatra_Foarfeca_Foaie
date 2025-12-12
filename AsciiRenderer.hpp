#pragma once
#include <string>
#include <vector>

using ImageType = std::vector<std::string>;

ImageType FromFile(const std::string& filename);
ImageType FlipImage(const ImageType& image);
ImageType MergeImages(const ImageType& left, const ImageType& right);

class AsciiRenderer {
public:
    void DrawImage(const ImageType& image);
};