#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

struct Province {
    int id;
    std::string terrain;
    std::string region;
    std::vector<sf::Vector2i> pixels; // Пиксели провинции (для хитбокса)
};

std::map<sf::Color, Province> loadProvinces(const std::string& csvPath, const sf::Image& provincesMap) {
    std::map<sf::Color, Province> provinces;
    // Парсим CSV (псевдокод)
    for (const auto& row : csvData) {
        sf::Color color(row.R, row.G, row.B);
        provinces[color] = Province{row.ID, row.Terrain, row.Region, {}};
    }

    // Заполняем пиксели провинций
    for (int y = 0; y < provincesMap.getSize().y; ++y) {
        for (int x = 0; x < provincesMap.getSize().x; ++x) {
            sf::Color pixelColor = provincesMap.getPixel(x, y);
            if (provinces.count(pixelColor)) {
                provinces[pixelColor].pixels.emplace_back(x, y);
            }
        }
    }
    return provinces;
}