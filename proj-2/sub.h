#ifndef	SUB_H
#define	SUB_H

// 長さ付き配列の構造体
#define	MAXLEN	1024		// 最大長
typedef struct {
	int	data[MAXLEN];	// 配列要素
	int	len;		// 配列長
} Array;
	// 手抜き...本来なら data[] は MAXLEN なしの動的配列とすべき．

// 等差数列を生成する関数（generate sequence）
// n：項数，from：初項，step：公差
extern void GenSeq(Array *a, int n, int from, int step);

// 総和を計算する関数
extern int Sum(Array *a);

#endif