#include <string>
//pour stocker du texte avec std::string
//permet de les manipuler
#include <iostream>
//pour lire et écrire depuis la console
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char) std::toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}



//std::cout est l'objet de flux de sortie standard pour écrire dans la console
// << est utilisé pour insérer du texte dans le flux de sortie
// std::endl est utilisé pour insérer un /n et vider le tampon du flux de sortie

//boucle for
//for(initialisation; condition; incrémentation)
//on initialise i à 1
//on détermine la condition de sortie de la boucle, i < argc
//on incrémente i à chaque itération

//nouvelle boucle for qui incrémente sur ma chaine de char
//j'utilise toupper pour transformer chaque char minuscule en majuscule
//pr toupper on a besoin de <cctype> qui n'est pas forcément inclus dans l'environnement
//je dois cast en char la sortie de toupper qui donne la lettre en ASCII qui est alors interpretée
//par std::count comme un entier lors de l'affichage

//en C++
//je n'ai plus de besoin d'initialiser mes itérateurs avant ma boucle
//je fais une initialisation locale dans la portée de la boucle
//pour initialiser i avant j'aurais écrit int i(0);