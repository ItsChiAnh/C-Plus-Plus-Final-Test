#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Vemaybay {
private:
    string tenchuyen;
    string ngaybay;
    float giave;
public:
    Vemaybay(string tc, string nb, float gv) : tenchuyen(tc), ngaybay(nb), giave(gv) {}
    ~Vemaybay() {
        cout << "Vemaybay: " << tenchuyen << endl;
    }

    void nhap() {
        cout << "Enter flight name: ";
        cin >> tenchuyen;
        cout << "Enter flight date: ";
        cin >> ngaybay;
        cout << "Enter ticket price: ";
        cin >> giave;
    }

    void xuat() const {
        cout << "Flight: " << tenchuyen << ", Date: " << ngaybay << ", Price: " << giave << endl;
    }

    float getgiave() const {
        return giave;
    }
};

class Nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;
public:
    Nguoi(string ht, string gt, int t) : hoten(ht), gioitinh(gt), tuoi(t) {}
    virtual ~Nguoi() {
        cout << "Nguoi: " << hoten << endl;
    }

    void nhap() {
        cout << "Enter name: ";
        cin >> hoten;
        cout << "Enter gender: ";
        cin >> gioitinh;
        cout << "Enter age: ";
        cin >> tuoi;
    }

    void xuat() const {
        cout << "Name: " << hoten << ", Gender: " << gioitinh << ", Age: " << tuoi << endl;
    }
};

class HanhKhach : public Nguoi {
private:
    vector<Vemaybay> ve;
public:
    HanhKhach(string ht, string gt, int t) : Nguoi(ht, gt, t) {}
    ~HanhKhach() {
        cout << "HanhKhach: " << hoten << endl;
    }

    void nhap() {
        Nguoi::nhap();
        int soluong;
        cout << "Enter the number of tickets: ";
        cin >> soluong;
        ve.reserve(soluong);
        for (int i = 0; i < soluong; ++i) {
            string tenchuyen, ngaybay;
            float giave;
            cout << "Enter details for ticket " << i + 1 << ":\n";
            cout << "Flight name: ";
            cin >> tenchuyen;
            cout << "Flight date: ";
            cin >> ngaybay;
            cout << "Ticket price: ";
            cin >> giave;
            ve.emplace_back(tenchuyen, ngaybay, giave);
        }
    }

    void xuat() const {
        Nguoi::xuat();
        for (const auto& ticket : ve) {
            ticket.xuat();
        }
    }

    float tongtien() const {
        float total = 0;
        for (const auto& ticket : ve) {
            total += ticket.getgiave();
        }
        return total;
    }
};

int main() {
    int n;
    cout << "Enter number of passengers: ";
    cin >> n;
    vector<HanhKhach> khachHang;
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for passenger " << i + 1 << ":\n";
        khachHang.emplace_back("", "", 0);
        khachHang.back().nhap();
    }

    // Displaying passenger details
    for (const auto& kh : khachHang) {
        kh.xuat();
        cout << "Total payment: " << kh.tongtien() << endl;
    }

    // Sorting passengers by total payment in descending order
    sort(khachHang.begin(), khachHang.end(), [](const HanhKhach& a, const HanhKhach& b) {
        return a.tongtien() > b.tongtien();
    });

    cout << "\nSorted List by Total Payment (Descending):\n";
    for (const auto& kh : khachHang) {
        kh.xuat();
        cout << "Total payment: " << kh.tongtien() << endl;
    }

    return 0;
}

