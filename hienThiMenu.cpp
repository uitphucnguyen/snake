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
