#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Diem {
    int x, y;
};

// Quy ý?c ði?m vô c?c O = (-1, -1)
const Diem DIEM_O = {-1, -1};

// Ch? gi? l?i b?ng ánh x? 26 ch? cái 'A' -> 'Z' trên ðý?ng cong E_23(1, 1)
Diem bangAnhXa[26] = {
    {0, 1},  {0, 22}, {1, 7},   {1, 16}, {3, 10},  {3, 13}, {4, 0},   // A -> G
    {5, 4},  {5, 19}, {6, 4},   {6, 19}, {7, 11},  {7, 12}, {9, 7},   // H -> N
    {9, 16}, {11, 3}, {11, 20}, {12, 4}, {12, 19}, {13, 7}, {13, 16}, // O -> U
    {17, 3}, {17, 20},{18, 3},  {18, 20},{19, 5}                      // V -> Z
};

// 1. Hàm chia l?y dý luôn tr? v? s? dýõng trong [0, p-1]
int mod(int a, int p) {
    return (a % p + p) % p;
}

// 2. Hàm t?m ngh?ch ð?o modulo b?ng v?ng l?p for thý?ng
int nghichDao(int a, int p) {
    a = mod(a, p);
    for (int x = 1; x < p; x++) {
        if ((a * x) % p == 1) return x;
    }
    return 0;
}

// 3. Hàm c?ng 2 ði?m P + Q trên ðý?ng cong E_p(a, b)
Diem congDiem(Diem P, Diem Q, int a, int p) {
    if (P.x == -1 && P.y == -1) return Q;
    if (Q.x == -1 && Q.y == -1) return P;

    // Trý?ng h?p 2 ði?m ð?i nhau: P + (-P) = O
    if (P.x == Q.x && mod(P.y + Q.y, p) == 0) {
        return DIEM_O;
    }

    int lambda;
    if (P.x == Q.x && P.y == Q.y) {
        // Trý?ng h?p 2 ði?m trùng nhau (nhân ðôi ði?m 2P)
        lambda = mod((3 * P.x * P.x + a) * nghichDao(2 * P.y, p), p);
    } else {
        // Trý?ng h?p 2 ði?m khác nhau (P + Q)
        lambda = mod((Q.y - P.y) * nghichDao(Q.x - P.x, p), p);
    }

    Diem R;
    R.x = mod(lambda * lambda - P.x - Q.x, p);
    R.y = mod(lambda * (P.x - R.x) - P.y, p);
    return R;
}

// 4. Hàm nhân k * P b?ng v?ng l?p for thý?ng
Diem nhanDiem(int k, Diem P, int a, int p) {
    Diem KQ = DIEM_O;
    for (int i = 0; i < k; i++) {
        KQ = congDiem(KQ, P, a, p);
    }
    return KQ;
}

Diem kyTuSangDiem(char c) {
    c = toupper(c);
    return bangAnhXa[c - 'A'];
}

char diemSangKyTu(Diem P) {
    for (int i = 0; i < 26; i++) {
        if (bangAnhXa[i].x == P.x && bangAnhXa[i].y == P.y) {
            return char('A' + i);
        }
    }
    return '?';
}

int main() {
    int p, a, b;
    Diem G;
    int nA, nB;
    string plaintext;

    // --- NH?P D? LI?U T? BÀN PHÍM ---
    cout << "Nhap tham so duong cong p, a, b: ";
    cin >> p >> a >> b;

    cout << "Nhap toa do diem sinh G (x y): ";
    cin >> G.x >> G.y;

    cout << "Nhap khoa bi mat nA cua A: ";
    cin >> nA;

    cout << "Nhap khoa bi mat nB cua B: ";
    cin >> nB;

    cout << "Nhap chuoi plaintext (chu cai in hoa A-Z): ";
    cin >> plaintext;

    // --- T?O KHÓA CÔNG KHAI ---
    Diem PA = nhanDiem(nA, G, a, p);
    Diem PB = nhanDiem(nB, G, a, p);

    cout << "\nKhoa cong khai PA = (" << PA.x << ", " << PA.y << ")\n";
    cout << "Khoa cong khai PB = (" << PB.x << ", " << PB.y << ")\n";

    // --- QUÁ TR?NH M? HÓA (t?i A) ---
    int len = plaintext.length();
    Diem banMa[100];

    Diem K_A = nhanDiem(nA, PB, a, p);
    cout << "Khoa chung K = (" << K_A.x << ", " << K_A.y << ")\n";

    cout << "Ban ma C gom cac diem: ";
    for (int i = 0; i < len; i++) {
        Diem P = kyTuSangDiem(plaintext[i]);
        banMa[i] = congDiem(P, K_A, a, p);
        cout << "(" << banMa[i].x << ", " << banMa[i].y << ") ";
    }
    cout << "\n";

    // --- QUÁ TR?NH GI?I M? (t?i B) ---
    Diem K_B = nhanDiem(nB, PA, a, p);
    Diem truK = {K_B.x, mod(-K_B.y, p)};

    string ketQuaGiaiMa = "";
    for (int i = 0; i < len; i++) {
        Diem P = congDiem(banMa[i], truK, a, p);
        ketQuaGiaiMa += diemSangKyTu(P);
    }

    cout << "Chuoi sau khi giai ma: " << ketQuaGiaiMa << "\n";
    return 0;
}
