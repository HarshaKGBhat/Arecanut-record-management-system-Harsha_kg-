//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include <iostream>    
#include <fstream>      
#include <limits>        
#include <cstring>
#include <iomanip>
#include<string>
#include<stdlib.h>
#include<stdio.h> 
#include<ctime>
#include<conio.h>
#include <windows.h>

using namespace std;


//***************************************************************
//        FUNCTIONs PROTOTYPES THAT USED IN PROJECTS
//****************************************************************


bool validateInput();               
bool isEmpty(ifstream &file);      
void Executions(int ch);

void harvmenu();

void admmenu();

int main();





//***************************************************************
//                   GLOBAL VARIABLES
//****************************************************************

const char *fileName = "recording.txt";


int logintype;
bool check = true;
int search;
int size;
bool flag;
int ids[100];
int count = 0;


// Here too i need to fill with some classes





//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************


class invoice
{
	public: int basic_ammount, weight, ammount, total_ammount,bonus,weighing_charge,labour,kid,bag;
			char name[50],city[20],typ[10];
};
invoice iv[100];

class marketrate
{
	public:char rashi[15],month[15],bette[5],chali[5],kole[15],buffer[100],dt[100];
};
marketrate s2[100];


class market_rate
{
public:char Rashi[15],Bette[15],kole[5],chali[5],buffer[45],aid[10],dt[100];
		int no;
};
market_rate  mr2[100];

//........ storage class.......
class storage
{
	public:			char ind[5],rashi[15],bette[5],sem[5],kole[15],slot[5];
					int kid;
					
}stdrec[20];

void display_records();
void add_record();


class Harvestor {
public:
    int kid, age,i,n,bag,weight;
    long long int phoneno;
    char name[100], address[100], Adhar_Number[100], gender[10], trade_crop[500],city[200],crop[100],land_size[100],trade_crop_No[100],manure[50];
    double ammount;
    char areca_name[100],code[100];
	float Rate;
	

public:
    // constructor function
    harvestor() {
        // Default Initialization Except Garbage Value
       // kid = '0';
        strcpy(name, "no name");
        strcpy(name, "no address");
        strcpy(name, "no Adhar_Number");
        //salary = 0;
    }








		   // member function
    void getData();             // function to get  Record From User.
    void writeFile();           // function to Write  Records in a file that get From User.
    void readFile();            // function to Read  Records from a file.
    void showData();            // function to Print All Employees Records that Read From a File.
    void searchData();          // function to search Data from file.
    void updateData(int input); // function to Update Data from file.
    void deleteData(int input); // function to Delete Data from file.
    void sortData();            // function to Sorts  Data in Desending Order w.r.t Salary.
    void randddep();

    void testdep();

    void traindep();

    void salesdep();

    void accdep();

    void invoice_generator();

    void id_validator();
    
    void getarecaData();
    
    void displayarecaData();
    
    //void add_record();
    //void display_records();
    void delete_record();
    void search_record();
    int get_num_records();
    void retrieve_details();
    void Trade();
    string takePasswdFromUser(

    char sp = '*');
    
    
};
    
///ar sl=s.slot;
    

//***************************************************************
//           DEFINATION OF MEMBER FUNCTIONS OF CLASS
//****************************************************************
void Harvestor::getData() {
    bool flag = false;

    label1:
    cout << "\tEnter Harvestor Name : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(name, 100);
    flag = validateInput();
    if (flag)
        goto label1;


    label2:
    int i = 0;
    cout << "\tEnter KISAN ID of cultivator : ";
    cin >> kid;
    for (i = 0; i <= count; i++) {
        if (kid == 0) {
            cout << "\nKiD can't be zero !";
            goto label2;
        }
        if (ids[i] == kid) {
            cout << "\n\tThat id is already exists ! \n \nPlease enter another id\n";
            goto label2;
        }
    }
    flag = validateInput();
    if (flag)
        goto label2;


    label3:
    cout << "\tEnter Harvestor Gender : ";
    cin >> gender;
    flag = validateInput();
    if (flag)
        goto label3;

    label4:
    cout << "\tEnter harvestor Age : ";
    cin >> age;
    flag = validateInput();
    if (flag)
        goto label4;


    label5:
    cout << "\tEnter the name of the areca type    : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(crop, 100);
    flag = validateInput();
    if (flag)
        goto label5;


    label6:
    cout << "\tEnter Harvestor Land size (in acre): ";
    cin.getline(land_size, 100);
    flag = validateInput();
    if (flag)
        goto label6;


    label7:
    cout << "\tEnter name of the fertillizers and manure used by Harvestor    : ";
    cin >> manure;
    flag = validateInput();
    if (flag)
        goto label7;

    label8:
    cout << "\nEnter Harvestor Phone number : ";
    cin >> phoneno;
    flag = validateInput();
    if (phoneno<10)
    cout<<"invalid!! must be 10 digit\n";
	    if (flag)
        goto label8;

    label9:
    cout << "\nEnter Harvestor City or village : ";
    cin >> city;
    flag = validateInput();
    if (flag)
        goto label9;
}






void Harvestor::writeFile() {
    if (name == "no name" && kid == 0) {
        cout << "\tHarvestor Record is not initialized" << endl;

    } else {
        fstream file;
        file.open(fileName, ios::out | ios::app | ios::binary);

        file.write((char *) this, sizeof(*this));

        file.close();

        if (!file.good()) {
            // this is enterd For Check Any Error After Writing the file. For Example File Memory Full, File Format Errors.
            cout << "\tError occurred at writing time!" << endl;
        }
    }
}





void Harvestor::readFile() {
    ifstream file;
    file.open(fileName, ios::in | ios::binary);

    if (!file) {
        cout << "\tFile can not Open";
        cout << '\n' << "Press any key to continue...\n";
        cin.ignore();
        cin.get();

        if (logintype == 1) {
            harvmenu();
        } else {
            admmenu();
        }
    } else {
        if (isEmpty(file)) {
            cout << "\n\tYour File is Empty! No Record is Available to Show\n";
            cout << '\n' << "Press any key to continue...\n";
            cin.ignore();
            cin.get();

            if (logintype == 1) {
                harvmenu();
            } else {
                admmenu();
            }
        } else {
            file.read((char *) this, sizeof(*this));
            cout
                    << "-----------------------------------------------------------------------------------------------------------------\n";
            cout << setw(12) << left << " KID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                 << setw(8) << left << "Gender" << setw(20) << left << "crop" << setw(15) << left << "land_size"
                 << setw(10) << "manure" << setw(15) << "Phoneno" << setw(14) << "City";
            cout
                    << "\n-----------------------------------------------------------------------------------------------------------------";
            cout << endl;
            while (!file.eof()) {
                showData();
                file.read((char *) this, sizeof(*this));
            }
            cout << '\n' << "Press any key to continue...\n";
            cin.ignore();
            cin.get();

            if (logintype == 1) {
                harvmenu();
            } else {
                admmenu();
            }

            file.close();
        }
    }
}



