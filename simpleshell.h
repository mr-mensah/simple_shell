#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <dirent.h>
#include <stdbool.h>
#define OUR_LINE_LENGTH 10000
#define OUR_ALIASES 100
/**
 * struct deowner - describes everything
 * @explainer: operations
 * @show_flag: shows flag
 * @shinput: copies data
 * @argv: argument
 */
typedef struct deowner
{
int explainer;
int show_flag;
char *shinput;
char **argv;
} ownership;
/**
 * struct movedline - copies another function
 * @explainer: operations
 * @readerloc: input
 * @indes: argument
 * @lens: length
 */
typedef struct movedline
{
int explainer;
char readerloc[OUR_LINE_LENGTH];
int indes;
int lens;
} bline;
/**
 * struct myinfohandler - input
 * @path: argument
 * @arg: argumment
 * @show: show
 * @argc: arguments
 * @argv: argument
 * @pipefd: argument
 * @report: condition
 * @lrf_fd : argument
 * @shell: shell
 */
typedef struct myinfohandler
{
char *path;
char *arg;
int argc;
int show;
char **argv;
int pipefd[2];
int report;
int lrf_fd;
char *shell;
} info_t;
/**
 * struct deboard - structure build
 * @type: argument
 * @func: argument
 */
typedef struct deboard
{
char *type;
int (*func)(info_t *);
} builtin_board;
/**
 * struct enters_alias - stucture build
 * @alias: argument
 * @force: argument
 */
typedef struct enters_alias
{
char alias[256];
char force[256];
} alias_enter;
extern char **environ;
ssize_t shll_shuff(int explanation, char *shuffler, ssize_t length);
ssize_t skim_shll(int explanation, char **shuffler);
off_t bring_out(int explanation, off_t offset, int hence);
int copy_bring(FILE *stream);
int myshell_exit(info_t *info);
int mycomp_env(info_t *info);
int comeset_env(info_t *info);
int alreadset_env(info_t *info);
int shll_ali(info_t *info);
int myshell_bullt(info_t *info);
int searchinbuilt_shll(info_t *info);
char **willdoenv_shll(void);
void dofunction_s(info_t *info);
void rewind_val(bline *reader, int explain);
ssize_t readall(int explain, bline *reader);
int chagefile(bline *reader, ssize_t *length, char **line);
ssize_t pthandler_flo(char **linepotr, size_t *n, int explain);
int myloopy(int explainer, int argc, char **argv, char *line,
size_t line_length, ownership file, info_t info,
int built_in_ret);
void copy_shuff(ownership file, char *line, size_t length);
void start_bill(info_t *info, int argc, char **argv, char *line);
void shll_move(info_t *info, char *line);
int wordlong(const char *str);
int wordtoword(char *str1, char *str2);
char *searchlett(char *str, char *character);
char *sendlett(char *dest, const char *src);
char *duplicateword(char *dests, char *sources);
int wordssep(info_t *info);
char **copy_stkk(char *abc, char *del);
int shl_dlm(char c, char *del);
void error_fan(info_t *info, const char *message);
char *intchanger(long int num, int base, int flags);
void myshllexe(info_t *info);
char *seeshllpth(info_t *info, char *pathstr, char *cmd);
int cmdfind(info_t *info, char *path);
char *plty_stings(char *placestr, int beg, int end);
char *digshll_ev(const char *var);
void ctrlCno(__attribute__((unused))int thisway);
void cust_print(void);
void _myprint(char *str);
int wordandwrd_o(const char *str1, const char *str2, size_t n);
char *wordsconding(char *str);
void myfile_send(char c, FILE *stream);
void fremmm(info_t *info, int out_stats);
char *fillmeme_shll(char *a, char b, unsigned int n);
#endif
