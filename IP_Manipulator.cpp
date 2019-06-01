/*
 * IP_Manipulator
 * Created by:
 * Justin Lautner
 */

#include <iostream>
#include <vector>
using namespace std;

struct IPAddress	{
	unsigned int valueFour: 8;
	unsigned int valueThree: 8;
	unsigned int valueTwo: 8;
	unsigned int valueOne: 8;
};
struct bits {
	unsigned int a1: 1;
	unsigned int a2: 1;
	unsigned int a3: 1;
	unsigned int a4: 1;
	unsigned int a5: 1;
	unsigned int a6: 1;
	unsigned int a7: 1;
	unsigned int a8: 1;
	unsigned int a9: 1;
	unsigned int a10: 1;
	unsigned int a11: 1;
	unsigned int a12: 1;
	unsigned int a13: 1;
	unsigned int a14: 1;
	unsigned int a15: 1;
	unsigned int a16: 1;
	unsigned int a17: 1;
	unsigned int a18: 1;
	unsigned int a19: 1;
	unsigned int a20: 1;
	unsigned int a21: 1;
	unsigned int a22: 1;
	unsigned int a23: 1;
	unsigned int a24: 1;
	unsigned int a25: 1;
	unsigned int a26: 1;
	unsigned int a27: 1;
	unsigned int a28: 1;
	unsigned int a29: 1;
	unsigned int a30: 1;
	unsigned int a31: 1;
	unsigned int a32: 1;
};
struct quarter{
	unsigned int threeQuarters: 24;
	unsigned int quarter: 8;
};
struct half{
	unsigned int half1: 16;
	unsigned int half2: 16;
};
struct threeQuarters{
	unsigned int quarter: 8;
	unsigned int threeQuarters: 24;
};
union wholeIPAddress		{
	IPAddress IP_Address;
	bits IP_Bits;
	quarter IP_quarter;
	half IP_half;
	threeQuarters IP_threeQuarters;
	unsigned int whole: 32;
};

int main()	{
	int selection, one, two, three, four, network, bit;
	wholeIPAddress IP;

	cout << "Enter an IP address (One value at a time): " << endl;
	cin >> one;
	cin >> two;
	cin >> three;
	cin >> four;
	IP.IP_Address.valueOne = one;
	IP.IP_Address.valueTwo = two;
	IP.IP_Address.valueThree = three;
	IP.IP_Address.valueFour = four;

	std::vector<unsigned int> bitArray{IP.IP_Bits.a32, IP.IP_Bits.a31, IP.IP_Bits.a30, IP.IP_Bits.a29, IP.IP_Bits.a28, IP.IP_Bits.a27,
						IP.IP_Bits.a26, IP.IP_Bits.a25, IP.IP_Bits.a24, IP.IP_Bits.a23, IP.IP_Bits.a22, IP.IP_Bits.a21,
						IP.IP_Bits.a20, IP.IP_Bits.a19, IP.IP_Bits.a18, IP.IP_Bits.a17, IP.IP_Bits.a16, IP.IP_Bits.a15,
						IP.IP_Bits.a14, IP.IP_Bits.a13, IP.IP_Bits.a12, IP.IP_Bits.a11, IP.IP_Bits.a10, IP.IP_Bits.a9,
						IP.IP_Bits.a8, IP.IP_Bits.a7, IP.IP_Bits.a6, IP.IP_Bits.a5, IP.IP_Bits.a4, IP.IP_Bits.a3,
						IP.IP_Bits.a2, IP.IP_Bits.a1};

	cout << "How would you like to see your IP address ((1) single value, (2) four values, (3), two values, (4) a single bit value): ";
	cin >> selection;
	switch(selection){;
		case 1:
			cout << IP.whole << endl;
			break;
		case 2:
			cout << IP.IP_Address.valueOne << "." << IP.IP_Address.valueTwo << "." << IP.IP_Address.valueThree << "." << IP.IP_Address.valueFour << endl;
			break;
		case 3:
			{
				cout << "How many bits in the network address (8, 16, 24): ";
				cin >> network;
				if (network == 8){
					cout << IP.IP_quarter.quarter << "," << IP.IP_quarter.threeQuarters << endl;
				}
				else if (network == 16){
					cout << IP.IP_half.half2 << "," << IP.IP_half.half1 << endl;
				}
				else if (network == 24){
					cout << IP.IP_threeQuarters.threeQuarters << "," << IP.IP_threeQuarters.quarter << endl;
				}
				else{
					cout << "Invalid Selection" << endl;
					cout << "Please choose an amount of bits in accordance with a valid subnet mask" << endl;
				}
			}
			break;
		case 4:
			{
				cout << "Which bit would you like to see (0-31): ";
				cin >> bit;
				if (bit < 0 || bit > 31){
					cout << "Invalid selection" << endl;
					cout << "Please choose a bit numbered 0 through 31";
					return 0;
				}
				else{
					bit = 31 - bit;
				}
				cout << bitArray.at(bit);
			}
			break;
		default:
			cout << "Invalid selection" << endl;
			cout << "Please choose an option: 1, 2, 3, or 4" << endl;
	}

	return 0;
}
