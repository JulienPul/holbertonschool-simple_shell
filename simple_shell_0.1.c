#include "main.h"

/**
 * main - Version petit shell 0.1
 * Return: 0 si succès sinon retourne 1
 */

 int main(void)
 {
	 char *ligne_lue = NULL;
	 size_t taille_buffer = 0;
	 ssize_t nb_caracteres_lus;
	 pid_t pid_enfant;
	 int statut;
	 char *arguments[2];
 
	 while (1)
	 {
		 printf("$ ");
		 nb_caracteres_lus = getline(&ligne_lue, &taille_buffer, stdin);
 
		 if (nb_caracteres_lus == -1) /* Ctrl+D */
		 {
			 free(ligne_lue);
			 exit(0);
		 }
 
		 /* Supprimer le \n à la fin de la ligne lue */
		 if (ligne_lue[nb_caracteres_lus - 1] == '\n')
			 ligne_lue[nb_caracteres_lus - 1] = '\0';
 
		 pid_enfant = fork();
		 if (pid_enfant == -1)
		 {
			 perror("fork");
			 free(ligne_lue);
			 exit(1);
		 }
		 else if (pid_enfant == 0)
		 {
			 arguments[0] = ligne_lue;
			 arguments[1] = NULL;
			 if (execve(arguments[0], arguments, environ) == -1)
			 {
				 perror("./hsh");
				 exit(1);
			 }
		 }
		 else
		 {
			 wait(&statut);
		 }
	 }
 
	 free(ligne_lue);
	 return (0);
 }
 
