#include "ownshell.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


char *get_history_file(info_t *info)
{
	char *directory = _getenv(info, "HOME=");
	if (!directory)
		return NULL;

	size_t buf_size = _strlen(directory) + _strlen(HIST_FILE) + 2;
	char *buf = malloc(sizeof(char) * buf_size);
	if (!buf) {
		free(directory);
		return NULL;
	}

	_strcpy(buf, directory);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);

	free(directory);
	return buf;
}

int write_history(info_t *info)
{
	char *name= get_history_file(info);
	if (!name)
		return -1;

	ssize_t fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	free(name);
	if (fd == -1)
		return -1;

	list_t *branch = info->history;
	while (branch) {
		_putsfd(branch->str, fd);
		_putfd('\n', fd);
		branch = branch->next;
	}

	_putfd(BUF_FLUSH, fd);
	close(fd);
	return 1;
}

int read_history(info_t *info)
{
	char *name = get_history_file(info);
	if (!name)
		return 0;

	int fd = open(name, O_RDONLY);
	free(name);
	if (fd == -1)
		return 0;

	struct stat st;
	if (fstat(fd, &st) != 0) {
		close(fd);
		return 0;
	}

	size_t fsize = st.st_size;
	if (fsize < 2) {
		close(fd);
		return 0;
	}

	char *buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf) {
		close(fd);
		return 0;
	}

	ssize_t rdlen = read(fd, buf, fsize);
	buf[fsize] = '\0';
	close(fd);

	if (rdlen <= 0) {
		free(buf);
		return 0;
	}

	int lastnumber = 0;
	int linecounted = 0;
	for (int i = 0; i < fsize; i++) {
		if (buf[i] == '\n') {
			buf[i] = '\0';
			build_history_list(info, buf + lastnumber, linecounted);
			lastnumber = i + 1;
			linecounted++;
		}
	}

	if (lastnumber != fsize) {
		build_history_list(info, buf + lastnumber, linecounted);
		linecounted++;
	}

	free(buf);

	info->histcounted = linecounted;

	while (info->histcounted >= HIST_MAX)
		delete_branch_at_index(&(info->history), 0);

	renumber_history(info);

	return info->histcounted;
}

int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *branch = NULL;

	if (info->history)
		branch = info->history;

	add_branch_end(&branch, buf, linecount);

	if (!info->history)
		info->history = branch;

	return 0;
}

int renumber_history(info_t *info)
{
	list_t *branch = info->history;
	int i = 0;

	while (branch) {
		branch->num = i++;
		branch = branch->next;
	}

	return (info->histcount = i);
}