void Harvestor::showData() {


    cout << setw(12) << left << kid << setw(20) << left << name << setw(5) << left << age << setw(8) << left << gender
         << setw(20) << left << crop << setw(15) << left << land_size << setw(10) << manure
         << setw(14) << phoneno << setw(15) << city << endl;


}



void Harvestor::searchData() {
    bool flag = false;
    int ch;
    char nm[100];
    int input;
    long long int phn;
    fstream file;
    file.open(fileName, ios::in | ios::binary);
    cout << "Enter the key on which you want to search\n";
    cout << "1.Name \n 2.KID \n 3.Phone number\n";
    cin >> ch;
    switch (ch) {
        case 1: {
            cout << "Enter the name:";
            cin >> nm;
            if (!file) {
                cout << "\tFile Cannot be Open";
            } else {
                file.read((char *) this, sizeof(*this));
                cout << setw(12) << left << " KID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                     << setw(8) << left << "Gender" << setw(20) << left << "crop" << setw(15) << left << "land_size"
                     << setw(10) << "manure" << setw(15) << "Phoneno" << setw(14) << "City" << "\n";
                while (!file.eof()) {
                    if (!strcmp(nm, name)) {
                        showData();
                        flag = true;
                    }
                    file.read((char *) this, sizeof(*this));
                }

                file.close();

                if (!flag) {
                    cout << "\tRecord For This ID Does Not Exist";
                    cout << '\n' << "Press any key to continue...\n";
                    cin.ignore();
                    cin.get();

                    if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }
                }
            }

        }
            break;
        case 2:
            cout << "Enter the Kisan ID:";
            cin >> input;

            if (!file) {
                cout << "\tFile Cannot be Open";
                cout << '\n' << "Press any key to continue...\n";
                cin.ignore();
                cin.get();

                if (logintype == 1) {
                    harvmenu();
                } else {
                    admmenu();
                }

            } else {
                file.read((char *) this, sizeof(*this));
                cout << setw(12) << left << " KID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                     << setw(8) << left << "Gender" << setw(20) << left << "crop" << setw(15) << left << "land_size"
                     << setw(10) << "manure" << setw(15) << "Phoneno" << setw(14) << "City";
                cout << endl;
                while (!file.eof()) {
                    if (input == kid) {
                        showData();
                        flag = true;
                    }
                    file.read((char *) this, sizeof(*this));
                }

                file.close();

                if (!flag) {
                    cout << "\tRecord For This ID Does Not Exist";
                    cout << '\n' << "Press any key to continue...\n";
                    cin.ignore();
                    cin.get();

                    if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }

                }
            }
            break;
        case 3: {
            cout << "Enter the phone number:";
            cin >> phn;
            if (!file) {
                cout << "\tFile Cannot be Open";
                cout << '\n' << "Press any key to continue...\n";
                cin.ignore();
                cin.get();

                if (logintype == 1) {
                    harvmenu();
                } else {
                    admmenu();
                }
            } else {
                file.read((char *) this, sizeof(*this));
                cout << setw(12) << left << " KID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                     << setw(8) << left << "Gender" << setw(20) << left << "crop" << setw(15) << left << "land_size"
                     << setw(10) << "manure" << setw(15) << "Phoneno" << setw(14) << "City";
                cout << endl;

                while (!file.eof()) {
                    if (phn == phoneno) {
                        showData();
                        flag = true;
                    }
                    file.read((char *) this, sizeof(*this));
                }

                file.close();

                if (!flag) {
                    cout << "\tRecord For This KID Does Not Exist";
                    cout << '\n' << "Press any key to continue...\n";
                    cin.ignore();
                    cin.get();

                    if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }
                }
            }

        }
            break;

    }
}


void Harvestor::updateData(int input) {
    bool flag = false;
    fstream file;
    file.open(fileName, ios::in | ios::out | ios::ate | ios::binary);

    if (!file) {
        cout << "\tFile Cannot Open Successfully!";
        cout << '\n' << "Press any key to continue...\n";
        cin.ignore();
        cin.get();

        if (logintype == 1) {
            harvmenu();
        } else {
            admmenu();
        }
    } else {
        file.seekg(0, ios::beg);
        file.read((char *) this, sizeof(*this));
        while (!file.eof()) {
            if (input == kid) {
                showData();
                cout << "\n\tEnter Updated Record :- \n\n";
                getData();
                int position = (-1) * static_cast<int>(sizeof(*this));
                file.seekp(position, ios::cur);
                file.write((char *) this, sizeof(*this));
                flag = true;
            }
            file.read((char *) this, sizeof(*this));
        }

        if (!flag) {
            cout << "\tRecord For This ID Does Not Exist";
        } else {
            cout << "\n\tNew Records Has Been Updated Successfully\n";
            Harvestor hp;
            //ep.id_validator();
            cout << '\n' << "Press any key to continue...\n";
            cin.ignore();
            cin.get();

            if (logintype == 1) {
                harvmenu();
            } else {
                admmenu();
            }
        }
    }
}





void Harvestor::deleteData(int input) {
    int c1, c2;
    bool flag = true;
    ofstream fout;
    ifstream fin;
    fin.open(fileName, ios::in | ios::binary);

   if (!fin) {
       cout << "\tFile Cannot Open Successfully!";
        cout << '\n' << "Press any key to continue...\n";
        cin.ignore();
        cin.get();

       if (logintype == 1) {
            harvmenu();
        } else {
           admmenu();
    }
    } else {
       fin.read((char *) this, sizeof(*this));
        fout.open("tempfile.txt", ios::out );
        while (!fin.eof()) {
           if (input != kid) {
                fout.write((char *) this, sizeof(*this));
            }
            fin.read((char *) this, sizeof(*this));
        }
        fin.close();
        fout.close();

        fstream f1, f2;
        f1.open(fileName, ios::in | ios::binary);
        f2.open("tempfile.txt", ios::in );

        while (true) {
            c1 = f1.get();
            c2 = f2.get();
            if (c1 != c2) {
                flag = false;
               break;
            }
          if ((c1 == EOF) || (c2 == EOF))
                break;
        }

		f1.close();
        f2.close();

        if (flag) {
            cout << "\tRecord For This ID Does Not Exist";
       } else {
           label:
            fstream file;
            file.open(fileName, ios::in | ios::binary);
            int choice;
            while (file.read((char *) this, sizeof(*this))) {
                if (input == kid) {
                    showData();
                }
            }
            file.close();
            cout << "\n\tAre Your Sure to Delete The Above Record\n";
            cout << "\t1 : Yes\n";
            cout << "\t2 : No\n";
            cout << "\tEnter Your Choice : ";
            cin >> choice;
            if (choice == 1) {
                remove(fileName);
                rename("tempfile.txt", fileName);
                cout << "\n\n\tRecord is Deleted Successfully";


            } else if (choice == 2) {
                remove("tempfile.txt");
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tError : Invalid Choice Detected! Please Enter Valid Choice";
                goto label;
            }

            Harvestor hp;
            hp.id_validator();

            cout << '\n' << "Press any key to continue...\n";
            cin.ignore();
            cin.get();

            if (logintype == 1) {
                harvmenu();
            } else {
                admmenu();
            }


    }
}

}


    




    


