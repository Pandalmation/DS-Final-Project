#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

//create artifact class that stores name, type, rarity, critrate, critdamage and crit value

class Artifact {
  public:
    string artifactname, type, rarity;
    double cv, critrate, critdamage;
    int level;
    Artifact * next; //pointer to a node and indicates the next item in the list
    Artifact * previous; //pointer to a node and indicates the prev item in the list
  
  Artifact() { //create default constructor
    artifactname = "";
    type = "";
    critrate = 0;
    critdamage = 0;
    cv = 0;
    level = 0;
    rarity = "";
    next = NULL;
    previous = NULL;
  }
  Artifact(string an, double cr, double cd, int lvl, string rty, string typ) {
    artifactname = an;
    type = typ;
    cv = (cr*2)+cd;
    level = lvl;
    rarity = rty;
    critrate = cr;
    critdamage = cd;
  }
};

class ArtifactLinkedList {

  public:
    Artifact * head; //pointer of class artifact where head is a pointer of Artifact node which points to the first node.

  ArtifactLinkedList() { //default constructor. When a doubly linked list object is created for the first time, head pointer inside the object will be pointing to null.
    head = NULL;
  }
  ArtifactLinkedList(Artifact * n) { //created parameterized constructor, if create by passing a node object then it will point to that node object.
    head = n;
  }

  // 1. Check if Artifact exists using artifact name

  Artifact * ArtifactExists(string an) { //if artifact exists in the doubly linked list, it will return address to that object
    Artifact * temp = NULL;//temporary pointer of class artifact and store null initially
    Artifact * ptr = head;//head pointer is going to be inside the object in doubly linked last, it will store the temporary pointer

    while (ptr != NULL) { //if it has address
      if (ptr -> artifactname == an) { //pointer accessing artifact's name and see if it matches 
        temp = ptr;
      }
      ptr = ptr -> next;  //pointing to the next object/artifact which will be storing the address of the next object until the list ends where the address is null
    }

    return temp; //return address
  }

  // 2. Append a Artifact to the list

  void appendArtifact(Artifact * n) { //passing the address of the node/artifact
    auto start = high_resolution_clock::now();
    if (ArtifactExists(n -> artifactname) != NULL) { //check if artifact exists alrdy with the same name value and head is pointing to an object
      cout << "Artifact Already exists with the artifact name: " << n -> artifactname << ". Append another Artifact with a different artifact name please." << endl;//accessing the artifact name of the object using pointer
    } else {
      if (head == NULL) {
        head = n; //store in head pointer
        auto stop = high_resolution_clock::now();
        cout << "Artifact Appended as Head Artifact" << endl;
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
      } else {
        Artifact * ptr = head;
        while (ptr -> next != NULL) { //if head is pointing into artiface node n1
          ptr = ptr -> next; //move n1 to n2
        }
        ptr -> next = n;
        n -> previous = ptr;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Artifact Appended" << endl;
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
      }
    }
  }

  // 3. Prepend Artifact - Attach a Artifact at the start
  void prependArtifact(Artifact * n) {
    auto start = high_resolution_clock::now();
    if (ArtifactExists(n -> artifactname) != NULL) {
      cout << "Artifact Already exists with the artifact name: " << n -> artifactname << ". Append another Artifact with a different artifact name please." << endl;
    } else {
      if (head == NULL) {
        head = n;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Artifact Prepended as Head Artifact" << endl;
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
      } else {
        head -> previous = n;
        n -> next = head;
        head = n;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Artifact Prepended" << endl;
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
      }
    }
  }

