#include "BigInt.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

typedef BigInt bINT;

std::string input(const char *message) {
    std::string text;
    std::cout << message;
    std::cout.flush();
    std::getline(std::cin, text);
    return text;
}

// recursively determine input
int get_from(std::string str) {
    try { // int
        return std::stoi(str);
    } catch (...) {
        try { // hexadecimal
            return std::stoi(str, 0, 16);
        } catch(...) {
            try {
                std::ifstream f(str);
                std::string fcts;
                std::getline(f, fcts, '\0');
                return get_from(fcts);
            } catch(...) {
                std::cerr << "Cannot parse input.";
                exit(1);
            }
        }
    }
}

std::vector<bINT> get_from_v(std::vector<std::string> s) {
    std::vector<bINT> v_i;
    for (int i = 0; i < s.size(); i++) {
        v_i.push_back(get_from(s[i]));
    }
    return v_i;
}

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos = 0;
    std::vector<std::string> tokens;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
    return tokens;
}

void print_vec(std::vector<bINT> v) {
    std::cout << "[";
    if (v.size() > 0) {
        std::cout << v[0];
    }
    for (int i = 1; i < v.size(); i++) {
        std::cout << ", " << v[i];
    }
    std::cout << "]";
}

int main(int argc, char ** argv) {
    std::vector<bINT> m, c;
    bINT n;
    std::string text = argv[2];
    std::string key = argv[3];
    std::string modulo = argv[4];
    if (argv[1][0] == 'd') {
        /*text = input("[+] Enter plaintext: ");
        key = input("[+] Enter key (e): ");
        modulo = input("[+] Enter the modulo (n): ");*/

        // m^e % n = c
        std::vector<std::string> s_sp = split(text, ", ");
        std::vector<std::string> sp = split(text, ",");
        m = get_from_v(s_sp.size() == sp.size()?s_sp:sp);
        n = get_from(modulo);

        for (int i = 0; i < m.size(); i++) c.push_back(pow(m[i], get_from(key)) % n);

        std::cout << "Ciphertext: ";
        print_vec(c);
        //std::cout << std::endl;
    } else {
        /*text = input("[+] Enter ciphertext: ");
        key = input("[+] Enter private key (d): ");
        modulo = input("[+] Enter the modulo (n): ");*/

        // m^e % n = c
        std::vector<std::string> s_sp = split(text, ", ");
        std::vector<std::string> sp = split(text, ",");
        m = get_from_v(s_sp.size() == sp.size()?s_sp:sp);
        n = get_from(modulo);

        for (int i = 0; i < m.size(); i++) c.push_back(pow(m[i], get_from(key)) % n);

        std::cout << "Plaintext: ";
        print_vec(c);
        //std::cout << std::endl;
    }
}