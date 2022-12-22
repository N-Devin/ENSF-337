//
// Created by Nimna Wijedasa 30146042
//

#include "lab7Clock.h"

Clock::Clock(): hour(0), minute(0), second(0) {

}

Clock::Clock(int h,int m,int s) {
    if(hour<0 || hour>23 || minute<0 || minute>59 || second<0 || second>59){
        hour = 0;
        minute = 0;
        second = 0;
    }
}

Clock::Clock(int total_sec) {
    if (total_sec < 0){
        hour = 0;
        minute = 0;
        second = 0;
    }
    else{
    }
    sec_to_hms(total_sec);
}

int Clock::get_hour() const {
    return hour;
}
int Clock::get_minute() const {
    return minute;
}
int Clock::get_second() const {
    return second;
}


void Clock::set_hour(int arg) {
    if (arg < 23 && arg > 0){
        hour = arg;
    }
}
void Clock::set_minute(int arg) {
    if (arg < 59 && arg > 0) {
        minute = arg;
    }
}
void Clock::set_second(int arg) {
    if (arg < 59 && arg > 0) {
        second = arg;
    }
}

void Clock::increment() {
    int sec_total = this->hms_to_sec() + 1;
    sec_to_hms(sec_total);
}

void Clock::decrement() {
    int sec_total = this->hms_to_sec() - 1;
    sec_to_hms(sec_total);

}

void Clock::add_seconds(int sec) {
    int sec_total = this->hms_to_sec() + sec;
    sec_to_hms(sec_total);

}

int Clock::hms_to_sec()const {
    int sec_total = hour*3600 + minute*60 + second;
    return sec_total;
}

void Clock::sec_to_hms(int s) {
    s = s % (24*60*60);
    hour = s / 3600;
    minute = s % 60;
    second = s - (hour*3600 + minute*60 );

    if (second == -1)
    {
        second = 59;
        minute--;
    }
    if (minute == -1)
    {
        minute = 59;
        hour--;
    }
    if (hour == -1)
    {
        hour = 23;
    }

}




