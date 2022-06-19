#include<iostream>

using namespace std;

class Artifact {
  public:
    string artifactname, type, rarity;
    double cv, critrate, critdamage;
    int level;
    Artifact * next;
    Artifact * previous;
  
  Artifact() {
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
    Artifact * head;

  ArtifactLinkedList() {
    head = NULL;
  }
  ArtifactLinkedList(Artifact * n) {
    head = n;
  }

  // 1. CHeck if Artifact exists using artifact name value

  Artifact * ArtifactExists(string an) {
    Artifact * temp = NULL;
    Artifact * ptr = head;

    while (ptr != NULL) {
      if (ptr -> artifactname == an) {
        temp = ptr;
      }
      ptr = ptr -> next;
    }

    return temp;
  }

  // 2. Append a Artifact to the list

  void appendArtifact(Artifact * n) {
    if (ArtifactExists(n -> artifactname) != NULL) {
      cout << "Artifact Already exists with artifactname value : " << n -> artifactname << ". Append another Artifact with different artifactname value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Artifact Appended as Head Artifact" << endl;
      } else {
        Artifact * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        n -> previous = ptr;
        cout << "Artifact Appended" << endl;
      }
    }
  }

  // 3. Prepend Artifact - Attach a Artifact at the start
  void prependArtifact(Artifact * n) {
    if (ArtifactExists(n -> artifactname) != NULL) {
      cout << "Artifact Already exists with artifactname value : " << n -> artifactname << ". Append another Artifact with different artifactname value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Artifact Prepended as Head Artifact" << endl;
      } else {
        head -> previous = n;
        n -> next = head;
        head = n;
        cout << "Artifact Prepended" << endl;
      }
    }
  }

  // 4. Insert a Artifact after a particular Artifact in the list
  void insertArtifactAfter(string an, Artifact * n) {
    Artifact * ptr = ArtifactExists(an);
    if (ptr == NULL) {
      cout << "No Artifact exists with the artifact name " << an << endl;
    } else {
      if (ArtifactExists(n -> artifactname) != NULL) {
        cout << "Artifact Already exists with artifactname value : " << n -> artifactname << ". Append another Artifact with different artifactname value" << endl;
      } else {
        Artifact * nextArtifact = ptr -> next;
        // inserting at the end
        if (nextArtifact == NULL) {
          ptr -> next = n;
          n -> previous = ptr;
          cout << "Artifact Inserted at the END" << endl;
        }

        //inserting in between
        else {
          n -> next = nextArtifact;
          nextArtifact -> previous = n;
          n -> previous = ptr;
          ptr -> next = n;

          cout << "Artifact Inserted in Between" << endl;

        }

      }
    }
  }

  //void searchArtifactByartifactname(string an) {
    //Artifact * ptr = ArtifactExists(an);
    //if (ptr == NULL) {
      //cout << "No Artifact exists with that artifact name! " << an << endl;
    //} else {
      //if (ArtifactExists(an -> artifactname) != NULL) {
        //cout << "\nArtifact name: " << temp -> artifactname << "\nType: " << temp -> type << "\nCrit value: " << temp -> cv << "\nLevel: " << temp -> level << "\nRarity: " << temp -> rarity << "";
      //}
    //}
  //}
  
  
  // 5. Delete Artifact by unique artifactname. Basically De-Link not delete
  void deleteArtifactByartifactname(string an) {
    Artifact * ptr = ArtifactExists(an);
    if (ptr == NULL) {
      cout << "No Artifact exists with artifact name" << an << endl;
    } else {
      if (head -> artifactname == an) {
        head = head -> next;
        cout << "Artifact UNLINKED with artifactnames value : " << an << endl;
      } else {
        Artifact * nextArtifact = ptr -> next;
        Artifact * prevArtifact = ptr -> previous;
        // deleting at the end
        if (nextArtifact == NULL) {

          prevArtifact -> next = NULL;
          cout << "Artifact Deleted at the END" << endl;
        }

        //deleting in between
        else {
          prevArtifact -> next = nextArtifact;
          nextArtifact -> previous = prevArtifact;
          cout << "Artifact Deleted in Between" << endl;

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

  void rateArtifact(string an1, double cv1) {
    Artifact * ptr = ArtifactExists(an1);
      if (cv1 >= 0 && cv1 <= 9) {
        cout << "Dont Upgrade";
        }
        else if (cv1 >= 10 && cv1 <= 19) {
          cout << "Average";
        }
        else if (cv1 >= 20 && cv1 <= 29) {
          cout << "Decent";
        }
        else if (cv1 >= 30 && cv1 <= 39) {
          cout << "Very Good";
        }
        else if (cv1 >= 40 && cv1 <= 49) {
          cout << "Jewel";
        }
        else {
          cout << "Magic Unicorn";
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
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. append Artifact" << endl;
    cout << "2. prepend Artifact" << endl;
    cout << "3. insert Artifact After" << endl;
    cout << "4. delete Artifact By Name" << endl;
    cout << "5. update Artifact By Name" << endl;
    cout << "6. print Artifact List" << endl;
    cout << "7. Clear Screen" << endl;

    cin >> option;
    Artifact * n1 = new Artifact();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "This is the Append Artifact Operation" << endl;
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
      cout << "Prepend Artifact Operation \nEnter the data of the Artifact that needs to be Prepended" << endl;
      cout << "Enter the new artifact name: " << endl;
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
      cout << "Insert Artifact After Operation \nEnter artifact name of existing Artifact after which you want to Insert this New Artifact: " << endl;
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

      cout << "Delete Artifact By artifact name Operation - \nEnter the name of an Artifact to be deleted: " << endl;
      cin >> an1;
      obj.deleteArtifactByartifactname(an1);
      break;

    //case 5:
      //cout << "SEARCH Artifact By artifact name Operation" << endl;
      //cout << "Enter the artifact name that you want to search for: " << endl;
      //cin >> an1;
      //obj.searchArtifactByartifactname(an1);

      //break;

    case 5:
      cout << "Update Artifact By artifact name Operation" << endl;
      cout << "Enter the artifact name that you want to update the stats for: " << endl;
      cin >> artifactname1;
      cout << "Enter the updated crit rate: " << endl;
      cin >> critrate1;
      cout << "Enter the updated crit damage: " << endl;
      cin >> critdamage1;
      cout << "Enter the updated level: " << endl;
      cin >> level1;

      obj.updateArtifactByartifactname(artifactname1, critrate1, critdamage1, level1);
      break;

    case 6:
      obj.printList();
      break;

    //case 7:
      //cout << "Rate Artifact By artifact name Operation" << endl;
      //cout << "Enter the artifact name that you want us to rate: " << endl;
     // cin >> an1;
      //n1 -> cv1 = (critrate1*2) + critdamage1;
      //obj.rateArtifact(an1, cv1, n1);
      //break;

    case 7:
      system("cls");
      break;
      
    default:
      cout << "Enter Proper Option number " << endl;
    }
  
  } 
  while (option != 0);
  return 0;
};