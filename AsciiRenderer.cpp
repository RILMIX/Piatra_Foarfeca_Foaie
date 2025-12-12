#include "AsciiRenderer.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <string>

// Получить максимальную ширину изображения
size_t GetImageWidth(const ImageType& image) {
    size_t maxWidth = 0;
    for (const auto& line : image) {
        if (line.length() > maxWidth) {
            maxWidth = line.length();
        }
    }
    return maxWidth;
}

// Получить высоту изображения
size_t GetImageHeight(const ImageType& image) {
    return image.size();
}

// Нормализовать изображение по ширине и высоте
ImageType NormalizeImage(const ImageType& image, size_t width, size_t height) {
    ImageType normalized;
    for (const auto& line : image) {
        std::string newLine = line;
        newLine.resize(width, ' ');
        normalized.push_back(newLine);
    }
    while (normalized.size() < height) {
        normalized.push_back(std::string(width, ' '));
    }
    return normalized;
}

// Загрузить изображение из файла
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

// Отразить изображение по горизонтали
ImageType FlipImage(const ImageType& image) {
    ImageType normalized = NormalizeImage(image, GetImageWidth(image), GetImageHeight(image));
    ImageType flipped;
    for (const auto& line : normalized) {
        std::string reversedLine = line;
        std::reverse(reversedLine.begin(), reversedLine.end());
        flipped.push_back(reversedLine);
    }
    return flipped;
}

// Объединить два изображения по горизонтали с пробелами между ними
ImageType MergeImages(const ImageType& left, const ImageType& right) {
    size_t height = std::max(GetImageHeight(left), GetImageHeight(right));
    size_t leftWidth = GetImageWidth(left);
    size_t rightWidth = GetImageWidth(right);
    ImageType leftNorm = NormalizeImage(left, leftWidth, height);
    ImageType rightNorm = NormalizeImage(right, rightWidth, height);
    ImageType merged;
    for (size_t i = 0; i < height; ++i) {
        merged.push_back(leftNorm[i] + "     " + rightNorm[i]);
    }
    return merged;
}

// Нарисовать изображение в консоль
void AsciiRenderer::DrawImage(const ImageType& image) {
    std::string buffer;
    for (const auto& line : image) {
        buffer += line + "\n";
    }
    std::printf("%s", buffer.c_str());
}
