#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,spaceCnt = 0,TabCnt = 0,lbCnt = 0;
    char ch;
    while (cin >> std::noskipws >> ch) {
        if (ch == 'a' || ch == 'A')
            ++aCnt;
        else if (ch == 'e' || ch == 'E')
            ++eCnt;
        else if (ch == 'i' || ch == 'I')
            ++iCnt;
        else if (ch == 'o' || ch == 'O')
            ++oCnt;
        else if (ch == 'u' || ch == 'U')
            ++uCnt;
		else if (ch == ' ')
			spaceCnt++;
		else if (ch == '\t')
			TabCnt++;
		else if (ch == '\n')
			lbCnt++;

    }
    cout << "Number of vowel a: \t" << aCnt << '\n' << "Number of vowel e: \t"
         << eCnt << '\n' << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n' << "Number of vowel u: \t"
         << uCnt << endl;
	cout << "Number of space : \t" << spaceCnt << '\n' << "Number of Tab : \t"
		 << TabCnt << "\n" << "Number of line break : \t" << lbCnt << endl; 

    return 0;
}
