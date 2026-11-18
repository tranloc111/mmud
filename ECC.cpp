
#include <iostream>
using namespace std;

struct Diem {
    long long x, y;
    bool voCuc;
};

// Chuan hoa modulo
long long mod(long long x, long long p) {
    return (x % p + p) % p;
}

// Tim diem doi -P
Diem Doi(Diem P, long long p) {
    if (P.voCuc) return P;

    return {P.x, mod(-P.y, p), false};
}

// Cong hai diem
Diem Cong(Diem P, Diem Q, long long a, long long p) {
    if (P.voCuc) return Q;
    if (Q.voCuc) return P;

    // P va Q doi nhau
    if (P.x == Q.x && mod(P.y + Q.y, p) == 0)
        return {0, 0, true};

    long long tu, mau;

    // Truong hop P = Q
    if (P.x == Q.x && P.y == Q.y) {
        tu = mod(3 * P.x * P.x + a, p);
        mau = mod(2 * P.y, p);
    }
    else {
        tu = mod(Q.y - P.y, p);
        mau = mod(Q.x - P.x, p);
    }

    // Tim lambda bang cach thu
    long long lambda = -1;

    for (int i = 0; i < p; i++) {
        if ((i * mau) % p == tu) {
            lambda = i;
            break;
        }
    }

    if (lambda == -1)
        return {0, 0, true};

    long long xR = mod(lambda * lambda - P.x - Q.x, p);
    long long yR = mod(lambda * (P.x - xR) - P.y, p);

    return {xR, yR, false};
}

// Nhan mot diem voi so nguyen n
Diem Nhan(Diem P, long long n, long long a, long long p) {
    Diem R = {0, 0, true};

    while (n > 0) {
        if (n % 2 == 1)
            R = Cong(R, P, a, p);

        P = Cong(P, P, a, p);
        n = n / 2;
    }

    return R;
}

// In diem
void InDiem(Diem P) {
    if (P.voCuc)
        cout << "O";
    else
        cout << "(" << P.x << ", " << P.y << ")";
}

int main() {
    long long a, b, p;
    long long nA, nB;

    Diem G, PA, PB, KA, KB, P, C, GiaiMa;

    // B1: Nhap thong so duong cong va diem G
    cout << "Nhap a, b, p: ";
    cin >> a >> b >> p;

    cout << "Nhap toa do diem G: ";
    cin >> G.x >> G.y;
    G.voCuc = false;

    // B2: Nhap khoa rieng A va B
    cout << "Nhap khoa rieng nA: ";
    cin >> nA;

    cout << "Nhap khoa rieng nB: ";
    cin >> nB;

    // B3: Tinh khoa cong khai
    PA = Nhan(G, nA, a, p);
    PB = Nhan(G, nB, a, p);

    cout << "\nKhoa cong khai PA = ";
    InDiem(PA);

    cout << "\nKhoa cong khai PB = ";
    InDiem(PB);

    // B4: Tinh khoa chung
    KA = Nhan(PB, nA, a, p);
    KB = Nhan(PA, nB, a, p);

    cout << "\n\nKhoa chung A tinh KA = ";
    InDiem(KA);

    cout << "\nKhoa chung B tinh KB = ";
    InDiem(KB);

    // Kiem tra khoa chung
    if (KA.voCuc || KB.voCuc ||
        KA.x != KB.x || KA.y != KB.y) {
        cout << "\nKhoa chung khong hop le!";
        return 0;
    }

    // Nhap ban ro la mot diem
    cout << "\n\nNhap toa do ban ro P: ";
    cin >> P.x >> P.y;
    P.voCuc = false;

    // Ma hoa: C = P + K
    C = Cong(P, KA, a, p);

    cout << "\nBan ma C = ";
    InDiem(C);

    // Giai ma: P = C - K = C + (-K)
    GiaiMa = Cong(C, Doi(KA, p), a, p);

    cout << "\nBan ro sau giai ma = ";
    InDiem(GiaiMa);

    return 0;
}