void  Harvestor::sortData() {
    int ch;
    int size, fileSize, objSize, position;
    Harvestor *ptr = NULL;

    ifstream file;
    file.open(fileName, ios::in | ios::binary);

    if (isEmpty(file)) {
        cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
    } else {
        file.close();
        cout << "\n Enter the data on which records are to be sorted:";

        cout << "\n 1.kisan ID\n 2.Name \n 3.Age\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                int size, fileSize, objSize, position;
                 Harvestor*ptr = NULL;

                ifstream file;
                file.open(fileName, ios::in | ios::binary);

                if (isEmpty(file)) {
                    cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
                } else {
                    file.seekg(0, ios::end);

                    fileSize = static_cast<int>(file.tellg());
                    objSize = static_cast<int>(sizeof(*this));
                    size = fileSize / objSize;

                    ptr = new Harvestor[size];

                    file.seekg(0, ios::beg);

                    for (int i = 0; i < size; i++) {
                        file.read((char *) &ptr[i], sizeof(*this));
                    }
                    file.close();

                    for (int i = 0; i < size; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (ptr[i].kid > ptr[j].kid) {
                                swap(ptr[i], ptr[j]);
                            }
                        }
                    }
                    cout
                            << "\n-----------------------------------------------------------------------------------------------------------------\n";
                    cout << "\nSorted Cultivator Details With Respect to kisan ID\n";
                    cout
                        << "\n-----------------------------------------------------------------------------------------------------------------\n";
                    cout << setw(12) << left << "kisan ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                         << setw(8) << left << "Gender" << setw(20) << left << "crop" << setw(15) << left
                         << "land_size"
                         << setw(10) << "manure" << setw(15) << "Phoneno" << setw(14) << "City";
                    cout
                         << "\n-----------------------------------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < size; i++) {
                        ptr[i].showData();
                    }

                    delete[] ptr;

                    cout << '\n' << "Press any key to continue...\n";
                    cin.ignore();
                    cin.get();

                    if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }

                }
                break;
            }

            case 2: {
                int count = 0;
                 Harvestor *ptr = NULL;

                ifstream file;
                ifstream file2;

                file2.open(fileName, ios::in | ios::binary);
                if (isEmpty(file2)) {
                    cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
                } else {
                    while (!file2.eof()) {

                        file2.read((char *) this, sizeof(*this));
                        count++;
                    }
                    count--;
                }


                file.open(fileName, ios::in | ios::binary);

                if (isEmpty(file)) {
                    cout << "\n\tYour File is Empty! No Record is Available to Show\n";
                } else {
                    file.seekg(0, ios::end);

                    fileSize = static_cast<int>(file.tellg());
                    objSize = static_cast<int>(sizeof(*this));
                    size = fileSize / objSize;

                    ptr = new  Harvestor[size];

                    file.seekg(0, ios::beg);

                    for (int i = 0; i < size; i++) {
                        file.read((char *) &ptr[i], sizeof(*this));
                    }
                    file.close();


                    






                    int i = 0, j = 0;
                    for (i = 1; i < count; i++) {
                        for (j = 1; j < count; j++) {
                            if (strcmp(ptr[j - 1].name, ptr[j].name) > 0) {


                                swap(ptr[j], ptr[j - 1]);

                            }
                        }
                    }


                    cout << "\n\n\t======== Sorted cultivator Details With Respect to Name ========\n\n";
                    cout << setw(12) << left << "kisan ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                         << setw(8) << left << "Gender" << setw(20) << left << "crop" << setw(15) << left
                         << "land_size"
                         << setw(10) << "manure" << setw(15) << "Phoneno" << setw(14) << "City";
                    cout << "\n";

                    for (int i = 0; i < size; i++) {
                        ptr[i].showData();
                    }

                    delete[] ptr;

                    cout << '\n' << "Press any key to continue...\n";
                    cin.ignore();
                    cin.get();

                    if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }

                }
                break;
            }
            case 3: {
                int size, fileSize, objSize, position;
                 Harvestor *ptr = NULL;

                ifstream file;
                file.open(fileName, ios::in | ios::binary);

                if (isEmpty(file)) {
                    cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
                    cout << '\n' << "Press any key to continue...\n";
                    cin.ignore();
                    cin.get();

                    if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }

                } else {
                    file.seekg(0, ios::end);

                    fileSize = static_cast<int>(file.tellg());
                    objSize = static_cast<int>(sizeof(*this));
                    size = fileSize / objSize;

                    ptr = new  Harvestor[size];

                    file.seekg(0, ios::beg);

                    for (int i = 0; i < size; i++) {
                        file.read((char *) &ptr[i], sizeof(*this));
                    }
                    file.close();

                    for (int i = 0; i < size; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (ptr[i].age < ptr[j].age) {
                                swap(ptr[i], ptr[j]);
                            }
                        }
                    }

                    cout << "\n\n\t======== Sorted cultivator Details With Respect to Age ========\n\n";
                    cout << setw(12) << left << "kisan ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                         << setw(8) << left << "Gender" << setw(20) << left << "crop" << setw(15) << left
                         << "land_size"
                         << setw(10) << "manure" << setw(15) << "Phoneno" << setw(14) << "City";
                    cout << "\n";

                    for (int i = 0; i < size; i++) {
                        ptr[i].showData();
                    }

                    delete[] ptr;
                    cout << '\n' << "Press any key to continue...\n";
                    cin.ignore();
                    cin.get();

                    if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }

                }
                break;
            }

            case 4: {
                int size, fileSize, objSize, position;
                 Harvestor *ptr = NULL;

                ifstream file;
                file.open(fileName, ios::in | ios::binary);

                if (isEmpty(file)) {
                    cout << "\n\tYour File is Empty! No Record is Available to Show\n";
                    cout << '\n' << "Press any key to \n";
                    cin.ignore();
                    cin.get();

                    if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }

                } else {
                    file.seekg(0, ios::end);

                    fileSize = static_cast<int>(file.tellg());
                    objSize = static_cast<int>(sizeof(*this));
                    size = fileSize / objSize;

                    ptr = new  Harvestor[size];

                    file.seekg(0, ios::beg);

                    for (int i = 0; i < size; i++) {
                        file.read((char *) &ptr[i], sizeof(*this));
                    }
                    file.close();

                    for (int i = 0; i < size; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (ptr[i].land_size > ptr[j].land_size) {
                                swap(ptr[i], ptr[j]);
                            }
                        }
                    }

                    cout << "\n\n\t======== Sorted  Harvestor Details With Respect to  highest Traded amount   ========\n\n";
                    cout << setw(12) << left << "kisan ID" << setw(20) << left << "Name" << setw(5) << left << "Age"
                         << setw(8) << left << "Gender" << setw(20) << left << "Role" << setw(15) << left
                         << "land_size"
                         << setw(10) << "manure" << setw(15) << "Phoneno" << setw(14) << "City";
                    cout << "\n";

                    for (int i = 0; i < size; i++) {
                        ptr[i].showData();
                    }

                    delete[] ptr;
                    cout << '\n' << "Press any key to continue...\n";
                    cin.ignore();
                    cin.get();

                    if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }

                }
                break;
            }
            default:
                cout << "\n Invalid Input ! Please try again !";
                sortData();
        }
    }
}







