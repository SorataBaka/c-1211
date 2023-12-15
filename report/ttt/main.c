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

typedef struct
{
  int size;
  int *cell;
} Board;
#define Y0 3
#define X0 3

char *sym[3] = {"・", "○", "×"}; // 空欄，プレーヤ１，プレーヤ２

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
void Free(Board *bd)
{
  if (bd == NULL)
    return;
  free(bd->cell);
  free(bd);
}

Board *New(int n)
{
  Board *bd;

  bd = (Board *)malloc(sizeof(Board));
  if (bd == NULL)
    return (NULL);

  bd->size = n;
  bd->cell = (int *)malloc(sizeof(int) * n * n);
  if (bd->cell == NULL)
  {
    free(bd);
    return (NULL);
  }
  return (bd);
}

/* ゲーム盤のプレーヤ番号を調べる関数
 * return：プレーヤ番号
 */
int Get(Board *bd, int y, int x)
{
  if (x < 0)
    return (-1); /* ハミ出し禁止 */
  if (x >= bd->size)
    return (-1); /* （バッファオーバラン防止） */
  if (y < 0)
    return (-1);
  if (y >= bd->size)
    return (-1);

  return (bd->cell[y * bd->size + x]);
}

/* ゲーム盤にプレーヤ番号を書き込む関数 */
void Set(Board *bd, int y, int x, int v)
{
  if (x < 0)
    return; /* ハミ出し禁止 */
  if (x >= bd->size)
    return; /* （バッファ−バラン防止） */
  if (y < 0)
    return;
  if (y >= bd->size)
    return;

  bd->cell[y * bd->size + x] = v;
}

/* ゲーム盤を初期化する関数 */
void Clear(Board *bd)
{
  int y, x;

  for (y = 0; y < bd->size; y++)
  {
    for (x = 0; x < bd->size; x++)
    {
      bd->cell[y * bd->size + x] = 0;
    }
  }
}

/* ゲーム盤を表示する関数 */
void Draw(Board *bd)
{
  int y, x;

  printf("\n");
  for (y = 0; y < bd->size; y++)
  {
    for (x = 0; x < bd->size; x++)
    {
      mvprintw(y + Y0, 2 * x + X0, "%s", sym[Get(bd, y, x)]);
    }
  }
  printw("\n\n");
}

// ゲームの本体... main() から移動・変更
int Game(void)
{
  Board *bd;
  int n;
  int y, x, player;

  erase();
  mvprintw(Y0, X0, "ゲーム盤のサイズ > ");
  refresh();
  if (scanw("%d", &n) == ERR)
    return (0);
  // 数値入力無しだと ERR になるよ

  bd = New(n);
  if (bd == NULL)
    goto ERROR;

  Clear(bd);

  player = 1;
  while (1)
  {
  CONTINUE:
    erase();
    Draw(bd);
    refresh();

    while (1)
    {
      printw("%s の番 > ", sym[player]);
      refresh();
      if (scanw("%d %d", &y, &x) == ERR)
        goto END;

      if (Get(bd, y, x) == 0)
        break;
      printw("そこには置けません!!\nもう一度 ");
    }
    Set(bd, y, x, player);

    player = player % 2 + 1;
  }
END:
  printw("中止？（y/n）");
  if (getch() != 'y')
    goto CONTINUE;

  Free(bd);
  return (0);

ERROR:
  printw("メモリ確保失敗\n");
  getch();
  return (1);
}
int main(void)
{
  setlocale(LC_ALL, "jp_JP"); // 日本語を使うよ
  initscr();                  // 端末制御を開始
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