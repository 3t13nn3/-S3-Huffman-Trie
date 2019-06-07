# -S3-Huffman-Trie
A project of my second year of university based on the words indexations and the huffman coding from a text library.

This project aims to compare 3 indexations methods of indexing by their speeds.

### Prerequisites

You must indicate your textes files in the ```texts.cpp```, in the ```addFilesPath``` function, by following this scheme:
* ```fichiers.push_back("myPath/myText.txt");```

You could use the default files I used:
* Download [Gutenberg Books](https://drive.google.com/open?id=1RnSn3jUBKIeumk7XZThDi_GBOAeGoJvq)
* Move it to the project directory
* Extract and remove the archive with ```tar xvzf gutenberg-books.tar.gz && rm gutenberg-books.tar.gz```


### How to use - *Linux Project*

Compile the program with ```make```.

Clean object files and binary by ```make clean```.

Lauch the binary as ```./ProjetAS1```.

## Authors

* **Etienne PENAULT** - *Algorithme & Structure de donnée I* - Paris VIII
