#include "seat.h"

//this function is used for throwing an error if there is no price for a seat
const char* NoPrice::what() const noexcept { //TODO noexcept?
    return ("Not For Sale !");
}

///Seat constructor

Seat::Seat(int row, int chair_number, int base_price) :
        row(row), chair_number(chair_number), base_price(base_price) {}

///MainHallSeat constructor
MainHallSeat::MainHallSeat(int row, int chair_number, int base_price) :
        Seat(row, chair_number, base_price) {}

///Start of GreenRoomSeat class methods:
GreenRoomSeat::GreenRoomSeat(int row, int chair_number) : Seat(row ,
        chair_number){}

const string GreenRoomSeat::location() const {
    string location;
    location += "Green Room-> line: ";
    location += to_string(this->row);
    location += ", chair: ";
    location += to_string(this->chair_number);
    return location;
}

const int GreenRoomSeat::price() const {
    throw NoPrice(); //green room has no price!
}

///RegularSeat constructor
RegularSeat::RegularSeat(char area, int row, int chair_number, int base_price)
        : MainHallSeat(row, chair_number, base_price), area(area) {}


///Start of FrontRegularSeat class methods:

FrontRegularSeat::FrontRegularSeat(char area, int row, int chair_number, int
base_price) : RegularSeat(area, row, chair_number, base_price) {}

const string FrontRegularSeat::location() const {
    string location;
    location += "Front-> area: ";
    location += this->area;
    location += ", line: ";
    location += to_string(this->row);
    location += ", chair: ";
    location += to_string(this->chair_number);
    return location;
}

const int FrontRegularSeat::price() const {
    return (this->base_price + MAIN_HALL_PRICE + FRONT_SEAT_PRICE);
}

///End of FrontRegularSeat class methods:

///Start of MiddleRegularSeat class methods:

MiddleRegularSeat::MiddleRegularSeat(char area, int row, int chair_number, int
base_price) : RegularSeat(area, row, chair_number, base_price) {}

const string MiddleRegularSeat::location() const {
    string location;
    location += "Middle-> area: ";
    location += this->area;
    location += ", line: ";
    location += to_string(this->row);
    location += ", chair: ";
    location += to_string(this->chair_number);
    return location;
}

const int MiddleRegularSeat::price() const {
    return (this->base_price + MAIN_HALL_PRICE + MIDDLE_SEAT_PRICE);
}

///End of MiddleRegularSeat class methods:

///Start of RearRegularSeat class methods:

RearRegularSeat::RearRegularSeat(char area, int row, int chair_number, int
base_price) : RegularSeat(area, row, chair_number, base_price) {}

const string RearRegularSeat::location() const {
    string location;
    location += "Rear-> area: ";
    location += this->area;
    location += ", line: ";
    location += to_string(this->row);
    location += ", chair: ";
    location += to_string(this->chair_number);
    return location;
}

const int RearRegularSeat::price() const {
    return (this->base_price + MAIN_HALL_PRICE);
}

///End of RearRegularSeat class methods:


///SpecialSeat constructor
SpecialSeat::SpecialSeat(int row, int chair_number, int base_price)
        : MainHallSeat(row, chair_number, base_price) {}

///Start of GoldenCircleSeat methods:

GoldenCircleSeat::GoldenCircleSeat(int row, int chair_number, int base_price) :
        SpecialSeat(row, chair_number, base_price) {}

const string GoldenCircleSeat::location() const {
    string location;
    location += "Golden Circle-> line: ";
    location += to_string(this->row);
    location += ", chair: ";
    location += to_string(this->chair_number);
    return location;
}

const int GoldenCircleSeat::price() const {
    return (this->base_price + MAIN_HALL_PRICE + SPECIAL_SEAT_PRICE +
            GOLDEN_CIRCLE_PRICE);
}

///End of GoldenCircleSeat class methods:

///Start of DisablePodiumSeat methods:

DisablePodiumSeat::DisablePodiumSeat(int row, int chair_number, int base_price)
        : SpecialSeat(row, chair_number, base_price) {}

const string DisablePodiumSeat::location() const {
    string location;
    location += "Disable Podium-> line: ";
    location += to_string(this->row);
    location += ", chair: ";
    location += to_string(this->chair_number);
    return location;
}

const int DisablePodiumSeat::price() const {
    return (DISABLE_SEAT_PRICE); //200 by default
}

///End of DisablePodiumSeat class methods: