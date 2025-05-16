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
