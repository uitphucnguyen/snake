void ve(){
void Ve (Point Qua) {
for (int i=0; i < DoDai; i++){
gotoxy(A[i].x,A[i].y);
cout<<"X";
gotoxy(Qua.x, Qua.y); cout<<"";
}
void DiChuyen (int Huong) {
void DiChuyen(int Huong, Point& Qua) {
for (int 1 DoDai-1; 1>0;1--)
A[1] A[1-1];
if (Huong==) A[0].x A[0].x + 1;
if (Huong==1) A[0].y A[8].y + 1;
if (Huong==2) A[0].x = A[0].x - 1;
if (Huong==3) A[0].y= A[0].y 1;
if ((A[0].x Qua.x) && (A[0].y == Qua.y)){
DoDai++;
Qua.x rand()%(MAXX-MINX)+MINX;
Qua.y rand()%(MAXY-MINY)+MINY;
}
Point Qua;
srand((int)time(0));
Qua.x = rand()%(MAXX-MINX)+MIN
Qua.y= rand()%(MAXY-MINY)+MIN
while (1) {
if (kbhit()){
t = getch();
-49,8 +62,8 @@ int main()
if (t=='x') Huong = 1;
system("cls");
r.ve();
r.DiChuyen (Huong);
r.ve(Qua);
r.DiChuyen (Huong, Qua);
Sleep(300);
}
