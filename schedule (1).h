//
// Created by bberk on 4/23/2023.
//

#ifndef HOMEWORK4_SCHEDULE_H
#define HOMEWORK4_SCHEDULE_H
#include <iostream>
using namespace std;
enum Days {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

class Schedule{
private:
    int time_slots;
    string ** data;

public:
    Schedule(); // default constructor
    Schedule(const int time_slots); // paramteric constructor
    Schedule (const Schedule &); //deep copy constructor
    ~Schedule(); //destructor
    void DeleteHelper(string ** data);
    Schedule & operator = (const Schedule & rhs);
    Schedule & operator + (const Days & rhs);
    Schedule & operator + (const int & rhs);
    Schedule & operator + (const Schedule & rhs);
    Schedule & operator * (const Schedule & rhs);
    string * operator [] (const Days & rhs) const;
    const bool & operator < (const Schedule & rhs);
    int getTime() const;
    string ** getData() const;
};

ostream & operator << (ostream & lhs, Schedule & rhs);
ostream & operator << (ostream & lhs, Days & rhs);
#endif //HOMEWORK4_SCHEDULE_H