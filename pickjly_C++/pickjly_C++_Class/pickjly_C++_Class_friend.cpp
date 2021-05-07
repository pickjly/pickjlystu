/*** 
 * 
 *  Author: pickjly
 *  Date  : 2021-04-25
 *  Email : 2461789521@qq.com
 * 
 * ***/

#include <iostream>
#include <string>
using namespace std;

// class Room1;
// class Room;


class Room {

public:

    friend class Room1;

    string _Sittingroom;
    string _Cleanroom;

    friend void confidante(Room &room);

    Room(){
        room_num = 0;
    }
    Room(int num){
        room_num = num;
    }
    Room(string sittingroom, string cleanroom, string bedroom): _Sittingroom(sittingroom), _Cleanroom(cleanroom), _Bedroom(bedroom) {

    }
    void dispRoomNum() {
        cout << " Room has  " << room_num << " rooms" << endl;
    }

private:

    string _Bedroom;
    int room_num;

};

class Room1 {
public:

    Room1() {
        room_num = 0;
    }

    Room1(Room *room) {
        // this->room_num = room->room_num += 1;
        this->room_num = room->room_num += 1;
    }

    void dispRoomNum() {
        cout << " Room1 has  " << room_num << " rooms" << endl;
    }

private:

    int room_num;
};

// 全局函数 做友元
void confidante(Room &room) {
    cout << " confidante is visiting your _Sittingroom " << room._Sittingroom << endl;
    cout << " confidante is visiting your Bedroom " << room._Bedroom << endl;
}

void test01() {
    Room room1("sittingroom", "cleanroom", "bedroom");
    confidante(room1);
}

void test02() {
    Room room01(10);
    room01.dispRoomNum();
    Room1 room02(&room01);
    room02.dispRoomNum();
}

int main() {
    // test01();
    test02();
}
