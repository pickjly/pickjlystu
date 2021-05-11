/***
 * 2021-05-07
 * pickjly
 * 重载运算符 + * <<
 * ***/

#include <iostream>

using namespace std;

class Time {

private:

    int _hours;
    int _minutes;
    int _seconds;

public:

    Time() {
        // _hours = 0;;
        // _minutes = 0;
        // _seconds = 0;
    }

    Time(int hours, int minutes, int seconds):_hours(hours), _minutes(minutes), _seconds(seconds) {

    }
    Time operator+(const Time &time) const;
    
    void disp();

};

Time Time::operator+(const Time &time1) const {
    Time tmp;
    tmp._hours   = this->_hours   + time1._hours;
    tmp._minutes = this->_minutes + time1._minutes;
    tmp._seconds = this->_seconds + time1._seconds;
    return tmp;
}

void Time::disp() {
    cout << " hour " << _hours << " _minutes " << _minutes << " _seconds " << _seconds << endl;
}

void test01() {

}

int main() {
    Time time1(1, 2, 3);
    Time time2(4, 5, 6);
    time1.disp();
    time2.disp();
    
    Time time;
    time = time1 + time2;
    time.disp();
}
