#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;

void diChuyenConTro(int cot, int dong) {
    COORD toaDo = {(SHORT)cot, (SHORT)dong};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), toaDo);
}

struct Diem { int x, y; };

void veKhung(int rong, int cao) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    diChuyenConTro(0, 0); cout << char(201);
    for (int x = 1; x < rong - 1; x++) cout << char(205);
    cout << char(187);

    for (int y = 1; y < cao - 1; y++) {
        diChuyenConTro(0, y); cout << char(186);
        diChuyenConTro(rong - 1, y); cout << char(186);
    }

    diChuyenConTro(0, cao - 1); cout << char(200);
    for (int x = 1; x < rong - 1; x++) cout << char(205);
    cout << char(188);

    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void taoMoi(Diem &thucAn, int rong, int cao) {
    thucAn.x = rand() % (rong - 2) + 1;
    thucAn.y = rand() % (cao - 2) + 1;
}

void luuLichSuDiem(int diem) {
    ofstream fout("lichsu.txt", ios::app);
    if (fout) fout << diem << endl;
}

void hienThiLichSu() {
    ifstream fin("lichsu.txt");
    int diem;
    cout << "--- Lich su diem ---\n";
    while (fin >> diem) cout << diem << "\n";
    cout << "Nhan phim bat ky de tro ve menu...";
    getch();
}

int luaChonDoKho() {
    int chon;
    do {
        cout << "\nChon do kho:\n";
        cout << "1. De (di chuyen cham)\n";
        cout << "2. Trung binh\n";
        cout << "3. Kho (di chuyen nhanh)\n";
        cout << "Lua chon (1-3): ";
        cin >> chon;
    } while (chon < 1 || chon > 3);

    switch (chon) {
        case 1: return 400;
        case 2: return 250;
        case 3: return 100;
    }
    return 250;
}

int hienThiMenu() {
    int chon;
    do {
        system("cls");
        cout << "====== MENU CHINH ======\n";
        cout << "1. Bat dau choi\n";
        cout << "2. Xem lich su diem\n";
        cout << "3. Chon do kho\n";
        cout << "4. Thoat\n";
        cout << "Lua chon: ";
        cin >> chon;
    } while (chon < 1 || chon > 4);
    return chon;
}

class Ran {
public:
    Diem than[100]; int doDai;

    Ran() {
        doDai = 3;
        than[0] = {10,10}; than[1] = {11,10}; than[2] = {12,10};
    }

    void ve() {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        for (int i = 0; i < doDai; i++) {
            diChuyenConTro(than[i].x, than[i].y);
            cout << 'O';
        }
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    void diChuyen(int huong) {
        for (int i = doDai - 1; i > 0; i--) {
            than[i] = than[i - 1];
        }
        if (huong == 0) than[0].x++;
        if (huong == 1) than[0].y++;
        if (huong == 2) than[0].x--;
        if (huong == 3) than[0].y--;
    }

    bool anThucAn(Diem thucAn) {
        if (than[0].x == thucAn.x && than[0].y == thucAn.y) {
            doDai++;
            return true;
        }
        return false;
    }
};

void layKichThuocConsole(int &rong, int &cao) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rong = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    cao = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int main() {
    srand((unsigned)time(nullptr));
    int rong, cao;
    layKichThuocConsole(rong, cao);
    cao -= 1;

    int tocDo = 250, diem = 0;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    while (true) {
        int luaChon = hienThiMenu();
        if (luaChon == 4) break;
        if (luaChon == 2) { system("cls"); hienThiLichSu(); continue; }
        if (luaChon == 3) { system("cls"); tocDo = luaChonDoKho(); continue; }

        Ran ran;
        Diem thucAn;
        layKichThuocConsole(rong, cao);
        cao -= 1;
        taoMoi(thucAn, rong, cao);
        int huong = 0;
        diem = 0;

        system("cls");
        veKhung(rong, cao);
        diChuyenConTro(thucAn.x, thucAn.y);
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << '@';
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        ran.ve();

        bool tamDung = false;
        while (true) {
            if (kbhit()) {
                int phim = getch();
                int huongMoi = huong;
                if (phim == 0 || phim == 224) {
                    switch (getch()) {
                        case 72: huongMoi = 3; break;
                        case 80: huongMoi = 1; break;
                        case 75: huongMoi = 2; break;
                        case 77: huongMoi = 0; break;
                    }
                } else {
                    if (phim == 'w' || phim == 'W') huongMoi = 3;
                    if (phim == 's' || phim == 'S') huongMoi = 1;
                    if (phim == 'a' || phim == 'A') huongMoi = 2;
                    if (phim == 'd' || phim == 'D') huongMoi = 0;
                }

                if (!((huong == 0 && huongMoi == 2) || (huong == 2 && huongMoi == 0) ||
                      (huong == 1 && huongMoi == 3) || (huong == 3 && huongMoi == 1))) {
                    huong = huongMoi;
                }

                if (!(phim == 'w' || phim == 'W' || phim == 'a' || phim == 'A' ||
                      phim == 's' || phim == 'S' || phim == 'd' || phim == 'D' ||
                      phim == 0 || phim == 224)) {
                    tamDung = true;
                    diChuyenConTro(rong / 2 - 20, cao / 2);
                    cout << "TAM DUNG - Nhan 0 de ve menu, phim bat ky de tiep tuc";
                    while (true) {
                        if (kbhit()) {
                            int k = getch();
                            if (k == '0') goto ketThuc;
                            else {
                                tamDung = false;
                                diChuyenConTro(rong / 2 - 20, cao / 2);
                                cout << string(60, ' ');
                                break;
                            }
                        }
                    }
                }
            }

            Diem duoi = ran.than[ran.doDai - 1];
            ran.diChuyen(huong);

            if (ran.than[0].x <= 0 || ran.than[0].x >= rong - 1 ||
                ran.than[0].y <= 0 || ran.than[0].y >= cao - 1) {
                diChuyenConTro(rong / 2 - 5, cao / 2);
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << "GAME OVER!";
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                Sleep(1500);
                break;
            }

            bool daAn = ran.anThucAn(thucAn);
            if (daAn) {
                diem++;
                diChuyenConTro(thucAn.x, thucAn.y); cout << ' ';
                taoMoi(thucAn, rong, cao);
                diChuyenConTro(thucAn.x, thucAn.y);
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << '@';
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                diChuyenConTro(duoi.x, duoi.y); cout << ' ';
            }

            ran.ve();
            diChuyenConTro(0, cao);
            cout << string(rong, ' ');
            diChuyenConTro(0, cao);
            cout << "Diem: " << diem;
            Sleep(tocDo);
        }

        ketThuc:
        if (!tamDung) luuLichSuDiem(diem);
    }

    return 0;
}