  // 4. Insert a Artifact after a particular Artifact in the list
  void insertArtifactAfter(string an, Artifact * n) {
    auto start = high_resolution_clock::now();
    Artifact * ptr = ArtifactExists(an);
    if (ptr == NULL) {
      cout << "No Artifact exists with the artifact name " << an << endl;
    } else {
      if (ArtifactExists(n -> artifactname) != NULL) {
        cout << "Artifact Already exists with the artifact name : " << n -> artifactname << ". Append another Artifact with a different artifact name please :)" << endl;
      } else {
        Artifact * nextArtifact = ptr -> next;
        // inserting at the end
        if (nextArtifact == NULL) {
          ptr -> next = n;
          n -> previous = ptr;
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "Artifact Inserted at the END" << endl;
          cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
        }

        //inserting in between
        else {
          n -> next = nextArtifact;
          nextArtifact -> previous = n;
          n -> previous = ptr;
          ptr -> next = n;
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "Artifact Inserted in Between" << endl;
          cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

        }

      }
    }
  }
  // Search artifact by the artifact name
  void searchArtifactByartifactname(string an) {
    auto start = high_resolution_clock::now();
    Artifact * ptr = ArtifactExists(an);
    if (ptr == NULL) {
      cout << "No Artifact exists with the artifact name: " << an << endl;
    } else {
      if (ptr -> artifactname == an) {
        cout << "\nThe Artifact " << an << " is found in the List!" << endl;
        cout << "\n<><><><><><><><><><><><><><><><>";
        cout << "\nArtifact name: " << ptr -> artifactname << "\nType: " << ptr -> type << "\nCrit value: " << ptr -> cv << "\nLevel: " << ptr -> level << "\nRarity: " << ptr -> rarity << "";
        cout << "\n<><><><><><><><><><><><><><><><>" << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
      }
    }
  }
  
  
  // 5. Delete Artifact by unique artifactname. Basically De-Link not delete
  void deleteArtifactByartifactname(string an) {
    auto start = high_resolution_clock::now();
    Artifact * ptr = ArtifactExists(an);
    if (ptr == NULL) {
      cout << "No Artifact exists with artifact name: " << an << endl;
    } else {
      if (head -> artifactname == an) {
        head = head -> next;
        cout << "Artifact " << an << " has been successfully deleted." << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
      } else {
        Artifact * nextArtifact = ptr -> next;
        Artifact * prevArtifact = ptr -> previous;
        // deleting at the end
        if (nextArtifact == NULL) {
          prevArtifact -> next = NULL;
          cout << "Artifact Deleted at the END" << endl;
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
        }
        //deleting in between
        else {
          prevArtifact -> next = nextArtifact;
          nextArtifact -> previous = prevArtifact;
          cout << "Artifact Deleted in Between" << endl;
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
           cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
        }
      }
    }
  }

  // 6th update Artifact
  void updateArtifactByartifactname(string an, double cr, double cd, int lvl) {

    Artifact * ptr = ArtifactExists(an);
    if (ptr != NULL) {
      ptr -> cv = (cr*2) + cd;
      ptr -> level = lvl;
      cout << "The Artifact's crit value and level has been Updated Successfully" << endl;
    } else {
      cout << "Cannot find the artifact with the name : " << an << endl;
    }

  }

  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Artifacts found in the List";
    } else {
      cout << endl << "YOUR ARTIFACTS LIST : ";
      cout << "\n<><><><><><><><><><><><><><><><>";
      Artifact * temp = head;

      while (temp != NULL) {
        cout << "\nArtifact name: " << temp -> artifactname << "\nType: " << temp -> type << "\nCrit value: " << temp -> cv << "\nLevel: " << temp -> level << "\nRarity: " << temp -> rarity << "";
        cout << "\n<><><><><><><><><><><><><><><><>";
        temp = temp -> next;
      }
    }
  }

  void rateArtifact(string an) {
    Artifact * ptr = ArtifactExists(an);
    double cv1 = ptr->cv;
    if (cv1 >= 0 && cv1 <= 9) {
      cout << "Our Rating:\nDont Upgrade";
    }
    else if (cv1 >= 10 && cv1 <= 19) {
      cout << "Our Rating:\nAverage";
    }
    else if (cv1 >= 20 && cv1 <= 29) {
      cout << "Our Rating:\nDecent";
    }
    else if (cv1 >= 30 && cv1 <= 39) {
      cout << "Our Rating:\nVery Good";
    }
    else if (cv1 >= 40 && cv1 <= 49) {
      cout << "Our rating:\nJewel";
    }
    else {
      cout << "Our rating: \nMagic Unicorn";
    } 
  } 
};   

