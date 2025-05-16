void layKichThuocConsole(int &rong, int &cao) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rong = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    cao = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
