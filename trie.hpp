#include <iostream>
#include <unordered_map>
#include <fstream>
#include <memory>
#include <chrono>
#include <vector>
using std::vector;

//Méthode 1
using hmap = std::unordered_map<std::string,int>;

//Méthode 2
using stdtrie = class trie{

private:
    std::unordered_map<char, std::unique_ptr<trie> > next_char_;
    int count_;

public:
	/*Ajoute un mot dans le trie de la méthode 2*/
	//int& permet d'incrémenter le compteur lors de l'appel de la fonction
	static int& push_trie(std::unique_ptr<trie>& t, std::string const& w){ //int& permet d'incrémenter le compteur lors de l'appel de la fonction
		//Alias pour naviguer dans notre trie
		trie* pt = t.get();	//.get() pour récupere l'adresse d'un unique_ptr.
		for(char c : w){	//On parcour les caractères du mot.
			if(pt->next_char_[c]==nullptr){	//trie pour ce caractère courant à cette position.
				pt->next_char_[c]=std::make_unique<trie>();	//Alors on en crée un.
			}
			pt=pt->next_char_[c].get();	//On passe au caractère suivant en attribuant l'adresse du prochain.
		}
		return pt->count_;	//On retourne le compteur du mot en question
	}	
};

//Méthode 3
using montrie = class mtrie{

private:
    std::unique_ptr<mtrie> next[26];
    int count_;

public:
    /*Ajoute un mot dans le trie de la méthode 3*/
	static int& push_montrie(std::unique_ptr<mtrie>& t, std::string const& w){
		mtrie* pt = t.get();
		int index;
		for(char c : w){
			//97 est la valeur de 'a' dans la table ASCII
			//On enlève cette valeur pour se caler sur les indexs du tableau(a=0, b=1...)
			index = c - 97; 
			if(pt->next[index]==nullptr){
				pt->next[index]=std::make_unique<mtrie>();
			}
			pt=pt->next[index].get();
		}
		return pt->count_;
	}
};

//Méthode 3old
struct Cellule{
	std::string word;
	int count;
	int key;
};
typedef Cellule cellule;


/*Fonctions de main.cpp*/
void up_to_low(char&);
hmap methode_1(const vector<std::string>);
std::unique_ptr<stdtrie> methode_2(const vector<std::string>);
std::unique_ptr<montrie> methode_3(const vector<std::string>);

/*Fonction texts.cpp*/
void addFilesPath(vector<std::string>&);

/*Fonctions des classes*/
int& push_trie(std::unique_ptr<stdtrie>&, std::string const&);
int& push_montrie(std::unique_ptr<montrie>&, std::string const&);

/*Fonctions de méthode3old.cpp*/
int hachage(std::string);
void push_cell(std::string, vector<cellule>&);
vector<cellule> methode_3old(const std::string []);