void  Harvestor::invoice_generator() {

    int input,bag;
    fstream file;
    float basic_ammount, weight, ammount, total_ammount,bonus,weighing_charge,labour;
    char typ[10];
    file.open(fileName, ios::in | ios::binary);
    cout << "Enter the Cultivator kisan ID:";
    cin >> input;
    cout<<"enter the no of bags\n";
    cin>>bag;
    cout<<"enter the total ammount \n";
    cin>>ammount;
    cout<<"enter the type of arecanut \n";
    cin>>typ;
    
    flag = validateInput();
    if (flag) {
        cout << "Enter correct KId!!";
        invoice_generator();
    } else {


        if (!file) {
            cout << "\tFile Cannot be Open";
            admmenu();
        } else {
            file.read((char *) this, sizeof(*this));
            while (!file.eof()) {
                if (input == kid) {

					weight=65*bag;
                    basic_ammount= ammount;
                    labour = 50;
                    bonus = 0.0025 * basic_ammount;
                    weighing_charge = 20.25 * bag ;
                    total_ammount = basic_ammount + bonus - labour - weighing_charge;

                    cout << "\n -------------------------------------- ";
                    cout << "\n Kisan Id              : " << kid;
                    cout << "\n Cultivator Name       : " << name;
                    cout << "\n city                  : " << city;
                    cout << "\n type of arecanut      : " << typ;
                    cout << "\n quantity of areca nut : " <<weight ;
                    cout << "\n Rate (for kg)         : " << basic_ammount;
                    cout << "\n No.of Bags            : " << bag;
                    cout << "\n ammount for weighing  : " << weighing_charge;
                    cout << "\n labour charge         : " << labour;
                    cout << "\n Bonus ammount         : " << bonus;
                    cout << "\nTotal ammount          : " << total_ammount;
                    //cout << "\n Net Salary      : " << net_salary;
                    cout << "\n -------------------------------------- ";
                    flag = true;
                }
                file.read((char *) this, sizeof(*this));
            }

            file.close();


            if (!flag) {
                cout << "\tRecord For This ID Does Not Exist";
                cout << '\n' << "Press any key to continue...\n";
                cin.ignore();
                cin.get();

                if (logintype == 1) {
                    harvmenu();
                } else {
                    admmenu();
                }

            }

            cout << '\n' << "Press any key to continue...\n";
            cin.ignore();
            cin.get();

            if (logintype == 1) {
                harvmenu();
            } else {
                admmenu();
            }

        }
    }


}






//void Harvestor::getarecaData() {
//	char areca_name[100],code[100],aid[10],buffer[45],extra[45];
//	float Rate;
//	int I,j;
//	market_rate mr1[100];
	//cout << "\tEnter the name of the arecanut  : ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.getline(areca_name, 100);
    //cout << "\tEnter the code for type of arecanut  : ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.getline(code, 100);
    //cout << "\tEnter the Rate of the arecanut-" <<areca_name<<":"  ;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n'
    //cin>>Rate;
    
//     fstream file;
//     file.open("market.txt", ios::out);
//     if(!file)
//		{
//			cout<<"\nUnable to open the file in input mode";
//			return;
//		}
//		cout<<"\nEnter the id for types of arecanut";
//		cin>>aid;
        //file.write((char *) this, sizeof(*this));

        //file.close();
//    time_t tmNow=time(0);
//    char*dt=ctime(&tmNow);
     //fstream file;
        //file.open("rate.txt", ios::out | ios::app | ios::binary);

        //file.write((char *) this, sizeof(*this));

        //file.close();

        //if (!file.good()) {
            // this is enterd For Check Any Error After Writing the file. For Example File Memory Full, File Format Errors.
            //cout << "\tError occurred at writing time!" << endl;
       // }
    //cout << "\n\n\t======== The Market Rate for the Arecanut   ========\n\n";
    //cout << setw(12) << left << dt << setw(20) << left<<areca_name << setw(5) << left << code << setw(8) << left << Rate  ;
    //cout << "\n";
    
   



//void modify()
//{
		//fstream in;
		//char usn[15],buffer[45],extra[45];
		//int I,j;
		//student s1[100];
		//in.open("student.txt",ios::in);
		//if(!in)
		//{
		//	cout<<"\nUnable to open the file in input mode";
		//	return;
		//}
		//cout<<"\nEnter the usn";
		//cin>>usn;
//..............................................................................................................................................................................
// from here  it is for market rate only//
//................................................................................................................................................................................


void writeRecord()
{
		fstream app;
		marketrate s;
		app.open("marketrated.txt",ios::out|ios::app);
		if(!app)
		{
				cout<<"cannot open the file in output mode";
				exit(0);
		}
		cout<<"\nEnter for month		=";
		cin>>s.month;
		cout<<"\nEnter the market rate for rashi per kg	= ";
		cin>>s.rashi;
		cout<<"\nEnter the market rate for bette per kg	= ";
		cin>>s.bette;
		cout<<"\nEnter the market rate for chali per kg	= ";
		cin>>s.chali;
		cout<<"\nEnter the market rate for kole per kg = ";
		cin>>s.kole;
		strcpy(s.buffer,s.month);
		strcat(s.buffer,"|");
		strcat(s.buffer,s.rashi);
		strcat(s.buffer,"|");
		strcat(s.buffer,s.bette);
		strcat(s.buffer,"|");
		strcat(s.buffer,s.chali);
		strcat(s.buffer,"|");
		strcat(s.buffer,s.kole);
		strcat(s.buffer,"\n");
		cout << "\nNew Records Has Been Added Successfully\n";

		app<<s.buffer;
		app.close();
}