int main() {
  ArtifactLinkedList obj;
  int option;
  string artifactname1, an1, rarity1, type1;
  int  level1;
  double cv1, critrate1, critdamage1;
  do {
    cout << "\nWelcome to Kokopium's Genshin Impact Artifact Rater!" << endl;                
    cout << "\nWhich operation would you like to perform? Enter 1-9. Enter 0 to exit." << endl;
    cout << "1. Append Artifact" << endl;
    cout << "2. Prepend Artifact" << endl;
    cout << "3. Insert Artifact After" << endl;
    cout << "4. Delete Artifact" << endl;
    cout << "5. Search for Artifact" << endl;
    cout << "6. Update Artifact" << endl;
    cout << "7. Print All Artifacts" << endl;
    cout << "8. Rate Artifact" << endl;
    cout << "9. Clear Screen" << endl;

    cin >> option;
    Artifact * n1 = new Artifact();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "This is the APPEND Artifact Operation\nEnter the data of the Artifact to be added into the list" << endl;
      cout << "Enter a new artifact name: " << endl;
      cin >> artifactname1;
      cout << "what is the artifact type? (ex: sands, hat, goblet, flower, feather)" << endl;
      cin >> type1;
      cout << "Enter a new artifact's crit rate: " << endl;
      cin >> critrate1;
      cout << "Enter a new artifact's crit damage: " << endl;
      cin >> critdamage1;
      cout << "Enter a new artifact's level: " << endl;
      cin >> level1;
      cout << "Enter a new artifact's rarity: " << endl;
      cin >> rarity1;
      n1 -> artifactname = artifactname1;
      n1 -> type = type1;
      n1 -> cv = (critrate1*2) + critdamage1;
      n1 -> level = level1;
      n1 -> rarity = rarity1;
      obj.appendArtifact(n1);
      break;

    case 2:
      cout << "PREPEND Artifact Operation \nEnter the data of the Artifact to be added into the top of the list" << endl;
      cout << "Enter a new artifact name: " << endl;
      cin >> artifactname1;
      cout << "what is the artifact type? (ex: sands, hat, goblet, flower, feather)" << endl;
      cin >> type1;
      cout << "Enter the new artifact's crit rate: " << endl;
      cin >> critrate1;
      cout << "Enter the new artifact's crit damage: " << endl;
      cin >> critdamage1;
      cout << "Enter the new artifact's level: " << endl;
      cin >> level1;
      cout << "Enter the new artifact's rarity: " << endl;
      cin >> rarity1;

      n1 -> artifactname = artifactname1;
      n1 -> type = type1;
      n1 -> cv = (critrate1*2)+critdamage1;
      n1 -> level = level1;
      n1 -> rarity = rarity1;
      obj.prependArtifact(n1);
      break;

    case 3:
      cout << "INSERT Artifact AFTER Operation \nEnter the name of an existing Artifact which you want to Insert this New Artifact after: " << endl;
      cin >> an1;
      cout << "Enter the name of the new artifact you want to insert: " << endl;
      cin >> artifactname1;
      cout << "what is the artifact type? (ex: sands, hat, goblet, flower, feather)" << endl;
      cin >> type1;
      cout << "Enter the new artifact's crit rate: " << endl;
      cin >> critrate1;
      cout << "Enter the new artifact's crit damage: " << endl;
      cin >> critdamage1;
      cout << "Enter the new artifact's level: " << endl;
      cin >> level1;
      cout << "Enter the new artifact's rarity: " << endl;
      cin >> rarity1;
      n1 -> artifactname = artifactname1;
      n1 -> type = type1;
      n1 -> cv = (critrate1*2) + critdamage1;
      n1 -> level = level1;
      n1 -> rarity = rarity1;

      obj.insertArtifactAfter(an1, n1);
      break;

    case 4:
      cout << "DELETE Artifact By artifact name Operation\nEnter the name of the Artifact to be deleted: " << endl;
      cin >> an1;
      obj.deleteArtifactByartifactname(an1);
      break;

    case 5:
      cout << "SEARCH Artifact By artifact name Operation" << endl;
      cout << "Enter the artifact's name that you want to search for: " << endl;
      cin >> an1;
      obj.searchArtifactByartifactname(an1);
      break;
      
    case 6:
      cout << "Update Artifact By artifact name Operation" << endl;
      cout << "Enter the artifact's name that you want to update the stats for: " << endl;
      cin >> artifactname1;
      cout << "Enter the updated crit rate: " << endl;
      cin >> critrate1;
      cout << "Enter the updated crit damage: " << endl;
      cin >> critdamage1;
      cout << "Enter the updated level: " << endl;
      cin >> level1;

      obj.updateArtifactByartifactname(artifactname1, critrate1, critdamage1, level1);
      break;

    case 7:
      obj.printList();
      break;

    case 8:
      cout << "Rate Artifact By artifact name Operation" << endl;
      cout << "Enter the artifact's name that you want us to rate: " << endl;
      cin >> an1;
      //n1 -> cv = (critrate1*2) + critdamage1;
      obj.rateArtifact(an1);
      break;

    case 9:
      system("cls");
      break;
      
    default:
      cout << "Enter Proper Option number " << endl;
    }
  
  } 
  while (option != 0);
  return 0;
};
