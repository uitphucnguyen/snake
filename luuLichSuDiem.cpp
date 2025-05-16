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
