#include "trie.hpp"

/*************MÉTHODE 3 OLD (INUTILISÉE)**************/
int hachage(std::string word){//Notre formule pour le hash
	int key=0;
    for(auto i=0; word[i] != '\0'; ++i){
        key += word[i] * 500;
    }
   	return key %= 20000;
}

/*Ajoute une cellule dans notre vecteur si la cellule est vide
sinon on va a la prochaine case du vecteur pour ajouter notre mot*/
/*GESTION DES COLLISIONS*/
void push_cell(std::string word, vector<cellule>& v){
	int k = hachage(word);
	for(vector<cellule>::size_type i=k; i<v.size(); ++i){ //i est initialiser a la valeur de notre clef
		if(v[i].word.empty()){
			v[i].key = i;	//La clef correspondante au mot correspond a i et non k, car en cas de collision, i=i+1
			v[i].word = word;
			v[i].count = 1;
		return;
		} else if((v[i].word == word) && v[i].key == (int)i){
			++v[i].count;	//Si le mot existe déjà, on augmente son compteur
			return;
		}
	}
}


vector<cellule> methode_3old(const vector<std::string> fichier){
	vector<cellule> m;
    cellule v; //cellule vide que l'on va rajouter au vecteur quand on va ajouter un mot.	
	for(std::vector<std::__cxx11::basic_string<char> >::size_type i = 0; i<fichier.size(); ++i){	
		std::ifstream file(fichier[i], std::ifstream::in);
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
						m.push_back(v); //On ajoute notre cellule
						push_cell(word,m);
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
	return m;
}
/*FIN*********MÉTHODE 3 OLD (INUTILISÉE)**********FIN*/
