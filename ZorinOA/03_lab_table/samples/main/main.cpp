#include <iostream>
#include <string>
#include "AVLTreeTable.h"

using namespace std;

int main()
{
	TreeTable<double, string> T;
	T.Insert(50, "");
	T.Insert(70, "");
	T.Insert(30, "");
	T.Insert(20, "");
	T.Insert(35, "");
	T.Insert(60, "");
	T.Insert(80, "");
	T.Insert(75, "");
	T.Insert(65, "");
	T.Insert(55, "");
	T.Insert(85, "");
	T.Insert(31, "");
	T.Insert(36, "");
	T.Insert(22, "");
	T.Insert(52, "");
	T.Insert(56, "");
	T.Insert(90, "");
	T.Insert(66, "");
	T.Insert(51, "");
	T.Insert(37, "");
	T.Insert(10, "");
	T.Insert(5, "");
	T.Insert(38, "");
	T.Insert(53, "");
	T.Insert(32, "");
	T.Insert(54, "");
	//T.Print();
	
	/*cout << endl << "After Delete: " << endl << endl;
	T.Delete(60);
	T.Delete(50);
	T.Delete(56);
	T.Print();*/
	cout << T << endl;

	return 0;

 /*               .---90(0)
            .---85(1)
        .---80(1)
       |    `---75(0)
    .---70(1)
   |   |    .---66(0)
   |    `---65(1)
---60(-1)
   |        .---56(0)
   |    .---55(-1)
   |   |   |    .---53(0)
   |   |    `---52(0)
   |   |        `---51(0)
    `---50(-1)
       |            .---38(0)
       |        .---37(0)
       |       |    `---36(0)
       |    .---35(0)
       |   |   |    .---32(0)
       |   |    `---31(1)
        `---30(0)
           |    .---22(0)
            `---20(-1)
                `---10(-1)
                    `---5(0)*/
}