void searchs()
{
		fstream in;
		char month[15],extra[45];
		in.open("marketrated.txt",ios::in);
		if(!in)
		{
				cout<<"\nUnable to open the file in input mode";
				exit(0);
		}
		cout<<"\n\nEnter the month you want to search for market rates = ";
		cin>>month;
		marketrate s;
		while(!in.eof())
		{
			in.getline(s.month,15,'|');
			in.getline(s.rashi,15,'|');
			in.getline(s.bette,5,'|');
			in.getline(s.chali,5,'|');
			in.getline(s.kole,15,'\n');
			if(strcmp(s.month,month)==0)
			{
				cout<<"\nRecord found\n";
				cout<<"\n\tMonth\trashi\tbette\tchali\tkole";
		cout<<"\n\t"<<s.month<<"\t"<<s.rashi<<"\t"<<s.bette<<"\t"<<s.chali<<"\t"<<s.kole;
				return;
			}

		}
		cout<<"\nRecord not found\n";
		return;
}
void displayFile()
{
		marketrate s;
		int c,I;
		fstream in;
		in.open("marketrated.txt",ios::in);
		if(!in)
		{
				cout<<"\ncannot open the file in output mode";
				exit(0);
		}
		I=0;
		printf("\nMonth\t\tRashi\t\tBette\t\tChali\t\tKole\n");
		while(!in.eof())
		{
				in.getline(s.month,15,'|');
				in.getline(s.rashi,15,'|');
				in.getline(s.bette,5,'|');
				in.getline(s.chali,5,'|');
				in.getline(s.kole,15,'\n');
			printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s",s.month,s.rashi,s.bette,s.chali,s.kole);
			I++;
		}
	in.close();
	if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }
	//break;
}
//break;
void modify()
{
		fstream in;
		char month[15];
		int I,j;
		marketrate s1[100];
		in.open("marketrated.txt",ios::in);
		if(!in)
		{
				cout<<"\nUnable to open the file in input mode";
				exit(0);
		}
		cout<<"\nFor which month do you want to modify market rates : ";
		cin>>month;
		I=0;
		while(!in.eof())
		{
				in.getline(s1[I].month,15,'|');
				in.getline(s1[I].rashi,15,'|');
				in.getline(s1[I].bette,5,'|');
				in.getline(s1[I].chali,5,'|');
				in.getline(s1[I].kole,15,'\n');
			I++;
		}
		I--;
		for(j=0;j<I;j++)
		{
			if(strcmp(month,s1[j].month)==0)
			{
				cout<<"\nThe old market rate of the month "<<month<<" are : ";
				cout<<"\nmonth    = "<<s1[j].month;
				cout<<"\nrashi	  ="<<s1[j].rashi;
				cout<<"\nbette    = "<<s1[j].bette;
				cout<<"\nchali    = "<<s1[j].chali;
				cout<<"\nkole      = "<<s1[j].kole;
				cout<<"\n\nEnter the new values \n";
				cout<<"\nFor the month    = ";  cin>>s1[j].month;
				cout<<"\nrashi    = "; cin>>s1[j].rashi;
				cout<<"\nbette    = ";  cin>>s1[j].bette;
				cout<<"\nchali    = ";  cin>>s1[j].chali;
				cout<<"\nkole      = ";  cin>>s1[j].kole;
				break;

			}
		}
		if(j==I)
		{
			cout<<"\nThe record with month "<<month<<" is not present\n";
			return;
		}
		in.close();
		fstream out1;
		out1.open("marketrated.txt",ios::out);
		if(!out1)
		{
				cout<<"\nUnable to open the file in output mode";
				return;
		}
		marketrate s;
		for(j=0;j<I;j++)
		{
out1<<s1[j].month<<'|'<<s1[j].rashi<<'|'<<s1[j].bette<<'|'<<s1[j].chali<<'|'<<s1[j].kole<<'\n';
		}
		out1.close();
		if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }
}


	
	
	
	
	
	
	
	
	
//..............................................................................................................................................................................
// till this it is for market rate only//
//................................................................................................................................................................................




    
//..............................................................................................................................................................................
// till this it is for storage only//
//................................................................................................................................................................................


int get_num_records()
{
	int I=0;
	fstream file2;
	file2.open("records.txt",ios::in);
	if(!file2)
	{
	return 0;
	}
	while(!file2.fail()) //Unpacking record data
	{
				file2.getline(stdrec[I].ind,5,'|');
				file2.getline(stdrec[I].slot,5,'|');
				file2.getline(stdrec[I].rashi,15,'|');
				file2.getline(stdrec[I].bette,5,'|');
				file2.getline(stdrec[I].sem,5,'|');
				file2.getline(stdrec[I].kole,15,'\n');
			I++;
		}
	I--;
	file2.close();
	return I;
}

void retrieve_details(char st_no[])
{
	int no;
		no = get_num_records();
		for(int i=0;i<no;i++)
		{
			if(strcmp(stdrec[i].ind,st_no)==0)
			{
				cout<<"\n\n"<<"\t Storage details of slot ";
				cout<<"\nSlot number    :"<<stdrec[i].slot<<"\nRashi bags   :"<<stdrec[i].rashi<<"\nBette bags  :" <<stdrec[i].bette<<"\nChali bags    :"<<stdrec[i].sem<<"\nKole bags   :"<<stdrec[i].kole<<"\n";
		break;
			}
		}
}

void add_record()
{
	int no,i;
	char buf1[100],buf2[20],slot[5];
	fstream file1,file2;
	int I,cnt,kid;
	storage s;
	int sl;
	sl=atoi(s.slot);

		cnt=get_num_records();
		file1.open("indexs.txt",ios::out|ios::app);
		if(!file1)
		{
			cout<<"\nError !\n";
			exit(0);
		}
		file2.open("records.txt",ios::out|ios::app);
		if(!file2)
		{
			cout<<"\nError !\n";
			exit(0);
		}
	
		
		//cout << "\tEnter KISAN ID of cultivator : ";
    	//cin >> kid;
    	label67:
		cout<<"\nHow many number of loads : ";
		cin>>no;
		if(no==0){
		
		cout<<"\n load number cannot be zero";
		goto label67;
	}
		else{
		cout<<"\nEnter the load details :\n";
		for(I=cnt; I<(cnt+no); I++)
		 {

			label66:
				cout<<"\nEnter the slot Number  :";
				cin>>sl;
				for (i = 0; i <= count; i++) {
				if(sl==0){
					cout<<"\n Slot number cannot be zero";
					goto label66;
					
				}
				
				if (ids[i]==sl){
					 cout << "\nThat id is already exists ! Please enter another id\n";
					 goto label66;
				}
				flag=validateInput();
				if(flag)
					return;
			}
					
				cout<<"\nNo of bags of Rashi : ";
				cin>>s.rashi;
				cout<<"\nNo of bags Bette : ";
				cin>>s.bette;
				cout<<"\nNo of bags of kole : ";
				cin>>s.kole;
				cout<<"\nNo of bags of Chali : ";
				cin>>s.sem;
				sprintf(buf2,"%d|%d\n",sl,I);
				file1<<buf2;
			sprintf(buf1,"%d|%d|%s|%s|%s|%s\n",I,sl,s.rashi,s.bette,s.sem,s.kole);
			file2<<buf1;
		}
		file1.close();
		file2.close();
		if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }
}
}

