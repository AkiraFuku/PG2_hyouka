#include <Scoer.h>
/// <summary>
/// ”‰F‚ÌŒ…”‚ğæ“¾‚·‚é
/// </summary>
/// <param name="targetnum"></param>
/// <returns></returns>
int GetDigit(int targetnum) {
	int digit = 0;
	while (targetnum > 0) {
		targetnum /= 10;
		digit++;
	}
	return digit;
}
/// <summary>
/// arrry‚Ì—v‘f”‚ğæ“¾‚·‚é
/// </summary>
/// <param name="targetnum">arry</param>
/// <returns></returns>
int GetDigit(std::vector<int> targetnum) { return 0; }
	
/// <summary>
/// ”š‚ğ”z—ñ‚É•ÏŠ·‚·‚é
/// </summary>
/// <param name="targetnum"></param>
/// <returns></returns>
std::vector<int> NumberArray(int targetnum) { 
	int digit=0;
	digit = GetDigit(targetnum);
	std::vector<int> numbeArray(digit);
	
	for (int i = 0; i < digit-1; i++) {
		numbeArray[i] = targetnum /static_cast<int>( pow(10,(digit-1)-i));
		targetnum %=static_cast<int> (pow(10,(digit-1)-i));
	}
		
	return numbeArray; 
}
