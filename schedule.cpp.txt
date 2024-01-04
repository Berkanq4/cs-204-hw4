//
// Created by bberk on 4/23/2023.
//
#include <iostream>
#include "schedule.h"
using namespace std;


Schedule::Schedule() {
    time_slots = 0;
    data = new string * [7];
    for (int i =0; i < 7; i++){
        data[i] = new string;
    }
}

Schedule::Schedule(const int c) {
    data = new string * [7];
    time_slots = c;
    for (int i = 0; i < 7; i++) {
        data[i] = new string[c];
        for (int j = 0; j < c; j++) {
            data[i][j] = "free";
        }
    }
}

Schedule::Schedule(const Schedule & copy) { //deep copy
    this->time_slots = copy.time_slots;
    this->data = new string * [7];
    for (int i = 0; i < 7; i++){
        data[i] = new string[copy.time_slots];
        for (int j = 0; j < copy.time_slots; j++){
            data[i][j] = copy.data[i][j];
        }
    }
}


void Schedule::DeleteHelper(string **data) { //helping the destrucotr
    for (int i = 0; i < 7; i++){
        delete[] data[i];
    }
    delete[] data;
}

Schedule::~Schedule() {
    DeleteHelper(data);
}

Schedule &Schedule::operator=(const Schedule &rhs) {
    if (this != &rhs){
        //this->Schedule::~Schedule();
        DeleteHelper(this->data);
        this->time_slots = rhs.time_slots;
        data = new string * [7];

        for (int i = 0; i < 7 ; i ++){
            data[i] = new string[time_slots];
        }

        for (int i = 0; i < 7; i++){
            for (int j = 0; j < time_slots; j++){
                data[i][j] = rhs.data[i][j];
            }
        }

    }
    return *this;
}

Schedule &Schedule::operator+(const Days & rhs){
    Schedule lhs = *this;
    for (int i = 0; i < lhs.time_slots; i++){
        lhs.data[rhs][i] = "busy";
    }
    return lhs;
}

Schedule & Schedule::operator+(const int & rhs){
    // Addition of an integer value to a Schedule object
    Schedule lhs = *this;
    for (int i = 0; i < 7; i++) {
        lhs.data[i][rhs] = "busy";
    }
    return lhs;
}

Schedule & Schedule::operator+(const Schedule & rhs){
    Schedule result(time_slots);
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < time_slots; j++){
            if (this->data[i][j] == "free" && rhs.data[i][j] == "free"){
                result.data[i][j] = "free";
            }
            else{
                result.data[i][j] = "busy";
            }
        }
    }
    return result;
}

Schedule & Schedule::operator*(const Schedule & rhs){
    Schedule result(time_slots);
    for(int i = 0; i < 7; i++){
        for (int j = 0; j < time_slots; j++){
            if (this->data[i][j] == "free" || rhs.data[i][j] == "free"){
                result.data[i][j] = "free";
            }
            else{
                result.data[i][j] = "busy";
            }
        }
    }
    return result;
}

string * Schedule::operator[](const Days & rhs) const{
    Days gun = rhs;
    return data[gun];
}

const bool & Schedule::operator < (const Schedule & rhs) {
    int count_lhs = 0;
    int count_rhs = 0;
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < time_slots;j ++){
            if (this->data[i][j] == "busy"){
                count_lhs += 1;
            }
            if (rhs.data[i][j] == "busy"){
                count_rhs += 1;
            }
        }
    }

    if (count_rhs > count_lhs){
        return true;
    }
    else{
        return false;
    }
}

int Schedule::getTime() const{
    return time_slots;
}

string ** Schedule::getData() const{
    return data;
}


ostream & operator<<(ostream & lhs, Schedule & rhs){
    int zaman = rhs.getTime();

    for (int i = 0; i < 7; i ++){
        for (int j = 0; j < zaman; j++) {
            lhs << rhs.getData()[i][j] << " ";
        }
        lhs << endl;
    }
    return lhs;
}


ostream & operator<<(ostream & lhs, Days & rhs){
    Days gun = rhs;

    switch (gun){
        case 0:
            lhs << "Monday" << endl;
            break;
        case 1:
            lhs << "Tuesday" << endl;
            break;
        case 2:
            lhs << "Wednesday" << endl;
            break;
        case 3:
            lhs << "Thursday" << endl;
            break;
        case 4:
            lhs << "Friday" << endl;
            break;
        case 5:
            lhs << "Saturday" << endl;
            break;
        case 6:
            lhs << "Sunday" << endl;
            break;
    }
    return lhs;
}