void search_record()
{
	int I,flag1;
	char st_no[5],st_slot[5],rt_slot[5];
	fstream file1;

		cout<<"\nPlease enter the slot number whose deatils is to be displayed:\n";
		cin>>st_slot;
		file1.open("indexs.txt",ios::in);
		if(!file1)
		{
				cout<<"\nError !\n";
				exit(0);
		}
		flag1=0;
		while(!file1.eof())
		{
				file1.getline(rt_slot,5,'|');
				file1.getline(st_no,5,'\n');

				if(strcmp(st_slot,rt_slot)==0)
				{
						retrieve_details(st_no);
						flag1=1;
						break;
				}
		}
		if(!flag1)
			cout<<"\nSlot available please select add slot option\n";
		file1.close();
}

void delete_stdrecord(char sloto[])
{
	int I=0,no;
	fstream file1,file2;
		no = get_num_records();
		int flag=-1;
			for(I=0;I<no;I++)       //Check for the record's existence
			{
				if(strcmp(stdrec[I].ind,sloto)==0)
				{
						flag=I;
						break;
				}
			}
			if(flag==-1)                //Record not found
			{
						cout<<"\nNo slots allocated\n";
						return;
			}
			if(flag==(no-1))            //Delete found last record
			{
						no--;
						cout<<"\n\t\tSlot Deleted !\n";
			}
			else
			{
					for(I=flag;I<no;I++)
					{
							stdrec[I] = stdrec[I+1];
					}
					no--;
					cout<<"\n\t\tSlot Deleted !\n";
			}
		file1.open("indexs.txt",ios::out);
		file2.open("records.txt",ios::out);
		for(I=0;I<no;I++)
		{
			 file1<<stdrec[I].slot<<"|"<<I<<"\n";
file2<<I<<"|"<<stdrec[I].slot<<"|"<<stdrec[I].rashi<<"|"<<stdrec[I].bette<<"|"<<stdrec[I].sem<<"|"<<stdrec[I].kole<<"\n";
		}
		file1.close();
		file2.close();
		return;
		if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }
}

void delete_record()
{
	int I,flag;
	char st_no[5],st_slot[5],rt_slot[5];
	fstream file1;
		cout<<"\nPlease enter the Slot number whose record is to be deleted:";
		cin>>st_slot;
		file1.open("index.txt",ios::in);
		if(!file1)
		{
				cout<<"\nError !\n";
				exit(0);
		}
		flag=0;
		while(!file1.eof())
		{
				file1.getline(rt_slot,5,'|');      //Search index file and
				file1.getline(st_no,5,'\n');       //call deletion
		//if index found
				if(strcmp(st_slot,rt_slot)==0)
				{
						delete_stdrecord(st_no);
						flag=1;
						break;
				}
		}
	if(!flag)
			cout<<"\nDeletion failed ! Slot is available please select add slot option\n";
	file1.close();
}



void display_records()
{
	
	storage s;
	//char sl[5];
	//sl=atoi(slot);
	fstream file2;
	//storage s;
			file2.open("records.txt",ios::in);
			cout<<"\n\n"<<"Storage details : \n";
				cout<<"\n\n"<<"one bag of arecanut contains 65kg  \n";
cout<<"Index"<<"\t"<<"slot"<<"\t"<<"Rashi(in bags)"<<"\t"<<"Bette(in bags)"<<"\t"<<"Kole(in bags)"<<"\t"<<"Chali(in bags)"<<"\t"<<"\n"<<endl;
		while(!file2.fail()) //Unpacking record data
		{
			file2.getline(s.ind,5,'|');
			//file2.getline(s.kid,5,'|');
			file2.getline(s.slot,5,'|');
			file2.getline(s.rashi,15,'|');
			file2.getline(s.bette,5,'|');
			file2.getline(s.sem,5,'|');
			file2.getline(s.kole,15,'\n');
			
cout<<s.ind<<"\t"<<s.slot<<"\t"<<s.rashi<<"\t"<<s.bette<<"\t"<<s.kole<<"\t"<<s.sem<<"\n";
		}
		file2.close();
		if (logintype == 1) {
                        harvmenu();
                    } else {
                        admmenu();
                    }
}


//..............................................................................................................................................................................
// till this it is for storage only//
//................................................................................................................................................................................


void Harvestor::Trade() {

	//displayFile();
	//goto label66;
	int rashi,bette,kole,chali;
	//char rashi[15],month[15],bette[5],chali[5],kole[15],buffer[100];
	//char sname[100];
	int choice,sname;
	 //cout << "\n -------------------------------------- ";
       //             cout << "\n Rashi     : " << Rashi;
        //            cout << "\n Bette   : " << Bette;
         //           cout << "\n kole  : " << kole;
           //         cout << "\n chali : " <<chali ;
                   
             //       cout << "\n -------------------------------------- ";
           
    label77:
    	
	 cout << "\n Enter the kisan id\n ";   
	 cin>>kid;
	 for (i = 0; i <= count; i++) {
        if (kid == 0) {
            cout << "\nKiD can't be zero !";
            goto label77;
        }
        //if (ids[i] == kid) {
            //cout << "\nThat id is already exists ! Please enter another id\n";
            //goto label66;
        //}
}
	 
	 //cout<<"\n choosed type is:"<<sname;
	 cout << "\n Enter the no of bags\n ";   
	 cin>>bag;
	// ammount=37440*weight;
	 //cout<<ammount;
	 cout << "\n the weight of the 1 bag is:65kg\n ";   
	  cout << "\n then the total weight of the  " << bag << "  bag is:\n "; 
	  weight= bag * 65;
	  cout<<weight;
	  ammount=rashi*weight;
	  cout<<ammount;
	  
	 //cout << "\t1 : Rashi\n";
     //cout << "\t2 : Bette\n";
     //cout << "\t3 : kole\n";
     //cout << "\t4 : chali\n";
      //cout << "\n Enter the choice to choose the name of the types of arecanut to sale\n ";   
	 //cin>>sname;
	  
	  //if(sname==1){
	  
	  //ammounts=37440*weight;
	  //cout<<ammounts;
	
	
	cout << "\n\tAre Your Sure to sale your stock as per todays rate\n";
            cout << "\t1 : Yes\n";
            cout << "\t2 : storage\n";
            cout << "\t3 : No\n";
            cout << "\tEnter Your Choice : ";
            cin >> choice;
            if (choice == 1) 
			{
               
                cout << "\n\n\tTrade has been Successfully";


            } 
			else if (choice == 2) 
			{
                
            
                 add_record();
            }
            
			


}
void Harvestor::id_validator() {
    ifstream file;
    int i = 0;
	//storage s;
	int sl;
    file.open(fileName, ios::in | ios::binary);
    if (!file) {
        cout << "\tFile can not Open";
    } else {
        if (isEmpty(file)) {
            cout << "\n\tYour File is Empty! No Record is Available to Show\n";
        } else {
            file.read((char *) this, sizeof(*this));
            while (!file.eof()) {
                ids[i] = kid,sl;
                i++;
                file.read((char *) this, sizeof(*this));
                count++;

            }

        }
        file.close();
    }

}






