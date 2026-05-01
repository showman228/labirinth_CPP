# include <iostream>
# include <time.h>
#include "funcTest.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Rus");

    time_t t = time(0);

    bool flag = true;
    bool flag_win = false;

    int row = 1;
    int col = 1;

    int count_point = 0;

    while (count_point != 5 && flag) {

        PrintControl(count_point, t);
        PrintMap();

        MoveHero(map, row, col, flag, flag_win);

        if (flag_win) {
            count_point++;
            flag_win = false;
        }

        system("clear");

    }
    cout << endl;
    if (count_point == 5) {
        cout << "Вы добрались до цели. ВЫ МОЛОДЦЫ!!!" << endl;
        cout << "Время прохождения: " << time(0) - t << " секунд" << endl;
    }

    cout << "Спасибо за игру" << endl;
    return 0;

}

