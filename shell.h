#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

/* buffer section */
#define READ_BUFF_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_FLUSH -1

/* command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* convert number */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

*1 if using getline() */
#define USE_GETLINE	0
#define USE_STRTOK	0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

/**
*struct liststr - singly linkedlist
*@num: number field
*@str: string
*@next: next node pointer
*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
*struct passinfo - contains pseudo-args to pass to a fn
*@arg: string generated from getline containing arguments
*@argv: array of strings generated from argv
*@path: path for current command
*@argc: arg count
*@line_count: erro count
*@err_num: erro code for ecit()s
*@linecount_flag: if on, count this input line
*@fname: program file name
*@env: linked list copy of environment
*@environ: custom modified cpy of environ from LL env
*@history: history node
*@alias: alias node
*@env_changed: on if env was changed
*@status: return statement of last executed command
*@cmd_buff: address if pointer to cmd_buff, on if chaining
*@cmd_buff_type: CMD_TYPE ||, &&, ;
*@readfd: the fd from which to read line input
*@histcount: history line number count
*/
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unisgned int lline_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;

char **cmd_buff;
int cmd_buff_type;
int readfd;
int histcount;

} info_t;

define INFO_INIT\
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0, NULL, 0, 0,
0, 0}

/**
*STRUCT BUILTIN - contains a builtin string and related function
*@type: the builtin command flag
*@func: function
*/
typedef struct builtin
{
	char *type;
	int (*fubc)(info_t *);
} builtin_table;

/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void finf_cmd(info_t *);
void fork_cmd(info_t *);

/* toem_parser.c */
int is_cmd(infor_t *, char *);
char *duo_chars(char *, int int);
char *finf_path(info_t *, char *, char *);

/* loophsh.c */
int loophshchar **);

/* toem_erros.c */
void _eputs(char*)
int e_putchar(char);
int _putfd(char c, int fd);
int_putsfd(char*str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_tokenizer.c *?
char **strtow(char*, char*);
char **strtow2(char *, char);

/* toem realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *realloc(void *, unsigned int, unisgned int);

/* toem_memory.c */
int _free(void **);

/*toem_atoi.c */
int interactive (info_t *);
int _isdelim(char char *);
int _isalpha(int);
int _atoi(char *);

/* toem_errors1.c */
int _erratoi(char *);
void print_erro(info_t * char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_builtin.c */
int _exit(info_t *);
int _changedir(info_t *);
int _help(info_t *);

/* toem_builtin2.c */
int _history(info_t *);
int _alias(info_t *);

/* toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/*toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t * char **);
void free_info(info_t *, int);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
info _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char **get_enviorn(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/*toem_history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history(info_t *info, char *buff, int linecount);
int renumber_history(info_t *info);

/*toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unisgned int);
void free_list(list_t **);

/* toem_lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *)
int replace_string(char **, char *);

#endif
