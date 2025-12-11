#pragma once
#include <string>
#include <vector>

using  ImageType = std::vector<std::string>;

size_t GetImageWidth(const ImageType& image);
size_t GetImageHeight(const ImageType& image);

ImageType NormalizeImage(const ImageType& image, size_t width, size_t height);

ImageType FromFile(const std::string& filename);
ImageType FlipImage(const ImageType& image);
ImageType MergeImages(const ImageType& left, const ImageType& right);

class AsciiRenderer 
{
public:
    void DrawImage(const ImageType& image);
    ~AsciiRenderer() = default;
};