#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

double critRate;
double critDmg;

//typedef string ItemType;
class Artifact {
private:
    string name;
    string type;
    int critValue = critDmg + (critRate * 2);
    string rating;
    int rarity;
    int level;
public:
    Artifact();
    Artifact(int level, int rarity, string name, int critValue, string type, string rating);
    string getName();
    int getCritValue();
    string getType();
    string getRating();
    int getLevel();
    int getRarity();
    void setName(string newname);
    void setCritValue(int newCritValue);
    void setType(string newType);
    void setRating(string newRating);
    void setLevel(int newLevel);
    void setRarity(int newRarity);
};
class BinarySearchTree
{
private:
    struct tree_node
    {
        tree_node* left;
        tree_node* right;
        //ItemType data;
        Artifact data;
    };
    tree_node* root;
public:
    BinarySearchTree()
    {
        root = NULL;
    }
    bool isEmpty() const { return root == NULL; }
    void print_inorder();
    void inorder(tree_node*);
    void insert(Artifact);
    void remove(string);
    void search(string key);
    void changeCritValue(string key, int newCritValue);
    void changeLevel(string key, int newLevel);
};
Artifact::Artifact()
{
}
Artifact::Artifact(int newLevel, int newRarity, string newname, int newCritValue, string newType, string newRating)
{
    name = newname;
    critValue = newCritValue;
    type = newType;
    rating = newRating;
    level = newLevel;
    rarity = newRarity;
}
int Artifact::getLevel() {
    return level;
}
string Artifact::getName() {
    return name;
}
int Artifact::getCritValue() {
    return critValue;
}
int Artifact::getRarity() {
    return rarity;
}
string Artifact::getType() {
    return type;
}
string Artifact::getRating() {
    return rating;
}
void Artifact::setLevel(int newLevel) {
    level = newLevel;
}
void Artifact::setName(string newname) {
    name = newname;
}
void Artifact::setType(string newType) {
    type = newType;
}
void Artifact::setCritValue(int newCritValue) {
    critValue = newCritValue;
}
void Artifact::setRating(string newRating) {
    rating = newRating;
}
void Artifact::setRarity(int newRarity) {
    rarity = newRarity;
}

// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert(Artifact p)
{
    auto start = high_resolution_clock::now();
    tree_node* t = new tree_node;
    tree_node* parent = NULL;
    t->data = p;
    t->left = NULL;
    t->right = NULL;
    // is this a new tree?
    if (isEmpty()) root = t;
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while (curr)
        {
            parent = curr;
            if (t->data.getName() > curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
        if (t->data.getName() < parent->data.getName())
            parent->left = t;
        else
            parent->right = t;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << " Time taken by function: "
            << duration.count() << " milliseconds" << endl;
    }
}
void BinarySearchTree::remove(string p)
{
    auto start = high_resolution_clock::now();
    //Locate the element
    bool found = false;
    if (isEmpty())
    {
        cout << " This Tree is empty! " << endl;
        return;
    }
    tree_node* curr;
    tree_node* parent = NULL;
    curr = root;
    while (curr != NULL)
    {
        if (curr->data.getName() == p)
        {
            found = true;
            break;
        }
        else
        { 
            parent = curr;
            if (p > curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
    }
    if (!found)
    {
        cout << " Data not found! " << endl;
        return;
    }
    if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL
        && curr->right == NULL))
    {
        if (curr->left == NULL && curr->right != NULL)
        {
            if (parent->left == curr)
            {
                parent->left = curr->right;
                delete curr;
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << " Time taken by function: "
                    << duration.count() << " milliseconds" << endl;
            }
            else
            {
                parent->right = curr->right;
                delete curr;
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << " Time taken by function: "
                    << duration.count() << " milliseconds" << endl;
            }
        }
        else // left child present, no right child
        {
            if (parent->left == curr)
            {
              
                parent->left = curr->left;
                delete curr;
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << " Time taken by function: "
                    << duration.count() << " milliseconds" << endl;
            }
            else
            {
              
                parent->right = curr->left;
                delete curr;
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << " Time taken by function: "
                    << duration.count() << " milliseconds" << endl;
            }
        }
        return;
    }
    //We're looking at a leaf node
    if (curr->left == NULL && curr->right == NULL)
    {
       
        if (parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
        delete curr;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << " Time taken by function: "
            << duration.count() << " milliseconds" << endl;
        return;
    }
    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if ((chkr->left == NULL) && (chkr->right == NULL))
        {
           
            curr = chkr;
            delete chkr;
            curr->right = NULL;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);

            cout << " Time taken by function: "
                << duration.count() << " milliseconds" << endl;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element
            if ((curr->right)->left != NULL)
            {
               
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while (lcurr->left != NULL)
                {
                    lcurrp = lcurr;
                    lcurr = lcurr->left;
                }
                curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << " Time taken by function: "
                    << duration.count() << " milliseconds" << endl;
            }
            else
            {
              
                tree_node* tmp;
                tmp = curr->right;
                curr->data = tmp->data;
                curr->right = tmp->right;
                delete tmp;
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << " Time taken by function: "
                    << duration.count() << " milliseconds" << endl;
            }
         
        }
        return;
    }
   
}
void BinarySearchTree::print_inorder()
{
    auto start = high_resolution_clock::now();
    inorder(root);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << " Time taken by function: "
        << duration.count() << " milliseconds" << endl;
}
void BinarySearchTree::inorder(tree_node* p)
{
    
    if (p != NULL)
    {
        if (p->left) inorder(p->left);
        cout << "  " << p->data.getLevel() << "\t\t" << p->data.getRarity() << "\t\t" << p->data.getName() << "\t\t" << p->data.getCritValue() << "\t\t\t" << p->data.getType() << "\t\t" << p->data.getRating() << endl;
        if (p->right) inorder(p->right);
    }
    else return;
    
}

