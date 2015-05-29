#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <unordered_set>
#include <chrono>
#include <ctime>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void vector_fill(vector<string>& words)
{
    string input_filename = "words.txt";
    
    ifstream fin;
    fin.open(input_filename.c_str());
    
    if (!fin.is_open())
    {
        cout << "The file " << input_filename << " could not be opened.";
        cout << endl;
        exit(1);
    }
    
    while (fin.good())
    {
        string word;
        fin >> word;
        words.push_back(word);
    }
    
    fin.close();
    
    // checking if the words are inserted in the vector properly
    /*
    ofstream fout;
    fout.open("word_test.txt");
    
    for (unsigned i = 0; i < words.size(); i++)
    {
        fout << words.at(i);
        if (i != words.size() - 1)
        fout << endl;
    }
    
    fout.close();
    */
    
}

double set_fill (set<string> & s, const vector<string> & v, int n)
{
    double x = 0;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    
    for (int i = 0; i < n; i++)
    {
        s.insert(v.at(i));
    }
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    
    x = time_span.count();
    
    return x;
}

double hash_fill(unordered_set<string> & s, const vector<string> & v, int n)
{
    double x = 0;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    
    for (int i = 0; i < n; i++)
    {
        s.insert(v.at(i));
    }
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    
    x = time_span.count();
    
    return x;
}

double set_find(set<string> & s, const vector<string> & v, int n)
{
    double x = 0;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        s.find(v.at(i));
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    
    x = time_span.count();
    
    return x;
}

double hash_find(unordered_set<string> & s, const vector<string> & v, int n)
{
    double x = 0;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        s.find(v.at(i));
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    
    x = time_span.count();
    
    return x;
}

int main()
{
    vector<string> words;
    vector_fill(words);
    
    set<string> tree;
    unordered_set<string> hash;
    
    int n = 0;
    int num_tests = 10;
    int min_inserts = 5000;
    int max_inserts = 50000;
    int iterations = 0;
    double set_insert = 0;
    double unordered_insert = 0;
    double set_query = 0;
    double unordered_query = 0;
    
    string output_filename = "data.txt";
    
    ofstream fout;
    fout.open(output_filename.c_str());
    if (!fout.is_open())
    {
        cout << "The file " << output_filename << "could not be opened.";
        cout << endl;
        exit(1);
    }
    
    for (int i = 0; i < num_tests; i++)
    {
        for (n = min_inserts; n <= max_inserts; n += 5000)
        {
            set_insert = set_fill(tree, words, n);
            unordered_insert = hash_fill(hash, words, n);
            
            set_query = set_find(tree, words, n);
            unordered_query = hash_find(hash, words, n);
            
            fout << n << ' ' << set_insert << ' ' << unordered_insert;
            fout << ' ' << set_query << ' ' << unordered_query;
            
            if (!(i == (num_tests - 1) && n == max_inserts))
            fout << endl;
            
            iterations++;
            
            tree.clear();
            hash.clear();
        }
        
        // cout << i << ' ' << n << endl;
        random_shuffle(words.begin(), words.end());
        // find average and print
        
        n = 0;
    }
    
    fout.close();
    
    
    return 0;
}