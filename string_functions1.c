#include "shell.h"

/**
* print_prompt - Display the shell prompt
*/
void print_prompt(void)
{
printf("#cisfun$ ");
}

/**
* execute_command - Execute the given command
* @command: The command to be executed
*/
void execute_command(const char *command)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execlp(command, command, (char *)NULL) == -1)
{
perror("execlp");
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(pid, &status, 0);
}
}
