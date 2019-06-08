# -S3-Huffman-Trie
A project of my second year of university based on the words indexations and the huffman coding from a text library.

This project aims to compare 3 indexations methods of indexing by their speed.

If you are a french speaker, I invite you to check the [Report of this project](https://github.com/3t13nn3/-S3-Huffman-Trie/blob/master/Rapport/RAPPORT.pdf) for more details.

## Prerequisites

You must indicate your texts files in the ```texts.cpp```, in the ```addFilesPath``` function, by following this scheme:
* ```fichiers.push_back("myPath/myText.txt");```

You could use the default files I used:
* Download [Gutenberg Books](https://drive.google.com/open?id=1RnSn3jUBKIeumk7XZThDi_GBOAeGoJvq)
* Move it to the project directory
* Extract and remove the archive with ```tar xvzf gutenberg-books.tar.gz && rm gutenberg-books.tar.gz```


## How to use - *Linux Project*

### Compilation

Compile the program with ```make```.

### Utilisation

Lauch the binary as ```./ProjetAS1```.

### Clean files

Clean object files and binary by ```make clean```.

## Exemple of Execution

You can find an example of execution at the end of the page 12 in my [Project Report](https://github.com/3t13nn3/-S3-Huffman-Trie/blob/master/Rapport/RAPPORT.pdf).


## Author

* **Etienne PENAULT** - *Algorithme & Structure de donnée I* - Paris VIII
