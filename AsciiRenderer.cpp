#include "AsciiRenderer.hpp"

#include <cstdio>
#include <fstream>
#include <format>

size_t GetImageWidth(const ImageType& image) {
    size_t maxWidth = 0;
    for (const auto& line : image) {
        if (line.length() > maxWidth) {
            maxWidth = line.length();
        }
    }
    return maxWidth;
}

size_t GetImageHeight(const ImageType& image) {
    return image.size();
}

ImageType NormalizeImage(const ImageType& image, size_t width, size_t height) {
    ImageType normalized;
    size_t currentHeight = GetImageHeight(image);
    size_t currentWidth = GetImageWidth(image);
    for (auto& line : image) {
        std::string newLine = line;
        newLine.resize(width, ' ');
        normalized.push_back(newLine);
    }
    while (normalized.size() < height) {
        normalized.push_back(std::string(width, ' '));
    }
    return normalized;
}

ImageType FromFile(const std::string& filename) {
    ImageType image;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        image.push_back(line);
    }
    return image;
}

ImageType FlipImage(const ImageType& image) {
    ImageType normalized = NormalizeImage(image, GetImageWidth(image), GetImageHeight(image));
    ImageType flipped;
    for (auto it = normalized.begin(); it != normalized.end(); ++it) {
        std::string reversedLine = *it;
        std::reverse(reversedLine.begin(), reversedLine.end());
        flipped.push_back(reversedLine);
    }
    return flipped;
}

ImageType MergeImages(const ImageType& left, const ImageType& right) {
    ImageType leftNorm = NormalizeImage(left, GetImageWidth(left), std::max(GetImageHeight(left), GetImageHeight(right)));
    ImageType rightNorm = NormalizeImage(right, GetImageWidth(right), std::max(GetImageHeight(left), GetImageHeight(right)));
    ImageType merged;

    for (size_t i = 0; i < leftNorm.size(); ++i) {
        merged.push_back(leftNorm[i] + "     " + rightNorm[i]);
    }
    return merged;
}

void AsciiRenderer::DrawImage(const ImageType& image) {
    std::string buffer = "";
    for (const auto& line : image) {
        buffer += line + "\n";
    }
    std::printf("%s", buffer.c_str());
}