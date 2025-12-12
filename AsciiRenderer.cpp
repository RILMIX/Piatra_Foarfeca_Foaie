#include "AsciiRenderer.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

//lib

ImageType FromFile(const std::string& filename) {
    ImageType image;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Warning: Could not open " << filename << std::endl;
        return image;
    }
    std::string line;
    while (std::getline(file, line)) {
        image.push_back(line);
    }
    return image;
}

ImageType FlipImage(const ImageType& image) {
    ImageType flipped = image;
    for (auto& line : flipped) {
        std::reverse(line.begin(), line.end());
    }
    return flipped;
}

ImageType MergeImages(const ImageType& left, const ImageType& right) {
    size_t height = std::max(left.size(), right.size());
    size_t leftWidth = left.empty() ? 0 : left[0].size();
    size_t rightWidth = right.empty() ? 0 : right[0].size();
    ImageType result(height, std::string(leftWidth + rightWidth, ' '));
    for (size_t i = 0; i < height; ++i) {
        if (i < left.size()) {
            result[i].replace(0, left[i].size(), left[i]);
        }
        if (i < right.size()) {
            result[i].replace(leftWidth, right[i].size(), right[i]);
        }
    }
    return result;
}

void AsciiRenderer::DrawImage(const ImageType& image) {
    for (const auto& line : image) {
        std::cout << line << std::endl;
    }
}