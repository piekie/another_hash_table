#include <vector>
#include <string.h>

template<typename A, typename B>
void show(std::vector<A> containerA, std::vector<B> containerB) {
    int size = containerA.size();
    for (int i = 0; i < size; i++) {
        std::cout << containerA[i] << " : " << containerB[i] << std::endl;
    }
}

class Hash {
private:
    unsigned int hashify(const char * str) { /* LY */
        unsigned int hash = 0;
        for(; *str; str++)
            hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;

        return hash % tableSize;
    }

    struct Cell {
        std::string value;
        std::string real_key;

        Cell(std::string _real_key, std::string _value) {
            value    = _value;
            real_key = _real_key;
        }
    };

    unsigned int tableSize;
    std::vector< std::vector<Cell> > table;
    std::vector< std::string       > keys;
    std::vector< unsigned int      > hashified_keys;

public:
    Hash() {
        /* tableSize = this->max_size() / 1000; */ //Uncomment for normal work. Comment next line
        tableSize = 5;                             //We got more collision with less tableSize. 5 for showing off.
        table.resize(tableSize);
    }

    void push(std::string real_key, std::string value) {
        unsigned int hashifed_key = hashify(real_key.c_str());

        table[ hashifed_key ].push_back( *(new Cell(real_key, value)) );
        keys.push_back(real_key);
        hashified_keys.push_back(hashifed_key);
    }

    std::string get(std::string real_key) {
        unsigned int hashified_key = hashify(real_key.c_str());

        //reverse iterator. when keys are the same, last pushed item will be returned. not first
        for (std::vector<Cell>::reverse_iterator i = table[hashified_key].rbegin(); i != table[hashified_key].rend(); i++) {
            if (strcmp( (*i).real_key.c_str(), real_key.c_str() ) == 0) {
                return (*i).value;
            }
        }
        return "no exist";
    }

    std::vector< std::string > getKeys() {
        return keys;
    }

    std::vector< unsigned int > getHashified() {
        return hashified_keys;
    }
};

