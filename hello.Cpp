#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <sstream>

using namespace std;
using namespace boost::filesystem;

int main()
{
    vector <string> str,parsed_str;
    path p("./fake_pcd");
    string delimiter = ".";
    string token,parsed_filename;
    size_t pos = 0;
    int int_filename;
    vector <int> int_dir;

    //insert filenames in the directory to a string vector
    for (auto i = directory_iterator(p); i != directory_iterator(); i++)
    {
        if (!is_directory(i->path())) //we eliminate directories in a list
        {
        str.insert(str.end(),i->path().filename().string());
        }
        else
            continue; 
    }

    //parse each string element in the vector, split from each delimiter 
    //add each token together and convert to integer
    //put inside a integer vector 
    parsed_str = str;
    for (std::vector<string>::iterator i=parsed_str.begin(); i != parsed_str.end(); ++i)
    {
        cout << *i << endl;
        while ((pos = i->find(delimiter)) != string::npos) {    
        token = i->substr(0,pos);
        parsed_filename += token;
        i->erase(0, pos + delimiter.length());
    }

    int_filename = stoi(parsed_filename);
    int_dir.push_back(int_filename);

    parsed_filename = "";
    }

    cout << endl;

    parsed_str.clear();

    sort(int_dir.begin(), int_dir.end());

    //print the sorted integers
    for(vector<int>::const_iterator i=int_dir.begin(); i != int_dir.end(); i++) {
        cout << *i << endl;
    }

    //convert sorted integers to string and put them back into string vector
    for (auto &x : int_dir) {
        stringstream ss;
        ss << x;
        string y;
        ss >> y;
        parsed_str.push_back(y);
    }

    cout << endl;

    //change the strings so that they are like the original filenames  
    for(vector<string>::iterator i=parsed_str.begin(); i != parsed_str.end(); i++) {
        *i = i->substr(0,3) + "." + i->substr(3,3) + ".pcd";
        cout << *i << endl;
    }


}
