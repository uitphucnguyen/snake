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
