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
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string type;
            double size, area;
            std::cout << "Enter type: ";
            std::cin >> type;
            std::cout << "Enter size: ";
            std::cin >> size;
            std::cout << "Enter area: ";
            std::cin >> area;
            keeper.addFigure(new FlatFigure(type, size, area));
        } else if (choice == 2) {
            std::string type;
            double size, volume;
            std::cout << "Enter type: ";
            std::cin >> type;
            std::cout << "Enter size: ";
            std::cin >> size;
            std::cout << "Enter volume: ";
            std::cin >> volume;
            keeper.addFigure(new VolumeFigure(type, size, volume));
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
        }
    } while (choice != 0);

    return 0;
}
