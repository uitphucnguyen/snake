void diChuyenConTro(int cot, int dong) {
    COORD toaDo = {(SHORT)cot, (SHORT)dong};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), toaDo);
}
