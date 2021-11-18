//laba3
//Вариант 20
//Алгоритм вычисления функции косинус гиперболический ch(x)  с помощью разложения в ряд по первым N членам этого ряда:
//C++ version:


#include <stdio.h>
#include <intrin.h>
#pragma intrinsic(__rdtsc)
#include <iostream>
#include <ctime>

using namespace std;
int main()
{
	
	
	const short N = 15;
	float arr[N];
	unsigned __int64 stop, start;
	long long start_t, stop_t;
	for (short j = 0; j < N; j++)
	{


		//start_t = time(nullptr);
		start = __rdtsc();
		
		unsigned short acc = 80;
		
		short iter = 1;
		int x;
		float chisl, znam, summ, temp, stackClear;
		chisl = znam = summ = 1.0;
		x = 2;
		//C++
		
		/*
		for (int i = 1; i < acc; i++)
		{
			chisl *= (x * x);
			znam *= (2 * i * (2 * i - 1));
			summ += chisl / znam;
		}
		*/
		//Assembler
		
		_asm {
			xor ecx, ecx;
			mov cx, acc;
			sub cx, 1;
			
		cycle:
			fld chisl;
			fild x;
			fild x;
			fmul;
			fmul;
			fstp chisl;

			
			fld znam;
			fild iter;
			inc iter;
			fild iter;
			inc iter;
			fmul;
			fmul;
			fstp znam;

			fld chisl;
			fld znam;
			fdiv;
			fld summ;
			fadd;
			fstp summ;
			loop cycle;
		}
		
		stop = __rdtsc();
		//stop_t = time(nullptr);
		float diff = (stop - start) / 2100000000.0 * 1000;
		//double diff = (stop_t - start_t);
		std::cout << diff << std::endl;
		arr[j] = diff;
	}
	float min = arr[0];
	for (size_t i = 1; i < N; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
	std::cout << min << std::endl;
}
