#include "Source.h"
#include <string>

void initilization_table(bool field[][10]) {
    for (int j = 0; j < 10; ++j)
        for (int i = 0; i < 10; ++i)
            field[j][i] = false;
    std::cout << std::endl;
}

bool control_check_pos(int x) {
    return ((x >= 0 && x <= 9) ? true : false);
}

bool print_table(bool tabel1[][10], bool table2[][10], int player) {
    int co{ 0 }, co2{ 0 };
    std::string gap = "   ";
    std::cout << " |       PLAYER " << (player == 3 ? "1" : std::to_string(player)) << "      |" << (player == 3 ? gap + " |       PLAYER 2      |" : "") << std::endl;
    std::cout << " |---------------------|" << (player == 3 ? gap + " |---------------------|" : "") << std::endl;
    for (int j = 9; j >= 0; --j) {
        std::cout << j << "| ";
        for (int i = 0; i < 10; ++i)
            if (tabel1[i][j]) {
                std::cout << 'o' << " ";
                ++co;
            }
            else std::cout << "  ";
        std::cout << "|";
        if (player == 3) {
            std::cout << gap << j << "| ";
            for (int i = 0; i < 10; ++i)
                if (table2[i][j]) {
                    std::cout << 'o' << " ";
                    ++co2;
                }
                else std::cout << "  ";
            std::cout << "|";
        }
        std::cout << std::endl;
    }
    std::cout << " |-0-1-2-3-4-5-6-7-8-9-|" << (player == 3 ? gap + " |-0-1-2-3-4-5-6-7-8-9-|" : "") << std::endl;
    if (player == 3) std::cout << "Player 1 have " << co << " ship units, Player 2 have " << co2 << " ship units" << std::endl;
    if (co2 > 0 && co > 0 && player == 3) std::cout << "No winner yet" << std::endl;
    else if (co == 0 && co2 > 0 && player == 3) {
        std::cout << "=============== Player 2 win! ===============" << std::endl;
        return true;
    }
    else if (co > 0 && co2 == 0 && player == 3) {
        std::cout << "=============== Player 1 win! ===============" << std::endl;
        return true;
    }
    return false;
}

bool check_coordinate(int x1, int y1, int x2, int y2, int size) {
    if (!(control_check_pos(x1) && control_check_pos(x2)
        && control_check_pos(y1) && control_check_pos(y2))) {
        return false;
    }
    if (x1 == x2 && y1 == y2 && size == 1) {
        return true;
    }
    if (x1 == x2 && abs(y2 - y1) == size - 1) {
        return true;
    }
    else if (y1 == y2 && abs(x2 - x1) == size - 1) {
        return true;
    }
    std::cout << "\n\t\tWrong coordinates!.Try again!\n";
    return false;
}

bool check_ships(bool table[][10], int x1, int y1, int x2, int y2) {
    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);
    for (int j = x1; j < 10 && j < x2; ++j) {
        for (int i = y1; i < 10 && i < y2; ++i)
            if (table[j][i]) return false;
    }
    return true;
}

bool check_enter_ships(bool table[][10], int size, int player) {
    int x1 = { 0 }, x2 = { 0 }, y1{ 0 }, y2{ 0 };
    bool ship_false = false;
    do {
        std::cout << "Player " << player << " ship size = " << size << ". ";
        std::cout << "Enter ship coords:";
        if (size > 1 && size < 5) {
            std::cout << "[x1,y1,x2,y2]:";
            std::cin >> x1 >> y1 >> x2 >> y2;
        }
        else if (size == 1) {
            std::cout << "[x,y]:";
            std::cin >> x1 >> y1;
            x2 = x1;
            y2 = y1;
        }
        else {
            std::cout << "Wrong size of ship\n";
            continue;
        }
    } while (!check_coordinate(x1, y1, x2, y2, size) || !check_ships(table, x1, y1, x2, y2));
    int coord[2], vector[2];
    coord[0] = x1;
    coord[1] = y1;
    vector[0] = (size > 1 ? (x2 - x1) / (size - 1) : 0);
    vector[1] = (size > 1 ? (y2 - y1) / (size - 1) : 0);
    for (int j = 0; j < size; ++j) {
        if (table[coord[0]][coord[1]]) return false;
        table[coord[0]][coord[1]] = true;
        coord[0] += vector[0];
        coord[1] += vector[1];
    }
    print_table(table, table, player);
    return true;
}

void enter_ship(bool table[][10], int player) {
    std::cout << "=================== Player " << player << "! Input your ship coords! ==========================" << std::endl;
    for (int j = 4; j > 0; --j) {
        for (int i = 0; i < 5 - j; ++i) {
            while (!check_enter_ships(table, j, player));
        }
    }
}

int step(bool table1[][10], bool table2[][10], int player) {
    if (player < 1 || player>2) {
        return -1;
    }

    int x{ -1 }, y{ -1 }, co{ 0 };
    while (true) {
        if (print_table(table1, table2, 3)) return -2;
        do {
            std::cout << "Player " << player << " step" << std::endl << "Enter coords to shoot: ";
            std::cin >> x >> y;
        } while (!(control_check_pos(x) && control_check_pos(y)));

        if ((player == 2 ? table1 : table2)[x][y]) {
            (player == 2 ? table1 : table2)[x][y] = false;
            ++co;
        }
        else return co;

    }

}

int main() {
    bool table1[10][10];
    bool table2[10][10];
    initilization_table(table1);
    initilization_table(table2);
    print_table(table1, table2, 3);
    enter_ship(table1, 1);
    enter_ship(table2, 2);
    int player = 1;
    while (true) {
        if (print_table(table1, table2, 3)) break;
        int point = step(table1, table2,player);
        if (point == -2) break;
        else if (point == -1) std::cout << "\n\t\terror\n" << std::endl;
        else if (point == 0) std::cout << "\nPlayer " << player << " missed!" << std::endl;
        else std::cout << "\nPlayer " << player << " hits " << point << " ship units!" << std::endl;
        if (player == 1) player = 2;
        else player = 1;
    }
}