#include <iostream>
#include "TPolinom.h"
#include "TList.h"

int main()
{
    TMonom m1(1, 1, 1, 1);
    TMonom m2(2, 2, 2, 2);
    TMonom m3(3, 0, 2, 2);


    TPolinom p1;
    p1.InsMonom(m1);

    //p1 = p1 + 2;
    p1.Print();
    putchar('\n');

    TPolinom p2;
    p2.InsMonom(m2);


    p2.Print();
    putchar('\n');

    TPolinom p3;
    p3 = p2 + p1;
    p3.Print();

    return 0;

    //TPolinom p2;
    //p2.InsMonom(m2);

    //
    //p1.Print();
    //putchar('\n');
    //p2.Print();
    //putchar('\n');
    //p3.Print();
    //putchar('\n');

    //return 0;

    /*THeadList<int> hd;
    hd.InsFirst(5);
    hd.InsFirst(34);
    hd.Print();*/
   // TMonom m1;
   // m1.coeff = 2;
   // m1.x = 1;
   // m1.y = 2;
   // m1.z = 5;

   // TMonom m2 = m1;
   // m2.z = 4;
   // if (m2 == m1)
   //     std::cout << "eq\n";
   // else if (m1 > m2)
   //     std::cout << "m1 > m2\n";
   // else
   //     std::cout << "m1 < m2\n";
   // //p.InsMonom(m1);
   //// p.Print();
   // std::cout << m1;
    
}

