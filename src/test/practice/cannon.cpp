#include "cannon.h"

void Cannon::load_bullets() {
    if (this -> canShoot)
    {
        cout << "不能反复填充子弹！" << endl;
        return;
    }
    this -> canShoot = true;
    cout << "已填充一颗子弹" << endl;
}

void Cannon::fire() {
    if (!this -> canShoot)
    {
        cout << "没有炮弹，发射失败！" << endl;
    }
    else
    {
        int target_loc = tools::rand(0, this -> SCENE_SIZE);
        int shot_loc = tools::rand(0, this -> SCENE_SIZE);
        if (abs(target_loc - shot_loc) <= HIT_RANGE)
        {
            win = true;
            cout << "恭喜你击中目标！" << endl;
        }
        else
        {
            cout << "炮弹偏离目标，继续努力！" << endl;
        }
        this -> canShoot = false;
    }
}

void start_cannon()
{
    system("CHCP 65001 && cls");

    size_t time = tools::timer([] {
        Cannon cannon;
        cout << "炮弹游戏\n输入1填充子弹\n输入2击打目标" << endl;
        while (!cannon.win)
        {
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                cannon.load_bullets();
            }
            else if (choice == 2)
            {
                cannon.fire();
            }
            else
            {
                cout << "输入不合法！" << endl;
            }
        }
    });

    cout << "\n本场游戏共耗时" << time << "ms!" << endl;
    system("pause");
}
