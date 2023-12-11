#CFLAGS = -DDEBUG -Wall
CFLAGS = -Wall


all:	sumseq

sumseq:	main.o sub.o
	cc main.o sub.o -o sumseq	# すべてのオブジェクトをリンク

main.o:	main.c sub.h

sub.o:	sub.c sub.h

.c.o:		# *.c から *.o へのコンパイル方法は共通なので統合したよ
	cc -c $< $(CFLAGS)

.SUFFIXES: .c .o	# .c とか .o は拡張子だよ．ファイル名じゃないよーん

clean:
	-rm *.o		# 生成したオブジェクトを削除


distclean:	clean
	-rm sumseq	# 生成したプログラムも削除

dist:	distclean
	(cd ..; tar zcvf proj-2.tgz proj-2/)	# 配布用圧縮ファイルを生成

.PHONY:	clean distclean dist