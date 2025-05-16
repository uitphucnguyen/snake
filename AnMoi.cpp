struct Diem { int x, y; };
void taoMoi(Diem &thucAn, int rong, int cao) {
    thucAn.x = rand() % (rong - 2) + 1;
    thucAn.y = rand() % (cao - 2) + 1;
}
