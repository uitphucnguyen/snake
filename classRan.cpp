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