//////////////////new/////////////////////////
void BinarySearchTree::search(string key)
{
    auto start = high_resolution_clock::now();
    bool found = false;
    if (isEmpty())
    {
        cout << " This Tree is empty! " << endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while (curr != NULL)
    {
        if (curr->data.getName() == key)
        {
            found = true;
            cout << "  LEVEL\t\tRARITY\t\tNAME\t\tCRITVALUE\t\tTYPE\t\tRATING" << endl;
            cout << "  "<<curr->data.getLevel() << "\t\t" << curr->data.getRarity() << "\t\t" << curr->data.getName() << "\t\t" << curr->data.getCritValue() << "\t\t\t" << curr->data.getType() << "\t\t\t" << curr->data.getRating() << endl;
            break;
        }
        else
        {
            parent = curr;
            if (key > curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
    }
    if (!found)
    {
        cout << " Data not found! " << endl;
        return;

    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << " Time taken by function: "
        << duration.count() << " milliseconds" << endl;
}
void BinarySearchTree::changeCritValue(string p, int newCritValue) {
    auto start = high_resolution_clock::now();
    bool found = false;
    if (isEmpty())
    {
        cout << " This Tree is empty! " << endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while (curr != NULL)
    {
        if (curr->data.getName() == p)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if (p > curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
    }
    if (!found)
    {
        cout << " Artifact not found. " << endl;
        return;
    }

    //change the crit value associated with the node
    curr->data.setCritValue(newCritValue);
    cout << "Crit value changed successfully. " << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << " Time taken by function: "
        << duration.count() << " milliseconds" << endl;

}
void BinarySearchTree::changeLevel(string p, int newLevel) {
    auto start = high_resolution_clock::now();
    bool found = false;
    if (isEmpty())
    {
        cout << " This Tree is empty! " << endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while (curr != NULL)
    {
        if (curr->data.getName() == p)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if (p > curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
    }
    if (!found)
    {
        cout << " Artifact not found. " << endl;
        return;
    }
    //Change Level
    curr->data.setLevel(newLevel);
    cout << "Level changed successfully. " << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << " Time taken by function: "
        << duration.count() << " milliseconds" << endl;

}
/////////////////////////////////////new add into Artifact manager class//////////////
//void fillTree( BinarySearchTree b)
void fillTree(BinarySearchTree* b)//Line 368
{
    auto start = high_resolution_clock::now();
    ifstream file;
    file.open("ArtifactInfo.txt");
    if (!file) {
        cout << " Error opening file. " << endl;
    }
    //variables used to load data into the tree
    string name;
    int critValue = critDmg + (critRate * 2);
    int rarity;
    string rating;
    string type;
    int level;
    Artifact p;
    while (file >> level >> rarity >> name >> critValue >> type >> rating)
    {
        p.setLevel(level);
        p.setName(name);
        p.setCritValue(critValue);
        p.setType(type);
        p.setRating(rating);
        cout << p.getLevel() << "  " << p.getRarity() << "  " << p.getName() << "  " << p.getCritValue() << "  " << p.getType() << "  " << p.getRating() << endl;
        //b.insert(p);
        (*b).insert(p); //Line 384
    }
    file.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
     
    cout << " Time taken by function: "
        << duration.count() << " milliseconds" << endl;
}

int main()
{
    BinarySearchTree b;
    int ch;
    string name;
    string key;
    string type;
    int rarity;
    int level;
    double critRate = 0;
    double critDmg = 0;
    int critValue = critDmg + (critRate * 2);
    string rating = "lul";
    Artifact tmp;
    Artifact tmp1;

    fillTree(&b); // Line 398//print the contents of ArtifactInfo.txt 
    while (1)
    {
        cout << endl << endl;
        cout << " Binary Search Tree Operations " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 0. Search             " << endl;
        cout << " 1. Insertion/Creation " << endl;
        cout << " 2. All Artifacts Information " << endl;
        cout << " 3. Removal " << endl;
        cout << " 4. Change Crit Value " << endl;
        cout << " 5. Exit " << endl;
        cout << " Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 0: cout << " Enter the name of the Artifact to search for: ";
            cin >> key;
            b.search(key);
            break;
        case 1: cout << " Enter name to be inserted: ";
            cin >> name;
            cout << " Enter Type(ex: Sands, Goblet, Flower, Feather): ";
            cin >> type;
            cout << " Enter Artifact Rarity: ";
            cin >> rarity;
            if (rarity == 5) {
                cout << " Enter Artifact Level: ";
                cin >> level;
                cout << " Enter crit rate: ";
                cin >> critRate;
                cout << " Enter crit damage: ";
                cin >> critDmg;
                critValue = critDmg + (critRate * 2);
                if (critValue >= 0 && critValue <= 9) {
                    rating = "Dont Upgrade";
                }
                else if (critValue >= 10 && critValue <= 19) {
                    rating = "Average";
                }
                else if (critValue >= 20 && critValue <= 29) {
                    rating = "Decent";
                }
                else if (critValue >= 30 && critValue <= 39) {
                    rating = "Very Good";
                }
                else if (critValue >= 40 && critValue <= 49) {
                    rating = "Jewel";
                }
                else {
                    rating = "Magic Unicorn";
                }
                tmp.setName(name);
                tmp.setCritValue(critValue);
                tmp.setType(type);
                tmp.setLevel(level);
                tmp.setRarity(rarity);
                tmp.setRating(rating);
                b.insert(tmp);
                break;
            }
            else {
                cout << " Invalid rarity, rarity must be above 5 stars";
                break;
            }
        case 2: cout << endl;
            cout << "  \t\t\t\t\tArtifact  Information " << endl;
            cout << " -----------------------------------------------------------------------------------------------" << endl;
            cout << "  LEVEL\t\tRARITY\t\tNAME\t\tCRITVALUE\t\tTYPE\t\tRATING" << endl;
            b.print_inorder();
            break;
        case 3: cout << " Enter data to be deleted : ";
            cin >> key;
            b.remove(key);;
            break;
        case 4: cout << " Enter the name of the Artifact of which the crit value you wish to change: " << endl;
            cin >> name;
            cout << "Enter new artifact level: ";
            cin >> level;
            cout << endl << " Enter the new Crit Rate: ";
            cin >> critRate;
            cout << endl << " Enter the new Crit Damage: ";
            cin >> critDmg;
            critValue = (critDmg + (critRate * 2));
            cout << endl;
            b.changeCritValue(name, critValue);
            b.changeLevel(name, level);
            break;
        case 5: return 0;

        }
    }
}
