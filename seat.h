#ifndef HW3_2_SEAT_H
#define HW3_2_SEAT_H
#define MAIN_HALL_PRICE 100
#define FRONT_SEAT_PRICE 500
#define MIDDLE_SEAT_PRICE 250
#define SPECIAL_SEAT_PRICE 300
#define GOLDEN_CIRCLE_PRICE 1000
#define DISABLE_SEAT_PRICE 200


#include <iostream>
#include <string>

using std::string;
using std::exception;
using std::to_string;


// ---------------------------------------------
class NoPrice : public exception {

    const char *what() const noexcept override; //TODO noexcept?
};

// ---------------------------------------------
class Seat {

protected: //TODO protected or getters?
    int row;
    int chair_number;
    int base_price;

public: //TODO copy and =?

    explicit Seat(int row, int chair_number, int base_price);

    explicit Seat(int row, int chair_number); //TODO is this the way another
    // constructor just for green room??

    virtual ~Seat() = default; //TODO default?

    virtual const string location() const = 0;

    virtual const int price() const = 0;

};

// ---------------------------------------------
class GreenRoomSeat : public Seat {

public:

    explicit GreenRoomSeat(int row, int chair_number);

    ~GreenRoomSeat() override = default;

    const string location() const override;

    const int price() const override;

};

// ---------------------------------------------
class MainHallSeat : public Seat {

public:

    explicit MainHallSeat(int row, int chair_number, int base_price);

    virtual ~MainHallSeat() = default; //TODO virtual vs override for
    // destructors?

};

// ---------------------------------------------
class SpecialSeat : public MainHallSeat {

public:

    explicit SpecialSeat(int row, int chair_number, int base_price);

    virtual ~SpecialSeat() = default;

};

// ---------------------------------------------
class GoldenCircleSeat : public SpecialSeat {

public:

    explicit GoldenCircleSeat(int row, int chair_number, int base_price);

    ~GoldenCircleSeat() override = default;

    const string location() const override;

    const int price() const override;
};


// ---------------------------------------------
class DisablePodiumSeat : public SpecialSeat {

public:

    explicit DisablePodiumSeat(int row, int chair_number, int base_price);

    explicit DisablePodiumSeat(int row, int chair_number); //TODO two cons.??

    ~DisablePodiumSeat() override = default;

    const string location() const override;

    const int price() const override;
};

// ---------------------------------------------
class RegularSeat : public MainHallSeat {

protected:
    char area;

public:

    explicit RegularSeat(char area, int row, int chair_number, int base_price);

    virtual ~RegularSeat() = default;

};

// ---------------------------------------------
class FrontRegularSeat : public RegularSeat {

public:

    explicit FrontRegularSeat(char area, int row, int chair_number, int
    base_price);

    ~FrontRegularSeat() override = default;

    const string location() const override;

    const int price() const override;
};

// ---------------------------------------------
class MiddleRegularSeat : public RegularSeat {

public:

    explicit MiddleRegularSeat(char area, int row, int chair_number, int
    base_price);

    ~MiddleRegularSeat() override = default;

    const string location() const override;

    const int price() const override;
};

// ---------------------------------------------
class RearRegularSeat : public RegularSeat {

public:

    explicit RearRegularSeat(char area, int row, int chair_number, int
    base_price);

    ~RearRegularSeat() override = default;

    const string location() const override;

    const int price() const override;

};

// ---------------------------------------------

#endif //HW3_2_SEAT_H
