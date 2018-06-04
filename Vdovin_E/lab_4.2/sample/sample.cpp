#include "hashtable.h"
#include "scantable.h"
#include "sorttable.h"

int main()
{
	int f = 0;
	hashtable h;
	sorttable sr(256);
	scantable st(256);
	do
	{
		cout << "Actions with tables" << endl;
		cout << "1 - Add record" << endl;
		cout << "2 - Delete record" << endl;
		cout << "3 - Find record" << endl;
		cin >> f;
		cin.ignore();
		switch (f)
		{
		case 1:
		{
			cout << "Write polinom" << endl;
			key k;
			cin >> k;
			datValue p(k);
			h.insRecord(k, p);
			sr.insRecord(k, p);
			st.insRecord(k, p);
			cout << "Hashtable" << endl;
			cout << h << endl;
			cout << "Sorttable" << endl;
			cout << sr << endl;
			cout << "Scantable" << endl;
			cout << st << endl;
			break;
		}
		case 2:
		{
			cout << "Write key" << endl;
			key k;
			cin >> k;
			h.delRecord(k);
			sr.delRecord(k);
			st.delRecord(k);
			cout << "Hashtable" << endl;
			cout << h << endl;
			cout << "Sorttable" << endl;
			cout << sr << endl;
			cout << "Scantable" << endl;
			cout << st << endl;
			break;
		}
		case 3:
		{
			cout << "Write key" << endl;
			key k;
			cin >> k;
			cout << "Hashtable" << endl;
			datValue* hd = h.findRecord(k);
			if (hd != NULL)
				cout << *hd << endl;
			else
				cout << "Not found" << endl;
			cout << "Sorttable" << endl;
			hd = sr.findRecord(k);
			if (hd != NULL)
				cout << *hd << endl;
			else
				cout << "Not found" << endl;
			cout << "Scantable" << endl;
			hd = st.findRecord(k);
			if (hd != NULL)
				cout << *hd << endl;
			else
				cout << "Not found" << endl;
			break;
		}
		}
		cout << "Want to continue" << endl;
		cout << "1 - yes" << endl;
		cout << "2 - no" << endl;
		cin >> f;
	} while (f == 1);
	return 0;
}