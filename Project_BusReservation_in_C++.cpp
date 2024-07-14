// Bus reservation system

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 4;

class Seat {
private:
    int row;
    int col;
    bool reserved;
    string passengerName;

public:
    Seat(int r, int c) {
        row = r;
        col = c;
        reserved = false;
        passengerName = "";
    }

    void reserve(const string& name) {
        reserved = true;
        passengerName = name;
    }

    void cancel() {
        reserved = false;
        passengerName = "";
    }

    bool isReserved() const {
        return reserved;
    }

    string getPassengerName() const {
        return passengerName;
    }

    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }

    void print() const {
        cout << "Row " << row << ", Col " << col;
        if (reserved) {
            cout << " (reserved for " << passengerName << ")";
        } else {
            cout << " (available)";
        }
        cout << endl;
    }
};

class Bus {
private:
    vector<vector<Seat>> seats;

public:
    Bus() {
        for (int i = 0; i < NUM_ROWS; i++) {
            vector<Seat> row;
            for (int j = 0; j < NUM_COLS; j++) {
                row.emplace_back(i, j);
            }
            seats.push_back(row);
        }
    }

    void reserve(int row, int col, const string& name) {
        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
            cout << "Invalid seat position" << endl;
            return;
        }
        Seat& seat = seats[row][col];  // Use reference to modify the original seat
        if (seat.isReserved()) {
            cout << "Seat is already reserved for " << seat.getPassengerName() << endl;
        } else {
            seat.reserve(name);
            cout << "Seat reserved for " << name << endl;
        }
    }

    void cancel(int row, int col) {
        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
            cout << "Invalid seat position" << endl;
            return;
        }
        Seat& seat = seats[row][col];  // Use reference to modify the original seat
        if (!seat.isReserved()) {
            cout << "Seat is not reserved" << endl;
        } else {
            string name = seat.getPassengerName();
            seat.cancel();
            cout << "Reservation for " << name << " cancelled" << endl;
        }
    }

    void printLayout() const {
        cout << "Bus Layout:" << endl;
        for (const auto& row : seats) {
            for (const auto& seat : row) {
                seat.print();
            }
        }
        cout << endl;
    }
};

int main() {
    Bus bus;

    bus.printLayout();

    bus.reserve(2, 1, "Alice");
    bus.reserve(5, 2, "Bob");

    bus.printLayout();

    bus.cancel(2, 1);

    bus.printLayout();

    return 0;
}


