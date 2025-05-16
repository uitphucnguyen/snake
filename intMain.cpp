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
