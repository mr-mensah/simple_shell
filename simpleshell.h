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
 * struct owner - name describing structure
 * @explainer: opens and closes a file
 * @show_flag: line input reader
 * @shinput: mimics read data
 * @argv: argument vector count values
 */

typedef struct owner
{
int explainer;
int show_flag;
char *shinput;
char **argv;
} ownership;
/**
 * struct curvedline - structure that mimics get line function
 * @explainer: opens and closes a file
 * @readerloc: input taken buffer
 * @indes: input that halted the buffer
 * @lens: line length of the function
 */
typedef struct curvedline
{
	int explainer;
	char readerloc[OUR_LINE_LENGTH];
	int indes;
	int lens;
} bline;
/**
 * struct infohandler - handles lines input
 * @path: the value of foremost argument
 * @arg: the totlal argumment
 * @show: counted line
 * @argc: the total argument count
 * @argv: argument vector count in the func
 * @pipefd: pipe file descriptor
 * @report: executes condition in the shell
 * @lrf_fd : left pipe reduction in shell
 * @shell: counts stuff in shell
 */
typedef struct infohandler
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
 * struct board - name of structure
 * @type: pointer to the types in struct
 * @func: pointer to the func in the struct
 */
typedef struct board
{
	char *type;
	int (*func)(info_t *);
} builtin_board;
/**
 * struct enter_alias - name of the structure
 * @alias: handles the alias in the shell
 * @force: force in the function
 */
typedef struct enter_alias
{
	char alias[256];
	char force[256];
} alias_enter;
ssize_t mybufferfile_handler(char **lineptr, size_t *n, int explainer);
ssize_t shel_bunffile(int explainer, char *buffer, ssize_t max_length);
ssize_t readers_shel(int explainer, char **buffer);
off_t myflush_file(int explainer, off_t offset, int whence);
int mimc_flush(FILE *stream);
int mystringlength(const char *str);
int astringcompare(char *str1, char *str2);
char *findcharacters(char *str, char *character);
char *appendstrings(char *dest, const char *src);
char *copystrings(char *dests, char *source);
char *stringduplicates(char *str);
void ishell_printer(void);
void executeshell_fd(info_t *info);
void aafree(info_t *info, int exit_status);
void e_constructer(info_t *info, const char *message);
char **allenv_dshell(void);
int wefindbuiltin_shell(info_t *info);
int myexitbuiltin_shell(info_t *info);
int mycustom_env(info_t *info);
int anoldsetenv_shell(info_t *info);
int anoldunsetenv_shell(info_t *info);
int ashell_aliashandler(info_t *info);
int destringsplit(info_t *info);
char **mimic_strtokc(char *inputString, char *delimiters);
int shel_lim(char c, char *delim);
void shellexecute(info_t *info);
char *seeshellpath(info_t *info, char *pathstr, char *cmd);
int shellloopmain(int explainer, int argc, char **argv, char *line,
size_t line_length, ownership file, info_t info,
int built_in_ret);
char *numbconverter(long int num, int base, int flags);
void _printers(char *str);
int stringcompare_num(const char *str1, const char *str2, size_t n);
char *igetshell_env(const char *variable);
void file_writers(char c, FILE *stream);
int ashell_builtincd(info_t *info);
int commandsearches(info_t *info, char *path);
char *mul_strings(char *pathstr, int start, int stop);
extern char **environ;
void myreset_structure(bline *reader, int explainer);
ssize_t afilereader(int explainer, bline *reader);
int afileplacereader(bline *reader, ssize_t *line_length, char **line);
void amimic_buffile(ownership file, char *line, size_t line_length);
void init_builtin(info_t *info, int argc, char **argv, char *line);
void ashell_freedom(info_t *info, char *line);
char *memfill_shela(char *s, char b, unsigned int n);
void icontrolC(__attribute__((unused))int thisway);
#endif