enum IN {
 

    // 13 is ASCII for carriage

    // return

    IN_BACK = 8,

    IN_RET = 13
 
};
 
// Function that accepts the password
std::string takePasswdFromUser(

    char sp = '*')
{

    // Stores the password

    string pass = "";

    char ch_ipt;
 

    // Until condition is true

    while (true) {
 

        ch_ipt = getch();
 

        // if the ch_ipt

        if (ch_ipt == IN_RET) {

            cout << endl;

            return pass;

        }

        else if (ch_ipt == IN_BACK

                 && pass.length() != 0) {

            //passwd.pop_back();
 

            // Cout statement is very

            // important as it will erase

            // previously printed character

            cout << "\b \b";
 

            continue;

        }
 

        // Without using this, program

        // will crash as \b can't be

        // print in beginning of line

        else if (ch_ipt == IN_BACK

                 && pass.length() == 0) {

            continue;

        }
 

        pass.push_back(ch_ipt);

        cout << sp;

    }
}
 





//***************************************************************
//            FUNCTION DEFINITION USED IN PROJECTS
//****************************************************************




void admmenu() {
    
    int choice;

    bool flag;
    cout
            << "\n----------------------------------------------------------------------------------------------------------------";
    cout << "\n Harvester Record Management System \n";
    cout << "Logged in as Admin\n";
    cout
            << "----------------------------------------------------------------------------------------------------------------";
    
	cout << "\nPlease Select Your Choice :- \n";
    cout << "\t1 : Create cultivator Account\n";
	cout << "\t2 : View Harvestor Details\n";
    
    cout << "\t3 : Add/update Arecanut Market Rate\n";
    cout << "\t4 : update  Arecanut storage Availability\n";
    cout << "\t5 : search Cultivator Records\n";
    cout << "\t6 : update Cultivator Records\n";
    cout << "\t7 : delete Cultivator Records \n";
    cout << "\t8 : sort Cultivator Record\n";
    cout << "\t9 : Invoice Generator\n";
    cout << "\t10 : Logout \n";
    cout << "\tEnter Your Choice : \n\n\n";
    cin >> choice;
    Executions(choice);
    admmenu();


}





void harvmenu() {

    int choice;
    cout
            << "\n----------------------------------------------------------------------------------------------------------------";
    cout << "\n Harvester Record Management System \n";
    cout << "Logged in as Cultivator\n";
    cout
            << "-----------------------------------------------------------------------------------------------------------------";
    
	cout << "\n  Please Select Your Choice :- \n";
    cout << "\t1 : Create Account\n";
    cout << "\t2 : update existing account\n";
    cout << "\t3 : view Account\n";
    cout << "\t4 : Trade\n";
    cout << "\t5 : Check storage Availabillity\n";
    cout << "\t6 : View Market Rate\n";
    cout << "\t7 : Delete Account\n";
    //cout << "\t8 : View Invoice\n";
    cout << "\t8 : Logout \n";
    cout << "\tEnter Your Choice : ";
    cin >> choice;

    switch (choice) {
        case 1:
            Executions(1);
            break;
        case 2:
            Executions(6);
            break;
        case 3:
            Executions(2);
            break;
            
        case 4:
        	
        	Executions(12);
            break;
        
        case 8:
            main();
            break;
            
            
        case 6:
            Executions(11);
            break;
            
        case 7:
            Executions(7);
            break;
            
        //case 8:
          //  Executions(13);
            break;
            
        case 5:
            Executions(4);
            break;
            
        default:
            cout << "\nInvalid choice !";
            harvmenu();
            break;

    }


}



bool validateInput() {
    /* Why do we use:
         1) cin.ignore
         2) cin.clear
         1) To ignore (extract and discard) values that we don't want on the stream.
         2) To clear the internal state of stream. After using cin.clear internal state is set again back to goodbit, which means that there are no 'errors'.
         Long version:
         If something is put on 'stream' (cin) then it must be taken from there. By 'taken' we mean 'used', 'removed', 'extracted' from stream. Stream has a flow. The data is flowing on cin like water on stream. You simply cannot stop the flow of water.
    */

    if (cin.fail()) {
        // Restore input stream
        cin.clear();
        // Clear The All Previous Input Before the '\n' Character
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Throwing Error and Again Input Value From User
        cout << "\n\tError : inValid Value Detected! Please Enter Valid Value Again\n\n";

        return true;
    } else {
        return false;
    }
}


bool isEmpty(ifstream &file) {
    /*
    The peek() function looks into the input stream and tells us what the next character is without removing it from the input stream. Moreover, the peek() function can store the character in a designated memory locatio without actually removing it from the stream.
    */
    return (file.peek() == ifstream::traits_type::eof());
}




