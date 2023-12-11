#ifdef	DEBUG
#include <stdio.h>
#endif
#include "sub.h"

// 等差数列を生成する関数（generate sequence）
// n：項数，from：初項，step：公差
void GenSeq(Array *a, int n, int from, int step)
{
	int	i;
	int	x = from;

	a->len = n;
	for (i = 0; i < n; i++) {
#ifdef	DEBUG
		// デバッグ出力．動作をわかり易くするよ
		printf("DEBUG: %d\n", x);
#endif
		a->data[i] = x;
		x += step;
	}
}

// 総和を計算する関数
int Sum(Array *a)
{
	int	s = 0;
	int	i;

	for (i = 0; i < a->len; i++) {
		s += a->data[i];
	}
	return (s);
}