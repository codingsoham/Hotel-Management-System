#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Room {
public:
    Room(int roomNumber, int capacity, double pricePerNight)
        : roomNumber(roomNumber), capacity(capacity), pricePerNight(pricePerNight), isOccupied(false) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    int getCapacity() const {
        return capacity;
    }

    double getPricePerNight() const {
        return pricePerNight;
    }

    bool isAvailable() const {
        return !isOccupied;
    }

    void bookRoom() {
        isOccupied = true;
    }

    void checkoutRoom() {
        isOccupied = false;
    }

private:
    int roomNumber;
    int capacity;
    double pricePerNight;
    bool isOccupied;
};

class Hotel {
public:
    void addRoom(int roomNumber, int capacity, double pricePerNight) {
        rooms.push_back(Room(roomNumber, capacity, pricePerNight));
    }

    void displayAvailableRooms() const {
        cout << "Available Rooms:" << endl;
        for (const Room& room : rooms) {
            if (room.isAvailable()) {
                cout << "Room Number: " << room.getRoomNumber() << " | Capacity: " << room.getCapacity()
                     << " | Price per Night: $" << room.getPricePerNight() << endl;
            }
        }
    }

    void bookRoom(int roomNumber) {
        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber && room.isAvailable()) {
                room.bookRoom();
                cout << "Room " << roomNumber << " has been booked." << endl;
                return;
            }
        }
        cout << "Room " << roomNumber << " is not available." << endl;
    }

    void checkoutRoom(int roomNumber) {
        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber && !room.isAvailable()) {
                room.checkoutRoom();
                cout << "Room " << roomNumber << " has been checked out." << endl;
                return;
            }
        }
        cout << "Room " << roomNumber << " is not occupied." << endl;
    }

private:
    vector<Room> rooms;
};

int main() {
    Hotel hotel;
    hotel.addRoom(101, 2, 100.0);
    hotel.addRoom(102, 4, 150.0);
    hotel.addRoom(103, 3, 120.0);

    int choice;
    while (true) {
        cout << "\nHotel Management System Menu:" << endl;
        cout << "1. Display available rooms" << endl;
        cout << "2. Book a room" << endl;
        cout << "3. Checkout from a room" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayAvailableRooms();
                break;
            case 2:
                int roomNumberToBook;
                cout << "Enter room number to book: ";
                cin >> roomNumberToBook;
                hotel.bookRoom(roomNumberToBook);
                break;
            case 3:
                int roomNumberToCheckout;
                cout << "Enter room number to checkout: ";
                cin >> roomNumberToCheckout;
                hotel.checkoutRoom(roomNumberToCheckout);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