void Executions(int ch) {
    //system("cls"); !!causing error
    int dp;

    Harvestor *ptr = NULL;
    Harvestor filedata;
    Harvestor filedata1;
    

    switch (ch) {
        case 1: //addrecords
        label:
            cout << "\tHow Many Cultivator Records that You Want to Store : ";
            cin >> size;

            flag = validateInput();

            if (flag) {
                goto label;
            } else {
                ptr = new Harvestor[size];

                for (int i = 0; i < size; i++) {
                    cout << "\nEnter the Details oF the Cultivator # " << i + 1 << endl;
                    ptr[i].getData();
                }

                for (int i = 0; i < size; i++) {
                    ptr[i].writeFile();
                }

                delete[] ptr;  // Explicitly Delete Memory Location From Heap.

                cout << "\nNew Records Has Been Added Successfully\n";

                Harvestor hp;
                hp.id_validator();
                break;
            }
        case 2: //view all records
            cout
                    << "\n-----------------------------------------------------------------------------------------------------------------";
            cout << "\nCultivator Details\n";
            filedata.readFile();
            break;
        
		case 11: //view market rate for trading
			displayFile();
            //filedata.displayarecaData();
            break;
            
		
		
		case 3: //add/update market rate
			
			//char areca_name[100],code[100];
			//float Rate;
	
			//cout << "\tHow many types of Arecanut should be added : ";
            //cin >> size;
			
			//cout << "\tEnter the name of the arecanut  : ";
            //cin >> areca_name;

			//cout << "\t Enter the code for type of arecanut : ";
            //cin >> code;

			//cout << "\t  Enter the Rate of the arecanut-" <<areca_name<<":" ;
            //cin >> Rate;
			
			//cout << "\tEnter the name of the arecanut  : ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.getline(areca_name, 100);
    //cout << "\tEnter the code for type of arecanut  : ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.getline(code, 100);
    //cout << "\tEnter the Rate of the arecanut-" <<areca_name<<":"  ;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n'
    //cin>>Rate;
			
            //flag = validateInput();

            //if (flag) {
                //goto label;
           // }// else {
                //ptr = new Harvestor[size];
//
                //for (int i = 0; i < size; i++) {
                    //cout << "\nEnter the Details for the types of arecanuts # " << i + 1 << endl;
                    //ptr[i].getarecaData();
                //}

               // for (int i = 0; i < size; i++) {
                    //ptr[i].writeFile();
                //}

                //delete[] ptr;  // Explicitly Delete Memory Location From Heap.

                //cout << "\nNew Records Has Been Added Successfully\n";
				
		int choice;	
		cout<<"\n\n\n0:exit";
		cout<<"\n1:Enter new market rate";
		cout<<"\n2:View market rate";
		cout<<"\n3:Update/modify market rate";
		cout<<"\n4:search market rates";
		cout<<"\n\nEnter the choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:writeRecord();
			break;
			
			case 2:displayFile();
			break;
			case 3:modify();
			break;
			case 4:searchs();
			break;
			case 0:exit(0);
			default:cout<<"\nInvalid input....";break;
		}
                //Harvestor hp;
                //hp.id_validator();
                //hp.getarecaData();
            break;
            
			
		
		
		
		
		//case 13: //view invoice cultivator side 
		//invoicedisplayFile();
		//break;
			
			
		
		case 5: //search records
            cout << "\nPlease Enter cultivator  Kisan ID That you Want to Search its Record : ";
            
             cin >> search;
            filedata.searchData();
            break;
    	case 6: //update records
            cout << "\tPlease Enter Cultivator Kisan ID That you Want to Update its Record : ";
            cin >> search;
            filedata.updateData(search);
            break;
    	case 7: //delete records
            cout << "\tPlease Enter cultivator Unique ID you Want to Delete its Record : ";
            cin >> search;
            filedata.deleteData(search);
            break;
    	case 8: //sort records
            filedata.sortData();
            break;
        case 4: //storage availability
            cout << "Enter the options in storage department\n";
            cout << "1.ADD arecanut slot\n2.display the slot\n3.search the areca slot \n4.Remove an areca slot\n5.Exit\n";
            cout << "\nEnter your choice: ";
            cin >> dp;

            switch (dp) {
                case 1:
                    add_record();
                    break;
                case 2:
                    display_records();
                    break;
                case 3:
                    search_record();
                    break;
                case 4:
                    delete_record();
                    break;
                //case 5:
                    //filedata.accdep();
                    //break;
                //case 6:
                    //harvmenu();
                    //break;
                case 5:
                    break;
                default:
                    cout << "Please give correct input " << endl;
            }
            break;

    	case 9 :
            filedata.invoice_generator();
            break;
            
            
        case 12:
        	//displayFile();
        	filedata.Trade();
        	
        	break;
        
		
		case 10:
            cout << "\nlogout Successful!\n";
            main();
            check = false;
            break; //invalid input
        default:
            cout << "\tInvalid Choice! Please Select Valid Choice.";
            break;
    }
    cout << "\n";
    cout << "\t" << system("pause");
}








int main() {


    string uname, pass;
    int ip,i=0;
    char c=' '; 
    Harvestor hp;
    hp.id_validator(); // i need to write above this for this function

    
    cout << "\n";
    cout
            << "-----------------------------------------------------------------------------------------------------------------------";
    cout << "\n    Harvester Record Management System  \n\n";
    cout << "           .--.                   .---.\n"
            "       .---|__|           .-.     |~~~|\n"
            "    .--|===|--|_          |_|     |~~~|--.\n"
            "    |  |===|  |'\\     .---!~|  .--|   |--|\n"
            "    |%%|   |  |.'\\    |===| |--|%%|   |  |\n"
            "    |%%|   |  |\\.'\\   |   | |__|  |   |  |\n"
            "    |  |   |  | \\  \\  |===| |==|  |   |  |\n"
            "    |  |   |__|  \\.'\\ |   |_|__|  |~~~|__|\n"
            "    |  |===|--|   \\.'\\|===|~|--|%%|~~~|--|\n"
            "    ^--^---'--^    `-'`---^-^--^--^---'--'";
    cout
            << "\n---------------------------------------------------------------------------------------------------------------------";

    cout << "\n\n1. Cultivator Login \n2. Admin Login \n3. Exit \n\n";
    cout << "Enter your choice :  \n";
    cin >> logintype;
    flag = validateInput();
    if (flag)
        main();
    switch (logintype) {

        case 1: {
            cout
                    << "----------------------------------------------------------------------------------------------------------------";
            cout << "\nCultivator Login \n";
            cout
                    << "----------------------------------------------------------------------------------------------------------------";
            cout << "\nEnter Cultivator username : ";
            cin >> uname;
            cout << "\nEnter Cultivator password : ";
            char ch;
            //cin >> pass;
            //pass = takePasswdFromUser();


            if (uname != "har001" || pass != "har001") {
                cout << "\nWrong username or password !";
                int ip;
                cout << "\n1.Try again\n2.Exit\nPlease enter your choice : ";
                cin >> ip;
                switch (ip) {
                    case 1:
                        main();
                        break;
                    case 2:
                        exit(0);
                    default:
                        cout << "\n Invalid input !\n";
                        main();
                }
                break;
            } else {
                cout << "\n Login successful !\n";
                harvmenu();
            }
            break;
        }
        case 2: {
            cout
                    << "\n----------------------------------------------------------------------------------------------------------------";
            cout << "\nAdmin Login\n";
            cout
                    << "\n----------------------------------------------------------------------------------------------------------------";
            cout << "\nEnter Admin  username : ";
            cin >> uname;
            cout << "\nEnter Admin  password : ";
            cin >> pass;
			//cout<<"*";
            
            	//while(i<10)
	//{
	  //  		pass[i]=getch();
	    //		c=pass[i];
	    //		if(c==13) break;
	    //		else printf("*");
	    //		i++;
	    		
	//}
			//	pass[i]='\0';
            
            if (uname != "mgr001" || pass != "mgr001") {
                cout << "\nWrong username or password !";
                int ip;
                cout << "\n1.Try again\n2.Exit\nPlease enter your choice : ";
                cin >> ip;
                switch (ip) {
                    case 1:
                        main();
                        break;
                    case 2:
                        exit(0);
                    default:
                        cout << "\nInvalid input !\n";
                        main();
                }

            } else {
                cout << "\nLogin successful !\n";
                admmenu();
            }
            break;

        }

        case 3:
            cout << "Thank you for using the system !";
            exit(0);

        default:
            cout << "\nInvalid input ! try again !";
            main();
    }


}
