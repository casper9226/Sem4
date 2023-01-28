/*
* A book consists of chapters, chapters consist of sections and sections consist of
* subsections. Construct a tree and print the nodes. Find the time and space requirements
* of your method.
*/

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#define clear_buffer cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

namespace mine
{
    class node
    {
    public:
        string data;
        vector<node*> children;
        int chapter_counter;
        node()
        {
            data = "";
            chapter_counter = 0;
        }
        node(const string& data)
        {
            this->data = data;
            this->chapter_counter = 0;
        }
    };

    class general_tree
    {
    private:
        friend class node;
        node* root_ptr;
        node* temp_ptr;
    public:
        general_tree();
        void create_tree();
        void insert_chapter(const int&);
        void insert_section(const int&, const string&);
        void insert_subsection(const int&, const int&, const string&);
        void display();
    };
}

int main()
{
    using mine::general_tree;

    general_tree *book = new general_tree();
    book->create_tree();
    book->display();
    
    return 0;
}

mine::general_tree::general_tree()
{
    this->root_ptr = new node();
    this->temp_ptr = new node();
}

void mine::general_tree::create_tree()
{
    cout << "Creating tree." << endl;
    int chapter_counter;

    cout << "\nEnter the name of Book: ";
    std::getline(cin, this->root_ptr->data);
    cout << endl;

    cout << "How many chapters are there?: ";
    cin >> chapter_counter;
    cout << endl;

    clear_buffer;
    this->insert_chapter(chapter_counter);
}

void mine::general_tree::insert_chapter(const int& chapter_counter)
{
    for (int i = 0; i < chapter_counter; i++)
    {
        // chapter creation and pushing
        string chapter_name;
        cout << "Enter the name of chapter " << (i+1) << ": ";
        std::getline(cin, chapter_name);
        cout << endl;
        
        node* chapter = new node(chapter_name);
        this->root_ptr->children.push_back(chapter);

        this->insert_section(i, chapter_name);
    }
}

void mine::general_tree::insert_section(const int& i, const string& chapter_name)
{
    // section creation corrwsponding to chapter[i]
    int section_count;
    cout << "How many sections are there in chapter " << chapter_name << ": ";
    cin >> section_count;
    cout << endl;
    clear_buffer;

    // appending sections to chapter[i]
    for (int c = 0; c < section_count; c++)
    {
        string section_name;
        cout << "Enter the name of section " << (c+1) << ": ";
        std::getline(cin, section_name);
        cout << endl;

        node* section = new node(section_name);
        this->root_ptr->children[i]->children.push_back(section);
        
        this->insert_subsection(i, c, section_name);
    }
}

void mine::general_tree::insert_subsection(const int& i, const int& c, const string& section_name)
{
    // sub-section creation corresponding to section[i]
    int sub_section_count = 0;
    cout << "How many sub-sections are there in section " << section_name << ": ";
    cin >> sub_section_count;
    cout << endl;
    clear_buffer

    // appending sub_section to section[i]
    for (int s = 0; s < sub_section_count; s++)
    {
        string sub_section_name;
        cout << "Enter the name of sub-section " << (s+1) << ": ";
        std::getline(cin, sub_section_name);
        cout << endl;

        node* sub_section = new node(sub_section_name);
        this->root_ptr->children[i]->children[c]->children.push_back(sub_section);
    }
}

void mine::general_tree::display()
{
    cout << "Book name: " << this->root_ptr->data << endl;
    for (auto chapter : this->root_ptr->children)
    {
        cout << "\tChapter name: " << chapter->data << endl;
        for (auto section : chapter->children)
        {
            cout << "\t\tSection name: " << section->data << endl;
            for (auto sub_section : section->children)
            {
                cout << "\t\t\tSub Section name: " << sub_section->data << endl;
            }
        }
    }
}