/* Tic-Tac-Toe 超簡易版 */
// ver.6 フルスクリーン化
/*
 * 主な変更点：
 *   main() の一部を Game() に移動．
 *   Title() の表示内容．
 *   入出力処理を curses化．
 */

#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include "game.h"

int Title(void)
{
  erase();
  mvprintw(Y0 + 0, X0, "+-------------------------------+");
  mvprintw(Y0 + 1, X0, "| The Most Simplest TIC-TAC-TOE |");
  mvprintw(Y0 + 2, X0, "+-------------------------------+");

  mvprintw(Y0 + 4, X0, "  位置の指定は行番号y，列番号x の順ね．");
  mvprintw(Y0 + 5, X0, "    （番号は 0 から数えるよ．）");
  mvprintw(Y0 + 6, X0, "  勝敗については自分達で判定すれや．");

  mvprintw(Y0 + 8, X0, "  プレーヤ１：%s", sym[1]);
  mvprintw(Y0 + 9, X0, "  プレーヤ２：%s", sym[2]);

  mvprintw(Y0 + 11, X0, "  終了：ここで [Q] or ゲーム中に [Enter]");
  mvprintw(Y0 + 12, X0, "  開始：[Enter]");
  refresh();
  return (getch());
}

int main(void)
{
  setlocale(LC_ALL, ""); // 日本語を使うよ
  initscr();             // 端末制御を開始
  while (1)
  {
    if (Title() == 'q')
      break;
    if (Game())
      break;
  }
  endwin(); // 端末制御を終了
  return 0;
}