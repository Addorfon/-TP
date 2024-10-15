#include "Keeper.h"
#include "FlatFigure.h"
#include "VolumeFigure.h"
#include <iostream>

int main() {
    Keeper keeper;
    int choice;
    do {
        std::cout << "1. Add Flat Figure\n";
        std::cout << "2. Add Volume Figure\n";
        std::cout << "3. Remove Figure\n";
        std::cout << "4. Display Figures\n";
        std::cout << "5. Save to File\n";
        std::cout << "6. Load from File\n";
        std::cout << "7. Edit Figure\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        try {
            if (choice == 1) {
                std::string type;
                double x, y;
                std::cout << "Enter type: ";
                std::cin >> type;
                std::cout << "Enter x y: ";
                std::cin >> x >> y;
                keeper.addFigure(new FlatFigure(type, x, y));
            } else if (choice == 2) {
                std::string type;
                double x, y, z;
                std::cout << "Enter type: ";
                std::cin >> type;
                std::cout << "Enter x y z: ";
                std::cin >> x >> y >> z;
                keeper.addFigure(new VolumeFigure(type, x, y, z));
            } else if (choice == 3) {
                int index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                keeper.removeFigure(index);
            } else if (choice == 4) {
                keeper.displayFigures();
            } else if (choice == 5) {
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                keeper.saveToFile(filename);
            } else if (choice == 6) {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::cin >> filename;
                keeper.loadFromFile(filename);
            } else if (choice == 7) {
                int id;
                std::string type;
                std::cout << "Enter index Figure: ";
                std::cin >> id;
                type = keeper.returnType(id);
                if (type != "Square" || type != "Rectangle" || type != "Parallelepiped" || type != "Triangle" || type != "Cube" || type != "Parallelogram" || type != "Pyramid"){
                    throw std::invalid_argument("Invalid type");
                }
                if (type == "Square" || type == "Rectangle" || type == "Parallelepiped" || type == "Triangle") {
                    double x, y;
                    std::cout << "Enter x y: ";
                    std::cin >> x >> y;
                    keeper.setSizeFlat(id, x, y);
                } else if (type == "Cube" || type == "Parallelogram" || type == "Pyramid") {
                    double x, y, z;
                    std::cout << "Enter x y z: ";
                    std::cin >> x >> y >> z;
                    keeper.setSizeVolume(id, x, y, z);
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    } while (choice != 0);

    return 0;
}
