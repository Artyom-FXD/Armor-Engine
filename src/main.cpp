#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>

// Func to get terrain types from .csv file

struct Terrain {
    int id;
    std::string type;
};

std::string loadTerrains(const std::string& csvPath) {
    std::ifstream terrainFile(csvPath);

    // error message / вывод при ошибке

    if (!terrainFile.is_open()) {
        std::cerr << "ErrTerrainTypes: Couldn't open CSV file / Невозможно открыть CSV файл" << std::endl;
        return "error";
    }

    // first line

    std::string line = "";
    terrainFile.getline(terrainFile, line);

    // import types

    while (terrainFile.getline(terrainFile, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(ss, cell, ';')) {
            row.push_back(cell);
        }

        int nextid = 0;

        if (row.size() == 1) {
            Terrain{

            };
        }
    }
};

// Func to get province from .csv file / Функция для получения провок из .csv файла

struct Province
{
    int id;
    std::string terrain;
    std::string region;
    std::vector<sf::Vector2u> pixels;
};

std::map<sf::Color, Province> loadProvinces(const std::string& csvPath) {
    // def
    std::map<sf::Color, Province> provinces;
    std::ifstream file(csvPath);

    // error message / вывод при ошибке

    if (!file.is_open()) {
        std::cerr << "ErrMap: Couldn't open CSV file / Невозможно открыть CSV файл" << std::endl;
        return provinces;
    }

    // Skip first line (title) / Пропуск первой строки (заголовок)

    std::string line;
    std::getline(file, line);

    // import provs from csv / импорт провок из csv

    while (file.getline(file, line)) {
        // def
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(ss, cell, ';')) {
            row.push_back(cell);
        }

        if (row.size() >= 6) {
            sf::Color color(
                std::stoi(row[0]),  // Red / Красный
                std::stoi(row[1]),  // Green / Зелёный
                std::stoi(row[2])   // Blue / Синий
            );
            provinces[color] = Province{
                std::stoi(row[3]),  // ID
                row[4],             // Terrain
                row[5]              // Region
            };
        }
    }

}
