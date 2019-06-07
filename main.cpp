#include "trie.hpp"

/*On test si le caractere est une majuscule,
si oui, on le transforme en minuscule*/
void up_to_low(char& c){
	if(c >= 'A' && c <= 'Z')
		c += 32; //difference entre une majuscule et une minuscule dans la table ASCII
}

hmap methode_1(const vector<std::string> fichier){
	hmap table;
	for(auto i : fichier){
		std::ifstream file(i, std::ifstream::in);
		if(file){
			std::string word;
			char c = file.get();
			while (file.good()){
				if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
					up_to_low(c);
					word.push_back(c);
				}
				else{
					if(word.empty() == 0){
						table[word]++;
						word.clear();
					}
				}
				c = file.get();
			}
			file.close();
		}else{
			std::cout << "Erreur lors de l'ouverture du fichier.\n";
		}
	}
	return table;	
}

/*REPRESENTATION VISUELLE DE LA METHODE 2
				H
			   / \
			  E   I
			 / \
			L  A
		   /    \
		  L      P
		 /
		O                               */
std::unique_ptr<stdtrie> methode_2(const vector<std::string> fichier){
	std::unique_ptr<stdtrie> pt = std::make_unique<stdtrie>();
	for(auto i : fichier){
		std::ifstream file(i, std::ifstream::in);
		if(file){
			std::string word;
			char c = file.get();
			while (file.good()){
				if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
					up_to_low(c);
					word.push_back(c);
				}
				else{
					if(word.empty() == 0){
						++stdtrie::push_trie(pt,word);
						word.clear();
					}
				}
				c = file.get();
			}
			file.close();
		}else{
			std::cout << "Erreur lors de l'ouverture du fichier.\n";
		}
	}	
	return pt;
}


std::unique_ptr<montrie> methode_3(const vector<std::string> fichier){
	std::unique_ptr<montrie> pt = std::make_unique<montrie>();
	for(auto i : fichier){
		std::ifstream file(i, std::ifstream::in);
		if(file){
			std::string word;
			char c = file.get();
			while (file.good()){
				if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
					up_to_low(c);
					word.push_back(c);
				}
				else{
					if(word.empty() == 0){
						++montrie::push_montrie(pt,word);
						word.clear();
					}
				}
				c = file.get();
			}
			file.close();
		}else{
			std::cout << "Erreur lors de l'ouverture du fichier.\n";
		}
	}	
	return pt;
}

int main(){
	vector<std::string> fichiers; //Vecteur ou l'on va stocker les fichiers
	addFilesPath(fichiers);	//On ajoute tout les chemins dans le vecteur

	std::chrono::time_point<std::chrono::system_clock> start, end;
	float temps;//Différence entre end et start.
	
	start = std::chrono::system_clock::now();
		hmap a = methode_1(fichiers);
	end = std::chrono::system_clock::now();
	temps = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	std::cout << "Temps pour la méthode 1: " << temps << " millisecondes"<< '\n';

//	Test pour voir si cela fonctionne.
	for(auto const& [mot, val] : a){
		if(mot == "according")
			std::cout << mot << " " << val << '\n';
	}

	start = std::chrono::system_clock::now();
		std::unique_ptr<stdtrie> pt = methode_2(fichiers);
	end = std::chrono::system_clock::now();
	temps = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	std::cout << "Temps pour la méthode 2: " << temps << " millisecondes"<< '\n';

//	Test pour voir si cela fonctionne.
	std::cout << stdtrie::push_trie(pt,"according") << "\n"; //On doit trouver 14480.



	start = std::chrono::system_clock::now();
		std::unique_ptr<montrie> ptt = methode_3(fichiers);
	end = std::chrono::system_clock::now();
	temps = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	std::cout << "Temps pour la méthode 3: " << temps << " millisecondes"<< '\n';

//	Test pour voir si cela fonctionne.
	std::cout << montrie::push_montrie(ptt,"according") << "\n"; //On doit trouver 14480.




//Méthode 3 faites à la base. VRAIMENT TROP LENTE pour beaucoup de mots a stocker car vector.
//Décommenter pour tester.
//Temps trop long pour tester sur tout les fichiers, tester avec un seul ou deux.
/*	start = std::chrono::system_clock::now();
		vector<cellule> b = methode_3old(fichiers);
	end = std::chrono::system_clock::now();
	temps = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	std::cout << "Temps pour la méthode 3old: " << temps << " millisecondes"<< '\n';
*/

//	Test pour voir si cela fonctionne.
/*	for(auto const& [mot, count, key] : b){
		if(mot != "") //Si notre case de notre table: contient un mot/n'est pas vide
			std::cout << mot << " " << count << " " << key <<'\n';
	}
*/
	return 0;
}