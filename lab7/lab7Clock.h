//
// Created by Nimna Wijedasa 30146042
//

#ifndef LAB7_LAB7CLOCK_H
#define LAB7_LAB7CLOCK_H

class Clock {
public:

    Clock();

    explicit Clock (int total_sec);

    Clock (int h, int m, int s);

     int get_hour () const ;
     int get_minute () const ;
     int get_second () const ;


    void set_hour(int arg);
    void set_minute(int arg);
    void set_second(int arg);

    void increment();
    void decrement();
    void add_seconds(int sec);

private:
    int hour{};
    int minute{};
    int second{};
    int hms_to_sec() const;
    void sec_to_hms(int s);

};

#endif //LAB7_LAB7CLOCK_H
