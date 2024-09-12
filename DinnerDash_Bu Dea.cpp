#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <unordered_map>

using namespace std;

enum class OrderStatus {
    NotYetTaken,
    InKitchen,
    Served
};

// Kelas untuk Order yang dipesan oleh pelanggan
class Order {
private:
    string details;
    OrderStatus status;

public:
    Order(const string& details) : details(details), status(OrderStatus::NotYetTaken) {}
    void setStatus(OrderStatus status) { this->status = status; }
    OrderStatus getStatus() const { return status; }

    string getDetails() const { return details; }
};

// Kelas untuk Pelanggan
class Customer {
private:
    string name;
    Order order;
    int emotionLevel; // Ranges from 1 (unhappy) to 5 (very happy)
    bool isServed;

public:
    Customer(const string& name, const string& orderDetails)
        : name(name), order(orderDetails), emotionLevel(5), isServed(false) {}

    Order& getOrder() { return order; }
    string getName() const { return name; }
    void decreaseEmotion() {
        if (emotionLevel > 1) {
            emotionLevel--;
        }
    }
    void resetEmotion() { emotionLevel = 5; }
    int getEmotionLevel() const { return emotionLevel; }
    bool getIsServed() const { return isServed; }
    void serveOrder() { isServed = true; }

    void displayEmotion() const {
        cout << name << "'s Emotion: " << emotionLevel << "/5" << endl;
    }
};

// Kelas untuk Meja yang bisa memiliki pelanggan
class Table {
private:
    int tableNumber;
    Customer* customer;

public:
    Table(int number) : tableNumber(number), customer(nullptr) {}

    void assignCustomer(Customer* cust) { customer = cust; }
    Customer* getCustomer() const { return customer; }

    void displayOrderStatus() const {
        if (customer == nullptr) {
            cout << "Table " << tableNumber << " has no customer." << endl;
            return;
        }

        OrderStatus status = customer->getOrder().getStatus();
        string statusMessage;
        switch (status) {
        case OrderStatus::NotYetTaken:
            statusMessage = "Not Yet Taken";
            break;
        case OrderStatus::InKitchen:
            statusMessage = "In Kitchen";
            break;
        case OrderStatus::Served:
            statusMessage = "Served";
            break;
        }

        cout << "Table " << tableNumber << " - Order: " << customer->getOrder().getDetails()
            << " - Status: " << statusMessage << endl;
    }
};

// Kelas untuk Pelayan yang bertugas mengambil dan mengantarkan pesanan
class Waiter {
public:
    void takeOrder(Table& table) {
        Customer* customer = table.getCustomer();
        if (customer != nullptr && customer->getOrder().getStatus() == OrderStatus::NotYetTaken) {
            customer->getOrder().setStatus(OrderStatus::InKitchen);
            cout << "Waiter has taken order from Table " << table.getCustomer()->getName()
                << " and sent it to the kitchen: " << customer->getOrder().getDetails() << endl;
        }
    }

    void deliverOrder(Table& table) {
        Customer* customer = table.getCustomer();
        if (customer != nullptr && customer->getOrder().getStatus() == OrderStatus::InKitchen) {
            customer->getOrder().setStatus(OrderStatus::Served);
            customer->resetEmotion();  // Reset customer emotion to 5
            customer->serveOrder();
            cout << "Waiter has delivered the order to Table " << customer->getName()
                << ": " << customer->getOrder().getDetails() << endl;
            customer->displayEmotion();  // Display reset emotion level
        }
    }
};

// Kelas untuk Dapur yang bertugas mempersiapkan pesanan
class Kitchen {
public:
    void prepareOrder(Table& table) {
        Customer* customer = table.getCustomer();
        if (customer != nullptr && customer->getOrder().getStatus() == OrderStatus::InKitchen) {
            cout << "Kitchen is preparing the order for " << customer->getName() << "..." << endl;
            this_thread::sleep_for(chrono::seconds(5)); // Simulate preparation time
            cout << "Order for " << customer->getName() << " is ready!" << endl;
        }
    }
};

// Fungsi simulasi permainan
void simulateDinerDash() {
    // Membuat pelanggan
    Customer customer1("John", "Pasta");
    Customer customer2("Anna", "Pizza");

    // Membuat meja
    Table table1(1);
    Table table2(2);

    // Menugaskan pelanggan ke meja
    table1.assignCustomer(&customer1);
    table2.assignCustomer(&customer2);

    // Membuat pelayan dan dapur
    Waiter waiter;
    Kitchen kitchen;

    // Menampilkan status awal meja
    table1.displayOrderStatus();
    table2.displayOrderStatus();

    // Pelayan mengambil pesanan
    waiter.takeOrder(table1);
    waiter.takeOrder(table2);

    // Mulai proses memasak di dapur
    kitchen.prepareOrder(table1);
    kitchen.prepareOrder(table2);

    // Pelayan mengantarkan pesanan setelah dapur selesai
    waiter.deliverOrder(table1);
    waiter.deliverOrder(table2);

    // Menampilkan status akhir
    table1.displayOrderStatus();
    table2.displayOrderStatus();
}

int main() {
    simulateDinerDash();
    return 0;
}
