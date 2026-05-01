#pragma once
#include <vector>
#include <ctime>
#include <time.h>
#include "map_for_game.h"

using namespace std;

void PrintControl(int& cnt_pnt, time_t tm) {
    cout << "W - вверх " << endl;
    cout << "S - вниз " << endl;
    cout << "A - влево" << endl;
    cout << "D - вправо" << endl;
    cout << "Чтобы выйти нажмите (e)xit" << endl;
    cout << cnt_pnt << "/5 очков" << endl;
    cout << time(0) - tm << " sec" << endl;
}

void RandPoint(vector<vector<char>>& map, int& row, int& col) {
    srand(time(NULL));
    vector<int> free_space;
    int p_x = rand() % (map.size() - 2) + 1;

    for (int i = 0; i < map.size(); i++) {
        if (map[p_x][i] != '#') {
            free_space.push_back(i);
        }
    }

    int p_y = rand() % free_space.size();
    map[p_x][free_space[p_y]] = '!';
}

void PrintMap() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void MoveHero(vector<vector<char>>& map, int& row, int& col, bool& flag, bool& flag_win) {
    char ch = getchar();
    putchar(ch);
    switch (ch) {
        case 's':
            if (map[row + 1][col] != '#') {
                map[row][col] = ' ';
                row++;
                if (map[row][col] == '!') {
                    flag_win = true;
                    map[row][col] = '@';
                    RandPoint(map, row, col);
                }
                else {
                    map[row][col] = '@';
                }
            }
            break;

        case 'w':
            if (map[row - 1][col] != '#') {
                map[row][col] = ' ';
                row--;
                if (map[row][col] == '!') {
                    flag_win = true;
                    map[row][col] = '@';
                    RandPoint(map, row, col);
                }
                else {
                    map[row][col] = '@';
                }
            }
            break;

        case 'a':
            if (map[row][col - 1] != '#') {
                map[row][col] = ' ';
                col--;
                if (map[row][col] == '!') {
                    flag_win = true;
                    map[row][col] = '@';
                    RandPoint(map, row, col);
                }
                else {
                    map[row][col] = '@';
                }
            }

            break;

        case 'd':
            if (map[row][col + 1] != '#') {
                map[row][col] = ' ';
                col++;
                if (map[row][col] == '!') {
                    flag_win = true;
                    map[row][col] = '@';
                    RandPoint(map, row, col);
                }
                else {
                    map[row][col] = '@';
                }
            }
            break;

        case 'e':
            flag = false;
            break;
    }
}
