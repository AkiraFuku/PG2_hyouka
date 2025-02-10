#include <Scoer.h>
/// <summary>
/// 数宇の桁数を取得する
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
/// arrryの要素数を取得する
/// </summary>
/// <param name="targetnum">arry</param>
/// <returns></returns>
int GetDigit(std::vector<int> targetnum) { return 0; }
	
/// <summary>
/// 数字を配列に変換する
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
