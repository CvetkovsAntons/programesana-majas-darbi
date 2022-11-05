#include <iostream>

using namespace std;

double circle_area(double r) { // funkcija atgriez rinka laukumu
    double pi = 3.14;

    return pi * r * r;
}

int main() {
    cout << "Ievadiet arpus rinka radiusu (R1):" << endl; // lietotajs ievada arpus rinka radiusu
    double r1;
    cin >> r1;

    cout << "Ievadiet ieksa rinka radiusu (R2):" << endl; // lietotajs ievada iekš rinka radiusu
    double r2;
    cin >> r2;

    while (r1 <= r2) {  // parbaudam vai ieksa rinka radius ir graks par arpus
        cout << "R2 nevar but garaks par R1" << endl;
        cout << "Ievadiet ieksa rinka radiusu (R2):" << endl;
        cin >> r2;
    }

    double area1 = circle_area(r1); // izsaucam funkciju circle_area un, ka parametru padodam r1
    double area2 = circle_area(r2); // izsaucam funkciju circle_area un, ka parametru padodam r2

    double outsideArea = area1 - area2; // atrodam arpus rinka laukumu

    double insideCircles = circle_area(r2 / 2); // izsaucam funkciju circle_area un, ka parametru padodam r2/2, lai atrasu ieksrinka laukumu

    cout << "Arpus rinka laukums: " << outsideArea << endl;
    cout << "Ieksa rinka laukums: " << insideCircles << endl;
    cout << "Iekrasotas figuras kolejas laukums: " << outsideArea + insideCircles * 2;

    return 0;
}
