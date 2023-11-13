#include "main.h"

void non_interactive_mode()
{
   char *line = NULL, *command, *argv[1024];
   size_t len = 0;
   ssize_t read;
   pid_t pid;
   int argc = 0, status;

  FILE *file = fopen("commands.txt", "r");
   if (file == NULL) {
      perror("Error opening file");
      return;
   }

   while ((read = getline(&line, &len, file)) != -1) {
      line[read - 1] = '\0';

      command = strtok(line, " ");
      while (command != NULL) {
         argv[argc] = command;
         argc++;
         command = strtok(NULL, " ");
      }
      argv[argc] = NULL;

      pid = fork();
      if (pid == 0) {
         if (execve(argv[0], argv, NULL) == -1) {
            perror("execve");
            return;
         }
      } else if (pid < 0) {
         perror("fork");
         return;
      } else {
         waitpid(pid, &status, 0);
      }
   }

   free(line);
   fclose(file);
}
